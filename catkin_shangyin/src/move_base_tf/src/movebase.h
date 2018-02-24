#ifndef MOVEBASE_H
#define MOVEBASE_H

#include <ros/ros.h>
#include <tf/transform_broadcaster.h>
#include <tf/transform_listener.h>
#include <geometry_msgs/PointStamped.h>
#include <tf/transform_datatypes.h>
#include <math.h>

class MoveBase{
    public:
        // varibales for set_frame
        double x_transform = 0;
        double y_transform = 0;
        double theta_transform = 0;

        bool reach_goal = false;
        bool reach_goal_theta = false;
        bool use_rearly_stop = true;
        bool point_sb_finish = false;
        bool set_frame_flag = true;

        tf::TransformBroadcaster br;
        tf::Transform transform;
        tf::TransformListener listener;
        ros::Publisher turtle_vel;

        // constructor
        MoveBase();

        ros::Subscriber Point_sub;  // = node.subscribe<geometry_msgs::PointStamped>("/my_topics/3dpoint", 1, &point_sub);
        void point_sb(const geometry_msgs::PointStamped::ConstPtr &point);

        double point_x = 0;
        double point_y = 0;

        // set_frame for external use
        void set_frame(double x, double y, double theta);
        void go_to_position();  // empty function


    private:
        ros::NodeHandle nh;
        ros::NodeHandle node;  // for frame broadcaster


};


#endif
