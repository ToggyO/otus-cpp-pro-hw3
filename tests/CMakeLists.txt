cmake_minimum_required(VERSION 3.12)

project(allocator.tests)

find_package(GTest REQUIRED)

enable_testing()

file(GLOB_RECURSE TEST_SOURCES LIST_DIRECTORIES false *.h *.cpp)

add_executable(${INSTALL_TARGET} ${TEST_SOURCES})
set_target_properties(${INSTALL_TARGET} PROPERTIES
    CXX_STANDARD 17
    CXX_STANDARD_REQUIRED ON
)
target_include_directories(${INSTALL_TARGET}
    PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/../src
)
target_link_libraries(${INSTALL_TARGET} PUBLIC
    GTest::gtest
    GTest::gtest_main
    ${ALLOCATOR_LIB_BINARY}
)

include(GoogleTest)
gtest_discover_tests(${INSTALL_TARGET})

