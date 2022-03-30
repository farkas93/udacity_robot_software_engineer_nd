#!/bin/sh

#Install GMapping
git clone https://github.com/ros-perception/slam_gmapping ./src/slam_gmapping

#Install Turtulebot
git clone https://github.com/turtlebot/turtlebot ./src/turtlebot
git clone https://github.com/turtlebot/turtlebot_interactions ./src/turtlebot_interactions
git clone https://github.com/turtlebot/turtlebot_simulator ./src/turtlebot_simulator