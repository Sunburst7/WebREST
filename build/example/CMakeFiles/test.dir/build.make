# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.16

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Remove some rules from gmake that .SUFFIXES does not remove.
SUFFIXES =

.SUFFIXES: .hpux_make_needs_suffix_list


# Suppress display of executed commands.
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
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/sunburst7/Desktop/WebREST

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/sunburst7/Desktop/WebREST/build

# Include any dependencies generated for this target.
include example/CMakeFiles/test.dir/depend.make

# Include the progress variables for this target.
include example/CMakeFiles/test.dir/progress.make

# Include the compile flags for this target's objects.
include example/CMakeFiles/test.dir/flags.make

example/CMakeFiles/test.dir/test.cc.o: example/CMakeFiles/test.dir/flags.make
example/CMakeFiles/test.dir/test.cc.o: ../example/test.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/sunburst7/Desktop/WebREST/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object example/CMakeFiles/test.dir/test.cc.o"
	cd /home/sunburst7/Desktop/WebREST/build/example && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/test.dir/test.cc.o -c /home/sunburst7/Desktop/WebREST/example/test.cc

example/CMakeFiles/test.dir/test.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/test.dir/test.cc.i"
	cd /home/sunburst7/Desktop/WebREST/build/example && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/sunburst7/Desktop/WebREST/example/test.cc > CMakeFiles/test.dir/test.cc.i

example/CMakeFiles/test.dir/test.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/test.dir/test.cc.s"
	cd /home/sunburst7/Desktop/WebREST/build/example && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/sunburst7/Desktop/WebREST/example/test.cc -o CMakeFiles/test.dir/test.cc.s

# Object files for target test
test_OBJECTS = \
"CMakeFiles/test.dir/test.cc.o"

# External object files for target test
test_EXTERNAL_OBJECTS =

bin/test: example/CMakeFiles/test.dir/test.cc.o
bin/test: example/CMakeFiles/test.dir/build.make
bin/test: lib/liblightserver-static.a
bin/test: example/CMakeFiles/test.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/sunburst7/Desktop/WebREST/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable ../bin/test"
	cd /home/sunburst7/Desktop/WebREST/build/example && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/test.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
example/CMakeFiles/test.dir/build: bin/test

.PHONY : example/CMakeFiles/test.dir/build

example/CMakeFiles/test.dir/clean:
	cd /home/sunburst7/Desktop/WebREST/build/example && $(CMAKE_COMMAND) -P CMakeFiles/test.dir/cmake_clean.cmake
.PHONY : example/CMakeFiles/test.dir/clean

example/CMakeFiles/test.dir/depend:
	cd /home/sunburst7/Desktop/WebREST/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/sunburst7/Desktop/WebREST /home/sunburst7/Desktop/WebREST/example /home/sunburst7/Desktop/WebREST/build /home/sunburst7/Desktop/WebREST/build/example /home/sunburst7/Desktop/WebREST/build/example/CMakeFiles/test.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : example/CMakeFiles/test.dir/depend

