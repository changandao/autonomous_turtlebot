#include<vector>
#include <ros/ros.h>
#include <geometry_msgs/Twist.h>
#include <sensor_msgs/LaserScan.h>
#include <nav_msgs/Odometry.h>

#include <nav_msgs/Odometry.h>
#include <tf/transform_datatypes.h>
#include <geometry_msgs/Quaternion.h>

class robogo {
  public:
    //const int DIM = 360;
    robogo();  //constructor

    double goal_x;
    double goal_y;
    double diff_x;
    double diff_y;
    double goal_angle;
    //std::vector<float> dataset;
    geometry_msgs::Twist vel_msg;
    
    //void dataInit();
    void AB_value();
    void checkData();
    void move();
    void startMove();
  private:
    ros::NodeHandle node;
    ros::Publisher commandPub;
    ros::Subscriber poseSub;
    ros::Subscriber scanSub;

    bool firstRUN;
    
    void scanCallback(const sensor_msgs::LaserScan::ConstPtr& scan);
    void poseCallback(const nav_msgs::Odometry::ConstPtr& msg);
};