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
CMAKE_COMMAND = "C:\Program Files\JetBrains\CLion 2021.2\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\JetBrains\CLion 2021.2\bin\cmake\win\bin\cmake.exe" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = C:\Users\bd\Desktop\Programacion\Parcial-2-Chaile-Mansilla-Zuliani

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\Users\bd\Desktop\Programacion\Parcial-2-Chaile-Mansilla-Zuliani\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/Parcial_2_Chaile_Mansilla_Zuliani.dir/depend.make
# Include the progress variables for this target.
include CMakeFiles/Parcial_2_Chaile_Mansilla_Zuliani.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Parcial_2_Chaile_Mansilla_Zuliani.dir/flags.make

CMakeFiles/Parcial_2_Chaile_Mansilla_Zuliani.dir/main.cpp.obj: CMakeFiles/Parcial_2_Chaile_Mansilla_Zuliani.dir/flags.make
CMakeFiles/Parcial_2_Chaile_Mansilla_Zuliani.dir/main.cpp.obj: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\bd\Desktop\Programacion\Parcial-2-Chaile-Mansilla-Zuliani\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Parcial_2_Chaile_Mansilla_Zuliani.dir/main.cpp.obj"
	C:\msys64\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\Parcial_2_Chaile_Mansilla_Zuliani.dir\main.cpp.obj -c C:\Users\bd\Desktop\Programacion\Parcial-2-Chaile-Mansilla-Zuliani\main.cpp

CMakeFiles/Parcial_2_Chaile_Mansilla_Zuliani.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Parcial_2_Chaile_Mansilla_Zuliani.dir/main.cpp.i"
	C:\msys64\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\bd\Desktop\Programacion\Parcial-2-Chaile-Mansilla-Zuliani\main.cpp > CMakeFiles\Parcial_2_Chaile_Mansilla_Zuliani.dir\main.cpp.i

CMakeFiles/Parcial_2_Chaile_Mansilla_Zuliani.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Parcial_2_Chaile_Mansilla_Zuliani.dir/main.cpp.s"
	C:\msys64\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\bd\Desktop\Programacion\Parcial-2-Chaile-Mansilla-Zuliani\main.cpp -o CMakeFiles\Parcial_2_Chaile_Mansilla_Zuliani.dir\main.cpp.s

# Object files for target Parcial_2_Chaile_Mansilla_Zuliani
Parcial_2_Chaile_Mansilla_Zuliani_OBJECTS = \
"CMakeFiles/Parcial_2_Chaile_Mansilla_Zuliani.dir/main.cpp.obj"

# External object files for target Parcial_2_Chaile_Mansilla_Zuliani
Parcial_2_Chaile_Mansilla_Zuliani_EXTERNAL_OBJECTS =

Parcial_2_Chaile_Mansilla_Zuliani.exe: CMakeFiles/Parcial_2_Chaile_Mansilla_Zuliani.dir/main.cpp.obj
Parcial_2_Chaile_Mansilla_Zuliani.exe: CMakeFiles/Parcial_2_Chaile_Mansilla_Zuliani.dir/build.make
Parcial_2_Chaile_Mansilla_Zuliani.exe: CMakeFiles/Parcial_2_Chaile_Mansilla_Zuliani.dir/linklibs.rsp
Parcial_2_Chaile_Mansilla_Zuliani.exe: CMakeFiles/Parcial_2_Chaile_Mansilla_Zuliani.dir/objects1.rsp
Parcial_2_Chaile_Mansilla_Zuliani.exe: CMakeFiles/Parcial_2_Chaile_Mansilla_Zuliani.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:\Users\bd\Desktop\Programacion\Parcial-2-Chaile-Mansilla-Zuliani\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable Parcial_2_Chaile_Mansilla_Zuliani.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\Parcial_2_Chaile_Mansilla_Zuliani.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Parcial_2_Chaile_Mansilla_Zuliani.dir/build: Parcial_2_Chaile_Mansilla_Zuliani.exe
.PHONY : CMakeFiles/Parcial_2_Chaile_Mansilla_Zuliani.dir/build

CMakeFiles/Parcial_2_Chaile_Mansilla_Zuliani.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\Parcial_2_Chaile_Mansilla_Zuliani.dir\cmake_clean.cmake
.PHONY : CMakeFiles/Parcial_2_Chaile_Mansilla_Zuliani.dir/clean

CMakeFiles/Parcial_2_Chaile_Mansilla_Zuliani.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\Users\bd\Desktop\Programacion\Parcial-2-Chaile-Mansilla-Zuliani C:\Users\bd\Desktop\Programacion\Parcial-2-Chaile-Mansilla-Zuliani C:\Users\bd\Desktop\Programacion\Parcial-2-Chaile-Mansilla-Zuliani\cmake-build-debug C:\Users\bd\Desktop\Programacion\Parcial-2-Chaile-Mansilla-Zuliani\cmake-build-debug C:\Users\bd\Desktop\Programacion\Parcial-2-Chaile-Mansilla-Zuliani\cmake-build-debug\CMakeFiles\Parcial_2_Chaile_Mansilla_Zuliani.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/Parcial_2_Chaile_Mansilla_Zuliani.dir/depend

