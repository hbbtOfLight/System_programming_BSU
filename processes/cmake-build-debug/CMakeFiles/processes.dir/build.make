# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.20

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

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "C:\Program Files\JetBrains\CLion 2020.2.4\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\JetBrains\CLion 2020.2.4\bin\cmake\win\bin\cmake.exe" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = D:\Clion_proga\SP\processes

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = D:\Clion_proga\SP\processes\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/processes.dir/depend.make
# Include the progress variables for this target.
include CMakeFiles/processes.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/processes.dir/flags.make

CMakeFiles/processes.dir/main.c.obj: CMakeFiles/processes.dir/flags.make
CMakeFiles/processes.dir/main.c.obj: ../main.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=D:\Clion_proga\SP\processes\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/processes.dir/main.c.obj"
	C:\PROGRA~2\MINGW-~1\I686-8~1.0-P\mingw32\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles\processes.dir\main.c.obj -c D:\Clion_proga\SP\processes\main.c

CMakeFiles/processes.dir/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/processes.dir/main.c.i"
	C:\PROGRA~2\MINGW-~1\I686-8~1.0-P\mingw32\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E D:\Clion_proga\SP\processes\main.c > CMakeFiles\processes.dir\main.c.i

CMakeFiles/processes.dir/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/processes.dir/main.c.s"
	C:\PROGRA~2\MINGW-~1\I686-8~1.0-P\mingw32\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S D:\Clion_proga\SP\processes\main.c -o CMakeFiles\processes.dir\main.c.s

# Object files for target processes
processes_OBJECTS = \
"CMakeFiles/processes.dir/main.c.obj"

# External object files for target processes
processes_EXTERNAL_OBJECTS =

processes.exe: CMakeFiles/processes.dir/main.c.obj
processes.exe: CMakeFiles/processes.dir/build.make
processes.exe: CMakeFiles/processes.dir/linklibs.rsp
processes.exe: CMakeFiles/processes.dir/objects1.rsp
processes.exe: CMakeFiles/processes.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=D:\Clion_proga\SP\processes\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable processes.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\processes.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/processes.dir/build: processes.exe
.PHONY : CMakeFiles/processes.dir/build

CMakeFiles/processes.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\processes.dir\cmake_clean.cmake
.PHONY : CMakeFiles/processes.dir/clean

CMakeFiles/processes.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" D:\Clion_proga\SP\processes D:\Clion_proga\SP\processes D:\Clion_proga\SP\processes\cmake-build-debug D:\Clion_proga\SP\processes\cmake-build-debug D:\Clion_proga\SP\processes\cmake-build-debug\CMakeFiles\processes.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/processes.dir/depend

