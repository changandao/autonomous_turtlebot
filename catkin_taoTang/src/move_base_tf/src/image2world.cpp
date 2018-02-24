#include "image2world.h"

Image2World::Image2World(){
    changeScanRange(angle_min+M_PI/2, M_PI/9);
    boud_bb = nh.subscribe<geometry_msgs::Point>("/image_processing/ball",1,&Image2World::bbprocess, this);
    laser_sub = nh.subscribe("/scan", 1, &Image2World::laser_sb, this);
    pointttt = nh.advertise<geometry_msgs::PointStamped>("/my_topics/3dpoint",10);
}

int Image2World::angle2index(double angle){
    int idx = int((angle- angle_min) / angle_increment);
    return idx;
}

double Image2World::index2angle(int index){
    double angle = double(angle_min + index * angle_increment);
    return angle;
}

// NOTE: 107 deg = left bottom; 95 = 2nd left bottom; 65 deg = 3rd left bottom
// 252 = right bottom, 264 = 2nd right bottom; 295 = 3rd right bottom
void Image2World::changeScanRange(double center, double range){
    angle_start = center - range/2 + ANGLE_OFFSET/2;
    angle_range = range;
    debug = true;
    if(debug) std::cout << "center: " << center << "range: " << range << std::endl;
    debug = false;
}

double Image2World::rad2degree(double rad){
    return 57.2958 * (rad-angle_min);
}

// call back functions
void Image2World::bbprocess(const geometry_msgs::PointConstPtr &point){
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

void Image2World::laser_sb(const sensor_msgs::LaserScanConstPtr &scan){
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

                double ratio = p.point.y / p.point.x;
                p.point.x -= 0.2;
                p.point.y -= 0.2*ratio + 0.05;

                p.point.z = theta + (double(x) - 320.0)/320.0 * angle_max;
                if((p.point.x!=0)|(p.point.y!=0)){
                    tf::TransformListener listener;
                    listener.waitForTransform("odom","/camera_dImage2Wroldepth_frame",ros::Time(0),ros::Duration(3.0));
                    geometry_msgs::PointStamped ppp;
                    listener.transformPoint("odom",p, ppp);
                    std::cout << "ppp " << ppp.point.x << " " << ppp.point.y << std::endl;

                    cb_count++;
                    if (cb_count < 5) pointttt.publish(ppp);
                }
            }
        }
        cache_idx = 1;

    }
}

int main(int argc, char **argv){

    ros::init(argc,argv,"feature_node");

    ros::NodeHandle nh;
    Image2World image2world;

    ros::Rate rate(30);
    int cache_idx = 1;


    image2world.changeScanRange(image2world.angle_min+0.57, M_PI/18);
    image2world.listener.waitForTransform("odom", "base_link", ros::Time(0), ros::Duration(3.0));

    while(nh.ok()){
        tf::StampedTransform transform;
        try{
            image2world.listener.lookupTransform("odom", "base_link", ros::Time(0), transform);
        }
        catch (tf::TransformException &ex){
            ROS_ERROR("%5", ex.what());
            ros::Duration(1.0).sleep();
            continue;
        }
        tf::Quaternion rotation;
        rotation = transform.getRotation();
        tf::Matrix3x3 m(rotation);
        double roll, pitch;
        m.getRPY(roll, pitch, image2world.theta);

        std::cout << "    " << image2world.theta << std::endl;

        ros::spinOnce();
        rate.sleep();
    }
    //else if(k<0)
    //changeScanRange(angle_max-M_PI/36+k, M_PI/10);

    //laser_sub_angel_change = nh.subscribe("/lidarscan", 1, &laser_sb_angel_change);
    //laserpoint = nh.subscribe<sensor_msgs/PointCloud>("my_cloud",1,&pcl);
    ros::spin();
}
