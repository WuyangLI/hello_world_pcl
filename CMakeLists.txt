cmake_minimum_required(VERSION 3.18 FATAL_ERROR)

project(hello_pcl)

find_package(PCL 1.11 REQUIRED)

include_directories(${PCL_INCLUDE_DIRS})
link_directories(${PCL_LIBRARY_DIRS})
add_definitions(${PCL_DEFINITIONS})

add_executable (hello_pcl main.cpp)
target_link_libraries (hello_pcl ${PCL_LIBRARIES})
