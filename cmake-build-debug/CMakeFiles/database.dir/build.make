# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.6

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
CMAKE_COMMAND = /home/ykd/clion-2016.2.2/bin/cmake/bin/cmake

# The command to remove a file.
RM = /home/ykd/clion-2016.2.2/bin/cmake/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/ykd/database

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/ykd/database/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/database.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/database.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/database.dir/flags.make

CMakeFiles/database.dir/filesystem/testfilesystem.cpp.o: CMakeFiles/database.dir/flags.make
CMakeFiles/database.dir/filesystem/testfilesystem.cpp.o: ../filesystem/testfilesystem.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ykd/database/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/database.dir/filesystem/testfilesystem.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/database.dir/filesystem/testfilesystem.cpp.o -c /home/ykd/database/filesystem/testfilesystem.cpp

CMakeFiles/database.dir/filesystem/testfilesystem.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/database.dir/filesystem/testfilesystem.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/ykd/database/filesystem/testfilesystem.cpp > CMakeFiles/database.dir/filesystem/testfilesystem.cpp.i

CMakeFiles/database.dir/filesystem/testfilesystem.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/database.dir/filesystem/testfilesystem.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/ykd/database/filesystem/testfilesystem.cpp -o CMakeFiles/database.dir/filesystem/testfilesystem.cpp.s

CMakeFiles/database.dir/filesystem/testfilesystem.cpp.o.requires:

.PHONY : CMakeFiles/database.dir/filesystem/testfilesystem.cpp.o.requires

CMakeFiles/database.dir/filesystem/testfilesystem.cpp.o.provides: CMakeFiles/database.dir/filesystem/testfilesystem.cpp.o.requires
	$(MAKE) -f CMakeFiles/database.dir/build.make CMakeFiles/database.dir/filesystem/testfilesystem.cpp.o.provides.build
.PHONY : CMakeFiles/database.dir/filesystem/testfilesystem.cpp.o.provides

CMakeFiles/database.dir/filesystem/testfilesystem.cpp.o.provides.build: CMakeFiles/database.dir/filesystem/testfilesystem.cpp.o


# Object files for target database
database_OBJECTS = \
"CMakeFiles/database.dir/filesystem/testfilesystem.cpp.o"

# External object files for target database
database_EXTERNAL_OBJECTS =

database: CMakeFiles/database.dir/filesystem/testfilesystem.cpp.o
database: CMakeFiles/database.dir/build.make
database: CMakeFiles/database.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/ykd/database/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable database"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/database.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/database.dir/build: database

.PHONY : CMakeFiles/database.dir/build

CMakeFiles/database.dir/requires: CMakeFiles/database.dir/filesystem/testfilesystem.cpp.o.requires

.PHONY : CMakeFiles/database.dir/requires

CMakeFiles/database.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/database.dir/cmake_clean.cmake
.PHONY : CMakeFiles/database.dir/clean

CMakeFiles/database.dir/depend:
	cd /home/ykd/database/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/ykd/database /home/ykd/database /home/ykd/database/cmake-build-debug /home/ykd/database/cmake-build-debug /home/ykd/database/cmake-build-debug/CMakeFiles/database.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/database.dir/depend
