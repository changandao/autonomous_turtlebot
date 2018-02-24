# how to run lidar_view_demo

1. turtlebot_bringup
	in turtlebot run `roslaunch turtlebot_bringup minimal.launch` and `roslaunch turtlebot_bringup 3dsensor.launch`
2. first in workstation
	`roslaunch rplidar_ros view_rplidar.launch`
3. than in turtlebot
	`roslaunch rplidar_ros rplidar.launch`
