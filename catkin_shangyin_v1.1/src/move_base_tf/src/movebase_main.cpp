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
    double linear_x_LR_idx_max = 10;

    while (nh.ok()){

        // frame broadcaster
        movebase.transform.setOrigin( tf::Vector3(movebase.x_transform, movebase.y_transform, 0.0) );
        tf::Quaternion q;
        q.setRPY(0, 0, movebase.theta_transform);
        movebase.transform.setRotation(q);
//        movebase.transform.setRPY(0, 0, movebase.theta_transform);
        movebase.br.sendTransform(tf::StampedTransform(movebase.transform, ros::Time::now(), "odom", "goal_pose"));

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
//        std::cout << "x, y, theta: " << x_base_goal << " " << y_base_goal << " " << theta_base_goal << " " << theta_goal_odom << std::endl;

        std::cout << "    " << x_base_goal << " " << y_base_goal << " " << theta_base_goal << std::endl;
        // 1.stage
        // rotate to goal_pose, go to goal_pose
        geometry_msgs::Twist vel_msg;
//        movebase.reach_goal = true;
        if(!movebase.reach_goal){
            double angular_z = double(1 * atan2(y_base_goal, x_base_goal));
            double linear_x = double(0.3 * sqrt(pow(x_base_goal, 2) + pow(y_base_goal, 2)));


            // check if near goal
            // mark: niu bi li taet
            if (std::abs(y_base_goal)<0.02 & std::abs(x_base_goal)<0.02 & movebase.use_rearly_stop == true){
                vel_msg.angular.z = 0;
                vel_msg.linear.x = 0;
                movebase.reach_goal = true;
                movebase.reach_goal_theta = false;
                std::cout << "reach goal" << std::endl;
            }else{
                std::cout << "+====+" << linear_x << " " << angular_z << std::endl;
                vel_msg.angular.z = angular_z * (linear_x_LR_idx/linear_x_LR_idx_max);
                vel_msg.linear.x = linear_x * (linear_x_LR_idx/linear_x_LR_idx_max);
                if (linear_x_LR_idx < linear_x_LR_idx_max){
                    linear_x_LR_idx ++;
                }
                std::cout << "+----+" << linear_x_LR_idx << std::endl;
                std::cout << "++++++" << vel_msg.linear.x << " " << vel_msg.angular.z << std::endl;
            }
            std::cout << "PUBLISH" << std::endl;
            movebase.turtle_vel.publish(vel_msg);
        }else if(!movebase.reach_goal_theta){
            // 2. stage
            // rotato to theta
            double angular_z = double(0.5*(theta_base_goal));
            if(std::abs(theta_base_goal)<0.04){
                vel_msg.angular.z = 0;
                vel_msg.linear.x = 0;
                movebase.reach_goal_theta = true;
                movebase.reach_goal = false;
                std::cout << "reach orientation" << std::endl;
            }else{
                vel_msg.angular.z = angular_z;
                vel_msg.linear.x = 0;
            }
            movebase.turtle_vel.publish(vel_msg);
        }



        movebase.go_to_position();
        ros::spinOnce();
        rate.sleep();
    }
    return 0;
};
