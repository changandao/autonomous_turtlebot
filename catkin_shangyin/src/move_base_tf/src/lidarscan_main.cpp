#include "lidarscan.h"
#include "movebase.h"
//#include "imageconverter.h"

bool checkReachGoalPos(tf::StampedTransform transform){
    double x = transform.getOrigin().x();
    double y = transform.getOrigin().y();
    std::cout << "    " << x << " " << y << std::endl;
    if (std::abs(x) < 0.05 && std::abs(y) < 0.001){
        return true;
    }else{
        return false;
    }
};

void move2TeamColor(ros::Publisher goal_pose_publisher, geometry_msgs::PointStamped goal_pose){
    goal_pose.point.x = 0;
    goal_pose.point.y = 0;
    goal_pose.point.z = 0;
    for (size_t i = 0; i < 10; i++){
        goal_pose_publisher.publish(goal_pose);
    }
    std::cout << "=======move to team colour=======" << std::endl;
}

void detectTeamColor(){

}

void detectPuck(){

}

void move2Puck(ros::Publisher goal_pose_publisher, geometry_msgs::PointStamped goal_pose){
    goal_pose.point.x = 0;
    goal_pose.point.y = 0;
    goal_pose.point.z = 0;
    for (size_t i = 0; i < 10; i++){
        goal_pose_publisher.publish(goal_pose);
    }
    std::cout << "=======move to puck=======" << std::endl;

}

void move2Tor(ros::Publisher goal_pose_publisher, geometry_msgs::PointStamped goal_pose){
    goal_pose.point.x = 0;
    goal_pose.point.y = 0;
    goal_pose.point.z = 0;
    for (size_t i = 0; i < 10; i++){
        goal_pose_publisher.publish(goal_pose);
    }
    std::cout << "=======move to tor=======" << std::endl;
}

void move2Init(ros::Publisher goal_pose_publisher, geometry_msgs::PointStamped goal_pose){
    goal_pose.point.x = 0;
    goal_pose.point.y = 0;
    goal_pose.point.z = 0;
    for (size_t i = 0; i < 10; i++){
        goal_pose_publisher.publish(goal_pose);
    }
    std::cout << "=======move to init=======" << std::endl;
}

// dead loop to use
void moveBack(ros::Publisher turtle_vel, geometry_msgs::Twist vel_msg){
    vel_msg.angular.z = 0;
    vel_msg.linear.x = -1;
    turtle_vel.publish(vel_msg);
    ros::Duration(1.0).sleep();
}

int main (int argc, char** argv) {

    ros::init(argc, argv, "lidarscan");
    ros::NodeHandle nh;

    LidarScan lidarscan;


    ros::Rate rate(30);

    lidarscan.a_b_ready = false;

    // some flags
    double reach_goal_pose = false;
    double detect_color_finish = false;
    double detect_puck_finish = false;

    // state variable
    int state = 0;

    // vel publisher
    ros::Publisher turtle_vel;
    geometry_msgs::Twist vel_msg;



    // goal pose publisher
    ros::Publisher goal_pose_publisher;
    geometry_msgs::PointStamped goal_pose;
    goal_pose_publisher = nh.advertise<geometry_msgs::PointStamped>("my_topics/3dpoint", 10);

    // tf
//    tf::TransformListener listener;
//    listener.waitForTransform("base_link", "goal_pose", ros::Time(0), ros::Duration(3.0));

    while(nh.ok()){

        goal_pose.point.x = 1;
        goal_pose.point.y = 1;
        goal_pose.point.z = M_PI;
        goal_pose_publisher.publish(goal_pose);

//            tf::StampedTransform transform;
//            try{
//                listener.lookupTransform("base_link", "goal_pose", ros::Time(0), transform);
//            }
//            catch (tf::TransformException &ex) {
//                ROS_ERROR("%s",ex.what());
//                ros::Duration(1.0).sleep();
//                continue;
//            }
//            // check reach_goal_pose
//            // get x y and theta
//            double x_base_goal = transform.getOrigin().x();
//            double y_base_goal = transform.getOrigin().y();
//            tf::Quaternion rotation;
//            rotation = transform.getRotation();
//            tf::Matrix3x3 m(rotation);
//            double roll, pitch, theta_base_goal;
//            m.getRPY(roll, pitch, theta_base_goal);
//            if (std::abs(x_base_goal)<0.05 & std::abs(y_base_goal)<0.05 & std::abs(theta_base_goal)<0.05){
//                reach_goal_pose = true;
//            }else{
//                reach_goal_pose = false;
//            }
//            std::cout << "reach goal pose: " << reach_goal_pose << std::endl;

            //use switch for state machine
            switch(state){
            case 1:
                lidarscan.calAandB();
                if(lidarscan.a_b_finish){
                    state = 2;
                    break;
                }
            case 2:
                lidarscan.calTorPos();
                if(lidarscan.tor_pos_finish){
                    state = 3;
                    break;
                }
            case 3:
                lidarscan.calTeamColourPos();
                if(lidarscan.team_colour_finish){
                    state = 4;
                    break;
                }
            case 4:
                move2TeamColor(goal_pose_publisher, goal_pose);
                if(reach_goal_pose){
                    state = 4;
                    break;
                }
            case 5:
                detectTeamColor();
                if(detect_color_finish){
                    state = 6;
                    break;
                }
            case 6:
                detectPuck();
                if(detect_puck_finish){
                    state = 7;
                    break;
                }

            case 7:
                move2Puck(goal_pose_publisher, goal_pose);
                if(reach_goal_pose){
                    state = 8;
                    break;
                }
            case 8:
                move2Tor(goal_pose_publisher, goal_pose);
                if(reach_goal_pose){
                    state = 9;
                    break;
                }
            case 9:
                move2Init(goal_pose_publisher, goal_pose);
                if(reach_goal_pose){
                    state = 6;
                }

            }

            ros::spinOnce();
            rate.sleep();
    }

//    ros::spin();
//    rate.sleep();
};
