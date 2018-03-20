#include <ros/ros.h>
#include <ros_tutorial/coordinates.h>
#include <ros_tutorial/get_coordinates.h>

using namespace ros_tutorial;

int main(int argc, char* argv[])
{

    ros::init(argc, argv, "point_client");
    ros::NodeHandle n;
    ros::ServiceClient client = n.serviceClient<get_coordinates>("/Points3D");
    get_coordinates srv;
    if (client.call(srv))
    {
        ROS_INFO("received response: point (%ld, %ld, %ld)",
                srv.response.point.x, srv.response.point.y, 
                srv.response.point.z);
    }
    else
    {
        ROS_ERROR("failed to get response of get_coordinates");
        return 1;
    }

    return 0;
}
