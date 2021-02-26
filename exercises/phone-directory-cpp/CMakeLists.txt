cmake_minimum_required(VERSION 3.10)

set (CMAKE_BUILD_TYPE Debug)
set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
set (CMAKE_CXX_COMPILER "D:\\mingw\\bin\\mingw32-g++.exe")
# General variables
set (PROJECT miniphonedir)

# Set the project name
project ($PROJECT)

# Set include directories
include_directories(
        ${PROJECT_SOURCE_DIR}/header
)

# Set source files
set (SOURCES ${CMAKE_CURRENT_SOURCE_DIR}/src/main.cpp
             ${CMAKE_CURRENT_SOURCE_DIR}/src/singleton.cpp
             ${CMAKE_CURRENT_SOURCE_DIR}/src/contactdata.cpp)

# add the executable
add_executable (${PROJECT} ${SOURCES})

# target_link_libraries (${PROJECT})