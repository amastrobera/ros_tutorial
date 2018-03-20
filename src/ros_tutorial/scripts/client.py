#!/usr/bin/env python

import rospy
from ros_tutorial.srv import *

def point_3d_client():
    rospy.wait_for_service('/Points3D')
    try:
        reqCoordinates = rospy.ServiceProxy('/Points3D', get_coordinates)
        res = reqCoordinates()
        return (res.point.x, res.point.y, res.point.z)
    except rospy.ServiceException, e:
        print "Service call failed: %s" % e
        return (0,0,0)

if __name__ == "__main__":
    print "Requesting point ..."
    res = point_3d_client()
    print "Received Point(%s, %s, %s)" % (res[0], res[1], res[2])
