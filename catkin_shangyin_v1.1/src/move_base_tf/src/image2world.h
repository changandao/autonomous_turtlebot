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

class Image2World{
    private:
        static const double DETECTION_RANGE = 4;
        static const double CYLINDER_OFFSET = 0.03;

        double angle_start = M_PI;
        double angle_range = M_PI/36;

        double ANGLE_OFFSET = angle_min+M_PI;

        // cache scan->ranegs
        int cache_idx = 1;
        static const int cache_idx_max = 6; // from 1 to 6, cache 5 times
        static const int num_ranges = 640;
        double cache_ranges[640][cache_idx_max-1] = {};
        double ranges_to_use[num_ranges] = {0.0};

        double range_min;
        double range_min_angle;

        // variables for 2nd laserscan call back function
        int angle_change = 1;
        int angle_loop_idx = 1; // 1 - 7
        static const int angle_loop_max = 7;
//        double angle_range_laser_sb_angle_change = M_PI/18;
//        const double angle_center1 = angle_min+1.65806;  // center 95 deg
//        const double angle_center2 = angle_min+1.8675;  // center 107 deg
//        const double angle_center3 = angle_min+4.39823;  // center 252 deg
//        const double angle_center4 = angle_min+5.14872;  // center 295 deg

        double a_b_saver[4] = {0};  // min_range at 95, 107 ... deg
        double k;
        int x = 10;
        geometry_msgs::PointStamped p;

        // some flags
        bool debug = false;
        bool a_b_ready = false;

        int cb_count = 0;

        ros::NodeHandle nh;
        ros::Subscriber laser_sub;
        ros::Subscriber laser_sub_angel_change;
        ros::Subscriber boud_bb;
        ros::Publisher pointttt;

        int angle2index(double angle);
        double index2angle(int index);
        double rad2degree(double rad);

        void laser_sb(const sensor_msgs::LaserScanConstPtr &scan);
        void bbprocess(const geometry_msgs::PointConstPtr &point);

    public:

        static const double angle_max = 0.5106329;
        static const double angle_min = -0.5106329;
        static const double angle_increment = 0.001598225;

        tf::Transform transform;
        tf::TransformListener listener;

        //void setTheta()
        double theta = 0;

        Image2World();

        // NOTE: 107 deg = left bottom; 95 = 2nd left bottom; 65 deg = 3rd left bottom
        // 252 = right bottom, 264 = 2nd right bottom; 295 = 3rd right bottom
        void changeScanRange(double center, double range);

};

