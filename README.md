# Project 3: Where Am I

The goal of this is the localization of a mobile robot using the ROS AMCL package.
The generated PGM Map should align in RVIZ with the robot and what it detects with its sensors.



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



