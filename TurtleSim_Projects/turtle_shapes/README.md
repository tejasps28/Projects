# TurtleSim Shapes ROS Package

This repository contains the `turtle_shapes` ROS package, which is part of the TurtleBot projects. This package enables the Turtlesim turtle to draw various shapes such as triangles, squares, circles, and rectangles.

## Overview

The `turtle_shapes` package is designed to run with the `turtlesim` platform, using ROS (Robot Operating System) to control the turtle's movements to create shapes. This is an educational project that demonstrates the basics of ROS topics and service handling.

## Prerequisites

Before you start using the `turtle_shapes` package, ensure you have the following installed:
- ROS (compatible with ROS Kinetic, Melodic, or Noetic)
- Turtlesim packages for your version of ROS

## Installation

Clone the repository into your catkin workspace's `src` directory:

```bash
cd ~/catkin_ws/src
git clone https://github.com/tejasps28/Projects.git 
cd ~/catkin_ws
catkin build

# Source your environment
source ~/catkin_ws/devel/setup.bash

# Run the turtlesim node
rosrun turtlesim turtlesim_node

# In another terminal, run the turtle_shapes node
rosrun turtle_shapes turtle_shapes_node

#In a new terminal, to draw a shape
rosservice call /draw_shape "num: 2"

![Turtlesim Drawing Shapes](Projects/img/turtle_shapes.gif)

