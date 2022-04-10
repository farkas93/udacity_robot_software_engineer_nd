#!/bin/bash


xterm  -e  " source devel/setup.bash;
 echo \"Starting GAZEBO WORLD \n\";
 export ROBOT_INITIAL_POSE='-x -2 -y -2 -z 0 -R 0 -P 0 -Y 0';
 roslaunch turtlebot_gazebo turtlebot_world.launch world_file:=$(pwd)/../my_robot/worlds/my.world " &

sleep 3

# launch gmapping_demo.launch to perform slam_gmapping
xterm -e " source devel/setup.bash;
echo \"Starting SLAM GMAPPING \n\";
rosparam set /slam_gmapping/iterations 10;
rosparam set /slam_gmapping/linearUpdate 0.05;
rosparam set /slam_gmapping/angularUpdate 0.1;
rosparam set /slam_gmapping/map_update_interval 0.25;
rosparam set /slam_gmapping/srr 0.01;
rosparam set /slam_gmapping/srt 0.01;
rosparam set /slam_gmapping/str 0.02;
rosparam set /slam_gmapping/stt 0.02;
roslaunch turtlebot_gazebo gmapping_demo.launch " &

sleep 3

# launch view_navigation for rviz
xterm -e " source devel/setup.bash;
  echo \"Starting RVIZ \n\";
  roslaunch turtlebot_rviz_launchers view_navigation.launch " &

sleep 3

# launch teleop_keyboard for manual control
xterm -e " source devel/setup.bash;
   echo \"Starting TURTLEBOT KEYBOARD \n\";
   roslaunch turtlebot_teleop keyboard_teleop.launch " &