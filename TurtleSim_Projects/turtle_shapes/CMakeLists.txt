cmake_minimum_required(VERSION 3.0.2)
project(turtle_shapes)

find_package(catkin REQUIRED COMPONENTS
  roscpp
  std_msgs
  message_generation
)

## Generate services
add_service_files(
  FILES
  DrawShape.srv
)

generate_messages(
  DEPENDENCIES
  std_msgs  # Add std_msgs as a dependency for message generation
)

catkin_package(
  CATKIN_DEPENDS roscpp std_msgs 
)

include_directories(
  include
  ${catkin_INCLUDE_DIRS}
)

add_executable(turtle_shapes_node src/turtle_shapes.cpp)
target_link_libraries(turtle_shapes_node ${catkin_LIBRARIES})
add_dependencies(turtle_shapes_node ${${PROJECT_NAME}_EXPORTED_TARGETS} ${catkin_EXPORTED_TARGETS})
