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
    switch (temp) {
        case 1: // Triangle
	        res.shape_id = "Triangle";
            draw_triangle();
            break;
        case 2: // Square
	        res.shape_id = "Square";
            draw_square();
            break;
        case 3: // Rectangle
	        res.shape_id = "Rectangle";
            draw_rectangle();
            break;
        case 4: // Circle
	        res.shape_id = "Circle";
            draw_circle();
            break;
        default:
            ROS_WARN("Invalid shape request: %d", req.num);
            return false;
    }
        
    res.success = true;
    return true;

}
void turtleshapes::draw_triangle()
{
    
    ROS_INFO("Drawing Triangle..!");
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

void turtleshapes::draw_square() {
    ROS_INFO("Drawing Square..!");
    geometry_msgs::Twist move_cmd;

    // Set linear velocity for moving forward
    move_cmd.linear.x = 2.0;

    // Set angular velocity for turning
    move_cmd.angular.z = 0.0; // Approximately 90 degrees in radians

    // Move forward to start drawing the square
    turtle_vel_pub.publish(move_cmd);
    ros::Duration(1.0).sleep(); // Adjust duration for moving forward

    // Turn for the first corner
    move_cmd.linear.x = 0.0;
    move_cmd.angular.z = 1.5708;
    turtle_vel_pub.publish(move_cmd);
    ros::Duration(1.0).sleep(); // Adjust duration for turning

    // Move forward to draw the first side
    move_cmd.linear.x = 2.0;
    move_cmd.angular.z = 0.0;
    turtle_vel_pub.publish(move_cmd);
    ros::Duration(2.0).sleep(); // Adjust duration for side length

    // Turn for the second corner
    move_cmd.linear.x = 0.0;
    move_cmd.angular.z = 1.5708;
    turtle_vel_pub.publish(move_cmd);
    ros::Duration(1.0).sleep(); // Adjust duration for turning

    // Move forward to draw the second side   
    move_cmd.linear.x = 2.0;
    move_cmd.angular.z = 0.0;
    turtle_vel_pub.publish(move_cmd);
    ros::Duration(2.0).sleep(); // Adjust duration for side length

    // Turn for the third corner
    move_cmd.linear.x = 0.0;
    move_cmd.angular.z = 1.5708;
    turtle_vel_pub.publish(move_cmd);
    ros::Duration(1.0).sleep(); // Adjust duration for turning

    // Move forward to draw the third side
    move_cmd.linear.x = 2.0;
    move_cmd.angular.z = 0.0;
    turtle_vel_pub.publish(move_cmd);
    ros::Duration(2.0).sleep(); // Adjust duration for side length

    // Turn for the fourth corner
    move_cmd.linear.x = 0.0;
    move_cmd.angular.z = 1.5708;
    turtle_vel_pub.publish(move_cmd);
    ros::Duration(1.0).sleep(); // Adjust duration for turning

    // Move forward to complete the square
    move_cmd.linear.x = 2.0;
    move_cmd.angular.z = 0.0;
    turtle_vel_pub.publish(move_cmd);
    ros::Duration(2.0).sleep(); // Adjust duration for side length

    // Stop the turtle after drawing
    move_cmd.linear.x = 0.0;
    move_cmd.angular.z = 0.0;
    turtle_vel_pub.publish(move_cmd);
}

void turtleshapes::draw_circle() {
    ROS_INFO("Drawing Circle..!");
    geometry_msgs::Twist move_cmd;

    // Set linear velocity for moving forward
    move_cmd.linear.x = 2.0;

    // Set angular velocity for turning - this will be a continuous turn
    move_cmd.angular.z = 2.0944; // Higher angular velocity for a smoother circle

    // Draw the circle with a continuous motion
    for(int i = 0; i < 20; ++i) { // Loop to make the circle
        turtle_vel_pub.publish(move_cmd);
        ros::Duration(0.5).sleep(); // Adjust duration for smoothness of the circle
    }

    // Stop the turtle after drawing
    move_cmd.linear.x = 0.0;
    move_cmd.angular.z = 0.0;
    turtle_vel_pub.publish(move_cmd);
}
void turtleshapes::draw_rectangle() {
    ROS_INFO("Drawing Rectangle..!");
    geometry_msgs::Twist move_cmd;

    // Set linear velocity for moving forward
    move_cmd.linear.x = 2.0;

    // Set angular velocity for turning
    move_cmd.angular.z = 0.0;

    // Move forward to start drawing the rectangle
    turtle_vel_pub.publish(move_cmd);
    ros::Duration(2.0).sleep(); // Adjust duration for moving forward

    // Turn for the first corner
    move_cmd.linear.x = 0.0;
    move_cmd.angular.z = 1.5708; // Approximately 90 degrees in radians
    turtle_vel_pub.publish(move_cmd);
    ros::Duration(1.0).sleep(); // Adjust duration for turning

    // Move forward to draw the long side of the rectangle
    move_cmd.linear.x = 4.0;
    move_cmd.angular.z = 0.0;
    turtle_vel_pub.publish(move_cmd);
    ros::Duration(3.0).sleep(); // Adjust duration for long side length

    // Turn for the second corner
    move_cmd.linear.x = 0.0;
    move_cmd.angular.z = 1.5708;
    turtle_vel_pub.publish(move_cmd);
    ros::Duration(1.0).sleep(); // Adjust duration for turning

    // Move forward to draw the short side of the rectangle
    move_cmd.linear.x = 2.0;
    move_cmd.angular.z = 0.0;
    turtle_vel_pub.publish(move_cmd);
    ros::Duration(2.0).sleep(); // Adjust duration for short side length

    // Turn for the third corner
    move_cmd.linear.x = 0.0;
    move_cmd.angular.z = 1.5708;
    turtle_vel_pub.publish(move_cmd);
    ros::Duration(1.0).sleep(); // Adjust duration for turning

    // Move forward to draw the long side of the rectangle again
    move_cmd.linear.x = 4.0;
    move_cmd.angular.z = 0.0;
    turtle_vel_pub.publish(move_cmd);
    ros::Duration(3.0).sleep(); // Adjust duration for long side length

    // Turn for the fourth corner
    move_cmd.linear.x = 0.0;
    move_cmd.angular.z = 1.5708;
    turtle_vel_pub.publish(move_cmd);
    ros::Duration(1.0).sleep(); // Adjust duration for turning

    // Move forward to complete the rectangle
    move_cmd.linear.x = 2.0;
    move_cmd.angular.z = 0.0;
    turtle_vel_pub.publish(move_cmd);
    ros::Duration(2.0).sleep(); // Adjust duration for short side length

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
    ROS_WARN("1. Traingle, 2.Square, 3.Rectangle, 4.Circle");

	turtleshapes turtle_shapes;

	ros::Rate rate(10.0);

	while(ros::ok())
	{
		ros::spin();
		rate.sleep();


	
	}
	
}
