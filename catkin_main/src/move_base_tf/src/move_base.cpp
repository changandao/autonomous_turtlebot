#include <ros/ros.h>
#include <tf/transform_broadcaster.h>
#include <tf/transform_listener.h>
#include <math.h>


int main(int argc, char** argv){
    ros::init(argc, argv, "move_base_listener");
    ros::NodeHandle node;

    ros::Publisher turtle_vel =
            node.advertise<geometry_msgs::Twist>("mobile_base/commands/velocity", 10);

    tf::TransformListener listener;
    ros::Rate rate(10.0);
    listener.waitForTransform("base_link", "goal_pose", ros::Time(0), ros::Duration(3.0));

    while (node.ok()){
        tf::StampedTransform transform;
        try{
            listener.lookupTransform("base_link", "goal_pose", ros::Time(0), transform);
            geometry_msgs::Twist vel_msg;
            double x = transform.getOrigin().x();
            double y = transform.getOrigin().y();
            double z = transform.getOrigin().z();
            ROS_INFO_STREAM(x << " " << y << " " << z);
            vel_msg.angular.z = double(1.0 * atan2(y, x));
            vel_msg.linear.x = double(0.1 * sqrt(pow(x, 2) + pow(y, 2)));
//            turtle_vel.publish(vel_msg);
        }
        catch (tf::TransformException &ex) {
            ROS_ERROR("%s",ex.what());
            ros::Duration(1.0).sleep();
            continue;
        }

        rate.sleep();
    }
    return 0;
};
