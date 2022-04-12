# udacity_robot_software_engineer_nd
Nanodegree for robot software engineer on Udacity

Please note that the current project to submit is always located in the root folder. It should be straight forward to use the repo root as catkin workspace. Previous project material should be found as hidden folder with the scheme ".prjectX/", with X indicating the project number. 
Small change for test push

# Project 5: Home Service Robot

The goal of this is creating a home service robot which can drive to a desired goal position, simulate picking up an object and then drop it off at a goal position. This is done autonomously.

## Prerequisites

The project consists of the following parts:
- Additional Drivers: [libspnav]
- ROS packages: [openslam_gmapping] (http://wiki.ros.org/openslam_gmapping),
                [turtlebot] (http://wiki.ros.org/Robots/TurtleBot)
                [map_server] (http://wiki.ros.org/map_server)

The openslam_gmapping catkin wrapper package which implements and models the GMapping algorithm. 
GMapping is an open-source SLAM algorithm. It is a very efficient Rao-Blackwellized particle filer which learns a grid map from LiDar. The particle filter uses local "mini-maps" around the robot to minimize the amount of particles in the room. 
This package was used to create the  map which is found in the "map" package of this repository. Use the script "test_slam.sh" to perform slam with the GMapping. Once you feel confident about the map you created, save it using the map_server package by executing following command:
```
rosrun map_server map_saver -f [path/name_of_map]
```
The turtlebot package contains the model and necessary software components of an autonomous mobile robot. It was created at the Willow Garage and is fully based on open-source software and low-cost components.

As far as I understood from the project description, the navigation stack uses the discretized map, described and created earlier, to span up a graph. The path is calculated by an implementation of Dijkstras shortest-path algorithm.

For installing the ros packages use these instructions
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

2. Moving back to `catkin_ws`, run install_pkg.sh script to install everything needed
```
$ cd ..
$ chmod +x ./src/scripts/install_pkg.sh
$ ./src/scripts/install_pkg.sh
```

2. Also within `catkin_ws`, build the project and source everything
```
$ catkin_make
$ source devel/setup.bash
```

4. Launch the world and the robot
```
$ ./src/scripts/home_service.sh
```

5. Watch the robot perform its task.

