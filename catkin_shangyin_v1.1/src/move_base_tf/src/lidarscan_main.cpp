#include "lidarscan.h"
#include "movebase.h"
#include "imageconverter.h"
//#include "image2world.h"

//bool checkReachGoalPos(tf::StampedTransform transform){
//    double x = transform.getOrigin().x();
//    double y = transform.getOrigin().y();
//    bool flag = false;

//    if (std::abs(x) < 0.05 && std::abs(y) < 0.05){
//        flag = true;
//    }else{
//        flag = false;
//    }
//    return flag;
//    std::cout << "    " << x << " " << y << " " << flag << std::endl;
//};

int main (int argc, char** argv) {

    ros::init(argc, argv, "lidarscan");
    ros::NodeHandle nh;

    // goal pose publisher
    ros::Publisher goal_pose_publisher;
    geometry_msgs::PointStamped goal_pose;
    goal_pose_publisher = nh.advertise<geometry_msgs::PointStamped>("my_topics/3dpoint", 10);

    // tf
    tf::Transform transform;
    tf::TransformListener listener;
    bool first_goal_pose = true;
    int first_goal_pose_count = 0;
    listener.waitForTransform("base_link", "goal_pose", ros::Time(0), ros::Duration(3.0));

    LidarScan lidarscan;
    ImageConverter imageconverter;
    //Image2World image2world;


    ros::Rate rate(30);

    lidarscan.a_b_ready = false;

    // some flags
    double reach_goal_pose = true;

    char team_color;

    while(nh.ok()){
        // first publish frame goal_pose equal to base_link, make sure turtlebot do not move
        tf::StampedTransform transform;
        try{
            listener.lookupTransform("base_link", "goal_pose", ros::Time(0), transform);
        }
        catch (tf::TransformException &ex) {
            ROS_ERROR("%s",ex.what());
            ros::Duration(1.0).sleep();
            continue;
        }



        // fun cal a and b
        if(lidarscan.a_b_ready & !lidarscan.a_b_finish){
            lidarscan.calAandB();
        }else if(lidarscan.a_b_finish & !lidarscan.tor_pos_finish){
            lidarscan.calTorPos();
        }else if(lidarscan.tor_pos_finish & !lidarscan.team_colour_finish){
            lidarscan.calTeamColourPos();
        }else if(lidarscan.team_colour_finish/* & !reach_goal_pose*/){
            // move to team colour pos
//            std::cout << "=======move to team colour=======" << std::endl;
            goal_pose.point.x = lidarscan.team_colour_x;
            goal_pose.point.y = lidarscan.team_colour_y;
            goal_pose.point.z = lidarscan.team_colour_theta;
            for (size_t i = 0; i < 500; i++){
                goal_pose_publisher.publish(goal_pose);
                std::cout << i << " ";
            }
//            ros::Duration(90.0).sleep();
//            std::cout << "publish goal pos" << std::endl;

//            // check reach goal
//            double x = transform.getOrigin().x();
//            double y = transform.getOrigin().y();

//            if (std::abs(x) < 0.05 && std::abs(y) < 0.05){
//                reach_goal_pose = true;
//            }else{
//                reach_goal_pose = false;b
//            }
//            std::cout << x << " " << y << " " << reach_goal_pose << std::endl;
//            std::cout << std::abs(x) << " " << std::abs(y) << " " << reach_goal_pose << std::endl;

        }else if(reach_goal_pose && !imageconverter.team_color_done()){
            std::cout << "======move to team color======" << std::endl;
            imageconverter.get_task(0);//0 means detecting team color
            if(imageconverter.team_color_done())
                 team_color = imageconverter.return_team_color();
            std::cout << "true color is"<<team_color<<std::endl;
        }else if(imageconverter.team_color_done()){

        }
        ros::spinOnce();
        rate.sleep();
    }

//    ros::spin();
//    rate.sleep();
};
