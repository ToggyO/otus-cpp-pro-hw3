if(EXISTS "/home/oleg-togushakov/Projects/plusplus/otus-pro/hw/otus-cpp-pro-hw3/build_debug/tests/tests[1]_tests.cmake")
  include("/home/oleg-togushakov/Projects/plusplus/otus-pro/hw/otus-cpp-pro-hw3/build_debug/tests/tests[1]_tests.cmake")
else()
  add_test(tests_NOT_BUILT tests_NOT_BUILT)
endif()
