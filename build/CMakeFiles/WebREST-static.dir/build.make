# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.23

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
CMAKE_COMMAND = /usr/local/bin/cmake

# The command to remove a file.
RM = /usr/local/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/sunburst7/桌面/WebREST

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/sunburst7/桌面/WebREST/build

# Include any dependencies generated for this target.
include CMakeFiles/WebREST-static.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/WebREST-static.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/WebREST-static.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/WebREST-static.dir/flags.make

CMakeFiles/WebREST-static.dir/WebREST/base/Thread.cc.o: CMakeFiles/WebREST-static.dir/flags.make
CMakeFiles/WebREST-static.dir/WebREST/base/Thread.cc.o: ../WebREST/base/Thread.cc
CMakeFiles/WebREST-static.dir/WebREST/base/Thread.cc.o: CMakeFiles/WebREST-static.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/sunburst7/桌面/WebREST/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/WebREST-static.dir/WebREST/base/Thread.cc.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/WebREST-static.dir/WebREST/base/Thread.cc.o -MF CMakeFiles/WebREST-static.dir/WebREST/base/Thread.cc.o.d -o CMakeFiles/WebREST-static.dir/WebREST/base/Thread.cc.o -c /home/sunburst7/桌面/WebREST/WebREST/base/Thread.cc

CMakeFiles/WebREST-static.dir/WebREST/base/Thread.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/WebREST-static.dir/WebREST/base/Thread.cc.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/sunburst7/桌面/WebREST/WebREST/base/Thread.cc > CMakeFiles/WebREST-static.dir/WebREST/base/Thread.cc.i

CMakeFiles/WebREST-static.dir/WebREST/base/Thread.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/WebREST-static.dir/WebREST/base/Thread.cc.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/sunburst7/桌面/WebREST/WebREST/base/Thread.cc -o CMakeFiles/WebREST-static.dir/WebREST/base/Thread.cc.s

CMakeFiles/WebREST-static.dir/WebREST/base/buffer.cc.o: CMakeFiles/WebREST-static.dir/flags.make
CMakeFiles/WebREST-static.dir/WebREST/base/buffer.cc.o: ../WebREST/base/buffer.cc
CMakeFiles/WebREST-static.dir/WebREST/base/buffer.cc.o: CMakeFiles/WebREST-static.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/sunburst7/桌面/WebREST/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/WebREST-static.dir/WebREST/base/buffer.cc.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/WebREST-static.dir/WebREST/base/buffer.cc.o -MF CMakeFiles/WebREST-static.dir/WebREST/base/buffer.cc.o.d -o CMakeFiles/WebREST-static.dir/WebREST/base/buffer.cc.o -c /home/sunburst7/桌面/WebREST/WebREST/base/buffer.cc

CMakeFiles/WebREST-static.dir/WebREST/base/buffer.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/WebREST-static.dir/WebREST/base/buffer.cc.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/sunburst7/桌面/WebREST/WebREST/base/buffer.cc > CMakeFiles/WebREST-static.dir/WebREST/base/buffer.cc.i

CMakeFiles/WebREST-static.dir/WebREST/base/buffer.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/WebREST-static.dir/WebREST/base/buffer.cc.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/sunburst7/桌面/WebREST/WebREST/base/buffer.cc -o CMakeFiles/WebREST-static.dir/WebREST/base/buffer.cc.s

CMakeFiles/WebREST-static.dir/WebREST/base/countdown_latch.cc.o: CMakeFiles/WebREST-static.dir/flags.make
CMakeFiles/WebREST-static.dir/WebREST/base/countdown_latch.cc.o: ../WebREST/base/countdown_latch.cc
CMakeFiles/WebREST-static.dir/WebREST/base/countdown_latch.cc.o: CMakeFiles/WebREST-static.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/sunburst7/桌面/WebREST/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/WebREST-static.dir/WebREST/base/countdown_latch.cc.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/WebREST-static.dir/WebREST/base/countdown_latch.cc.o -MF CMakeFiles/WebREST-static.dir/WebREST/base/countdown_latch.cc.o.d -o CMakeFiles/WebREST-static.dir/WebREST/base/countdown_latch.cc.o -c /home/sunburst7/桌面/WebREST/WebREST/base/countdown_latch.cc

CMakeFiles/WebREST-static.dir/WebREST/base/countdown_latch.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/WebREST-static.dir/WebREST/base/countdown_latch.cc.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/sunburst7/桌面/WebREST/WebREST/base/countdown_latch.cc > CMakeFiles/WebREST-static.dir/WebREST/base/countdown_latch.cc.i

CMakeFiles/WebREST-static.dir/WebREST/base/countdown_latch.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/WebREST-static.dir/WebREST/base/countdown_latch.cc.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/sunburst7/桌面/WebREST/WebREST/base/countdown_latch.cc -o CMakeFiles/WebREST-static.dir/WebREST/base/countdown_latch.cc.s

CMakeFiles/WebREST-static.dir/WebREST/base/timestamp.cc.o: CMakeFiles/WebREST-static.dir/flags.make
CMakeFiles/WebREST-static.dir/WebREST/base/timestamp.cc.o: ../WebREST/base/timestamp.cc
CMakeFiles/WebREST-static.dir/WebREST/base/timestamp.cc.o: CMakeFiles/WebREST-static.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/sunburst7/桌面/WebREST/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/WebREST-static.dir/WebREST/base/timestamp.cc.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/WebREST-static.dir/WebREST/base/timestamp.cc.o -MF CMakeFiles/WebREST-static.dir/WebREST/base/timestamp.cc.o.d -o CMakeFiles/WebREST-static.dir/WebREST/base/timestamp.cc.o -c /home/sunburst7/桌面/WebREST/WebREST/base/timestamp.cc

CMakeFiles/WebREST-static.dir/WebREST/base/timestamp.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/WebREST-static.dir/WebREST/base/timestamp.cc.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/sunburst7/桌面/WebREST/WebREST/base/timestamp.cc > CMakeFiles/WebREST-static.dir/WebREST/base/timestamp.cc.i

CMakeFiles/WebREST-static.dir/WebREST/base/timestamp.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/WebREST-static.dir/WebREST/base/timestamp.cc.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/sunburst7/桌面/WebREST/WebREST/base/timestamp.cc -o CMakeFiles/WebREST-static.dir/WebREST/base/timestamp.cc.s

CMakeFiles/WebREST-static.dir/WebREST/core/acceptor.cc.o: CMakeFiles/WebREST-static.dir/flags.make
CMakeFiles/WebREST-static.dir/WebREST/core/acceptor.cc.o: ../WebREST/core/acceptor.cc
CMakeFiles/WebREST-static.dir/WebREST/core/acceptor.cc.o: CMakeFiles/WebREST-static.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/sunburst7/桌面/WebREST/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/WebREST-static.dir/WebREST/core/acceptor.cc.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/WebREST-static.dir/WebREST/core/acceptor.cc.o -MF CMakeFiles/WebREST-static.dir/WebREST/core/acceptor.cc.o.d -o CMakeFiles/WebREST-static.dir/WebREST/core/acceptor.cc.o -c /home/sunburst7/桌面/WebREST/WebREST/core/acceptor.cc

CMakeFiles/WebREST-static.dir/WebREST/core/acceptor.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/WebREST-static.dir/WebREST/core/acceptor.cc.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/sunburst7/桌面/WebREST/WebREST/core/acceptor.cc > CMakeFiles/WebREST-static.dir/WebREST/core/acceptor.cc.i

CMakeFiles/WebREST-static.dir/WebREST/core/acceptor.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/WebREST-static.dir/WebREST/core/acceptor.cc.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/sunburst7/桌面/WebREST/WebREST/core/acceptor.cc -o CMakeFiles/WebREST-static.dir/WebREST/core/acceptor.cc.s

CMakeFiles/WebREST-static.dir/WebREST/core/channel.cc.o: CMakeFiles/WebREST-static.dir/flags.make
CMakeFiles/WebREST-static.dir/WebREST/core/channel.cc.o: ../WebREST/core/channel.cc
CMakeFiles/WebREST-static.dir/WebREST/core/channel.cc.o: CMakeFiles/WebREST-static.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/sunburst7/桌面/WebREST/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object CMakeFiles/WebREST-static.dir/WebREST/core/channel.cc.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/WebREST-static.dir/WebREST/core/channel.cc.o -MF CMakeFiles/WebREST-static.dir/WebREST/core/channel.cc.o.d -o CMakeFiles/WebREST-static.dir/WebREST/core/channel.cc.o -c /home/sunburst7/桌面/WebREST/WebREST/core/channel.cc

CMakeFiles/WebREST-static.dir/WebREST/core/channel.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/WebREST-static.dir/WebREST/core/channel.cc.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/sunburst7/桌面/WebREST/WebREST/core/channel.cc > CMakeFiles/WebREST-static.dir/WebREST/core/channel.cc.i

CMakeFiles/WebREST-static.dir/WebREST/core/channel.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/WebREST-static.dir/WebREST/core/channel.cc.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/sunburst7/桌面/WebREST/WebREST/core/channel.cc -o CMakeFiles/WebREST-static.dir/WebREST/core/channel.cc.s

CMakeFiles/WebREST-static.dir/WebREST/core/epoller.cc.o: CMakeFiles/WebREST-static.dir/flags.make
CMakeFiles/WebREST-static.dir/WebREST/core/epoller.cc.o: ../WebREST/core/epoller.cc
CMakeFiles/WebREST-static.dir/WebREST/core/epoller.cc.o: CMakeFiles/WebREST-static.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/sunburst7/桌面/WebREST/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building CXX object CMakeFiles/WebREST-static.dir/WebREST/core/epoller.cc.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/WebREST-static.dir/WebREST/core/epoller.cc.o -MF CMakeFiles/WebREST-static.dir/WebREST/core/epoller.cc.o.d -o CMakeFiles/WebREST-static.dir/WebREST/core/epoller.cc.o -c /home/sunburst7/桌面/WebREST/WebREST/core/epoller.cc

CMakeFiles/WebREST-static.dir/WebREST/core/epoller.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/WebREST-static.dir/WebREST/core/epoller.cc.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/sunburst7/桌面/WebREST/WebREST/core/epoller.cc > CMakeFiles/WebREST-static.dir/WebREST/core/epoller.cc.i

CMakeFiles/WebREST-static.dir/WebREST/core/epoller.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/WebREST-static.dir/WebREST/core/epoller.cc.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/sunburst7/桌面/WebREST/WebREST/core/epoller.cc -o CMakeFiles/WebREST-static.dir/WebREST/core/epoller.cc.s

CMakeFiles/WebREST-static.dir/WebREST/core/eventloop.cc.o: CMakeFiles/WebREST-static.dir/flags.make
CMakeFiles/WebREST-static.dir/WebREST/core/eventloop.cc.o: ../WebREST/core/eventloop.cc
CMakeFiles/WebREST-static.dir/WebREST/core/eventloop.cc.o: CMakeFiles/WebREST-static.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/sunburst7/桌面/WebREST/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Building CXX object CMakeFiles/WebREST-static.dir/WebREST/core/eventloop.cc.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/WebREST-static.dir/WebREST/core/eventloop.cc.o -MF CMakeFiles/WebREST-static.dir/WebREST/core/eventloop.cc.o.d -o CMakeFiles/WebREST-static.dir/WebREST/core/eventloop.cc.o -c /home/sunburst7/桌面/WebREST/WebREST/core/eventloop.cc

CMakeFiles/WebREST-static.dir/WebREST/core/eventloop.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/WebREST-static.dir/WebREST/core/eventloop.cc.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/sunburst7/桌面/WebREST/WebREST/core/eventloop.cc > CMakeFiles/WebREST-static.dir/WebREST/core/eventloop.cc.i

CMakeFiles/WebREST-static.dir/WebREST/core/eventloop.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/WebREST-static.dir/WebREST/core/eventloop.cc.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/sunburst7/桌面/WebREST/WebREST/core/eventloop.cc -o CMakeFiles/WebREST-static.dir/WebREST/core/eventloop.cc.s

CMakeFiles/WebREST-static.dir/WebREST/core/eventloop_thread.cc.o: CMakeFiles/WebREST-static.dir/flags.make
CMakeFiles/WebREST-static.dir/WebREST/core/eventloop_thread.cc.o: ../WebREST/core/eventloop_thread.cc
CMakeFiles/WebREST-static.dir/WebREST/core/eventloop_thread.cc.o: CMakeFiles/WebREST-static.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/sunburst7/桌面/WebREST/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_9) "Building CXX object CMakeFiles/WebREST-static.dir/WebREST/core/eventloop_thread.cc.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/WebREST-static.dir/WebREST/core/eventloop_thread.cc.o -MF CMakeFiles/WebREST-static.dir/WebREST/core/eventloop_thread.cc.o.d -o CMakeFiles/WebREST-static.dir/WebREST/core/eventloop_thread.cc.o -c /home/sunburst7/桌面/WebREST/WebREST/core/eventloop_thread.cc

CMakeFiles/WebREST-static.dir/WebREST/core/eventloop_thread.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/WebREST-static.dir/WebREST/core/eventloop_thread.cc.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/sunburst7/桌面/WebREST/WebREST/core/eventloop_thread.cc > CMakeFiles/WebREST-static.dir/WebREST/core/eventloop_thread.cc.i

CMakeFiles/WebREST-static.dir/WebREST/core/eventloop_thread.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/WebREST-static.dir/WebREST/core/eventloop_thread.cc.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/sunburst7/桌面/WebREST/WebREST/core/eventloop_thread.cc -o CMakeFiles/WebREST-static.dir/WebREST/core/eventloop_thread.cc.s

CMakeFiles/WebREST-static.dir/WebREST/core/eventloop_thread_pool.cc.o: CMakeFiles/WebREST-static.dir/flags.make
CMakeFiles/WebREST-static.dir/WebREST/core/eventloop_thread_pool.cc.o: ../WebREST/core/eventloop_thread_pool.cc
CMakeFiles/WebREST-static.dir/WebREST/core/eventloop_thread_pool.cc.o: CMakeFiles/WebREST-static.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/sunburst7/桌面/WebREST/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_10) "Building CXX object CMakeFiles/WebREST-static.dir/WebREST/core/eventloop_thread_pool.cc.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/WebREST-static.dir/WebREST/core/eventloop_thread_pool.cc.o -MF CMakeFiles/WebREST-static.dir/WebREST/core/eventloop_thread_pool.cc.o.d -o CMakeFiles/WebREST-static.dir/WebREST/core/eventloop_thread_pool.cc.o -c /home/sunburst7/桌面/WebREST/WebREST/core/eventloop_thread_pool.cc

CMakeFiles/WebREST-static.dir/WebREST/core/eventloop_thread_pool.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/WebREST-static.dir/WebREST/core/eventloop_thread_pool.cc.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/sunburst7/桌面/WebREST/WebREST/core/eventloop_thread_pool.cc > CMakeFiles/WebREST-static.dir/WebREST/core/eventloop_thread_pool.cc.i

CMakeFiles/WebREST-static.dir/WebREST/core/eventloop_thread_pool.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/WebREST-static.dir/WebREST/core/eventloop_thread_pool.cc.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/sunburst7/桌面/WebREST/WebREST/core/eventloop_thread_pool.cc -o CMakeFiles/WebREST-static.dir/WebREST/core/eventloop_thread_pool.cc.s

CMakeFiles/WebREST-static.dir/WebREST/core/http_request.cc.o: CMakeFiles/WebREST-static.dir/flags.make
CMakeFiles/WebREST-static.dir/WebREST/core/http_request.cc.o: ../WebREST/core/http_request.cc
CMakeFiles/WebREST-static.dir/WebREST/core/http_request.cc.o: CMakeFiles/WebREST-static.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/sunburst7/桌面/WebREST/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_11) "Building CXX object CMakeFiles/WebREST-static.dir/WebREST/core/http_request.cc.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/WebREST-static.dir/WebREST/core/http_request.cc.o -MF CMakeFiles/WebREST-static.dir/WebREST/core/http_request.cc.o.d -o CMakeFiles/WebREST-static.dir/WebREST/core/http_request.cc.o -c /home/sunburst7/桌面/WebREST/WebREST/core/http_request.cc

CMakeFiles/WebREST-static.dir/WebREST/core/http_request.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/WebREST-static.dir/WebREST/core/http_request.cc.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/sunburst7/桌面/WebREST/WebREST/core/http_request.cc > CMakeFiles/WebREST-static.dir/WebREST/core/http_request.cc.i

CMakeFiles/WebREST-static.dir/WebREST/core/http_request.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/WebREST-static.dir/WebREST/core/http_request.cc.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/sunburst7/桌面/WebREST/WebREST/core/http_request.cc -o CMakeFiles/WebREST-static.dir/WebREST/core/http_request.cc.s

CMakeFiles/WebREST-static.dir/WebREST/core/http_response.cc.o: CMakeFiles/WebREST-static.dir/flags.make
CMakeFiles/WebREST-static.dir/WebREST/core/http_response.cc.o: ../WebREST/core/http_response.cc
CMakeFiles/WebREST-static.dir/WebREST/core/http_response.cc.o: CMakeFiles/WebREST-static.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/sunburst7/桌面/WebREST/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_12) "Building CXX object CMakeFiles/WebREST-static.dir/WebREST/core/http_response.cc.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/WebREST-static.dir/WebREST/core/http_response.cc.o -MF CMakeFiles/WebREST-static.dir/WebREST/core/http_response.cc.o.d -o CMakeFiles/WebREST-static.dir/WebREST/core/http_response.cc.o -c /home/sunburst7/桌面/WebREST/WebREST/core/http_response.cc

CMakeFiles/WebREST-static.dir/WebREST/core/http_response.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/WebREST-static.dir/WebREST/core/http_response.cc.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/sunburst7/桌面/WebREST/WebREST/core/http_response.cc > CMakeFiles/WebREST-static.dir/WebREST/core/http_response.cc.i

CMakeFiles/WebREST-static.dir/WebREST/core/http_response.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/WebREST-static.dir/WebREST/core/http_response.cc.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/sunburst7/桌面/WebREST/WebREST/core/http_response.cc -o CMakeFiles/WebREST-static.dir/WebREST/core/http_response.cc.s

CMakeFiles/WebREST-static.dir/WebREST/core/inet_address.cc.o: CMakeFiles/WebREST-static.dir/flags.make
CMakeFiles/WebREST-static.dir/WebREST/core/inet_address.cc.o: ../WebREST/core/inet_address.cc
CMakeFiles/WebREST-static.dir/WebREST/core/inet_address.cc.o: CMakeFiles/WebREST-static.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/sunburst7/桌面/WebREST/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_13) "Building CXX object CMakeFiles/WebREST-static.dir/WebREST/core/inet_address.cc.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/WebREST-static.dir/WebREST/core/inet_address.cc.o -MF CMakeFiles/WebREST-static.dir/WebREST/core/inet_address.cc.o.d -o CMakeFiles/WebREST-static.dir/WebREST/core/inet_address.cc.o -c /home/sunburst7/桌面/WebREST/WebREST/core/inet_address.cc

CMakeFiles/WebREST-static.dir/WebREST/core/inet_address.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/WebREST-static.dir/WebREST/core/inet_address.cc.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/sunburst7/桌面/WebREST/WebREST/core/inet_address.cc > CMakeFiles/WebREST-static.dir/WebREST/core/inet_address.cc.i

CMakeFiles/WebREST-static.dir/WebREST/core/inet_address.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/WebREST-static.dir/WebREST/core/inet_address.cc.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/sunburst7/桌面/WebREST/WebREST/core/inet_address.cc -o CMakeFiles/WebREST-static.dir/WebREST/core/inet_address.cc.s

CMakeFiles/WebREST-static.dir/WebREST/core/socket.cc.o: CMakeFiles/WebREST-static.dir/flags.make
CMakeFiles/WebREST-static.dir/WebREST/core/socket.cc.o: ../WebREST/core/socket.cc
CMakeFiles/WebREST-static.dir/WebREST/core/socket.cc.o: CMakeFiles/WebREST-static.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/sunburst7/桌面/WebREST/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_14) "Building CXX object CMakeFiles/WebREST-static.dir/WebREST/core/socket.cc.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/WebREST-static.dir/WebREST/core/socket.cc.o -MF CMakeFiles/WebREST-static.dir/WebREST/core/socket.cc.o.d -o CMakeFiles/WebREST-static.dir/WebREST/core/socket.cc.o -c /home/sunburst7/桌面/WebREST/WebREST/core/socket.cc

CMakeFiles/WebREST-static.dir/WebREST/core/socket.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/WebREST-static.dir/WebREST/core/socket.cc.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/sunburst7/桌面/WebREST/WebREST/core/socket.cc > CMakeFiles/WebREST-static.dir/WebREST/core/socket.cc.i

CMakeFiles/WebREST-static.dir/WebREST/core/socket.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/WebREST-static.dir/WebREST/core/socket.cc.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/sunburst7/桌面/WebREST/WebREST/core/socket.cc -o CMakeFiles/WebREST-static.dir/WebREST/core/socket.cc.s

CMakeFiles/WebREST-static.dir/WebREST/core/tcp_connection.cc.o: CMakeFiles/WebREST-static.dir/flags.make
CMakeFiles/WebREST-static.dir/WebREST/core/tcp_connection.cc.o: ../WebREST/core/tcp_connection.cc
CMakeFiles/WebREST-static.dir/WebREST/core/tcp_connection.cc.o: CMakeFiles/WebREST-static.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/sunburst7/桌面/WebREST/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_15) "Building CXX object CMakeFiles/WebREST-static.dir/WebREST/core/tcp_connection.cc.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/WebREST-static.dir/WebREST/core/tcp_connection.cc.o -MF CMakeFiles/WebREST-static.dir/WebREST/core/tcp_connection.cc.o.d -o CMakeFiles/WebREST-static.dir/WebREST/core/tcp_connection.cc.o -c /home/sunburst7/桌面/WebREST/WebREST/core/tcp_connection.cc

CMakeFiles/WebREST-static.dir/WebREST/core/tcp_connection.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/WebREST-static.dir/WebREST/core/tcp_connection.cc.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/sunburst7/桌面/WebREST/WebREST/core/tcp_connection.cc > CMakeFiles/WebREST-static.dir/WebREST/core/tcp_connection.cc.i

CMakeFiles/WebREST-static.dir/WebREST/core/tcp_connection.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/WebREST-static.dir/WebREST/core/tcp_connection.cc.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/sunburst7/桌面/WebREST/WebREST/core/tcp_connection.cc -o CMakeFiles/WebREST-static.dir/WebREST/core/tcp_connection.cc.s

CMakeFiles/WebREST-static.dir/WebREST/core/tcp_server.cc.o: CMakeFiles/WebREST-static.dir/flags.make
CMakeFiles/WebREST-static.dir/WebREST/core/tcp_server.cc.o: ../WebREST/core/tcp_server.cc
CMakeFiles/WebREST-static.dir/WebREST/core/tcp_server.cc.o: CMakeFiles/WebREST-static.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/sunburst7/桌面/WebREST/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_16) "Building CXX object CMakeFiles/WebREST-static.dir/WebREST/core/tcp_server.cc.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/WebREST-static.dir/WebREST/core/tcp_server.cc.o -MF CMakeFiles/WebREST-static.dir/WebREST/core/tcp_server.cc.o.d -o CMakeFiles/WebREST-static.dir/WebREST/core/tcp_server.cc.o -c /home/sunburst7/桌面/WebREST/WebREST/core/tcp_server.cc

CMakeFiles/WebREST-static.dir/WebREST/core/tcp_server.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/WebREST-static.dir/WebREST/core/tcp_server.cc.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/sunburst7/桌面/WebREST/WebREST/core/tcp_server.cc > CMakeFiles/WebREST-static.dir/WebREST/core/tcp_server.cc.i

CMakeFiles/WebREST-static.dir/WebREST/core/tcp_server.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/WebREST-static.dir/WebREST/core/tcp_server.cc.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/sunburst7/桌面/WebREST/WebREST/core/tcp_server.cc -o CMakeFiles/WebREST-static.dir/WebREST/core/tcp_server.cc.s

CMakeFiles/WebREST-static.dir/WebREST/core/timer.cc.o: CMakeFiles/WebREST-static.dir/flags.make
CMakeFiles/WebREST-static.dir/WebREST/core/timer.cc.o: ../WebREST/core/timer.cc
CMakeFiles/WebREST-static.dir/WebREST/core/timer.cc.o: CMakeFiles/WebREST-static.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/sunburst7/桌面/WebREST/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_17) "Building CXX object CMakeFiles/WebREST-static.dir/WebREST/core/timer.cc.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/WebREST-static.dir/WebREST/core/timer.cc.o -MF CMakeFiles/WebREST-static.dir/WebREST/core/timer.cc.o.d -o CMakeFiles/WebREST-static.dir/WebREST/core/timer.cc.o -c /home/sunburst7/桌面/WebREST/WebREST/core/timer.cc

CMakeFiles/WebREST-static.dir/WebREST/core/timer.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/WebREST-static.dir/WebREST/core/timer.cc.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/sunburst7/桌面/WebREST/WebREST/core/timer.cc > CMakeFiles/WebREST-static.dir/WebREST/core/timer.cc.i

CMakeFiles/WebREST-static.dir/WebREST/core/timer.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/WebREST-static.dir/WebREST/core/timer.cc.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/sunburst7/桌面/WebREST/WebREST/core/timer.cc -o CMakeFiles/WebREST-static.dir/WebREST/core/timer.cc.s

CMakeFiles/WebREST-static.dir/WebREST/core/timer_queue.cc.o: CMakeFiles/WebREST-static.dir/flags.make
CMakeFiles/WebREST-static.dir/WebREST/core/timer_queue.cc.o: ../WebREST/core/timer_queue.cc
CMakeFiles/WebREST-static.dir/WebREST/core/timer_queue.cc.o: CMakeFiles/WebREST-static.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/sunburst7/桌面/WebREST/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_18) "Building CXX object CMakeFiles/WebREST-static.dir/WebREST/core/timer_queue.cc.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/WebREST-static.dir/WebREST/core/timer_queue.cc.o -MF CMakeFiles/WebREST-static.dir/WebREST/core/timer_queue.cc.o.d -o CMakeFiles/WebREST-static.dir/WebREST/core/timer_queue.cc.o -c /home/sunburst7/桌面/WebREST/WebREST/core/timer_queue.cc

CMakeFiles/WebREST-static.dir/WebREST/core/timer_queue.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/WebREST-static.dir/WebREST/core/timer_queue.cc.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/sunburst7/桌面/WebREST/WebREST/core/timer_queue.cc > CMakeFiles/WebREST-static.dir/WebREST/core/timer_queue.cc.i

CMakeFiles/WebREST-static.dir/WebREST/core/timer_queue.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/WebREST-static.dir/WebREST/core/timer_queue.cc.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/sunburst7/桌面/WebREST/WebREST/core/timer_queue.cc -o CMakeFiles/WebREST-static.dir/WebREST/core/timer_queue.cc.s

CMakeFiles/WebREST-static.dir/WebREST/server/echo.cc.o: CMakeFiles/WebREST-static.dir/flags.make
CMakeFiles/WebREST-static.dir/WebREST/server/echo.cc.o: ../WebREST/server/echo.cc
CMakeFiles/WebREST-static.dir/WebREST/server/echo.cc.o: CMakeFiles/WebREST-static.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/sunburst7/桌面/WebREST/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_19) "Building CXX object CMakeFiles/WebREST-static.dir/WebREST/server/echo.cc.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/WebREST-static.dir/WebREST/server/echo.cc.o -MF CMakeFiles/WebREST-static.dir/WebREST/server/echo.cc.o.d -o CMakeFiles/WebREST-static.dir/WebREST/server/echo.cc.o -c /home/sunburst7/桌面/WebREST/WebREST/server/echo.cc

CMakeFiles/WebREST-static.dir/WebREST/server/echo.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/WebREST-static.dir/WebREST/server/echo.cc.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/sunburst7/桌面/WebREST/WebREST/server/echo.cc > CMakeFiles/WebREST-static.dir/WebREST/server/echo.cc.i

CMakeFiles/WebREST-static.dir/WebREST/server/echo.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/WebREST-static.dir/WebREST/server/echo.cc.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/sunburst7/桌面/WebREST/WebREST/server/echo.cc -o CMakeFiles/WebREST-static.dir/WebREST/server/echo.cc.s

CMakeFiles/WebREST-static.dir/WebREST/server/http.cc.o: CMakeFiles/WebREST-static.dir/flags.make
CMakeFiles/WebREST-static.dir/WebREST/server/http.cc.o: ../WebREST/server/http.cc
CMakeFiles/WebREST-static.dir/WebREST/server/http.cc.o: CMakeFiles/WebREST-static.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/sunburst7/桌面/WebREST/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_20) "Building CXX object CMakeFiles/WebREST-static.dir/WebREST/server/http.cc.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/WebREST-static.dir/WebREST/server/http.cc.o -MF CMakeFiles/WebREST-static.dir/WebREST/server/http.cc.o.d -o CMakeFiles/WebREST-static.dir/WebREST/server/http.cc.o -c /home/sunburst7/桌面/WebREST/WebREST/server/http.cc

CMakeFiles/WebREST-static.dir/WebREST/server/http.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/WebREST-static.dir/WebREST/server/http.cc.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/sunburst7/桌面/WebREST/WebREST/server/http.cc > CMakeFiles/WebREST-static.dir/WebREST/server/http.cc.i

CMakeFiles/WebREST-static.dir/WebREST/server/http.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/WebREST-static.dir/WebREST/server/http.cc.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/sunburst7/桌面/WebREST/WebREST/server/http.cc -o CMakeFiles/WebREST-static.dir/WebREST/server/http.cc.s

# Object files for target WebREST-static
WebREST__static_OBJECTS = \
"CMakeFiles/WebREST-static.dir/WebREST/base/Thread.cc.o" \
"CMakeFiles/WebREST-static.dir/WebREST/base/buffer.cc.o" \
"CMakeFiles/WebREST-static.dir/WebREST/base/countdown_latch.cc.o" \
"CMakeFiles/WebREST-static.dir/WebREST/base/timestamp.cc.o" \
"CMakeFiles/WebREST-static.dir/WebREST/core/acceptor.cc.o" \
"CMakeFiles/WebREST-static.dir/WebREST/core/channel.cc.o" \
"CMakeFiles/WebREST-static.dir/WebREST/core/epoller.cc.o" \
"CMakeFiles/WebREST-static.dir/WebREST/core/eventloop.cc.o" \
"CMakeFiles/WebREST-static.dir/WebREST/core/eventloop_thread.cc.o" \
"CMakeFiles/WebREST-static.dir/WebREST/core/eventloop_thread_pool.cc.o" \
"CMakeFiles/WebREST-static.dir/WebREST/core/http_request.cc.o" \
"CMakeFiles/WebREST-static.dir/WebREST/core/http_response.cc.o" \
"CMakeFiles/WebREST-static.dir/WebREST/core/inet_address.cc.o" \
"CMakeFiles/WebREST-static.dir/WebREST/core/socket.cc.o" \
"CMakeFiles/WebREST-static.dir/WebREST/core/tcp_connection.cc.o" \
"CMakeFiles/WebREST-static.dir/WebREST/core/tcp_server.cc.o" \
"CMakeFiles/WebREST-static.dir/WebREST/core/timer.cc.o" \
"CMakeFiles/WebREST-static.dir/WebREST/core/timer_queue.cc.o" \
"CMakeFiles/WebREST-static.dir/WebREST/server/echo.cc.o" \
"CMakeFiles/WebREST-static.dir/WebREST/server/http.cc.o"

# External object files for target WebREST-static
WebREST__static_EXTERNAL_OBJECTS =

lib/libWebREST-static.a: CMakeFiles/WebREST-static.dir/WebREST/base/Thread.cc.o
lib/libWebREST-static.a: CMakeFiles/WebREST-static.dir/WebREST/base/buffer.cc.o
lib/libWebREST-static.a: CMakeFiles/WebREST-static.dir/WebREST/base/countdown_latch.cc.o
lib/libWebREST-static.a: CMakeFiles/WebREST-static.dir/WebREST/base/timestamp.cc.o
lib/libWebREST-static.a: CMakeFiles/WebREST-static.dir/WebREST/core/acceptor.cc.o
lib/libWebREST-static.a: CMakeFiles/WebREST-static.dir/WebREST/core/channel.cc.o
lib/libWebREST-static.a: CMakeFiles/WebREST-static.dir/WebREST/core/epoller.cc.o
lib/libWebREST-static.a: CMakeFiles/WebREST-static.dir/WebREST/core/eventloop.cc.o
lib/libWebREST-static.a: CMakeFiles/WebREST-static.dir/WebREST/core/eventloop_thread.cc.o
lib/libWebREST-static.a: CMakeFiles/WebREST-static.dir/WebREST/core/eventloop_thread_pool.cc.o
lib/libWebREST-static.a: CMakeFiles/WebREST-static.dir/WebREST/core/http_request.cc.o
lib/libWebREST-static.a: CMakeFiles/WebREST-static.dir/WebREST/core/http_response.cc.o
lib/libWebREST-static.a: CMakeFiles/WebREST-static.dir/WebREST/core/inet_address.cc.o
lib/libWebREST-static.a: CMakeFiles/WebREST-static.dir/WebREST/core/socket.cc.o
lib/libWebREST-static.a: CMakeFiles/WebREST-static.dir/WebREST/core/tcp_connection.cc.o
lib/libWebREST-static.a: CMakeFiles/WebREST-static.dir/WebREST/core/tcp_server.cc.o
lib/libWebREST-static.a: CMakeFiles/WebREST-static.dir/WebREST/core/timer.cc.o
lib/libWebREST-static.a: CMakeFiles/WebREST-static.dir/WebREST/core/timer_queue.cc.o
lib/libWebREST-static.a: CMakeFiles/WebREST-static.dir/WebREST/server/echo.cc.o
lib/libWebREST-static.a: CMakeFiles/WebREST-static.dir/WebREST/server/http.cc.o
lib/libWebREST-static.a: CMakeFiles/WebREST-static.dir/build.make
lib/libWebREST-static.a: CMakeFiles/WebREST-static.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/sunburst7/桌面/WebREST/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_21) "Linking CXX static library lib/libWebREST-static.a"
	$(CMAKE_COMMAND) -P CMakeFiles/WebREST-static.dir/cmake_clean_target.cmake
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/WebREST-static.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/WebREST-static.dir/build: lib/libWebREST-static.a
.PHONY : CMakeFiles/WebREST-static.dir/build

CMakeFiles/WebREST-static.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/WebREST-static.dir/cmake_clean.cmake
.PHONY : CMakeFiles/WebREST-static.dir/clean

CMakeFiles/WebREST-static.dir/depend:
	cd /home/sunburst7/桌面/WebREST/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/sunburst7/桌面/WebREST /home/sunburst7/桌面/WebREST /home/sunburst7/桌面/WebREST/build /home/sunburst7/桌面/WebREST/build /home/sunburst7/桌面/WebREST/build/CMakeFiles/WebREST-static.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/WebREST-static.dir/depend

