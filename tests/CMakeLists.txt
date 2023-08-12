cmake_minimum_required(VERSION 3.12)

project(otus-cpp-pro-hw3.tests)

find_package(GTest REQUIRED)

enable_testing()

file(GLOB_RECURSE TEST_SOURCES LIST_DIRECTORIES false *.h *.cpp)

add_executable(tests ${TEST_SOURCES}
        test_common.cpp)
set_target_properties(tests PROPERTIES
        CXX_STANDARD 17
        CXX_STANDARD_REQUIRED ON
)
target_link_libraries(tests PUBLIC
        GTest::gtest
        GTest::gtest_main
        ${MAIN_BINARY}_lib
)

include(GoogleTest)
gtest_discover_tests(tests)

# TODO: check
#target_include_directories(tests PRIVATE ${CMAKE_SOURCE_DIR}/src)
