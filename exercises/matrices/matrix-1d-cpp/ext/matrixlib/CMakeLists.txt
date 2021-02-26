cmake_minimum_required(VERSION 3.10)

set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

# General variables
set (PROJECT matrices)
#set the default path for built libraries to the "lib" directory
set (LIBRARY_OUTPUT_PATH ${CMAKE_CURRENT_SOURCE_DIR}/lib)

# Set the project name
project ($PROJECT)

# Set include directories
include_directories(
        ${PROJECT_SOURCE_DIR}/include
)

# Set source files
set (SOURCES ${CMAKE_CURRENT_SOURCE_DIR}/src/matrix.cpp
             ${CMAKE_CURRENT_SOURCE_DIR}/src/matrix_factory.cpp)

# set lib location
#set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/lib)

# add the executable
add_library(matrix SHARED ${SOURCES})