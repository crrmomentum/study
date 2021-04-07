cmake_minimum_required(VERSION 3.10)

if(CMAKE_CXX_COMPILER_ID STREQUAL "GNU" OR CMAKE_CXX_COMPILER_ID STREQUAL "Clang")
    add_compile_options(-Wall -Wextra)
elseif(CMAKE_CXX_COMPILER_ID STREQUAL "MSVC")
    add_definitions(
        -D_SCL_SECURE_NO_WARNINGS
        -D_CRT_SECURE_NO_WARNINGS
        -D_WIN32_WINNT=0x601
        -D_WINSOCK_DEPRECATED_NO_WARNINGS
    )
endif()

# General variables
set (PROJECT testjson)

# Extra compiler flags
set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

add_definitions(-D_GLIBCXX_USE_CXX11_ABI)

# Set include directories
include_directories(
    ${CMAKE_SOURCE_DIR}/ext/jsonlib/include
)

# Set source files
set (SOURCES ${CMAKE_CURRENT_SOURCE_DIR}/src/readFromStream.cpp)

add_executable(${PROJECT} ${SOURCES})
link_directories(${CMAKE_SOURCE_DIR}/ext/jsonlib/lib)
target_include_directories(${PROJECT} PUBLIC ${CMAKE_SOURCE_DIR}/ext/jsonlib/include)
target_link_libraries(${PROJECT} jsoncpp)
install (TARGETS ${PROJECT} RUNTIME DESTINATION ${PROJECT_BINARY_DIR}/bin)
# add_custom_target(examples ALL DEPENDS ${EXAMPLES})