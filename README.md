# udacity_robot_software_engineer_nd
Nanodegree for robot software engineer on Udacity

Please note that the current project to submit is always located in the root folder. It should be straight forward to use the repo root as catkin workspace. Previous project material should be found as hidden folder with the scheme ".prjectX/", with X indicating the project number. 
Small change for test push

# Project 5: Home Service Robot

The goal of this is creating a home service robot which can drive around autonomously in the world.

## Demo 


## Prerequisites

The project consists of the following parts:
- Drivers: [libspnav]
- Additional Software:
- ROS packages: [openslam_gmapping] (http://wiki.ros.org/openslam_gmapping),
                [joy](http://wiki.ros.org/joy),
                [gmapping] (),
                [turtlebot_teleop] ()
                [turtlebot_rviz_launcher] ()
                [turtlebot_gazebo] ()


for installing the ros packages use these instructions
```
$ sudo apt-get update && sudo apt-get upgrade -y
$ sudo apt install libspnav-dev
$ sudo apt install ros-[version]-gazebo-ros
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

5. To save the map use
```
rosrun map_server map_saver -f [path/name_of_map]
```

5. Open another terminal, and execute the package with the `mapping.launch` file. Here,
the RTAB-mapping algorithm will be launched for doing the SLAM.
```
$ source devel/setup.bash
$ roslaunch my_robot mapping.launch
```

6. Open another terminal, and run the `teleop` node.
```
$ source devel/setup.bash
$ roslaunch my_robot teleop.launch
```

7. Navigate the robot around and let it perform the SLAM .

8. Open another terminal, and execute the package with the `localization.launch` file. Here,
the RTAB-mapping algorithm will be launched in localization mode, using the database generated previously.
```
$ source devel/setup.bash
$ roslaunch my_robot localization.launch
```
