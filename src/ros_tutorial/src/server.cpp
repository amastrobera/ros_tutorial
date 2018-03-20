#include <ros/ros.h>
#include <ros_tutorial/coordinates.h>
#include <ros_tutorial/get_coordinates.h>
#include <random>

using namespace ros_tutorial;

bool set_coordinates(get_coordinates::Request &req,
                     get_coordinates::Response &res)
{
    static std::default_random_engine generator;
    std::uniform_int_distribution<int> distribution(0,100);
    
    res.point.x = distribution(generator);
    res.point.y = distribution(generator);
    res.point.z = distribution(generator);
    
    ROS_INFO("received request. sending back point(%ld, %ld, %ld)",
            res.point.x, res.point.y, res.point.z);
    return true;
}


int main(int argc, char* argv[])
{
    ros::init(argc, argv, "point_server");
    ros::NodeHandle n;
    ros::ServiceServer service = n.advertiseService("/Points3D", 
                                                    set_coordinates);
    
    ROS_INFO("ready to serve");
    
    ros::spin();

    return 0;
}
