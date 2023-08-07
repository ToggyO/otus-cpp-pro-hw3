cmake_minimum_required(VERSION 3.12)

project(alloc_runner)

file(GLOB SOURCES *.cpp allocators/*.cpp allocators/*.h adapters/*.cpp adapters/*.h)

add_executable(run_alloc ${SOURCES})

set_target_properties(run_alloc PROPERTIES
    CXX_STANDARD 17
    CXX_STANDARD_REQUIRED ON
)
