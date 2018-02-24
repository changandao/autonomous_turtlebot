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

    x_transform = point->point.x;
    y_transform = point->point.y;
    theta_transform = point->point.z;

    point_sb_finish = true;

//    x_transform = point->point.x;
//    y_transform = point->point.y;

//    std::cout << "=======POINT CALL BACK========" << std::endl;
//    std::cout << "    " << x_transform << " " << y_transform << " " << theta_transform<< std::endl;
}

void MoveBase::set_frame(double x, double y, double theta){

    x_transform = x;
    y_transform = y;
    theta_transform = theta;
    std::cout << "===============" << std::endl;
    std::cout << "set frame: " << x_transform << " " << y_transform << std::endl;
}

void MoveBase::go_to_position(){

}



//Ojfalkaunsog
