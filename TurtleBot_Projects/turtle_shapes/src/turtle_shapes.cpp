#include <turtle_shapes/turtle_shapes.h>


turtleshapes::turtleshapes(){

    nh = new ros::NodeHandle();
    draw_service= nh->advertiseService("/draw_shape",&turtleshapes::draw_service_cb,this);

    temp = 0;



}
turtleshapes::~turtleshapes(){
    // delete nh;
}


bool turtleshapes::draw_service_cb(turtle_shapes::DrawShape::Request& req,turtle_shapes::DrawShape::Response& res){
    
    temp = req.num;
    std::cout<< "Input is :"<< temp << std::endl;

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