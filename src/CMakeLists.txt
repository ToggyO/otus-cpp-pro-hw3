cmake_minimum_required(VERSION 3.12)

project(alloc_runner)

set(MAIN_BINARY ${CMAKE_PROJECT_NAME} CACHE INTERNAL "")

file(GLOB_RECURSE SOURCES LIST_DIRECTORIES true *.h *.cpp)

add_executable(${MAIN_BINARY} ${SOURCES})
set_target_properties(${MAIN_BINARY} PROPERTIES
    CXX_STANDARD 17
    CXX_STANDARD_REQUIRED ON
)

add_library(${MAIN_BINARY}_lib STATIC ${SOURCES})
