#!/bin/bash

#Install GMapping
git clone https://github.com/ros-perception/slam_gmapping ./src/slam_gmapping
git clone https://github.com/ros-perception/openslam_gmapping ./src/openslam_gmapping

git clone https://github.com/turtlebot/turtlebot ./src/turtlebot

source devel/setup.bash
rosdep -i install turtlebot_teleop