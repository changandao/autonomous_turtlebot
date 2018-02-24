
//Angelina h file*******************************
#include <QtGui>
#include "Controller.h"
#include <QApplication>

#include <QTimer>
#include <QWidget>

//processing h file
#include "lidarscan.h"
#include "movebase.h"
#include "imageconverter.h"

double x, y, z;

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
    std::cout << "move to team color" << std::endl;
    for (size_t i = 0; i < 500; i++){
        goal_pose_publisher.publish(goal_pose);
    }
    //std::cout << "=======move to team colour=======" << std::endl;
}

//bool detectTeamColor(ImageConverter imageconverter, char team_color){
//    imageconverter.get_task(0);
//    if(imageconverter.team_color_done())
//        team_color = imageconverter.return_team_color();
//    std::cout << "true color is"<<team_color<<std::endl;
//    bool detect_color_finish = imageconverter.team_color_done();
//    return detect_color_finish;
//}

//bool detectPuck(ImageConverter imageconverter, char ture_color){
//    imageconverter.get_task(1);
//    imageconverter.setcolor(ture_color);
//    bool transform_flag = imageconverter.return_detected_signal();
//    return transform_flag;
//}

void move2Puck(ros::Publisher goal_pose_publisher, geometry_msgs::PointStamped goal_pose){
    for (size_t i = 0; i < 500; i++){
        goal_pose_publisher.publish(goal_pose);
    }
    //std::cout << "=======move to puck=======" << std::endl;

}

void move2Tor(ros::Publisher goal_pose_publisher, geometry_msgs::PointStamped goal_pose){
    for (size_t i = 0; i < 500; i++){
        goal_pose_publisher.publish(goal_pose);
    }
    //std::cout << "=======move to tor=======" << std::endl;
}

void move2Init(ros::Publisher goal_pose_publisher, geometry_msgs::PointStamped goal_pose){
    for (size_t i = 0; i < 500; i++){
        goal_pose_publisher.publish(goal_pose);
    }
    //std::cout << "=======move to init=======" << std::endl;
}

// dead loop to use
void moveBack(ros::Publisher turtle_vel, geometry_msgs::Twist vel_msg){
    vel_msg.angular.z = 0;
    vel_msg.linear.x = -1;
    turtle_vel.publish(vel_msg);
}

Controller controller;

int main (int argc, char** argv) {

    //Angelina related************************************
    QApplication app(argc, argv);


    ros::init(argc, argv, "lidarscan");
    ros::NodeHandle nh;

    LidarScan lidarscan;
    ImageConverter imageconverter;

    ros::Rate rate(30);

    lidarscan.a_b_ready = false;

    // some flags
    double reach_goal_pose = false;
    double detect_color_finish = false;
    double detect_puck_finish = false;



    //variables from angilina
    char team_color;
    char true_color = 'b';

    // state variable
    int state = 1;

    // vel publisher
    ros::Publisher turtle_vel;
    geometry_msgs::Twist vel_msg;



    // goal pose publisher
    ros::Publisher goal_pose_publisher;
    geometry_msgs::PointStamped goal_pose;
    goal_pose_publisher = nh.advertise<geometry_msgs::PointStamped>("my_topics/3dpoint", 10);

    // TODO: write a call back to check reach_goal_pose
    // tf
    tf::TransformListener listener;
    listener.waitForTransform("base_link", "goal_pose", ros::Time(0), ros::Duration(3.0));

    while(nh.ok()){
	    app.processEvents();
            tf::StampedTransform transform;
            try{
                listener.lookupTransform("base_link", "goal_pose", ros::Time(0), transform);
            }
            catch (tf::TransformException &ex) {
                ROS_ERROR("%s",ex.what());
                ros::Duration(1.0).sleep();
                continue;
            }
            // check reach_goal_pose
            // get x y and theta
            double x_base_goal = transform.getOrigin().x();
            double y_base_goal = transform.getOrigin().y();
            tf::Quaternion rotation;
            rotation = transform.getRotation();
            tf::Matrix3x3 m(rotation);
            double roll, pitch, theta_base_goal;
            m.getRPY(roll, pitch, theta_base_goal);
            if (std::abs(x_base_goal)<0.05 & std::abs(y_base_goal)<0.05 & std::abs(theta_base_goal)<0.05){
                reach_goal_pose = true;
            }else{
                reach_goal_pose = false;
            }
            //std::cout << "reach goal pose: " << reach_goal_pose << std::endl;

            //use switch for state machine
            switch(state){
            case 1:
                if(lidarscan.a_b_ready){
                    lidarscan.calAandB();
                }
                if(lidarscan.a_b_finish){
                    state = 2;
                    std::cout << "we will go to state ==22==" <<std::endl;
                }
                break;
            case 2:
                lidarscan.calTorPos();
                if(lidarscan.tor_pos_finish){
                    state = 3;
                    std::cout << "we will go to state ==33==" <<std::endl;
                }
                break;
            case 3:
                lidarscan.calTeamColourPos();
                if(lidarscan.team_colour_finish){
                    state = 4;
                    std::cout << "we will go to state ==44==" <<std::endl;
                    goal_pose.point.x = lidarscan.team_colour_x;
                    goal_pose.point.y = lidarscan.team_colour_y;
                    goal_pose.point.z = lidarscan.team_colour_theta;
                }
                break;
            case 4:
                move2TeamColor(goal_pose_publisher, goal_pose);
                if(reach_goal_pose){
                    std::cout << "we will go to state ==55==" <<std::endl;
                    state = 5;
                }
                break;
            case 5:
                imageconverter.get_task(0);
                if(imageconverter.team_color_done())
                    team_color = imageconverter.return_team_color();
                std::cout << "true color is"<<team_color<<std::endl;
                detect_color_finish = imageconverter.team_color_done();
                if(detect_color_finish){
                    std::cout << "we will go to state ==66==" <<std::endl;
                    state = 6;
                }

                break;
            case 6:
                imageconverter.get_task(1);
                imageconverter.setcolor(true_color);
                detect_puck_finish = imageconverter.return_detected_signal();
                if(detect_puck_finish){
                    std::cout << "we will go to state ==77==" <<std::endl;
                    state = 7;
                }
                break;
            case 7:
                move2Puck(goal_pose_publisher, goal_pose);
                if(reach_goal_pose){
                    std::cout << "we will go to state ==88==" <<std::endl;
                    state = 8;
                }
                break;
            case 8:
                move2Tor(goal_pose_publisher, goal_pose);
                if(reach_goal_pose){
                    std::cout << "we will go to state ==99==" <<std::endl;
                    state = 9;
                }
                break;
            case 9:
                move2Init(goal_pose_publisher, goal_pose);
                if(reach_goal_pose){
                    std::cout << "we will go to state ==100==" <<std::endl;
                    state = 6;
                }
                break;

            }   // end of switch

            ros::spinOnce();
            rate.sleep();
    }   // end of while
        
    //Angelina return****************************
    return app.exec();
 
//    ros::spin();
//    rate.sleep();
} // end of main



//int main (int argc, char** argv) {

//    ros::init(argc, argv, "lidarscan");
//    ros::NodeHandle nh;

//    // goal pose publisher
//    ros::Publisher goal_pose_publisher;
//    geometry_msgs::PointStamped goal_pose;
//    goal_pose_publisher = nh.advertise<geometry_msgs::PointStamped>("my_topics/3dpoint", 10);

//    // tf
//    tf::Transform transform;
//    tf::TransformListener listener;
//    bool first_goal_pose = true;
//    int first_goal_pose_count = 0;
//    listener.waitForTransform("base_link", "goal_pose", ros::Time(0), ros::Duration(3.0));

//    LidarScan lidarscan;
//    ImageConverter imageconverter;
//    ros::Rate rate(30);

//    lidarscan.a_b_ready = false;

//    // some flags
//    bool reach_goal_pose = false;
//    char team_color = 'y';
//    bool detecttionPrepared = false;


//    while(nh.ok()){
//        //first publish frame goal_pose equal to base_link, make sure turtlebot do not move
//        tf::StampedTransform transform;
//        try{
//            listener.lookupTransform("base_link", "goal_pose", ros::Time(0), transform);
//        }
//        catch (tf::TransformException &ex) {
//            ROS_ERROR("%s",ex.what());
//            ros::Duration(1.0).sleep();
//            continue;
//        }
//        double x = transform.getOrigin().x();
//        double y = transform.getOrigin().y();




//        //fun cal a and b
//        if(lidarscan.a_b_ready & !lidarscan.a_b_finish){
//            lidarscan.calAandB();
//        }else if(lidarscan.a_b_finish & !lidarscan.tor_pos_finish){
//            lidarscan.calTorPos();
//        }else if(lidarscan.tor_pos_finish & !lidarscan.team_colour_finish){
//            lidarscan.calTeamColourPos();
//        }else if(lidarscan.team_colour_finish & !reach_goal_pose){
//            // move to team colour pos
//            std::cout << "=======move to team colour=======" << std::endl;
//            goal_pose.point.x = lidarscan.team_colour_x;
//            goal_pose.point.y = lidarscan.team_colour_y;
//            goal_pose.point.z = lidarscan.team_colour_theta;

//            /* this is the test codes*/
//            //            goal_pose.point.x = 0.7;
//            //            goal_pose.point.y = -0.2;
//            //            goal_pose.point.z = M_PI/2;

//            for (size_t i = 0; i < 10; i++){
//                goal_pose_publisher.publish(goal_pose);
//                std::cout << i << " ";
//            }
//            if (std::abs(x) < 0.05 && std::abs(y) < 0.001){
//                reach_goal_pose = true;
//            }
//            //std::cout << std::endl;
//        }else if(reach_goal_pose && !imageconverter.team_color_done()){
//            std::cout << "======move to team color======" << std::endl;
//            imageconverter.get_task(0);//0 means detecting team color
//            if(imageconverter.team_color_done())
//                team_color = imageconverter.return_team_color();
//            std::cout << "true color is"<<team_color<<std::endl;
//        }else if(imageconverter.team_color_done() && ! detecttionPrepared){
//            std::cout << "======detect team color======" << std::endl;
//            goal_pose.point.x = 0;
//            goal_pose.point.y = 0;
//            goal_pose.point.z = -M_PI/4;
//            for (size_t i = 0; i < 10; i++){
//                goal_pose_publisher.publish(goal_pose);
//            }
//            if (std::abs(x) < 0.05 && std::abs(y) < 0.001){
//                detecttionPrepared = true;
//            }
//        }else if(detecttionPrepared && ! detecttionPrepared){

//        //reach_goal_pose = false;
//        }
//        ros::spinOnce();
//        rate.sleep();
//    }

//    //    ros::spin();
//    //    rate.sleep();

//};
