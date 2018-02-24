#include "lidarscan.h"
#include "movebase.h"
#include "imageconverter.h"

double x, y, z;

// transform

//bool checkReachGoalPos(tf::StampedTransform transform){
//    double x = transform.getOrigin().x();
//    double y = transform.getOrigin().y();
//    std::cout << "    " << x << " " << y << std::endl;
//    if (std::abs(x) < 0.05 && std::abs(y) < 0.001){
//        return true;
//    }else{
//        return false;
//    }
//};

//void move2TeamColor(ros::Publisher goal_pose_publisher, geometry_msgs::PointStamped goal_pose){
//    std::cout << "move to team color" << std::endl;
//    for (size_t i = 0; i < 500; i++){
//        goal_pose_publisher.publish(goal_pose);
//    }
//    //std::cout << "=======move to team colour=======" << std::endl;
//}

//bool detectTeamColor(ImageConverter imageconverter, char team_color){
//    imageconverter.get_task(0);
//    if(imageconverter.team_color_done())
//        team_color = imageconverter.return_team_color();
//    std::cout << "true color is"<<teanhm_color<<std::endl;
//    bool detect_color_finish = imageconverter.team_color_done();
//    return detect_color_finish;
//}

//bool detectPuck(ImageConverter imageconverter, char ture_color){
//    imageconverter.get_task(1);
//    imageconverter.setcolor(ture_color);
//    bool transform_flag = imageconverter.return_detected_signal();
//    return transform_flag;
//}

void updatePos(ros::Publisher goal_pose_publisher, geometry_msgs::PointStamped goal_pose){
    for (size_t i = 0; i < 50000; i++){
        goal_pose_publisher.publish(goal_pose);
    }
    //std::cout << "=======move to puck=======" << std::endl;

}

//listener.waitForTransform("base_link", "goal_pose", ros::Time(0), ros::Duration(3.0));
// dead loop to use
void moveBack(ros::Publisher turtle_vel, geometry_msgs::Twist vel_msg, double x){

}

double reach_goal_pose = false;

void reach_goal_sb(const geometry_msgs::TwistConstPtr &msg){
    reach_goal_pose = msg->linear.x;
}

double world_x = 0;
double world_y = 0;
double world_theta = 0;

void world_cords_sb(const geometry_msgs::PointStamped::ConstPtr &point){
    world_x = point->point.x;
    world_y = point->point.y;
    world_theta = point->point.z;
    if (isnan(world_x)||isnan(world_y)||isnan(world_theta)){
        world_x = 0;
        world_y = 0;
        world_theta = 0;
    }
}

int main (int argc, char** argv) {

    ros::init(argc, argv, "lidarscan");
    ros::NodeHandle nh;

    LidarScan lidarscan;
    ImageConverter imageconverter;

    ros::Rate rate(30);

    lidarscan.a_b_ready = false;

    // some flags

    double detect_color_finish = false;
    double detect_puck_finish = false;


    //variables from angilina
    char team_color;
    char true_color = 'y';

    // state variable
<<<<<<< HEAD
    int state = 8;
    int num_init = 1;
    bool flag = true;
=======
<<<<<<< HEAD
    int state = 5;
=======
    int state = 1;
>>>>>>> 0059c7947f56eca8d2619dfe3365894de6115446

>>>>>>> 854d1ed9208bd20e88102e3d3e652a30477d504d
    // vel publisher
    ros::Publisher turtle_vel;
    turtle_vel = nh.advertise<geometry_msgs::Twist>("mobile_base/commands/velocity", 10);
    geometry_msgs::Twist vel_msg;

    // laser scan subscriber
    ros::Subscriber reach_goal_sub;
    ros::Subscriber world_cords_sub;
    reach_goal_sub = nh.subscribe("my_topics/reach_goal_pose", 1, &reach_goal_sb);
    world_cords_sub = nh.subscribe("my_topics/world3d",1, &world_cords_sb);

    // goal pose publisher
    ros::Publisher goal_pose_publisher;
    geometry_msgs::PointStamped goal_pose;
    goal_pose_publisher = nh.advertise<geometry_msgs::PointStamped>("my_topics/3dpoint", 10);


    while(nh.ok()){
            //use switch for state machine
            std::cout << "we will gee the reach goal"<< reach_goal_pose <<std::endl;
            switch(state){
            case 1:
                std::cout<< "we are now in state ==11=="<<std::endl;
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
                // go to team color point
                updatePos(goal_pose_publisher, goal_pose);
                ros::Duration(25.0).sleep();

//                if(reach_goal_pose){
                    std::cout << "we will go to state ==55==" <<std::endl;
                    state = 5;
//                }
                break;
            case 5:
                imageconverter.get_task(0);
                if(imageconverter.team_color_done())
                    team_color = imageconverter.return_team_color();
                std::cout << "true color is: "<<team_color<<std::endl;
                detect_color_finish = imageconverter.team_color_done();
                if(detect_color_finish){
<<<<<<< HEAD
                    std::cout << "we will go to state ==51==" <<std::endl;
                    state = 51;
                    goal_pose.point.z = -M_PI/9;
=======
<<<<<<< HEAD
                    state = 5;
                    break;
=======
                    std::cout << "we will go to state ==66==" <<std::endl;
                    state = 6;
>>>>>>> 0059c7947f56eca8d2619dfe3365894de6115446
>>>>>>> 854d1ed9208bd20e88102e3d3e652a30477d504d
                }
                break;
            case 51:
                // turn 60 deg to detect puck
                updatePos(goal_pose_publisher, goal_pose);
                ros::Duration(5.0).sleep();
                //if(reach_goal_pose){
                    state = 6;
                //}
                break;
            case 6:
                imageconverter.get_task(1);
                imageconverter.setcolor(true_color);
                //detect_puck_finish = imageconverter.return_detected_signal();
                std::cout << world_x << "    " << world_y <<std::endl;
                if (world_x != 0 || world_y != 0 ){//|| world_theta !=0){
                    detect_puck_finish = true;
                }
                else{
                    detect_puck_finish = false;
                }
                ros::Duration(2.0).sleep();

                if(detect_puck_finish){
<<<<<<< HEAD
                    state = 7;
                    break;
=======
                    std::cout << "we will go to state ==77==" <<std::endl;
<<<<<<< HEAD

                    if (world_x > 2*lidarscan.a){
                        state = 61;
                        if (flag){

                            goal_pose.point.z = M_PI/8;
                        }
                        else
                            goal_pose.point.z = -M_PI/8;
                        }
                        flag = ~flag;

                    }else{
                        goal_pose.point.x = world_x;
                        goal_pose.point.y = world_y;
                        goal_pose.point.z = world_theta;
                        state = 7;
                    }

                    // TODO: goal_pose

=======
                    state = 7;
>>>>>>> 0059c7947f56eca8d2619dfe3365894de6115446
                }
>>>>>>> 854d1ed9208bd20e88102e3d3e652a30477d504d
                break;
            case 61:
                updatePos(goal_pose_publisher, goal_pose);
                ros::Duration(10.0).sleep();
                state = 6;
                break;


            case 7:
                // pick puck
                updatePos(goal_pose_publisher, goal_pose);
                ros::Duration(10.0).sleep();
                //if(reach_goal_pose){
//                    imageconverter.get_puck_catch_signal(reach_goal_pose);
//                    if(!imageconverter.return_catching_puck_signal()) moveBack();
                    std::cout << "we will go to state ==88==" <<std::endl;
                    state = 8;
                    goal_pose.point.x = lidarscan.tor_x;
                    goal_pose.point.y = lidarscan.tor_y;
                    goal_pose.point.z = 0;
                //}
                break;
            case 8:
                // move to tor
//                updatePos(goal_pose_publisher, goal_pose);
//                ros::Duration(15.0).sleep();
                //if(reach_goal_pose){

                for (size_t i = 0; i < 25; i++){
                vel_msg.angular.z = 0;
                vel_msg.linear.x = -0.3;
                turtle_vel.publish(vel_msg);
                ros::Duration(0.1).sleep();
                }
                vel_msg.linear.x = 0;
                turtle_vel.publish(vel_msg);
                ros::Duration(25).sleep();
                break;

                std::cout << "we will go to state ==99==" <<std::endl;
                switch(num_init){
                case 1:
                    state = 9;
                    goal_pose.point.x = 0;
                    goal_pose.point.y = 0;
                    goal_pose.point.z = 0;
                    num_init = 2;
                    break;

                case 2:
                    state = 10;
                    goal_pose.point.x = -lidarscan.team_colour_x;
                    goal_pose.point.y = 0;
                    goal_pose.point.z = M_PI/9;
                    num_init = 3;
                    break;
                case 3:
                    state = 11;
                    break;
                }

                //}
                break;
            case 9:
                // move to init point for the second time
                updatePos(goal_pose_publisher, goal_pose);
                ros::Duration(20.0).sleep();
                //if(reach_goal_pose){
                    std::cout << "we will go to state ==100==" <<std::endl;
                    state = 6;
//                }
                break;
            case 10:
                // move to init point for the second time
                updatePos(goal_pose_publisher, goal_pose);
                ros::Duration(20.0).sleep();
//                if(reach_goal_pose){
                    std::cout << "we will go to state ==100==" <<std::endl;
                    state = 6;
//                }
                break;
            case 11:
                std::cout << "FINISH" << std::endl;
                while(1){
                    goal_pose.point.x = 0;
                    goal_pose.point.y = 0;
                    goal_pose.point.z = 0;

                }

            }

            ros::spinOnce();
            rate.sleep();
    }

//    ros::spin();
//    rate.sleep();
}



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
