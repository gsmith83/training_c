# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.2

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
CMAKE_SOURCE_DIR = /home/gsmith/prototypes_tutorials/enqueue

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/gsmith/prototypes_tutorials/enqueue/build

# Include any dependencies generated for this target.
include CMakeFiles/testEnqueue.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/testEnqueue.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/testEnqueue.dir/flags.make

CMakeFiles/testEnqueue.dir/enqueueTest.c.o: CMakeFiles/testEnqueue.dir/flags.make
CMakeFiles/testEnqueue.dir/enqueueTest.c.o: ../enqueueTest.c
	$(CMAKE_COMMAND) -E cmake_progress_report /home/gsmith/prototypes_tutorials/enqueue/build/CMakeFiles $(CMAKE_PROGRESS_1)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building C object CMakeFiles/testEnqueue.dir/enqueueTest.c.o"
	/usr/bin/cc  $(C_DEFINES) $(C_FLAGS) -o CMakeFiles/testEnqueue.dir/enqueueTest.c.o   -c /home/gsmith/prototypes_tutorials/enqueue/enqueueTest.c

CMakeFiles/testEnqueue.dir/enqueueTest.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/testEnqueue.dir/enqueueTest.c.i"
	/usr/bin/cc  $(C_DEFINES) $(C_FLAGS) -E /home/gsmith/prototypes_tutorials/enqueue/enqueueTest.c > CMakeFiles/testEnqueue.dir/enqueueTest.c.i

CMakeFiles/testEnqueue.dir/enqueueTest.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/testEnqueue.dir/enqueueTest.c.s"
	/usr/bin/cc  $(C_DEFINES) $(C_FLAGS) -S /home/gsmith/prototypes_tutorials/enqueue/enqueueTest.c -o CMakeFiles/testEnqueue.dir/enqueueTest.c.s

CMakeFiles/testEnqueue.dir/enqueueTest.c.o.requires:
.PHONY : CMakeFiles/testEnqueue.dir/enqueueTest.c.o.requires

CMakeFiles/testEnqueue.dir/enqueueTest.c.o.provides: CMakeFiles/testEnqueue.dir/enqueueTest.c.o.requires
	$(MAKE) -f CMakeFiles/testEnqueue.dir/build.make CMakeFiles/testEnqueue.dir/enqueueTest.c.o.provides.build
.PHONY : CMakeFiles/testEnqueue.dir/enqueueTest.c.o.provides

CMakeFiles/testEnqueue.dir/enqueueTest.c.o.provides.build: CMakeFiles/testEnqueue.dir/enqueueTest.c.o

# Object files for target testEnqueue
testEnqueue_OBJECTS = \
"CMakeFiles/testEnqueue.dir/enqueueTest.c.o"

# External object files for target testEnqueue
testEnqueue_EXTERNAL_OBJECTS =

testEnqueue: CMakeFiles/testEnqueue.dir/enqueueTest.c.o
testEnqueue: CMakeFiles/testEnqueue.dir/build.make
testEnqueue: /home/gsmith/core-c/prefix/lib/libdof-oal.so.7.0
testEnqueue: /home/gsmith/core-c/prefix/lib/libdof-pcr.so.2.0
testEnqueue: /home/gsmith/core-c/prefix/lib/libdof-inet.so.2.0
testEnqueue: CMakeFiles/testEnqueue.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --red --bold "Linking C executable testEnqueue"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/testEnqueue.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/testEnqueue.dir/build: testEnqueue
.PHONY : CMakeFiles/testEnqueue.dir/build

CMakeFiles/testEnqueue.dir/requires: CMakeFiles/testEnqueue.dir/enqueueTest.c.o.requires
.PHONY : CMakeFiles/testEnqueue.dir/requires

CMakeFiles/testEnqueue.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/testEnqueue.dir/cmake_clean.cmake
.PHONY : CMakeFiles/testEnqueue.dir/clean

CMakeFiles/testEnqueue.dir/depend:
	cd /home/gsmith/prototypes_tutorials/enqueue/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/gsmith/prototypes_tutorials/enqueue /home/gsmith/prototypes_tutorials/enqueue /home/gsmith/prototypes_tutorials/enqueue/build /home/gsmith/prototypes_tutorials/enqueue/build /home/gsmith/prototypes_tutorials/enqueue/build/CMakeFiles/testEnqueue.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/testEnqueue.dir/depend

