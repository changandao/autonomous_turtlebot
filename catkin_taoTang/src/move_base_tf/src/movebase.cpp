#include "movebase.h"

MoveBase::MoveBase(){
    turtle_vel = nh.advertise<geometry_msgs::Twist>("mobile_base/commands/velocity", 10);
    Point_sub = nh.subscribe<geometry_msgs::PointStamped>("/my_topics/3dpoint", 1, &MoveBase::point_sb, this);
}

void MoveBase::point_sb(const geometry_msgs::PointStamped::ConstPtr &point){
//    std::cout << "point call back" << std::endl;
//    point_x = point->point.x;
//    point_y = point->point.y;

//    double ratio = point_y/point_x;
//    point_x -= 0.3;
//    point_y -= 0.3*ratio;


    // frame broadcaster
//    static tf::TransformBroadcaster br;
//    tf::Transform transform;

    x_transform = point->point.x;
    y_transform = point->point.y;
    theta_transform = point->point.z;

//    // frame broadcaster
//    transform.setOrigin( tf::Vector3(x_transform, y_transform, 0.0) );
//    tf::Quaternion q;
//    q.setRPY(0, 0, theta_transform);
//    transform.setRotation(q);
////        movebase.transform.setRPY(0, 0, movebase.theta_transform);
//    br.sendTransform(tf::StampedTransform(transform, ros::Time::now(), "odom", "goal_pose"));

    point_sb_finish = true;

}

void MoveBase::set_frame(double x, double y, double theta){

    x_transform = x;
    y_transform = y;
    theta_transform = theta;
}

void MoveBase::go_to_position(){

}



//Ojfalkaunsog
