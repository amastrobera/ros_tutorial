
# app: client 
add_executable(client client.cpp)
#target_link_libraries(client ${catkin_LIBRARIES})
add_dependencies(client beginner_tutorials_gencpp)

# app: server 
add_executable(server server.cpp)
#target_link_libraries(server ${catkin_LIBRARIES})
add_dependencies(server beginner_tutorials_gencpp)

