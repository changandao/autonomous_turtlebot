#ifndef LIDARSCAN_H
#define LIDARSCAN_H

#include <ros/ros.h>
#include <tf/tf.h>
#include <tf/transform_listener.h>
#include <tf/transform_broadcaster.h>
#include <sensor_msgs/LaserScan.h>


class LidarScan {

    public:
        // some flags
        bool debug = false;
        bool a_b_ready = true;  // for four cylinder, true = not save pos and angle
        bool pick_puck_ready = true;  // true = not save pos and angle

        static const double angle_max = 3.141593;
        static const double angle_min = -3.121439;
        static const double angle_increment = 0.0174533;
        static const int num_ranges = 360;

        double pick_puck_saver[2][2] = {};
        double a_b_saver[4][2] = {};  // [range][angle(rad)] at 95, 107 ... deg


        void changeScanRange(double center, double range);

        // calculate A and B, return
        // for a and b
        double a = 0;
        double b = 0;
        bool a_b_finish = false;
        void calAandB();

        // calculate tor pos
        double tor_x = 0;
        double tor_y = 0;
        bool tor_pos_finish = false;
        void calTorPos();

        // border
        double border_1;  // left border
        double border_2;  // right border
        double border_3;  // bottom border


        // cal team colour detection pos
        double team_colour_x = 0;
        double team_colour_y = 0;
        double team_colour_theta = 0;
        bool team_colour_finish = false;
        void calTeamColourPos();

        ros::NodeHandle nh;

        // for pick_puck
        ros::Publisher turtle_vel;

        LidarScan();

    private:
        static const double DETECTION_RANGE = 2;
        static const double CYLINDER_OFFSET = 0.03;
        static const double TURTLEBOT_OFFSET = 0.15;

        // for pick_pucks
        static const double PICK_RANGE = 0.6;

        double angle_start = M_PI;
        double angle_range = M_PI/36;

        double ANGLE_OFFSET = angle_min+M_PI;

        // cache scan->ranegs
        int cache_idx = 1;
        static const int cache_idx_max = 6; // from 1 to 6, cache 5 times
        double cache_ranges[360][cache_idx_max-1] = {};
        double ranges_to_use[num_ranges];

        double range_min;
        double range_min_angle;

        // variables for 2nd laserscan call back function
        int angle_change = 1;
        int angle_loop_idx = 1; // 1 - 7
        static const int angle_loop_max = 7;  // TODO: chage angle_loop_max to cache_idx_max + 1
        static const double angle_range_laser_sb_angle_change = M_PI/18;
        double angle_center1 = angle_min+1.0821;  // center 65 deg
        double angle_center2 = angle_min+1.8675;  // center 107 deg
        double angle_center3 = angle_min+4.39823;  // center 252 deg
        double angle_center4 = angle_min+5.14872;  // center 295 deg

        // varibales for 3rd laserscan call back
        int angle_change_pick_puck = 1;
        static const double angle_range_LR_angle_change = M_PI/4.5;  //detect angle range = 40 deg
        double angle_center_left = angle_min+angle_range_LR_angle_change/2;
        double angle_center_right = angle_max-angle_range_LR_angle_change/2;
//        double angle_center_LR_threshold_rad = angle_range_LR_angle_change/2;

        // varibales for 1st laserscan call back function
        int angle_center1_idx = angle2index(angle_center1);
        int angle_center2_idx = angle2index(angle_center2);
        int angle_center3_idx = angle2index(angle_center3);
        int angle_center4_idx = angle2index(angle_center4);
        double angle_center_threshold_rad = angle_range_laser_sb_angle_change/2;  // half angle of angle_range_laser_sb_angle_change
        static const int angle_center_threshold_idx = 5;


        int angle2index(double angle);
        double index2angle(int index);
        double rad2degree(double rad);

        // for pick_puckS
        void checkLeft();
        void checkRight();

        // NOTE: commit this if do not use this call back function
        ros::Subscriber laser_sub;
        ros::Subscriber laser_sub_angel_change;
        ros::Subscriber laser_sub_pick_puck;

        tf::Transform transform;
        tf::TransformListener listener;

        void laser_sb(const sensor_msgs::LaserScan::ConstPtr &scan);
        void laser_sb_angel_change(const sensor_msgs::LaserScan::ConstPtr &scan);
        void laser_sb_pick_puck(const sensor_msgs::LaserScan::ConstPtr &scan);
};

#endif
