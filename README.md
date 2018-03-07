### ROS tutorial ###

I will use the ROS messaging system to build a pair of apps. They will first
communicate as client/server, then publisher/subscriber. It will be demoed in C\+\+ and python.

### Requirements ###
Install [ROS](http://wiki.ros.org/it/ROS/Tutorials) and get familiar with it. Also install the relative environment variables in the bashrc

All examples will use (at least) three terminal windows (t1, t2...).

### 1. client/server ###

#### C++ example ####

    $ cd client_server_cpp
    $ mkdir build && cd build
    $ cmake .. && make
    $ roscore (t1)
    $ ./server (t2)
    $ ./client (t3)


