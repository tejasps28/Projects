#include <turtle_shapes/turtle_shapes.h>


turtleshapes::turtleshapes(){

    nh = new ros::NodeHandle();
    turtle_vel_pub = nh->advertise<geometry_msgs::Twist>("/turtle1/cmd_vel", 10);
    draw_service= nh->advertiseService("/draw_shape",&turtleshapes::draw_service_cb,this);

    temp = 0;



}
turtleshapes::~turtleshapes(){
    // delete nh;
}


bool turtleshapes::draw_service_cb(turtle_shapes::DrawShape::Request& req,turtle_shapes::DrawShape::Response& res){
    
    temp = req.num;
    std::cout<< "Input is :"<< temp << std::endl;
    if (temp ==1)
        draw_triangle();
    res.success = true;

}
void turtleshapes::draw_triangle(){
    

    // Set linear velocity for moving forward
    move_cmd.linear.x = 2.0;

    // Set angular velocity for turning
    move_cmd.angular.z = 0.0;

    // Move forward to start drawing the triangle
    turtle_vel_pub.publish(move_cmd);
    ros::Duration(1.0).sleep(); // Adjust duration for moving forward

    // Turn for the first corner
    move_cmd.linear.x = 0.0;
    move_cmd.angular.z = 2.0944;
    turtle_vel_pub.publish(move_cmd);
    ros::Duration(1.0).sleep(); // Adjust duration for turning

    // Move forward to draw the first side
    
    move_cmd.linear.x = 2.0;
    move_cmd.angular.z = 0.0;
    turtle_vel_pub.publish(move_cmd);
    ros::Duration(2.0).sleep(); // Adjust duration for side length

    // Turn for the second corner
    move_cmd.linear.x = 0.0;
    move_cmd.angular.z = 2.0944;
    turtle_vel_pub.publish(move_cmd);
    ros::Duration(1.0).sleep(); // Adjust duration for turning

    // Move forward to draw the second side
    move_cmd.linear.x = 2.0;
    move_cmd.angular.z = 0.0;
    turtle_vel_pub.publish(move_cmd);
    ros::Duration(2.0).sleep(); // Adjust duration for side length

    // Turn for the third corner
    move_cmd.linear.x = 0.0;
    move_cmd.angular.z = 2.0944;
    turtle_vel_pub.publish(move_cmd);
    ros::Duration(1.0).sleep(); // Adjust duration for turning

    // Move forward to complete the triangle
    move_cmd.linear.x = 2.0;
    move_cmd.angular.z = 0.0; 
    turtle_vel_pub.publish(move_cmd);
    ros::Duration(2.0).sleep(); // Adjust duration for side length

    // Stop the turtle after drawing
    move_cmd.linear.x = 0.0;
    move_cmd.angular.z = 0.0;
    turtle_vel_pub.publish(move_cmd);

    
}
int main (int argc, char** argv)
{
	// Initialize ROS
	ros::init (argc, argv, "turtle_shapes_node");
    ROS_INFO("Started turtle shape drawing node.");

	turtleshapes turtle_shapes;

	ros::Rate rate(10.0);

	while(ros::ok())
	{
		ros::spin();
		rate.sleep();


	
	}
	
}