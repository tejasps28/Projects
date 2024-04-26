# 2D SLAM ROS implementations

This repository contains the `Unity3D` based implementation of a 2D SLAM ROS package. The goal of this project was to 
provide an "easy-to-use" testbed, for 2D algorithms. CUrrently, implemented `amcl` and `gmapping`.

## Overview

This package is designed to for testing 2D SLAM algorithms, using ROS (Robot Operating System).  After running these, we can expect to get `tf`, `scan`, `cmd_vel`, `odom`. After following any tutorial for generating a map(example: using gmapping), with this Unity environment, we can get the map. This is an educational project that demonstrates the basics of ROS navigation stack using a simulation platform other than Gazebo.

## Prerequisites

Before you start using this package, ensure you have the following installed:
- ROS (compatible with ROS Kinetic, Melodic, or Noetic).
- Navigation stack your version of ROS.

## Installation

Clone the repository into your catkin workspace's `src` directory:

```bash
cd ~/catkin_ws/src
git clone https://github.com/tejasps28/Projects.git 
cd ~/catkin_ws
catkin build

# Source your environment
source ~/catkin_ws/devel/setup.bash

# Run the unity endpoint launch
roslaunch ros_tcp_endpoint endpoint.launch

# In another terminal, run the navigation node
roslaunch amr_navigation move_base.launch

```
The `ros_tcp_endpoint` is a unity TCP-bridge of sorts, that establishes connection between Unity and ROS.
For more information, refer [this](https://github.com/Unity-Technologies/Unity-Robotics-Hub/blob/main/tutorials/ros_unity_integration/README.md).

The `move_base.launch` is a boilerplate template of navigation stack's implementation. Go through it for further understanding.
NOTE: This is using an exisiting version of the environment as map. You can follow any tutorial for creating a map, regenerate it and test out the SLAM.

![Unity 2D SLAM Demo](https://raw.githubusercontent.com/tejasps28/Projects/main/Diffbot_unitysim/Diffbot_2D/img/unity-2d.gif)


