cmake_minimum_required(VERSION 3.10)

# General variables
set (PROJECT testMatrix)
set (LIBS matrix)
set (CMAKE_BUILD_TYPE Debug)
set (CMAKE_CXX_FLAGS "-g3 -Wall -O0") 

file (MAKE_DIRECTORY ${PROJECT_SOURCE_DIR}/bin)

project ($PROJECT)

# Set include directories
include_directories(
        ${PROJECT_SOURCE_DIR}/ext/matrixlib/include
)

set (SOURCES ${CMAKE_CURRENT_SOURCE_DIR}/src/main.cpp)

add_subdirectory (ext/matrixlib)
add_executable (${PROJECT} ${SOURCES})

link_directories (${LIBRARY_OUTPUT_PATH})
target_link_libraries (${PROJECT} ${LIBS})

install (TARGETS ${PROJECT} RUNTIME DESTINATION ${PROJECT_BINARY_DIR}/bin)
