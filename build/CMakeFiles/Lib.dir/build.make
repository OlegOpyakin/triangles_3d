# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.25

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
CMAKE_SOURCE_DIR = /home/user/Документы/GitHub/triangles_3d

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/user/Документы/GitHub/triangles_3d/build

# Include any dependencies generated for this target.
include CMakeFiles/Lib.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/Lib.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/Lib.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Lib.dir/flags.make

CMakeFiles/Lib.dir/src/main.cc.o: CMakeFiles/Lib.dir/flags.make
CMakeFiles/Lib.dir/src/main.cc.o: /home/user/Документы/GitHub/triangles_3d/src/main.cc
CMakeFiles/Lib.dir/src/main.cc.o: CMakeFiles/Lib.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/user/Документы/GitHub/triangles_3d/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Lib.dir/src/main.cc.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/Lib.dir/src/main.cc.o -MF CMakeFiles/Lib.dir/src/main.cc.o.d -o CMakeFiles/Lib.dir/src/main.cc.o -c /home/user/Документы/GitHub/triangles_3d/src/main.cc

CMakeFiles/Lib.dir/src/main.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Lib.dir/src/main.cc.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/user/Документы/GitHub/triangles_3d/src/main.cc > CMakeFiles/Lib.dir/src/main.cc.i

CMakeFiles/Lib.dir/src/main.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Lib.dir/src/main.cc.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/user/Документы/GitHub/triangles_3d/src/main.cc -o CMakeFiles/Lib.dir/src/main.cc.s

# Object files for target Lib
Lib_OBJECTS = \
"CMakeFiles/Lib.dir/src/main.cc.o"

# External object files for target Lib
Lib_EXTERNAL_OBJECTS =

libLib.so: CMakeFiles/Lib.dir/src/main.cc.o
libLib.so: CMakeFiles/Lib.dir/build.make
libLib.so: CMakeFiles/Lib.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/user/Документы/GitHub/triangles_3d/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX shared library libLib.so"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Lib.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Lib.dir/build: libLib.so
.PHONY : CMakeFiles/Lib.dir/build

CMakeFiles/Lib.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/Lib.dir/cmake_clean.cmake
.PHONY : CMakeFiles/Lib.dir/clean

CMakeFiles/Lib.dir/depend:
	cd /home/user/Документы/GitHub/triangles_3d/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/user/Документы/GitHub/triangles_3d /home/user/Документы/GitHub/triangles_3d /home/user/Документы/GitHub/triangles_3d/build /home/user/Документы/GitHub/triangles_3d/build /home/user/Документы/GitHub/triangles_3d/build/CMakeFiles/Lib.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/Lib.dir/depend

