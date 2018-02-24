#include "lidarscan.h"

// constructor
LidarScan::LidarScan(){
    // inti angel_start and angle_stop
    changeScanRange(angle_min+M_PI/36, M_PI/18);

    laser_sub = nh.subscribe("/lidarscan", 1, &LidarScan::laser_sb, this);
    // find cylinder call back function
    laser_sub_angel_change = nh.subscribe("/lidarscan", 1, &LidarScan::laser_sb_angel_change, this);

//    laser_sub_pick_puck = nh.subscribe("/lidarscan", 1, &LidarScan::laser_sb_pick_puck, this);

    // for pick_puck
    turtle_vel = nh.advertise<geometry_msgs::Twist>("mobile_base/commands/velocity", 10);
}

int LidarScan::angle2index(double angle){
    int idx = int((angle- angle_min) / angle_increment);
    return idx;
}

double LidarScan::index2angle(int index){
    double angle = double(angle_min + index * angle_increment);
    return angle;
}

// NOTE: 107 deg = left bottom; 95 = 2nd left bottom; 62 deg = 3rd left bottom
// 252 = right bottom, 264 = 2nd right bottom; 295 = 3rd right bottom
// 65, 107, 252, 295
void LidarScan::changeScanRange(double center, double range){
    angle_start = center - range/2 + ANGLE_OFFSET/2;
    angle_range = range;
}

void LidarScan::calAandB(){
//    a_b_ready = false; //pick_puck_ready = true;  // save cylindar pos, not save puck pos
    double angle_1;
    double angle_2;
    double angle_3;
    double A_tmp;
    double B_tmp;
    double a_tmp;
    double b_tmp;
    double measure_a1;
    double measure_a2;
    std::cout << "=======cal a and b=======" << std::endl;

    debug = false;
    if (debug){
        for (size_t idx = 0; idx < 4; idx ++){
            std::cout << a_b_saver[idx][0] << " ";
        }
        std::cout << "range" << std::endl;
        for (size_t idx = 0; idx < 4; idx ++){
            std::cout << a_b_saver[idx][1] << " ";
        }
        std::cout << "angle" << std::endl;
    }
    debug = false;

    A_tmp = a_b_saver[0][0];
    B_tmp = a_b_saver[1][0];
    b_tmp = a_b_saver[2][0];
    a_tmp = a_b_saver[3][0];

    angle_1 = a_b_saver[1][1] - a_b_saver[0][1];
    angle_2 = a_b_saver[2][1] - a_b_saver[1][1];
    angle_3 = a_b_saver[3][1] - a_b_saver[2][1];


    measure_a1 = sqrt(pow(A_tmp, 2)+pow(B_tmp, 2) - 2*A_tmp*B_tmp*cos(angle_1));
    measure_a2 = sqrt(pow(a_tmp, 2)+pow(b_tmp, 2) - 2*a_tmp*b_tmp*cos(angle_3));
    a = (measure_a1 + measure_a2)/2;
    b = sqrt(pow(b_tmp, 2)+pow(B_tmp, 2) - 2*b_tmp*B_tmp*cos(angle_2));

    std::cout << "a: " << a << " b: " << b << std::endl;

    a_b_finish = true;
}

// if a_b_finish = true
void LidarScan::calTorPos(){
    std::cout << "=======cal tor pos=======" << std::endl;
    tor_x = 3*a + TURTLEBOT_OFFSET;
//    tor_x = 2*1.21 + TURTLEBOT_OFFSET;
    tor_y = 0;
    std::cout << "tor x: " << tor_x << " tor y: " << tor_y << std::endl;
    tor_pos_finish = true;
//    a_b_finish = false;
}

void LidarScan::calTeamColourPos(){
    std::cout << "=======cal team colour pos=======" << std::endl;
    team_colour_x = 0;
    team_colour_y = b/3;
    team_colour_theta = -M_PI/2;
    std::cout << "x: " << team_colour_x << " y: " << team_colour_y << " theta: " << team_colour_theta << std::endl;
    team_colour_finish = true;
}

void LidarScan::checkLeft(){
    changeScanRange(angle_center_left, angle_range_LR_angle_change);
    debug = false;
    if (debug) std::cout << "    check left" << std::endl;
    debug = false;
}

void LidarScan::checkRight(){
    changeScanRange(angle_center_right, angle_range_LR_angle_change);
    debug = false;
    if (debug) std::cout << "    check right" << std::endl;
    debug = false;
}

double LidarScan::rad2degree(double rad){
    return 57.2958 * (rad-angle_min);
}

int num_loop_laser_sb = 0;
// first laser call back function
void LidarScan::laser_sb(const sensor_msgs::LaserScan::ConstPtr &scan){
//    double angle_min = scan->angle_min;
//    double angle_max = scan->angle_max;
//    double angle_increment = scan->angle_increment;
//    int num_ranges = scan->ranges.size();

    // chache scan->ranges

//    std::cout << "    call back laserscan" << std::endl;

    int num_missing = 0;
    if(cache_idx<cache_idx_max){
        //cache
        for (size_t idx = 1; idx <= num_ranges; idx++){
            if (!isinf(scan->ranges[idx])){
                cache_ranges[idx][cache_idx] = scan->ranges[idx];
            }else{
                cache_ranges[idx][cache_idx] = 0;
            }
            if(debug) std::cout << cache_ranges[idx][cache_idx] << " ";
        };
        if(debug) std::cout << std::endl;
        if(debug) std::cout << "cache_idx = " << cache_idx << std::endl;
        cache_idx++;
    }else{
        // cal mean for cache_ranges
        int num_zero = 0;
        double sum_nonzeros = 0;
        for (size_t i = 1; i <= num_ranges; i++){
            for (size_t j = 1; j < cache_idx_max; j++){
                // num of non zero
                if (cache_ranges[i][j] == 0){
                    num_zero++;
                }else{
                    sum_nonzeros += cache_ranges[i][j];
                }
            }
            if (num_zero == cache_idx_max-1){
                num_missing ++;
            }
            // all values missing, set ranges_to_use to 0
            if (num_zero == cache_idx_max-1){
                ranges_to_use[i] = 0;
            }else{
                ranges_to_use[i] = sum_nonzeros / (cache_idx_max-1-num_zero);
            }
//            if(debug) std::cout << i << ":sum: " << sum_nonzeros <<  " num_zero: " << num_zero << " range: " << ranges_to_use[i] << "  ";
            num_zero = 0;
            sum_nonzeros = 0;
            if(debug) std::cout << ranges_to_use[i] << " ";
        }
        if(debug) std::cout << "cache_id: " << cache_idx << " num of missing values: " << num_missing << std::endl;
        num_missing = 0;
        if(debug) std::cout << std::endl;
        if(debug) std::cout << "cache_idx = " << cache_idx << std::endl;
        cache_idx = 0;
    }


    // make sure angle_start and angle_range legal
    // cache_idx == 0 -> find range_min
    if (cache_idx == 0){
        debug = false;
        if(debug) std::cout << "cache finished" << std::endl;
        if(debug) std::cout << pick_puck_ready << std::endl;
        debug = false;
        if (angle_start < scan->angle_min & angle_start > scan->angle_max){
            // illegal angel_start, do nothing
        }else {
            int idx_start = angle2index(angle_start);
            int idx_stop = angle2index(angle_start + angle_range);
            range_min = scan->range_max;
            range_min_angle = scan->angle_min;
            for (size_t idx = idx_start; idx <= idx_stop; idx++){
                if (ranges_to_use[idx]<range_min & ranges_to_use[idx] != 0){
                    range_min = ranges_to_use[idx];
                    range_min_angle = index2angle(idx);
                }
            }
            // range threshold
            if (range_min >= DETECTION_RANGE){
                range_min = 0;
                range_min_angle = angle_min;
            }

            debug = false;
            if(debug) std::cout << "index range: " << idx_start << " " << idx_stop << std::endl;
//            if(debug) std::cout << "angel range: " << rad2degree(index2angle(idx_start)) << " " << rad2degree(index2angle(idx_stop)) << std::endl;
            if(debug) std::cout << "range: " << range_min << " angle: " << rad2degree(range_min_angle) << std::endl;

            debug = false;

            // save range_min and range_min_angle at center 95, 107 ...
            if(!a_b_ready){
                double center = angle_start+angle_range/2-ANGLE_OFFSET/2;
                if (debug) std::cout << center << " " << range_min << std::endl;
                if (debug) std::cout << std::abs(center-angle_center1) << " " << std::abs(center-angle_center2) << " " << std::abs(center-angle_center3) << " " << std::abs(center-angle_center4) << std::endl;
                if (std::abs(center-angle_center1)<angle_center_threshold_rad){
                    a_b_saver[0][0] = range_min;
                    a_b_saver[0][1] = range_min_angle;
                }else if (std::abs(center-angle_center2)<angle_center_threshold_rad){
                    a_b_saver[1][0] = range_min;
                    a_b_saver[1][1] = range_min_angle;
                }else if (std::abs(center-angle_center3)<angle_center_threshold_rad){
                    a_b_saver[2][0] = range_min;
                    a_b_saver[2][1] = range_min_angle;
                }else if (std::abs(center-angle_center4)<angle_center_threshold_rad){
                    a_b_saver[3][0] = range_min;
                    a_b_saver[3][1] = range_min_angle;
                }
                // check if a_b_saver no zero
                int a_b_saver_num_nonzero = 0;
                for (size_t idx = 0; idx < 4; idx ++){
                    if (a_b_saver[idx][0] != 0)
                        a_b_saver_num_nonzero ++;
                }
                if (a_b_saver_num_nonzero == 4)
                    a_b_ready = true;
                if(debug) std::cout << "    save a and b" << std::endl;
                if(debug) std::cout << "    a_b_ready: " << a_b_ready << std::endl;

            }else{
                // print a_b_saver
                debug = false;
                if (debug){
                    for (size_t idx = 0; idx < 4; idx ++){
                        std::cout << a_b_saver[idx][0] << " ";
                    }
                    std::cout << "range" << std::endl;
                    for (size_t idx = 0; idx < 4; idx ++){
                        std::cout << rad2degree(a_b_saver[idx][1]) << " ";
                    }
                    std::cout << "angle" << std::endl;
                }
                debug = false;
            }



            // save range and angle for pick puck
            if (!pick_puck_ready){
//                if (debug) std::cout << "===========pick puck save===========" << std::endl;
                debug = false;
                double center = angle_start+angle_range/2-ANGLE_OFFSET/2;  // center = -3.03 or 3.05
                if (debug) std::cout << "center: " << center << std::endl;
                debug = false;
                if (center<0){  // left side
                    if (debug) std::cout << "save left" << std::endl;
                    pick_puck_saver[0][0] = range_min;
                    pick_puck_saver[0][1] = range_min_angle;
                }else if (center>0){  //right side
                    if (debug) std::cout << "save right" << std::endl;
                    pick_puck_saver[1][0] = range_min;
                    pick_puck_saver[1][1] = range_min_angle;
                }
                // check if pick_puck_saver no zero
//                int pick_puck_saver_num_nonzero = 0;
//                for (size_t idx = 0; idx < 2; idx ++){
//                    if (pick_puck_saver[idx][0] != 0)
//                        pick_puck_saver_num_nonzero ++;
//                }
                if (/*pick_puck_saver_num_nonzero == 2 |*/ num_loop_laser_sb > 1){  // cache 2 times
                    pick_puck_ready = true;
                    num_loop_laser_sb = 0;
                }


            } else {
                debug = false;
                if(debug) std::cout << "=========print pick puck saver=========" << std::endl;
                if (debug){
                    for (size_t idx = 0; idx < 2; idx ++){
                        std::cout << pick_puck_saver[idx][0] << " ";
                    }
                    std::cout << "range" << std::endl;
                    for (size_t idx = 0; idx < 2; idx ++){
                        std::cout << rad2degree(pick_puck_saver[idx][1]) << " ";
                    }
                    std::cout << "angle" << std::endl;
                }
                pick_puck_ready = false;
                debug = false;
            }

        }
        cache_idx = 1;
        num_loop_laser_sb ++;
    }


}

// third laser call back function
// no use, use /scan instead and without cache
void LidarScan::laser_sb_pick_puck(const sensor_msgs::LaserScan::ConstPtr &scan){

    // rewrite if else if to switch
    debug = false;

    switch(angle_change_pick_puck){
        case 1:
            if(debug) std::cout << "first command" << std::endl;
            checkLeft();
        break;
        case 2:
            if(debug) std::cout << "second command" << std::endl;
            checkRight();
        break;
    }
    debug = false;

    // change command
    if(debug) std::cout << angle_loop_idx << std::endl;
    if (angle_loop_idx >= angle_loop_max){
        switch(angle_change_pick_puck){
            case 1:
                angle_change_pick_puck = 2;
                if(debug) std::cout << "change command to two" << std::endl;
            break;
            case 2:
                angle_change_pick_puck = 1;
                if(debug) std::cout << "change command to one" << std::endl;
            break;
        }
        angle_loop_idx = 1;
    }
    angle_loop_idx ++;

    debug = false;
}

// second laser call back function
void LidarScan::laser_sb_angel_change(const sensor_msgs::LaserScan::ConstPtr &scan){

    // rewrite if else if to switch
//    std::cout << "    call back angle change" << std::endl;
    debug = false;

    switch(angle_change){
        case 1:
            if(debug) std::cout << "first command" << std::endl;
            changeScanRange(angle_center1, angle_range_laser_sb_angle_change);
        break;
        case 2:
            if(debug) std::cout << "second command" << std::endl;
            changeScanRange(angle_center2, angle_range_laser_sb_angle_change);
        break;
        case 3:
            if(debug) std::cout << "third command" << std::endl;
            changeScanRange(angle_center3, angle_range_laser_sb_angle_change);
        break;
        case 4:
            if(debug) std::cout << "fouth command" << std::endl;
            changeScanRange(angle_center4, angle_range_laser_sb_angle_change);
        break;
    }
    debug = false;

    // change command
    if(debug) std::cout << angle_loop_idx << std::endl;
    if (angle_loop_idx >= angle_loop_max){
        switch(angle_change){
            case 1:
                angle_change = 2;
                if(debug) std::cout << "change command to two" << std::endl;
            break;
            case 2:
                angle_change = 3;
                if(debug) std::cout << "change command to three" << std::endl;
            break;
            case 3:
                angle_change = 4;
                if(debug) std::cout << "change command to one" << std::endl;
            break;
            case 4:
                angle_change = 1;
                if(debug) std::cout << "change command to one" << std::endl;
            break;
        }
        angle_loop_idx = 1;
    }
    angle_loop_idx ++;

    debug = false;
}
