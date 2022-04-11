# udacity_robot_software_engineer_nd
Nanodegree for robot software engineer on Udacity

Please note that the current project to submit is always located in the root folder. It should be straight forward to use the repo root as catkin workspace. Previous project material should be found as hidden folder with the scheme ".prjectX/", with X indicating the project number. 
Small change for test push

# Project 5: Home Service Robot

The goal of this is creating a home service robot which can drive to a desired goal position, simulate picking up an object and then drop it off at a goal position. This is done autonomously.
## Demo 


## Prerequisites

The project consists of the following parts:
- Drivers: [libspnav]
- Additional Software:
- ROS packages: [openslam_gmapping] (http://wiki.ros.org/openslam_gmapping),
                [turtlebot]


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

