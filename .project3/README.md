# Project 3: Where Am I

The goal of this is the localization of a mobile robot using the ROS AMCL package.
The generated PGM Map should align in RVIZ with the robot and what it detects with its sensors.

## Demo 
In following GIF you can see how we kidnap the robot and it has to relocate itself on the map:
![Demo GIF](.videos_and_images/where_am_i_demo.gif)

In following screenshots I will explain what is happening in this GIF:
![Kidnapping the Robot](.videos_and_images/screenshot0.PNG)
The robot is just being kidnapped from one room to another which leads to confusion for the robot and the need for re-localization.

![Uncertainty](.videos_and_images/screenshot1.PNG)
The AMCL package immediately increases the uncertainty about the robots whereabouts which are well seen by the nicely distributed particle (red arrows) in the room.

![Decresing Uncertainty](.videos_and_images/screenshot2.PNG)
The robot starts to turn and the particle resampling begins. The image shows very well how the particles start to converges towards eachother.

![Rising certainty](.videos_and_images/screenshot3.PNG)
The robot starts to become more certain about its position and the AMCL algorithm rotates and aligns the map successfully with the robots sensor data.

![Matching map](.videos_and_images/screenshot4.PNG)
After the robot managed to do its turning maneuver, we start moving out of the room and one can clearly see how the sensor data still matches the walls ahead of the robot.

## Differences to the project requirements

Please note, that since in world.launch the robot is specified to be instantiated at point (2.0, -1.5), I also specified in the amcl.launch file the initial pose to be (2.0, -1.5). This change has to be made, since my worlds origin, (0.0, 0.0), is within the walls.

## Prerequisites

The project consists of the following parts:
- ROS packages: [map_server](http://wiki.ros.org/map_server), [amcl](http://wiki.ros.org/amcl), 
[move_base](http://wiki.ros.org/move_base).
- The PGM Map file used for the localization was created with following tool: 
[pgm_map_creator](https://github.com/hyfan1116/pgm_map_creator)

for installing the ros packages use these instructions
```
$ sudo apt-get update && sudo apt-get upgrade -y
$ sudo apt-get install ros-${ROS_DISTRO}-map-server
$ sudo apt-get install ros-${ROS_DISTRO}-amcl
$ sudo apt-get install ros-${ROS_DISTRO}-move-base
```

## Build and Launch
1. Clone project and initialize catkin workspace
```
$ git clone https://github.com/farkas93/udacity_robot_software_engineer_nd catkin_ws
$ cd catkin_ws/src
$ catkin_init_workspace
```

2. Also within `catkin_ws/src`, clone the `teleop` package
```
$ git clone https://github.com/ros-teleop/teleop_twist_keyboard
```

3. Move back to `catkin_ws\` and build
```
$ cd ..
$ catkin_make
```

4. Launch the world and the robot
```
$ source devel/setup.bash
$ roslaunch my_robot world.launch
```

5. Open another terminal, and execute the package with the `amcl.launch` file. Here,
the map_server, amcl, and move_back packages will be launched.
```
$ source devel/setup.bash
$ roslaunch my_robot amcl.launch
```

6. Open another terminal, and run the `teleop` node.
```
$ source devel/setup.bash
$ rosrun teleop_twist_keyboard teleop_twist_keyboard.py
```

7. Navigate the robot around and let it locate itself.

