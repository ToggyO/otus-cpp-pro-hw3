cmake_minimum_required(VERSION 3.12)

project(otus-cpp-pro-hw3)

if (CMAKE_BUILD_TYPE MATCHES Debug)
    add_definitions(-DDEBUG)
endif()

include_directories(src)

add_subdirectory(src)
add_subdirectory(tests)
