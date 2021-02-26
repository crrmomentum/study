cmake_minimum_required(VERSION 3.10)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

# General variables
set (PROJECT threadTest)

# Set the project name
project($PROJECT)

# Set source files
set(SOURCES thread_example.cpp)

# Set the necessary libraries
set (LIBS pthread)

# add the executable
add_executable(${PROJECT} ${SOURCES})

target_link_libraries(${PROJECT} ${LIBS} ${CMAKE_THREAD_LIBS_INIT})