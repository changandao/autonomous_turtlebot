#include "robogo.h"
#include <geometry_msgs/Twist.h>
//constructor
robogo::robogo(){
     firstRUN = true;

  // Advertise a new publisher for the simulated robot's velocity command topic
     commandPub = node.advertise<geometry_msgs::Twist>("/cmd_vel_mux/input/teleop", 10);
     scanSub  = node.subscribe("/lidarscan",10,&robogo::scanCallback,this);
     poseSub  = node.subscribe("/odom",10,&robogo::poseCallback,this);
     //dataset(360);
     //for(int j=0;j<360;j++){
     //    dataset[j] = 0.0;
     //}
}

void robogo::AB_value(){

}

void robogo::scanCallback(const sensor_msgs::LaserScan::ConstPtr& scan){
  //nav_msgs::Odometry::ConstPtr g_pos;

  std::vector<float> dataset(360);
  if(firstRUN){
     
     dataset = scan->ranges;
}

     for(int i=0;i<360;i++){
	dataset[i] = 0.0;
     }

     int inf_count;
     int i;
     inf_count = 0;
     for(i=0;i<360;i++){
         if(scan->ranges[i] < 10.0  && dataset[i] == 0.0){
            inf_count++;
	    dataset[i] = scan->ranges[i];

            }
         //ROS_INFO("[%f][%i]",dataset[i],i);
     }

     float angle_max_ = scan->angle_max;
     float angle_min_ = scan->angle_min;
     float angle_incre_ = scan->angle_increment;
     ROS_INFO("PPPPProperties:[%f][%f][%f]",angle_max_,angle_min_,angle_incre_);

     int count = 1;
     for(int j=0;j<360;j++){
         if(dataset[j] <= 10.0) count++;        // Data bigger than 10.0 treated as 'inf'
     }
     ROS_INFO("The number of usable data:[%i]",count);
}

void robogo::poseCallback(const nav_msgs::Odometry::ConstPtr& msg){

  tf::Quaternion q;
  tf::quaternionMsgToTF(msg->pose.pose.orientation, q);
  tf::Matrix3x3 m(q);

  double roll, pitch, yaw;
  m.getRPY(roll, pitch, yaw);
  ROS_INFO("The angle is:[%f]",yaw);
  


  vel_msg.angular.z = 0.6;
  //while(true){
  //if(yaw < -0.1 || yaw > 0.1){
  bool keepTURN;
  if(yaw < -0.05 || yaw > 0.1){
          vel_msg.linear.x = 0.0;
         vel_msg.angular.z = 0.0;
         keepTURN = true;
         ROS_INFO_STREAM("TURN");
     }
  else{
         vel_msg.linear.x = 0.0;
         vel_msg.angular.z = 0.0;
         keepTURN = false;
         ROS_INFO_STREAM("STOP TURN");
  }

  ROS_INFO("My position[%f]",msg->pose.pose.position.x);
  if(!keepTURN){
    if(msg->pose.pose.position.x < 3.1 || msg->pose.pose.position.x > 3.2)
    {
       vel_msg.linear.x = 0.0;
       ROS_INFO_STREAM("RUN");
    }
  }
  if(keepTURN)
  {
     vel_msg.linear.x = 0.0;
     ROS_INFO_STREAM("wait");
  }
  //}
  
  //firstRun:  set the Goal(position,angle)
  if(firstRUN){                         
     ROS_INFO_STREAM("FIRST RUN");
     goal_x = msg->pose.pose.position.x + 0.25;
     goal_y = msg->pose.pose.position.y + 0.25;
     goal_angle = yaw +2.6;
     ROS_INFO("Set Goal[%f,%f,%f]",goal_x,goal_y,goal_angle);
     firstRUN = false;
  }
  else{
     
     diff_x = goal_x - msg->pose.pose.position.x;
     diff_y = goal_y - msg->pose.pose.position.y;
    // ROS_INFO("Currant Position :[%f,%f]",msg->pose.pose.position.x,msg->pose.pose.position.y);
     //ROS_INFO("Position Difference:[%f,%f]",diff_x,diff_y);
  }
}



void robogo::move(){
  ROS_INFO_STREAM("Set Velocity == 0");
  vel_msg.linear.x = 0;
  vel_msg.angular.z = 0;
  ROS_INFO("velocity[%f,%f]",vel_msg.linear.x,vel_msg.angular.z);
  }

void robogo::startMove()
{
  ros::Rate rate(10);   //every 1/1.0 second, give it a velocity
  ROS_INFO("Start,Start,Start");

 //while(ros::ok())
 //{

for(int i=0;i<5;i++){
  ros::spinOnce();

  //move();
  commandPub.publish(vel_msg);
  
  AB_value();
  rate.sleep();
}

  //}
}

//////////////////////////////////////////////////////////////////////////

//int main(int argc, char** argv){
  
//  ros::init(argc, argv, "robogo");

//  robogo botgo;
  
//  botgo.startMove();

//  return 0;

//}


