# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.22

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:

#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:

# Disable VCS-based implicit rules.
% : %,v

# Disable VCS-based implicit rules.
% : RCS/%

# Disable VCS-based implicit rules.
% : RCS/%,v

# Disable VCS-based implicit rules.
% : SCCS/s.%

# Disable VCS-based implicit rules.
% : s.%

.SUFFIXES: .hpux_make_needs_suffix_list

# Command-line flag to silence nested $(MAKE).
$(VERBOSE)MAKESILENT = -s

#Suppress display of executed commands.
$(VERBOSE).SILENT:

# A target that is always out of date.
cmake_force:
.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/oleg-togushakov/Projects/plusplus/otus-pro/hw/otus-cpp-pro-hw3

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/oleg-togushakov/Projects/plusplus/otus-pro/hw/otus-cpp-pro-hw3/build

# Include any dependencies generated for this target.
include src/CMakeFiles/otus-cpp-pro-hw3.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include src/CMakeFiles/otus-cpp-pro-hw3.dir/compiler_depend.make

# Include the progress variables for this target.
include src/CMakeFiles/otus-cpp-pro-hw3.dir/progress.make

# Include the compile flags for this target's objects.
include src/CMakeFiles/otus-cpp-pro-hw3.dir/flags.make

src/CMakeFiles/otus-cpp-pro-hw3.dir/allocators/mallocator.cpp.o: src/CMakeFiles/otus-cpp-pro-hw3.dir/flags.make
src/CMakeFiles/otus-cpp-pro-hw3.dir/allocators/mallocator.cpp.o: ../src/allocators/mallocator.cpp
src/CMakeFiles/otus-cpp-pro-hw3.dir/allocators/mallocator.cpp.o: src/CMakeFiles/otus-cpp-pro-hw3.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/oleg-togushakov/Projects/plusplus/otus-pro/hw/otus-cpp-pro-hw3/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object src/CMakeFiles/otus-cpp-pro-hw3.dir/allocators/mallocator.cpp.o"
	cd /home/oleg-togushakov/Projects/plusplus/otus-pro/hw/otus-cpp-pro-hw3/build/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT src/CMakeFiles/otus-cpp-pro-hw3.dir/allocators/mallocator.cpp.o -MF CMakeFiles/otus-cpp-pro-hw3.dir/allocators/mallocator.cpp.o.d -o CMakeFiles/otus-cpp-pro-hw3.dir/allocators/mallocator.cpp.o -c /home/oleg-togushakov/Projects/plusplus/otus-pro/hw/otus-cpp-pro-hw3/src/allocators/mallocator.cpp

src/CMakeFiles/otus-cpp-pro-hw3.dir/allocators/mallocator.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/otus-cpp-pro-hw3.dir/allocators/mallocator.cpp.i"
	cd /home/oleg-togushakov/Projects/plusplus/otus-pro/hw/otus-cpp-pro-hw3/build/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/oleg-togushakov/Projects/plusplus/otus-pro/hw/otus-cpp-pro-hw3/src/allocators/mallocator.cpp > CMakeFiles/otus-cpp-pro-hw3.dir/allocators/mallocator.cpp.i

src/CMakeFiles/otus-cpp-pro-hw3.dir/allocators/mallocator.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/otus-cpp-pro-hw3.dir/allocators/mallocator.cpp.s"
	cd /home/oleg-togushakov/Projects/plusplus/otus-pro/hw/otus-cpp-pro-hw3/build/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/oleg-togushakov/Projects/plusplus/otus-pro/hw/otus-cpp-pro-hw3/src/allocators/mallocator.cpp -o CMakeFiles/otus-cpp-pro-hw3.dir/allocators/mallocator.cpp.s

src/CMakeFiles/otus-cpp-pro-hw3.dir/main.cpp.o: src/CMakeFiles/otus-cpp-pro-hw3.dir/flags.make
src/CMakeFiles/otus-cpp-pro-hw3.dir/main.cpp.o: ../src/main.cpp
src/CMakeFiles/otus-cpp-pro-hw3.dir/main.cpp.o: src/CMakeFiles/otus-cpp-pro-hw3.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/oleg-togushakov/Projects/plusplus/otus-pro/hw/otus-cpp-pro-hw3/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object src/CMakeFiles/otus-cpp-pro-hw3.dir/main.cpp.o"
	cd /home/oleg-togushakov/Projects/plusplus/otus-pro/hw/otus-cpp-pro-hw3/build/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT src/CMakeFiles/otus-cpp-pro-hw3.dir/main.cpp.o -MF CMakeFiles/otus-cpp-pro-hw3.dir/main.cpp.o.d -o CMakeFiles/otus-cpp-pro-hw3.dir/main.cpp.o -c /home/oleg-togushakov/Projects/plusplus/otus-pro/hw/otus-cpp-pro-hw3/src/main.cpp

src/CMakeFiles/otus-cpp-pro-hw3.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/otus-cpp-pro-hw3.dir/main.cpp.i"
	cd /home/oleg-togushakov/Projects/plusplus/otus-pro/hw/otus-cpp-pro-hw3/build/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/oleg-togushakov/Projects/plusplus/otus-pro/hw/otus-cpp-pro-hw3/src/main.cpp > CMakeFiles/otus-cpp-pro-hw3.dir/main.cpp.i

src/CMakeFiles/otus-cpp-pro-hw3.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/otus-cpp-pro-hw3.dir/main.cpp.s"
	cd /home/oleg-togushakov/Projects/plusplus/otus-pro/hw/otus-cpp-pro-hw3/build/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/oleg-togushakov/Projects/plusplus/otus-pro/hw/otus-cpp-pro-hw3/src/main.cpp -o CMakeFiles/otus-cpp-pro-hw3.dir/main.cpp.s

src/CMakeFiles/otus-cpp-pro-hw3.dir/utils/utils.cpp.o: src/CMakeFiles/otus-cpp-pro-hw3.dir/flags.make
src/CMakeFiles/otus-cpp-pro-hw3.dir/utils/utils.cpp.o: ../src/utils/utils.cpp
src/CMakeFiles/otus-cpp-pro-hw3.dir/utils/utils.cpp.o: src/CMakeFiles/otus-cpp-pro-hw3.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/oleg-togushakov/Projects/plusplus/otus-pro/hw/otus-cpp-pro-hw3/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object src/CMakeFiles/otus-cpp-pro-hw3.dir/utils/utils.cpp.o"
	cd /home/oleg-togushakov/Projects/plusplus/otus-pro/hw/otus-cpp-pro-hw3/build/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT src/CMakeFiles/otus-cpp-pro-hw3.dir/utils/utils.cpp.o -MF CMakeFiles/otus-cpp-pro-hw3.dir/utils/utils.cpp.o.d -o CMakeFiles/otus-cpp-pro-hw3.dir/utils/utils.cpp.o -c /home/oleg-togushakov/Projects/plusplus/otus-pro/hw/otus-cpp-pro-hw3/src/utils/utils.cpp

src/CMakeFiles/otus-cpp-pro-hw3.dir/utils/utils.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/otus-cpp-pro-hw3.dir/utils/utils.cpp.i"
	cd /home/oleg-togushakov/Projects/plusplus/otus-pro/hw/otus-cpp-pro-hw3/build/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/oleg-togushakov/Projects/plusplus/otus-pro/hw/otus-cpp-pro-hw3/src/utils/utils.cpp > CMakeFiles/otus-cpp-pro-hw3.dir/utils/utils.cpp.i

src/CMakeFiles/otus-cpp-pro-hw3.dir/utils/utils.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/otus-cpp-pro-hw3.dir/utils/utils.cpp.s"
	cd /home/oleg-togushakov/Projects/plusplus/otus-pro/hw/otus-cpp-pro-hw3/build/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/oleg-togushakov/Projects/plusplus/otus-pro/hw/otus-cpp-pro-hw3/src/utils/utils.cpp -o CMakeFiles/otus-cpp-pro-hw3.dir/utils/utils.cpp.s

# Object files for target otus-cpp-pro-hw3
otus__cpp__pro__hw3_OBJECTS = \
"CMakeFiles/otus-cpp-pro-hw3.dir/allocators/mallocator.cpp.o" \
"CMakeFiles/otus-cpp-pro-hw3.dir/main.cpp.o" \
"CMakeFiles/otus-cpp-pro-hw3.dir/utils/utils.cpp.o"

# External object files for target otus-cpp-pro-hw3
otus__cpp__pro__hw3_EXTERNAL_OBJECTS =

src/otus-cpp-pro-hw3: src/CMakeFiles/otus-cpp-pro-hw3.dir/allocators/mallocator.cpp.o
src/otus-cpp-pro-hw3: src/CMakeFiles/otus-cpp-pro-hw3.dir/main.cpp.o
src/otus-cpp-pro-hw3: src/CMakeFiles/otus-cpp-pro-hw3.dir/utils/utils.cpp.o
src/otus-cpp-pro-hw3: src/CMakeFiles/otus-cpp-pro-hw3.dir/build.make
src/otus-cpp-pro-hw3: src/CMakeFiles/otus-cpp-pro-hw3.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/oleg-togushakov/Projects/plusplus/otus-pro/hw/otus-cpp-pro-hw3/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Linking CXX executable otus-cpp-pro-hw3"
	cd /home/oleg-togushakov/Projects/plusplus/otus-pro/hw/otus-cpp-pro-hw3/build/src && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/otus-cpp-pro-hw3.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
src/CMakeFiles/otus-cpp-pro-hw3.dir/build: src/otus-cpp-pro-hw3
.PHONY : src/CMakeFiles/otus-cpp-pro-hw3.dir/build

src/CMakeFiles/otus-cpp-pro-hw3.dir/clean:
	cd /home/oleg-togushakov/Projects/plusplus/otus-pro/hw/otus-cpp-pro-hw3/build/src && $(CMAKE_COMMAND) -P CMakeFiles/otus-cpp-pro-hw3.dir/cmake_clean.cmake
.PHONY : src/CMakeFiles/otus-cpp-pro-hw3.dir/clean

src/CMakeFiles/otus-cpp-pro-hw3.dir/depend:
	cd /home/oleg-togushakov/Projects/plusplus/otus-pro/hw/otus-cpp-pro-hw3/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/oleg-togushakov/Projects/plusplus/otus-pro/hw/otus-cpp-pro-hw3 /home/oleg-togushakov/Projects/plusplus/otus-pro/hw/otus-cpp-pro-hw3/src /home/oleg-togushakov/Projects/plusplus/otus-pro/hw/otus-cpp-pro-hw3/build /home/oleg-togushakov/Projects/plusplus/otus-pro/hw/otus-cpp-pro-hw3/build/src /home/oleg-togushakov/Projects/plusplus/otus-pro/hw/otus-cpp-pro-hw3/build/src/CMakeFiles/otus-cpp-pro-hw3.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : src/CMakeFiles/otus-cpp-pro-hw3.dir/depend

