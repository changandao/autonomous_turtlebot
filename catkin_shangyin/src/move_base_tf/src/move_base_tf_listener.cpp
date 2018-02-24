#include <ros/ros.h>
#include <tf/tf.h>
#include <tf/transform_listener.h>
#include <geometry_msgs/Twist.h>

int main(int argc, char** argv){
  ros::init(argc, argv, "my_tf_listener");

  ros::NodeHandle node;

  ros::Publisher turtle_vel = node.advertise<geometry_msgs::Twist>("my_topics/reach_goal_pose", 1);

  tf::TransformListener listener;

  ros::Rate rate(60.0);
  double reach_goal_pose = false;
  while (node.ok()){
    tf::StampedTransform transform;
    try{
      listener.lookupTransform("base_link", "goal_pose", ros::Time(0), transform);
    }
    catch (tf::TransformException &ex) {
      ROS_ERROR("%s",ex.what());
      ros::Duration(1.0).sleep();
      continue;
    }
    double x_base_goal = transform.getOrigin().x();
    double y_base_goal = transform.getOrigin().y();
    tf::Quaternion rotation;
    rotation = transform.getRotation();
    tf::Matrix3x3 m(rotation);
    double roll, pitch, theta_base_goal;
    m.getRPY(roll, pitch, theta_base_goal);
    std::cout << "==========================" << std::endl;
    std::cout << std::abs(x_base_goal) << " " << std::abs(y_base_goal) << " " << std::abs(theta_base_goal) << std::endl;
    if (std::abs(x_base_goal)<0.02 & std::abs(y_base_goal)<0.02 & std::abs(theta_base_goal)<0.04){
        reach_goal_pose = true;
    }else{
        reach_goal_pose = false;
    }

    geometry_msgs::Twist vel_msg;
    vel_msg.linear.x = reach_goal_pose;
    turtle_vel.publish(vel_msg);


    rate.sleep();
  }
  return 0;
};
