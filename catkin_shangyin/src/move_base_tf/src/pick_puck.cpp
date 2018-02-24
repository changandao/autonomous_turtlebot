#include "lidarscan.h"

double range_left;
double range_right;
double angle_left;
double angle_right;

double angular_vel_threshold = 0.2;

int goal_LR = 0;  // 0 = left; 1 = right

bool debug = false;

int main(int argc, char** argv){
    ros::init(argc, argv, "pick_puck");
    ros::NodeHandle nh;

    // lidarscan constructor
    // for lidarscan
    LidarScan lidarscan;
    ros::Rate rate(30.0);
    lidarscan.changeScanRange(lidarscan.angle_min+M_PI/2, M_PI/9*3);

    lidarscan.pick_puck_ready = false;  // false = check left and right for pick puck


    geometry_msgs::Twist vel_msg;

    while (nh.ok()){
        if(debug) std::cout << "one loop" << std::endl;

        // cal range angle of left and right
        range_left = lidarscan.pick_puck_saver[0][0];
        range_right = lidarscan.pick_puck_saver[1][0];
        angle_left = lidarscan.pick_puck_saver[0][1];
        angle_right = lidarscan.pick_puck_saver[1][1];

        // TODO: use tf to control vel_msg
        if(goal_LR == 0){
            // go to left cylinder
            vel_msg.angular.z = 0.2*(-angle_left);
        }

        // if angular.z too small, then stop
        if (vel_msg.angular.z < angular_vel_threshold)
            vel_msg.angular.z = 0;

        debug = true;
        if(debug) std::cout << "angular vel: " << vel_msg.angular.z << std::endl;
        debug = false;

        lidarscan.turtle_vel.publish(vel_msg);


        ros::spinOnce();
        rate.sleep();
    }

    return 0;
};
