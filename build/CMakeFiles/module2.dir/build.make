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
CMAKE_SOURCE_DIR = /mnt/g/my_programs/DockerC/translit

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /mnt/g/my_programs/DockerC/translit/build

# Include any dependencies generated for this target.
include CMakeFiles/module2.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/module2.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/module2.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/module2.dir/flags.make

CMakeFiles/module2.dir/src/translateTables.cpp.o: CMakeFiles/module2.dir/flags.make
CMakeFiles/module2.dir/src/translateTables.cpp.o: ../src/translateTables.cpp
CMakeFiles/module2.dir/src/translateTables.cpp.o: CMakeFiles/module2.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/mnt/g/my_programs/DockerC/translit/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/module2.dir/src/translateTables.cpp.o"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/module2.dir/src/translateTables.cpp.o -MF CMakeFiles/module2.dir/src/translateTables.cpp.o.d -o CMakeFiles/module2.dir/src/translateTables.cpp.o -c /mnt/g/my_programs/DockerC/translit/src/translateTables.cpp

CMakeFiles/module2.dir/src/translateTables.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/module2.dir/src/translateTables.cpp.i"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /mnt/g/my_programs/DockerC/translit/src/translateTables.cpp > CMakeFiles/module2.dir/src/translateTables.cpp.i

CMakeFiles/module2.dir/src/translateTables.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/module2.dir/src/translateTables.cpp.s"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /mnt/g/my_programs/DockerC/translit/src/translateTables.cpp -o CMakeFiles/module2.dir/src/translateTables.cpp.s

# Object files for target module2
module2_OBJECTS = \
"CMakeFiles/module2.dir/src/translateTables.cpp.o"

# External object files for target module2
module2_EXTERNAL_OBJECTS =

libmodule2.a: CMakeFiles/module2.dir/src/translateTables.cpp.o
libmodule2.a: CMakeFiles/module2.dir/build.make
libmodule2.a: CMakeFiles/module2.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/mnt/g/my_programs/DockerC/translit/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX static library libmodule2.a"
	$(CMAKE_COMMAND) -P CMakeFiles/module2.dir/cmake_clean_target.cmake
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/module2.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/module2.dir/build: libmodule2.a
.PHONY : CMakeFiles/module2.dir/build

CMakeFiles/module2.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/module2.dir/cmake_clean.cmake
.PHONY : CMakeFiles/module2.dir/clean

CMakeFiles/module2.dir/depend:
	cd /mnt/g/my_programs/DockerC/translit/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /mnt/g/my_programs/DockerC/translit /mnt/g/my_programs/DockerC/translit /mnt/g/my_programs/DockerC/translit/build /mnt/g/my_programs/DockerC/translit/build /mnt/g/my_programs/DockerC/translit/build/CMakeFiles/module2.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/module2.dir/depend

