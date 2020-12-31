cmake_minimum_required(VERSION 3.10)

set (CMAKE_BUILD_TYPE Debug)
set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

# General variables
set (PROJECT matrices)

# Set the project name
project ($PROJECT)

# Set include directories
include_directories(
        ${PROJECT_SOURCE_DIR}/include
        ${PROJECT_SOURCE_DIR}/src
)

# Set source files
set (SOURCES ${CMAKE_CURRENT_SOURCE_DIR}/src/main.cpp
             ${CMAKE_CURRENT_SOURCE_DIR}/src/matrix.cpp)

# add the executable
add_executable (${PROJECT} ${SOURCES})

# target_link_libraries (${PROJECT})
