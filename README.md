## ROS tutorial ##

I will use the ROS messaging system to build a pair of apps. They will first
communicate as publisher/subscriber with strings, then client/server with a proper rosmsg. It will be demoed in C\+\+ and python. I will create a package called **ros_tutorial**.

### Requirements ###

Install [ROS](http://wiki.ros.org/it/ROS/Tutorials) and get familiar with it. Also install the relative environment variables in the bashrc.

In all examples I will use (at least) three terminal windows (T1, T2, T3).

### Publisher - Subscriber ###

I want to build a plain vanilla pub-sub to communicate string messages. The reference files are in ros_tutorial/src/ -> **publisher.cpp**, **subscriber.cpp**

#### Build the whole WS with catkin ####

From the workspace main directory (the repo directory, basically)

	catkin_make

Now the executables will be in **devel/lib/<package_name>**

	roscore (T1)
	cd devel/lib/ros_tutorial
	./listener (T2)
	./talker (T3)

#### Build one package at a time ####

From the workspace main directory

	cd src/ros_tutorial
	mkdir build && cd build
	cmake .. && make -j4

The same folder structure of catkin main workspace will be created in build

	cd build/devel/lib/ros_tutorial
	roscore (T1)
	./listener (T2)
	./talker (T3)

#### Make libs/execs available to rosrun ####

If you don't want to use the command line to run executables, and prefer other ros tools (like ***rosrun***, ***roslaunch***, ***rosmsg***, ***rossrv*** ...") type this from the main workspace directory.

    source devel/setup.bash

You can now try thus to lanch pub-sub

    roscore (T1)
    rosrun ros_tutorial listener (T2)
    rosrun ros_tutorial talker (T3)

After *setup.bash* you can verify the service and msg created. I won't use it for publisher-subscriber, but will use it for client-sever

    rosmsg show ros_tutorial/coordinate
    rossrv show ros_tutorial/get_coordinates


### Client - Server ###

I want to sent a message composed of three long ints, a point (x,y,z). I want to send it via a **service**, which received a request and sends back a response with this **message**. 

In \"ros_tutorial\"/src, the reference files are **client.cpp** and **server.cpp**. The messages and service are into ros_tutorial/**msg/coordinates.msg** and ros_tutorial/**srv/get_coordinates.srv**.

Built the project as in one of the two options of the previous (pub-sub) section. Then go to the devel/lib/<package_name> binaries directory. 

	roscore (T1)
	cd devel/lib/ros_tutorial
	./server (T2)
	./client (T3) // can repeat exec serveral times


### Examples in Python ###

I will replicate the examples above using python. 

The catkin build (or the cmake build) have generated the python dist-packages that I will need to import in the main python executables. Python I create, importing rospy, also require to be executable (*chmod a+x \*.py*). Because I have previously built the package with *catkin* and run *source devel/setup.bash*, I can now launch it with ros tools. 


#### Publisher - Subscriber ####

The publisher talks a bunch of strings to the subscriber. Python files need to be added manually in the **scripts** directory inside the <package_name> directory.

    roscore (T1)
    rosrun ros_tutorial listener.py (T2)
    rosrun ros_tutorial talker.py (T3)


#### Client - Server ####

It will use the **message** \"coordinates\" and **service** \"get_coordinates\". The server waits for a request, and sends a point(x,y,z) back as a single response, and then the client terminates. 

	roscore (T1)
    rosrun ros_tutorial server.py (T2)
    rosrun ros_tutorial client.py (T3) // can repeat exec serveral times


