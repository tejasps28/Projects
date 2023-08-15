#ifndef TURTLE_SHAPES_H
#define TURTLE_SHAPES_H

#include <ros/ros.h>
#include <geometry_msgs/Twist.h>
#include <turtlesim/Spawn.h>
#include <std_msgs/Int32.h>
#include <turtle_shapes/DrawShape.h>
#include <turtle_shapes/DrawShapeRequest.h>
#include <turtle_shapes/DrawShapeResponse.h>

#include <iostream>


class turtleshapes{

    public:
        turtleshapes();
        ~turtleshapes();


        ros::NodeHandle* nh;

        ros::ServiceServer draw_service;


        int temp;



        void initPubSub();
        bool draw_service_cb(turtle_shapes::DrawShape::Request& ,turtle_shapes::DrawShape::Response& );
        





};













































#endif

