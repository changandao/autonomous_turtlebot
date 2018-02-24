#include<ros/ros.h>

#include<tf/transform_boradcaster.h>//tf转换的头文件

#include<nav_msgs/Odometry.h>//导航信息的头文件

int main(int argc,char **argv)

{

　　ros::init(argc,argv,"state_publisher");//节点名字为state_publisher

　　ros::NodeHandle n;

　　//创建一个publisher，用来发布消息类型为nav_msgs::Odometry，发布到主题为odom上

　　ros::Publisher odom_pub=n.advertise<nav_msgs::Odometry>("odom",10);

　　//创建三个变量来初始化位置

　　double x=0.0;

　　double y=0.0;

　　double th=0.0;

　　//初始化速度

 　　double vx=0.4;

　　double vy=0;
double vth=0.2;//角速度

　　//创建两个时间对象用来记录发生的时间，用时间相减就的到δt

　　ros::Time current_time=ros::Time::now();

　　ros::Time last_time=ros::Time::now();

　　//创建一个tf树中广播器用来广播tf变换

　　tf::TransformBroadcaster broadcaster;

　　ros::Rate rate(10);//消息发布的频率

　　//储存广播的tf变换

　　geometry_msgs::TransformStamped odom_trans;

　　//对其成员变量赋值

　　odom_trans.header.frame_id="odom";//父坐标系为odom

　　//child的frame_id设为如下,那么子坐标系为base_footprint

　　odom_trans.child.frame_id="base_footprint";

　　//下面来完成位置信息的变换
while(ros::ok())

　　{

　　//更新一下current_time

　　current_time=ros::Time::now();

　　//计算位置变换和姿态的变换

　　double dt=(current_time-last_time).toSec();//当前时间减去过去时间，并转换成秒

　　double delta_x=(vx*cos(th)-vy*sin(th))*dt;

　　double delta_y=(vx*sin(th)+vy*cos(th))*dt;

　　double delta_th=vth*dt;

　　//下面更新x,y,以及theta的值

　　x+=delta_x;

　　y+=delta_y;

　　th+=delta_th;

　　//创建一个四元组,下面返回的是一个geometry_msgs::Quaternion类型的消息

　　geometry_msgs::Quaternion odom_quat=tf::createQuaternionMsgFromYaw(th);

　　//下面更新一下transform消息

　　odom_trans.header.stamp=current_time;

　　odom_trans.transform.translation.x=x;

　　odom_trans.transform.translation.y=y;
odom_trans.transform.translation.z=0;

　　odom_trans.transform.rotation=odo_quat;

　　nav_msgs::Odometry odom;

　　odom.header.stamp=current_time;

　　odom.header.frame_id="odom";

　　odom.child.frame_id="base_footprint";

　　odom.pose.pose.position.x=x;

　　odom.pose.pose.position.y=y;

　　odom.pose.pose.position.z=0;

　　odom.twist.twist.linear.x=vx;

　　odom.twist.twist.linear.y=vy;

　　odom.twist.twist.linear.z=0;

　　odom.twist.twist.angular.z=vth;

　　odom.twist.twist.angular.x=0;

　　odom.twist.twist.angular.y=0;

　　last_time=current_time;

　　//把odometry_transform消息发布出去，以及把odom消息发布在odometry上

　　broadcaster.sendTransform(odom_trans);

　　odom_pub.publish(odom);

　　}
  rate.sleep();

　　return 0;

}

