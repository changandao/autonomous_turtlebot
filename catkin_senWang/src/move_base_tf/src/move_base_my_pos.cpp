#include <ros/ros.h>
#include <tf/transform_broadcaster.h>
#include <tf/transform_listener.h>
#include <math.h>


int main(int argc, char** argv){
    ros::init(argc, argv, "move_base_listener");
    ros::NodeHandle node;
    ros::Publisher turtle_vel =
           node.advertise<geometry_msgs::Twist>("mobile_base/commands/velocity", 10);



    //ros::Subscriber goal_pos_sub = node.subscribe("/my_move_base/goal_pos", 10, &goalcallback);

//    ros::Publisher my_pose_pub =
//            node.advertise<geometry_msgs::Point>("/my_move_base/my_pos", 10);

    tf::TransformListener listener;
    ros::Rate rate(10.0);
    listener.waitForTransform("goal_pos", "base_link", ros::Time(0), ros::Duration(3.0));


    while (node.ok()){
        tf::StampedTransform transform;
        try{
            listener.lookupTransform("goal_pos", "base_link", ros::Time(0), transform);

        }
        catch (tf::TransformException &ex) {
            ROS_ERROR("%s",ex.what());
            ros::Duration(1.0).sleep();
            continue;
        }

        geometry_msgs::Twist vel_msg;
        double x = transform.getOrigin().x();
        double y = transform.getOrigin().y();
        double z = transform.getOrigin().z();

//        geometry_msgs::Point my_pose;
//        my_pose.x = P_3d.x-x;
//        my_pose.y = P_3d.y-y;
//        my_pose.z = P_3d.z-z;
        vel_msg.angular.z = double(1.0 * atan2(y, x));
        vel_msg.linear.x = double(0.1 * sqrt(pow(x, 2) + pow(y, 2)));
        ROS_INFO_STREAM(vel_msg.angular.z << " " << vel_msg.linear.x);

        turtle_vel.publish(vel_msg);

        ros::spinOnce();
        rate.sleep();
    }
    return 0;
};
