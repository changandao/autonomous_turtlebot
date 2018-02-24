#include <ros/ros.h>
#include <geometry_msgs/Twist.h>
#include <sensor_msgs/LaserScan.h>
#include <nav_msgs/Odometry.h>

bool firstRUN = true;
bool dataOK = false;
geometry_msgs::Twist vel_msg;

std::vector<float> dataset;

double goal_x;
double goal_y;
double diff_x;
double diff_y;

void checkDataset(){
     int count = 1;
     for(int i=0;i<360;i++){
         if(dataset[i] < 10.0){count++;}
     }
     if(count == 360){dataOK = true;}
}

void scanCallback(const sensor_msgs::LaserScan::ConstPtr& scan){
  //nav_msgs::Odometry::ConstPtr g_pos;

     dataset = scan->ranges;

     int inf_count;
     int i;
     inf_count = 0;
     for(i=0;i<360;i++){
         if(scan->ranges[i] < 10.0){
            inf_count++;
	    dataset[i] = scan->ranges[i];
            }
         //ROS_INFO("[%f]",dataset[i]);
     }
     //ROS_INFO("Data is:[%f]",dataset[100]);
     ROS_INFO("The number of inf data:[%i]",inf_count);


     float angle_max_ = scan->angle_max;
     float angle_min_ = scan->angle_min;
     float angle_incre_ = scan->angle_increment;
     ROS_INFO("PPPPProperties:[%f][%f][%f]",angle_max_,angle_min_,angle_incre_);
}

//void move(float goal_x,float goal_y){
//  }

void move(){
  ROS_INFO_STREAM("Set Velocity == 0");
  vel_msg.linear.x = 0;     //double(0.2*sqrt(pow(diff_x, 2) +pow(diff_y, 2)));    //linear velocity
  vel_msg.angular.z = 0;    // -double(0.2* atan2(diff_y,diff_x));
  ROS_INFO("velocity[%f,%f]",vel_msg.linear.x,vel_msg.angular.z);
    //publish the message
  }

int main(int argc, char** argv){

  ros::init(argc, argv, "robogo");
  ros::NodeHandle node;
  ros::Publisher commandPub; // Publisher to the robot's velocity command topic
  ros::Subscriber poseSub;
  // Advertise a new publisher for the simulated robot's velocity command topic
  
  //firstRUN = true;

  commandPub = node.advertise<geometry_msgs::Twist>("/cmd_vel_mux/input/teleop", 10);
  poseSub  = node.subscribe("/scan",10,scanCallback);
  

  ros::Rate rate(1);   //every 1/1.0 second, give it a velocity

  while(ros::ok())
 {
  ros::spinOnce();
  //move(goal_x,goal_y);
  move();
  commandPub.publish(vel_msg);
  
  checkDataset();
  if(dataOK){
       for(int i=0;i<360;i++){
         ROS_INFO("[%f]",dataset[i]);
     }
  }
  
  rate.sleep();
  }
  return 0;
}


