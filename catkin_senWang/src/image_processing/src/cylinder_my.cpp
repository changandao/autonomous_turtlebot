#include <ros/ros.h>
#include <tf/tf.h>
#include <tf/transform_listener.h>
#include <sensor_msgs/LaserScan.h>
#include <geometry_msgs/Point.h>
#include <iostream>
#include <geometry_msgs/PointStamped.h>
#include <math.h>
#include <perception_msgs/Rect.h>

using namespace std;
const double DETECTION_RANGE = 4;
const double CYLINDER_OFFSET = 0.03;

ros::Subscriber laser_sub;
ros::Subscriber laser_sub_angel_change;
ros::Subscriber boud_bb;
//ros::Publisher pointttt;

/*ros::Subscriber laserpoint;*/
const double angle_max = 0.5106329;
const double angle_min = -0.5106329;
const double angle_increment = 0.001598225;
const int num_ranges = 640;

double angle_start = M_PI;
double angle_range = M_PI/36;

const double ANGLE_OFFSET = angle_min+M_PI;

// cache scan->ranegs
int cache_idx = 1;
const int cache_idx_max = 6; // from 1 to 6, cache 5 times
double cache_ranges[640][cache_idx_max-1] = {};
double ranges_to_use[num_ranges];

double range_min;
double range_min_angle;

// variables for 2nd laserscan call back function
int angle_change = 1;
int angle_loop_idx = 1; // 1 - 7
int angle_loop_max = 7;
double angle_range_laser_sb_angle_change = M_PI/18;
const double angle_center1 = angle_min+1.65806;  // center 95 deg
const double angle_center2 = angle_min+1.8675;  // center 107 deg
const double angle_center3 = angle_min+4.39823;  // center 252 deg
const double angle_center4 = angle_min+5.14872;  // center 295 deg

double a_b_saver[4] = {0};  // min_range at 95, 107 ... deg
double k;
int x = 10;
geometry_msgs::PointStamped p;

// some flags
bool debug = false;
bool a_b_ready = false;

// some functions
int angle2index(double angle){
    int idx = int((angle- angle_min) / angle_increment);
    return idx;
}

double index2angle(int index){
    double angle = double(angle_min + index * angle_increment);
    return angle;
}

// NOTE: 107 deg = left bottom; 95 = 2nd left bottom; 65 deg = 3rd left bottom
// 252 = right bottom, 264 = 2nd right bottom; 295 = 3rd right bottom
void changeScanRange(double center, double range){
    angle_start = center - range/2 + ANGLE_OFFSET/2;
    angle_range = range;
    debug = true;
    if(debug) std::cout << "center: " << center << "range: " << range << std::endl;
    debug = false;
}
void bbprocess(const geometry_msgs::PointConstPtr &point){
    k = (640 - point->x)/640*1.0212;
    x = (640 - point->x);
    //cout << k <<endl;
    //cout<<k<<endl;
    //if(k>=0)
    cout<<x<<endl;
    changeScanRange(angle_min+k, M_PI/18);
    //else if(k<0)
    //changeScanRange(angle_max-M_PI/36+k, M_PI/18);

}
double rad2degree(double rad){
    return 57.2958 * (rad-angle_min);
}

// varibales for 1st laserscan call back function
const int angle_center1_idx = angle2index(angle_center1);
const int angle_center2_idx = angle2index(angle_center2);
const int angle_center3_idx = angle2index(angle_center3);
const int angle_center4_idx = angle2index(angle_center4);
const int angle_center_threshold_idx = 5;
const double angle_center_threshold_rad = 0.0872665;  // 5 deg

// first laser call back function
void laser_sb(const sensor_msgs::LaserScanConstPtr &scan){
    //cout <<scan->ranges.size()<<endl;;
    int num_missing = 0;
    if(cache_idx<cache_idx_max){
        //cache
        for (size_t idx = 1; idx <= num_ranges; idx++){
            if (!isinf(scan->ranges[idx])){
                cache_ranges[idx][cache_idx] = scan->ranges[idx];
            }else{
                cache_ranges[idx][cache_idx] = 0;
            }
            if(debug) std::cout << cache_ranges[idx][cache_idx] << " ";
        };
        if(debug) std::cout << std::endl;
        if(debug) std::cout << "cache_idx = " << cache_idx << std::endl;
        cache_idx++;
    }else{
        // cal mean for cache_ranges
        int num_zero = 0;
        double sum_nonzeros = 0;
        for (size_t i = 1; i <= num_ranges; i++){
            for (size_t j = 1; j < cache_idx_max; j++){
                // num of non zero
                if (cache_ranges[i][j] == 0){
                    num_zero++;
                }else{
                    sum_nonzeros += cache_ranges[i][j];
                }
            }
            if (num_zero == cache_idx_max-1){
                num_missing ++;
            }
            // all values missing, set ranges_to_use to 0
            if (num_zero == cache_idx_max-1){
                ranges_to_use[i] = 0;
            }else{
                ranges_to_use[i] = sum_nonzeros / (cache_idx_max-1-num_zero);
            }
            //            if(debug) std::cout << i << ":sum: " << sum_nonzeros <<  " num_zero: " << num_zero << " range: " << ranges_to_use[i] << "  ";
            num_zero = 0;
            sum_nonzeros = 0;
            if(debug) std::cout << ranges_to_use[i] << " ";
        }
        if(debug) std::cout << "cache_id: " << cache_idx << " num of missing values: " << num_missing << std::endl;
        num_missing = 0;
        if(debug) std::cout << std::endl;
        if(debug) std::cout << "cache_idx = " << cache_idx << std::endl;
        cache_idx = 0;
    }
    //cout << 1 << endl;

    // make sure angle_start and angle_range legal
    // cache_idx == 0 -> find range_min
    if (cache_idx == 0)
    {
        /* code */

        if (x>20)
        {
            /* code */
            
            int idx_start = x - 20;
            int idx_stop = x + 20;
            
            range_min = scan->range_max;
            range_min_angle = scan->angle_min;
            for (size_t idx = idx_start; idx <= idx_stop; idx++){
                if (0.4<ranges_to_use[idx]<range_min & ranges_to_use[idx] != 0 & !isnan(ranges_to_use[idx])){
                    range_min = ranges_to_use[idx];
                    range_min_angle = index2angle(idx);
                }
            }
            //cout << range_min <<endl;
            // range threshold
            if (range_min >= DETECTION_RANGE){
                range_min = 0;
                range_min_angle = angle_min;
            }
            debug = true;
            if(debug) std::cout << "index range: " << idx_start << " " << idx_stop << std::endl;
            //            if(debug) std::cout << "angel range: " << rad2degree(index2angle(idx_start)) << " " << rad2degree(index2angle(idx_stop)) << std::endl;
            if(debug) std::cout << "range: " << range_min << " angle: " << rad2degree(range_min_angle) << std::endl;
            debug = false;


            if (!isnan(range_min_angle))
            {
                /* code */
                cout <<"fuck" <<endl;//cout <<"fuck" <<endl;
                p.header.frame_id = "/camera_depth_frame";
                p.header.stamp = ros::Time();
                p.point.x = cos(range_min_angle) * range_min;
                p.point.y = sin(range_min_angle) * range_min;
                p.point.z = 0.25;
                if((p.point.x!=0)|(p.point.y!=0)){
                    tf::TransformListener listener;
                    listener.waitForTransform("odom","/camera_depth_frame",ros::Time(0),ros::Duration(3.0));
                    geometry_msgs::PointStamped ppp;
                    listener.transformPoint("odom",p, ppp);
                    std::cout << "ppp " << ppp.point.x << " " << ppp.point.y << std::endl;
//                    pointttt.publish(ppp);
                }
            }
        }
        cache_idx = 1;

    }
}


int main(int argc, char **argv){

    ros::init(argc,argv,"feature_node");
    ros::NodeHandle nh;
    //tf::TransformListener listener;


    ros::Rate rate(30);
    int cache_idx = 1;

    // inti angel_start and angle_stop
    changeScanRange(angle_min+M_PI/2, M_PI/9);

    //cout << M_PI << endl;


    boud_bb = nh.subscribe<geometry_msgs::Point>("/image_processing/ball",1,&bbprocess);
    laser_sub = nh.subscribe("/scan", 1, &laser_sb);

    //if(k>=0)
    changeScanRange(angle_min+0.57, M_PI/18);
    //else if(k<0)
    //changeScanRange(angle_max-M_PI/36+k, M_PI/10);

//    pointttt = nh.advertise<geometry_msgs::PointStamped>("/my_topics/3dpoint",10);
    //laser_sub_angel_change = nh.subscribe("/lidarscan", 1, &laser_sb_angel_change);
    //laserpoint = nh.subscribe<sensor_msgs/PointCloud>("my_cloud",1,&pcl);
    ros::spin();
}
