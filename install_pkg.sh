#!/bin/sh

#Install GMapping
git clone https://github.com/ros-perception/slam_gmapping ./src/slam_gmapping
git clone https://github.com/ros-perception/openslam_gmapping ./src/openslam_gmapping

#Install Turtlebot
git clone https://github.com/turtlebot/turtlebot ./src/turtlebot
git clone https://github.com/turtlebot/turtlebot_interactions ./src/turtlebot_interactions
git clone https://github.com/turtlebot/turtlebot_simulator ./src/turtlebot_simulator

#Additional Joystick drivers required by Turtulebots
git clone https://github.com/ros-drivers/joystick_drivers ./src/joystick_drivers
