#include "collision_prevention.h"

collision_prevention::collision_prevention()
{
    this->correct_theta_rad = 0.0;
    this->ang_z = 0.0;
    this->dodge_ang_z = 0.0;
    this->forward_speed_mps = 0.15;
    this->decision = STOP;
    this->previous_decision = F;
    this->makingDecision = false;
    this->movingForward = true;

    this->mid_index = 0;
    this->right_index = 309;
    this->left_index = 50;
    this->right_front_index = 345;
    this->left_front_index = 14;
    this->rL_index = left_index + 1;
    this->lL_index = rL_index + 15;
    this->lR_index = right_index - 1;
    this->rR_index = lR_index - 15;
}



// Process the incoming laser scan message
void collision_prevention::scanCallback(const sensor_msgs::LaserScan::ConstPtr& scan)
{
    Range closest_front_range = getClosestRange(scan, this->right_front_index, this->left_front_index);
    Range closest_range = getClosestRange(scan, this->right_index, this->left_index);

    // Evaluate left side reservoir
    Reservoir left_rsv = getReservoir(scan, this->lL_index, this->rL_index);
    // Evaluate right side reservoir
    Reservoir right_rsv = getReservoir(scan, this->lR_index, this->rR_index);

    float t_approach;

    makeDecision(left_rsv,
                 right_rsv,
                 closest_front_range,
                 closest_range,
                 this->mid_index);

    ROS_INFO_STREAM("CFR: " << closest_front_range.range << " CR: " << closest_range.range);
    ROS_INFO_STREAM("LR: " << left_rsv.avg_range << " RR: " << right_rsv.avg_range);

    switch (this->decision) {
    case F:
        //this->ang_z = 0;
        //moveForward();
        break;
    case L:
        this->correct_theta_rad = abs(left_rsv.max_range_index - closest_range.index) * ANGLE_INCREMENT;
        this->correct_theta_rad = fmin(2*M_PI - this->correct_theta_rad, this->correct_theta_rad);
        t_approach = (closest_range.range / this->forward_speed_mps);
        this->ang_z = this->correct_theta_rad / t_approach + 0.1;
        break;
    case R:
        this->correct_theta_rad = abs(right_rsv.max_range_index - closest_range.index) * ANGLE_INCREMENT;
        this->correct_theta_rad = fmin(2*M_PI - this->correct_theta_rad, this->correct_theta_rad);
        t_approach = (closest_range.range / this->forward_speed_mps);
        this->ang_z = - this->correct_theta_rad / t_approach - 0.1;
        break;
    case AGGRESIVE_L:
        this->correct_theta_rad = abs(left_rsv.max_range_index - closest_range.index) * ANGLE_INCREMENT;
        this->correct_theta_rad = fmin(2*M_PI - this->correct_theta_rad, this->correct_theta_rad);
        t_approach = (closest_range.range / this->forward_speed_mps);
        if (t_approach < 0.5) {
            this->ang_z = M_PI / 2;
        } else {
            this->ang_z = this->correct_theta_rad / t_approach + 0.2;
        }
        break;
    case AGGRESIVE_R:
        this->correct_theta_rad = abs(right_rsv.max_range_index - closest_range.index) * ANGLE_INCREMENT;
        this->correct_theta_rad = fmin(2*M_PI - this->correct_theta_rad, this->correct_theta_rad);
        t_approach = (closest_range.range / this->forward_speed_mps);
        if (t_approach < 0.5) {
            this->ang_z = - M_PI / 2;
        } else {
            this->ang_z = - this->correct_theta_rad / t_approach - 0.2;
        }
        break;
    case STOP:
        if (closest_range.index > 180 && this->previous_decision != STOP){
            this->ang_z = - M_PI / 4;
        } else {
            this->ang_z = M_PI / 4;
        }
        break;
    default:
        break;
    }

    this->previous_decision = decision;
    //ROS_INFO_STREAM("left_rsv: " << left_rsv.avg_range << " right_rsv: " << right_rsv.avg_range);
    return;
}

void collision_prevention::switchMovingDirection()
{
    if (this->movingForward) {
        this->mid_index = 0;
        this->right_index = 309;
        this->right_front_index = 345;
        this->left_index = 50;
        this->left_front_index = 14;

        this->rL_index = left_index + 1;
        this->lL_index = rL_index + 15;
        this->lR_index = right_index - 1;
        this->rR_index = lR_index - 15;
    } else {
        this->mid_index = 179;
        this->left_index = mid_index + 50;
        this->right_index = mid_index - 50;
        this->left_front_index = mid_index + 14;
        this->right_front_index = mid_index - 14;

        this->rL_index = left_index + 1;
        this->lL_index = rL_index + 15;
        this->lR_index = right_index - 1;
        this->rR_index = lR_index - 15;
    }
    return;
}


void collision_prevention::makeDecision(const Reservoir &left_rsv,
                                        const Reservoir &right_rsv,
                                        const Range &closest_front_range,
                                        const Range &closest_range,
                                        const int &mid_index)
{
    if (closest_range.range < this->MIN_PROXIMITY_RANGE_M) {
        if (ROS_INFO_ON) ROS_INFO_STREAM("STOP");
        decision = STOP;
    } else if (closest_front_range.range > left_rsv.avg_range && closest_front_range.range > right_rsv.avg_range) {
        if (ROS_INFO_ON) ROS_INFO_STREAM("F");
        this->decision = F;
    } else if (left_rsv.avg_range < right_rsv.avg_range && closest_range.range > this->MIN_PROXIMITY_RANGE_M * 1.5) {
        if (ROS_INFO_ON) ROS_INFO_STREAM("L but F");
        this->decision = F;
    } else if (left_rsv.avg_range > right_rsv.avg_range && closest_range.range > this->MIN_PROXIMITY_RANGE_M * 1.5) {
        if (ROS_INFO_ON) ROS_INFO_STREAM("R but F");
        this->decision = F;
    } else if ( closest_range.range < 1.5 * this->MIN_PROXIMITY_RANGE_M && closest_range.range > this->MIN_PROXIMITY_RANGE_M ) {
        if (closest_range.index < 180) {
            if (ROS_INFO_ON) ROS_INFO_STREAM("AR");
            this->decision = AGGRESIVE_R;
        } else {
            if (ROS_INFO_ON) ROS_INFO_STREAM("AL");
            this->decision = AGGRESIVE_L;
        }
    }
    return;
}

Range collision_prevention::getClosestRange(const sensor_msgs::LaserScan::ConstPtr& scan,
                                            const int &right_index,
                                            const int &left_index)
{
    Range range;
    range.range = scan->ranges[right_index];
    range.index = right_index;

    if (left_index - right_index < 0) {
        for (int curr_index = right_index + 1; curr_index < 359; curr_index++) {
            //if (scan->ranges[curr_index] == INFINITY) continue;
            if (scan->ranges[curr_index] < range.range) {
                range.range = scan->ranges[curr_index];
                range.index = curr_index;
              }
        }

        for  (int curr_index = 0; curr_index < left_index; curr_index++) {
            //if (scan->ranges[curr_index] == INFINITY) continue;
            if (scan->ranges[curr_index] < range.range) {
                range.range = scan->ranges[curr_index];
                range.index = curr_index;
              }
        }
    } else {
        for (int curr_index = right_index + 1; curr_index <= left_index; curr_index++) {
            //if (scan->ranges[curr_index] == INFINITY) continue;
            if (scan->ranges[curr_index] < range.range) {
                range.range = scan->ranges[curr_index];
                range.index = curr_index;
              }
        }
    }

    return range;
}

geometry_msgs::Twist collision_prevention::getVelMsg(const float &lin_x, const float &ang_z)
{
    if (lin_x < 0 && this->movingForward) {
        this->movingForward = false;
        switchMovingDirection();
    } else if (lin_x > 0 && !this->movingForward) {
        this->movingForward = true;
        switchMovingDirection();
    }

    geometry_msgs::Twist vel_msg;

    if (this->decision != STOP) {
        vel_msg.linear.x = lin_x;
        vel_msg.angular.z = ang_z;
    } else {
        vel_msg.angular.z = this->ang_z;
        vel_msg.linear.x = 0;
    }
    return vel_msg;
}

Reservoir collision_prevention::getReservoir(const sensor_msgs::LaserScan::ConstPtr& scan,
                                                                    const int &left_index,
                                                                    const int &right_index)
{
    Reservoir rsv;
    rsv.max_range = scan->ranges[right_index];
    rsv.max_range_index = right_index;
    rsv.avg_range = 0;
    int count = 0;
/*
    if ((left_index - right_index) < 0) {
        for (int curr_index = right_index + 1; curr_index < 359; curr_index++) {
            rsv.avg_range += scan->ranges[curr_index];
            count++;
            if (scan->ranges[curr_index] > rsv.max_range) {
                rsv.max_range = scan->ranges[curr_index];
                rsv.max_range_index = curr_index;
            }
        }

        for (int curr_index = 0; curr_index < left_index; curr_index++) {
            rsv.avg_range += scan->ranges[curr_index];
            count++;
            if (scan->ranges[curr_index] > rsv.max_range) {
                rsv.max_range = scan->ranges[curr_index];
                rsv.max_range_index = curr_index;
            }
        }
    } else {*/
        for (int curr_index = right_index + 1; curr_index < left_index; curr_index++) {
            if (scan->ranges[curr_index] == INFINITY) continue;
            rsv.avg_range += scan->ranges[curr_index];
            count++;
            if (scan->ranges[curr_index] > rsv.max_range) {
                rsv.max_range = scan->ranges[curr_index];
                rsv.max_range_index = curr_index;
            }
        }
    //}
        if (count == 0) {
            rsv.avg_range = 0;
            rsv.max_range = 0;
            rsv.max_range_index = 0;
            return rsv;
        }
    rsv.avg_range /= count;
    return rsv;
}
