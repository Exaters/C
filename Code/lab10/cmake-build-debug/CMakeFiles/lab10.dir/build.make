# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.27

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
CMAKE_COMMAND = "D:\CLion 2023.3.2\bin\cmake\win\x64\bin\cmake.exe"

# The command to remove a file.
RM = "D:\CLion 2023.3.2\bin\cmake\win\x64\bin\cmake.exe" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = C:\Users\FSB\Documents\GitHub\C\Code\lab10

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\Users\FSB\Documents\GitHub\C\Code\lab10\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/lab10.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/lab10.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/lab10.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/lab10.dir/flags.make

CMakeFiles/lab10.dir/klme10.c.obj: CMakeFiles/lab10.dir/flags.make
CMakeFiles/lab10.dir/klme10.c.obj: C:/Users/FSB/Documents/GitHub/C/Code/lab10/klme10.c
CMakeFiles/lab10.dir/klme10.c.obj: CMakeFiles/lab10.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=C:\Users\FSB\Documents\GitHub\C\Code\lab10\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/lab10.dir/klme10.c.obj"
	"D:\CLion 2023.3.2\bin\mingw\bin\gcc.exe" $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/lab10.dir/klme10.c.obj -MF CMakeFiles\lab10.dir\klme10.c.obj.d -o CMakeFiles\lab10.dir\klme10.c.obj -c C:\Users\FSB\Documents\GitHub\C\Code\lab10\klme10.c

CMakeFiles/lab10.dir/klme10.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing C source to CMakeFiles/lab10.dir/klme10.c.i"
	"D:\CLion 2023.3.2\bin\mingw\bin\gcc.exe" $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E C:\Users\FSB\Documents\GitHub\C\Code\lab10\klme10.c > CMakeFiles\lab10.dir\klme10.c.i

CMakeFiles/lab10.dir/klme10.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling C source to assembly CMakeFiles/lab10.dir/klme10.c.s"
	"D:\CLion 2023.3.2\bin\mingw\bin\gcc.exe" $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S C:\Users\FSB\Documents\GitHub\C\Code\lab10\klme10.c -o CMakeFiles\lab10.dir\klme10.c.s

# Object files for target lab10
lab10_OBJECTS = \
"CMakeFiles/lab10.dir/klme10.c.obj"

# External object files for target lab10
lab10_EXTERNAL_OBJECTS =

lab10.exe: CMakeFiles/lab10.dir/klme10.c.obj
lab10.exe: CMakeFiles/lab10.dir/build.make
lab10.exe: CMakeFiles/lab10.dir/linkLibs.rsp
lab10.exe: CMakeFiles/lab10.dir/objects1.rsp
lab10.exe: CMakeFiles/lab10.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=C:\Users\FSB\Documents\GitHub\C\Code\lab10\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable lab10.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\lab10.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/lab10.dir/build: lab10.exe
.PHONY : CMakeFiles/lab10.dir/build

CMakeFiles/lab10.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\lab10.dir\cmake_clean.cmake
.PHONY : CMakeFiles/lab10.dir/clean

CMakeFiles/lab10.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\Users\FSB\Documents\GitHub\C\Code\lab10 C:\Users\FSB\Documents\GitHub\C\Code\lab10 C:\Users\FSB\Documents\GitHub\C\Code\lab10\cmake-build-debug C:\Users\FSB\Documents\GitHub\C\Code\lab10\cmake-build-debug C:\Users\FSB\Documents\GitHub\C\Code\lab10\cmake-build-debug\CMakeFiles\lab10.dir\DependInfo.cmake "--color=$(COLOR)"
.PHONY : CMakeFiles/lab10.dir/depend

