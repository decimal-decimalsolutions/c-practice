# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.13

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
CMAKE_COMMAND = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake

# The command to remove a file.
RM = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/pankaj/CProjects/mp_traversals

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/pankaj/CProjects/mp_traversals/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/mp_traversals.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/mp_traversals.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/mp_traversals.dir/flags.make

CMakeFiles/mp_traversals.dir/main.cpp.o: CMakeFiles/mp_traversals.dir/flags.make
CMakeFiles/mp_traversals.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/pankaj/CProjects/mp_traversals/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/mp_traversals.dir/main.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/mp_traversals.dir/main.cpp.o -c /Users/pankaj/CProjects/mp_traversals/main.cpp

CMakeFiles/mp_traversals.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/mp_traversals.dir/main.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/pankaj/CProjects/mp_traversals/main.cpp > CMakeFiles/mp_traversals.dir/main.cpp.i

CMakeFiles/mp_traversals.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/mp_traversals.dir/main.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/pankaj/CProjects/mp_traversals/main.cpp -o CMakeFiles/mp_traversals.dir/main.cpp.s

# Object files for target mp_traversals
mp_traversals_OBJECTS = \
"CMakeFiles/mp_traversals.dir/main.cpp.o"

# External object files for target mp_traversals
mp_traversals_EXTERNAL_OBJECTS =

mp_traversals: CMakeFiles/mp_traversals.dir/main.cpp.o
mp_traversals: CMakeFiles/mp_traversals.dir/build.make
mp_traversals: CMakeFiles/mp_traversals.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/pankaj/CProjects/mp_traversals/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable mp_traversals"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/mp_traversals.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/mp_traversals.dir/build: mp_traversals

.PHONY : CMakeFiles/mp_traversals.dir/build

CMakeFiles/mp_traversals.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/mp_traversals.dir/cmake_clean.cmake
.PHONY : CMakeFiles/mp_traversals.dir/clean

CMakeFiles/mp_traversals.dir/depend:
	cd /Users/pankaj/CProjects/mp_traversals/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/pankaj/CProjects/mp_traversals /Users/pankaj/CProjects/mp_traversals /Users/pankaj/CProjects/mp_traversals/cmake-build-debug /Users/pankaj/CProjects/mp_traversals/cmake-build-debug /Users/pankaj/CProjects/mp_traversals/cmake-build-debug/CMakeFiles/mp_traversals.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/mp_traversals.dir/depend

