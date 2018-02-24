

#include <turtlesim/Pose.h>

#include <ros/ros.h>
#include <tf/transform_broadcaster.h>
#include <tf/transform_listener.h>
#include <geometry_msgs/PointStamped.h>
#include <tf/transform_datatypes.h>
#include <math.h>

//std::string turtle_name;

//void poseCallback(const turtlesim::PoseConstPtr& msg){
//  static tf::TransformBroadcaster br;
//  tf::Transform transform;
//  transform.setOrigin( tf::Vector3(msg->x, msg->y, 0.0) );
//  tf::Quaternion q;
//  q.setRPY(0, 0, msg->theta);
//  transform.setRotation(q);
//  br.sendTransform(tf::StampedTransform(transform, ros::Time::now(), "world", turtle_name));
//}

//int main(int argc, char** argv){
//  ros::init(argc, argv, "my_tf_broadcaster");
//  if (argc != 2){ROS_ERROR("need turtle name as argument"); return -1;};
//  turtle_name = argv[1];

//  ros::NodeHandle node;
//  ros::Subscriber sub = node.subscribe(turtle_name+"/pose", 10, &poseCallback);

//  ros::spin();
//  return 0;
//};


double x_transform;
double y_transform;
double theta_transform;


void poseCallback(const geometry_msgs::PointStamped::ConstPtr &point){

    x_transform = point->point.x;
    y_transform = point->point.y;
    theta_transform = point->point.z;


}

int main(int argc, char** argv){
  ros::init(argc, argv, "movebase_broadcaster");

  ros::NodeHandle node;
  // frame broadcaster
  tf::TransformBroadcaster br;
  tf::Transform transform;

  ros::Rate rate(30);


  ros::Subscriber sub = node.subscribe<geometry_msgs::PointStamped>("/my_topics/3dpoint", 1, &poseCallback);
  while(node.ok()){


      // frame broadcaster
      transform.setOrigin( tf::Vector3(x_transform, y_transform, 0.0) );
      tf::Quaternion q;
      q.setRPY(0, 0, theta_transform);
      transform.setRotation(q);
      //        movebase.transform.setRPY(0, 0, movebase.theta_transform);
      br.sendTransform(tf::StampedTransform(transform, ros::Time::now(), "/odom", "/goal_pose"));

      ros::spinOnce();
      rate.sleep();
  }

//  ros::spin();
//  rate.sleep();
  return 0;
};
