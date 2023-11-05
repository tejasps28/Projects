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

        ros::Publisher turtle_vel_pub;
        
        ros::ServiceServer draw_service;


        int temp;
        geometry_msgs::Twist move_cmd;



        void initPubSub();
        void draw_triangle();
        void draw_square();
        void draw_rectangle();
        void draw_circle();
        bool draw_service_cb(turtle_shapes::DrawShape::Request& ,turtle_shapes::DrawShape::Response& );
        





};













































#endif

