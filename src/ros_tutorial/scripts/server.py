#!/usr/bin/env python

from ros_tutorial.srv import *
import rospy
import random

def set_coordinates(req):
    res = get_coordinatesResponse()
    res.point.x = random.randint(0, 100)
    res.point.y = random.randint(0, 100)
    res.point.z = random.randint(0, 100)
    print "Received request. Returning Point(%s, %s, %s)" % (res.point.x, res.point.y, res.point.z)
    return res

def point_3d_server():
    rospy.init_node('point_3d_server')
    s = rospy.Service('/Points3D', get_coordinates, set_coordinates)
    print "Ready to serve"
    rospy.spin()

if __name__ == "__main__":
    try:
        point_3d_server()
    except:
        print "error in execution. terminating .."
