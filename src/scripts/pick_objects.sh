#!/bin/bash

xterm  -e  " source devel/setup.bash;
 echo \"Starting GAZEBO WORLD\";
 export ROBOT_INITIAL_POSE='-x -2 -y -2 -z 0 -R 0 -P 0 -Y 0';
 roslaunch turtlebot_gazebo turtlebot_world.launch world_file:=$(pwd)/src/my_robot/worlds/my.world " &

sleep 3

xterm -e "source devel/setup.bash;
echo \"Starting AMCL\";
source devel/setup.bash;
roslaunch turtlebot_gazebo amcl_demo.launch map_file:=$(pwd)/src/map/map_savefile.yaml " &

sleep 3

xterm -e "source devel/setup.bash;
echo \"Starting View Navigation in RVIZ\";
source devel/setup.bash;
roslaunch turtlebot_rviz_launchers view_navigation.launch" &

sleep 20

xterm -e "source devel/setup.bash;
echo \"Starting Pick Objects\";
source devel/setup.bash;
rosrun pick_objects pick_objects" &
