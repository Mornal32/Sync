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
CMAKE_SOURCE_DIR = /home/ubu/workspace/github/Sync

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/ubu/workspace/github/Sync/build

# Include any dependencies generated for this target.
include Sync/CMakeFiles/Sync.dir/depend.make

# Include the progress variables for this target.
include Sync/CMakeFiles/Sync.dir/progress.make

# Include the compile flags for this target's objects.
include Sync/CMakeFiles/Sync.dir/flags.make

Sync/CMakeFiles/Sync.dir/Sync.cpp.o: Sync/CMakeFiles/Sync.dir/flags.make
Sync/CMakeFiles/Sync.dir/Sync.cpp.o: ../Sync/Sync.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ubu/workspace/github/Sync/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object Sync/CMakeFiles/Sync.dir/Sync.cpp.o"
	cd /home/ubu/workspace/github/Sync/build/Sync && /usr/bin/g++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Sync.dir/Sync.cpp.o -c /home/ubu/workspace/github/Sync/Sync/Sync.cpp

Sync/CMakeFiles/Sync.dir/Sync.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Sync.dir/Sync.cpp.i"
	cd /home/ubu/workspace/github/Sync/build/Sync && /usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/ubu/workspace/github/Sync/Sync/Sync.cpp > CMakeFiles/Sync.dir/Sync.cpp.i

Sync/CMakeFiles/Sync.dir/Sync.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Sync.dir/Sync.cpp.s"
	cd /home/ubu/workspace/github/Sync/build/Sync && /usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/ubu/workspace/github/Sync/Sync/Sync.cpp -o CMakeFiles/Sync.dir/Sync.cpp.s

# Object files for target Sync
Sync_OBJECTS = \
"CMakeFiles/Sync.dir/Sync.cpp.o"

# External object files for target Sync
Sync_EXTERNAL_OBJECTS =

Sync/Sync: Sync/CMakeFiles/Sync.dir/Sync.cpp.o
Sync/Sync: Sync/CMakeFiles/Sync.dir/build.make
Sync/Sync: Sync/CMakeFiles/Sync.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/ubu/workspace/github/Sync/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable Sync"
	cd /home/ubu/workspace/github/Sync/build/Sync && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Sync.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
Sync/CMakeFiles/Sync.dir/build: Sync/Sync

.PHONY : Sync/CMakeFiles/Sync.dir/build

Sync/CMakeFiles/Sync.dir/clean:
	cd /home/ubu/workspace/github/Sync/build/Sync && $(CMAKE_COMMAND) -P CMakeFiles/Sync.dir/cmake_clean.cmake
.PHONY : Sync/CMakeFiles/Sync.dir/clean

Sync/CMakeFiles/Sync.dir/depend:
	cd /home/ubu/workspace/github/Sync/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/ubu/workspace/github/Sync /home/ubu/workspace/github/Sync/Sync /home/ubu/workspace/github/Sync/build /home/ubu/workspace/github/Sync/build/Sync /home/ubu/workspace/github/Sync/build/Sync/CMakeFiles/Sync.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : Sync/CMakeFiles/Sync.dir/depend
