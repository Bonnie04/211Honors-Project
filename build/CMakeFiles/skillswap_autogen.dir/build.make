# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.31

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
CMAKE_SOURCE_DIR = /Users/M.Y./Documents/QTProject

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/M.Y./Documents/QTProject/build

# Utility rule file for skillswap_autogen.

# Include any custom commands dependencies for this target.
include CMakeFiles/skillswap_autogen.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/skillswap_autogen.dir/progress.make

CMakeFiles/skillswap_autogen: skillswap_autogen/timestamp

skillswap_autogen/timestamp: /usr/local/share/qt/libexec/moc
skillswap_autogen/timestamp: /usr/local/share/qt/libexec/uic
skillswap_autogen/timestamp: CMakeFiles/skillswap_autogen.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --blue --bold --progress-dir=/Users/M.Y./Documents/QTProject/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Automatic MOC and UIC for target skillswap"
	/usr/local/bin/cmake -E cmake_autogen /Users/M.Y./Documents/QTProject/build/CMakeFiles/skillswap_autogen.dir/AutogenInfo.json ""
	/usr/local/bin/cmake -E touch /Users/M.Y./Documents/QTProject/build/skillswap_autogen/timestamp

CMakeFiles/skillswap_autogen.dir/codegen:
.PHONY : CMakeFiles/skillswap_autogen.dir/codegen

skillswap_autogen: CMakeFiles/skillswap_autogen
skillswap_autogen: skillswap_autogen/timestamp
skillswap_autogen: CMakeFiles/skillswap_autogen.dir/build.make
.PHONY : skillswap_autogen

# Rule to build all files generated by this target.
CMakeFiles/skillswap_autogen.dir/build: skillswap_autogen
.PHONY : CMakeFiles/skillswap_autogen.dir/build

CMakeFiles/skillswap_autogen.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/skillswap_autogen.dir/cmake_clean.cmake
.PHONY : CMakeFiles/skillswap_autogen.dir/clean

CMakeFiles/skillswap_autogen.dir/depend:
	cd /Users/M.Y./Documents/QTProject/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/M.Y./Documents/QTProject /Users/M.Y./Documents/QTProject /Users/M.Y./Documents/QTProject/build /Users/M.Y./Documents/QTProject/build /Users/M.Y./Documents/QTProject/build/CMakeFiles/skillswap_autogen.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : CMakeFiles/skillswap_autogen.dir/depend

