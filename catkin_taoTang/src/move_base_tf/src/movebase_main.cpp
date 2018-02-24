#include "movebase.h"

void pose_publish(double x, double y, double theta){

}

int main(int argc, char** argv){
    ros::init(argc, argv, "move_base_listener");
    ros::NodeHandle nh;
    // constructor
    MoveBase movebase;

    ros::Rate rate(10.0);

    movebase.listener.waitForTransform("base_link", "goal_pose", ros::Time(0), ros::Duration(3.0));

//    if(movebase.point_sb_finish & movebase.set_frame_flag){
//        // here set_frame
//        std::cout << movebase.point_x << " " << movebase.point_y << std::endl;
//        movebase.set_frame(movebase.point_x, movebase.point_y, 0);
//        movebase.set_frame_flag = false;
//    }
//    double x_goal_odom = 1;
//    double y_goal_odom = 0;
//    double theta_goal_odom = 3.14;
//    movebase.set_frame(x_goal_odom, y_goal_odom, theta_goal_odom);
    double linear_x_LR_idx = 0;
    double linear_x_LR_idx_max = 15;

    bool new_goal = true;
    double x_transform_old = 0, y_transform_old = 0, theta_transform_old = 0;
    double new_goal_theta_thershold = 0.01;
    double new_goal_xy_thershold = 0.03;


    while (nh.ok()){
/////////
        // frame broadcaster
//        movebase.transform.setOrigin( tf::Vector3(movebase.x_transform, movebase.y_transform, 0.0) );
//        tf::Quaternion q;
//        q.setRPY(0, 0, movebase.theta_transform);
//        movebase.transform.setRotation(q);
////        movebase.transform.setRPY(0, 0, movebase.theta_transform);
//        movebase.br.sendTransform(tf::StampedTransform(movebase.transform, ros::Time::now(), "odom", "goal_pose"));

        // near frame 'base_link' and 'goal_pose'
        //TODO: make transform global variable
        tf::StampedTransform transform;

        try{
            movebase.listener.lookupTransform("base_link", "goal_pose", ros::Time(0), transform);
        }
        catch (tf::TransformException &ex) {
            ROS_ERROR("%s",ex.what());
            ros::Duration(1.0).sleep();
            continue;
        }

        // get x y and theta
        double x_base_goal = transform.getOrigin().x();
        double y_base_goal = transform.getOrigin().y();

        tf::Quaternion rotation;
        rotation = transform.getRotation();
        tf::Matrix3x3 m(rotation);
        double roll, pitch, theta_base_goal;
        m.getRPY(roll, pitch, theta_base_goal);
        std::cout << "x, y, theta: " << x_base_goal << " " << y_base_goal << " " << theta_base_goal << " " << std::endl;
///////

        // 1.stage
        // rotate to goal_pose, go to goal_pose
        geometry_msgs::Twist vel_msg;

//        std::cout << "=======" << movebase.x_transform
//                  << "=======" << movebase.y_transform
//                  << "=======" << movebase.theta_transform << std::endl;
//        std::cout << "++++++" << x_transform_old
//                  << "++++++" << y_transform_old
//                  << "++++++" << theta_transform_old << std::endl;

        // check if new goal
        if(std::abs(x_transform_old - movebase.x_transform) > new_goal_xy_thershold ||
                std::abs(y_transform_old - movebase.y_transform) > new_goal_xy_thershold ||
                std::abs(theta_transform_old - movebase.theta_transform) > new_goal_theta_thershold){
            new_goal = true;

            std::cout << "++++++" << x_transform_old << " " << y_transform_old << " " << theta_transform_old << std::endl;
            x_transform_old = movebase.x_transform;
            y_transform_old = movebase.y_transform;
            theta_transform_old = movebase.theta_transform;

            std::cout << new_goal << std::endl;
            std::cout << "======" << movebase.x_transform << " " << movebase.y_transform << " " << movebase.theta_transform << std::endl;

        }
//        double if_new_goal = double(sqrt());



        if(new_goal)
        {
            movebase.reach_goal = false;
            movebase.reach_goal_theta = false;
            new_goal = false;
            std::cout << "===set new goal===" << std::endl;
            continue;
        }
        std::cout << "check continue" << std::endl;
//        movebase.reach_goal = true;
        double linear_x;
        double angular_z;
        if(!movebase.reach_goal){
            angular_z = double(1 * atan2(y_base_goal, x_base_goal));
//            if(x_base_goal < 0 | y_base_goal < 0){
//                linear_x = -double(0.3 * sqrt(pow(x_base_goal, 2) + pow(y_base_goal, 2)));
//            }else{
                linear_x = double(0.3 * sqrt(pow(x_base_goal, 2) + pow(y_base_goal, 2)));
//            }

            // check if near goal
            // mark: niu bi li taet
            if (std::abs(y_base_goal)<0.02 && std::abs(x_base_goal)<0.02 && movebase.use_rearly_stop == true){
                vel_msg.angular.z = 0;
                vel_msg.linear.x = 0;
                movebase.reach_goal = true;
                //movebase.reach_goal_theta = false;
            }else{
                std::cout << "+====+" << linear_x << " " << angular_z << std::endl;
                vel_msg.angular.z = angular_z * (linear_x_LR_idx/linear_x_LR_idx_max);
                vel_msg.linear.x = linear_x * (linear_x_LR_idx/linear_x_LR_idx_max);
                if (linear_x_LR_idx < linear_x_LR_idx_max){
                    linear_x_LR_idx ++;
                }
            }
            movebase.turtle_vel.publish(vel_msg);
        }else if(!movebase.reach_goal_theta){
            // 2. stage
            // rotato to theta
            double angular_z = double(0.7*(theta_base_goal));
            if(std::abs(theta_base_goal)<0.04){
                vel_msg.angular.z = 0;
                vel_msg.linear.x = 0;
                movebase.reach_goal_theta = true;
                //movebase.reach_goal = false;
            }else{
                vel_msg.angular.z = angular_z;
                vel_msg.linear.x = 0;
            }
            movebase.turtle_vel.publish(vel_msg);
        }
        if(movebase.reach_goal) std::cout << "reach goal" << std::endl;
        if(movebase.reach_goal_theta) std::cout << "reach oreintation"<< std::endl;


        movebase.go_to_position();
        ros::spinOnce();
        rate.sleep();
    }

//    ros::spin();
//    rate.sleep();
    return 0;
};
