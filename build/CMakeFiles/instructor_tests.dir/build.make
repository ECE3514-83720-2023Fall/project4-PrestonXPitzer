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
CMAKE_COMMAND = "C:\Program Files\CMake\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\CMake\bin\cmake.exe" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = C:\Users\coach\Desktop\3514\project4-PrestonXPitzer

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\Users\coach\Desktop\3514\project4-PrestonXPitzer\build

# Include any dependencies generated for this target.
include CMakeFiles/instructor_tests.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/instructor_tests.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/instructor_tests.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/instructor_tests.dir/flags.make

CMakeFiles/instructor_tests.dir/.github/instructor_tests.cpp.obj: CMakeFiles/instructor_tests.dir/flags.make
CMakeFiles/instructor_tests.dir/.github/instructor_tests.cpp.obj: C:/Users/coach/Desktop/3514/project4-PrestonXPitzer/.github/instructor_tests.cpp
CMakeFiles/instructor_tests.dir/.github/instructor_tests.cpp.obj: CMakeFiles/instructor_tests.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=C:\Users\coach\Desktop\3514\project4-PrestonXPitzer\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/instructor_tests.dir/.github/instructor_tests.cpp.obj"
	C:\msys64\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/instructor_tests.dir/.github/instructor_tests.cpp.obj -MF CMakeFiles\instructor_tests.dir\.github\instructor_tests.cpp.obj.d -o CMakeFiles\instructor_tests.dir\.github\instructor_tests.cpp.obj -c C:\Users\coach\Desktop\3514\project4-PrestonXPitzer\.github\instructor_tests.cpp

CMakeFiles/instructor_tests.dir/.github/instructor_tests.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/instructor_tests.dir/.github/instructor_tests.cpp.i"
	C:\msys64\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\coach\Desktop\3514\project4-PrestonXPitzer\.github\instructor_tests.cpp > CMakeFiles\instructor_tests.dir\.github\instructor_tests.cpp.i

CMakeFiles/instructor_tests.dir/.github/instructor_tests.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/instructor_tests.dir/.github/instructor_tests.cpp.s"
	C:\msys64\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\coach\Desktop\3514\project4-PrestonXPitzer\.github\instructor_tests.cpp -o CMakeFiles\instructor_tests.dir\.github\instructor_tests.cpp.s

CMakeFiles/instructor_tests.dir/treeNode.cpp.obj: CMakeFiles/instructor_tests.dir/flags.make
CMakeFiles/instructor_tests.dir/treeNode.cpp.obj: C:/Users/coach/Desktop/3514/project4-PrestonXPitzer/treeNode.cpp
CMakeFiles/instructor_tests.dir/treeNode.cpp.obj: CMakeFiles/instructor_tests.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=C:\Users\coach\Desktop\3514\project4-PrestonXPitzer\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/instructor_tests.dir/treeNode.cpp.obj"
	C:\msys64\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/instructor_tests.dir/treeNode.cpp.obj -MF CMakeFiles\instructor_tests.dir\treeNode.cpp.obj.d -o CMakeFiles\instructor_tests.dir\treeNode.cpp.obj -c C:\Users\coach\Desktop\3514\project4-PrestonXPitzer\treeNode.cpp

CMakeFiles/instructor_tests.dir/treeNode.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/instructor_tests.dir/treeNode.cpp.i"
	C:\msys64\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\coach\Desktop\3514\project4-PrestonXPitzer\treeNode.cpp > CMakeFiles\instructor_tests.dir\treeNode.cpp.i

CMakeFiles/instructor_tests.dir/treeNode.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/instructor_tests.dir/treeNode.cpp.s"
	C:\msys64\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\coach\Desktop\3514\project4-PrestonXPitzer\treeNode.cpp -o CMakeFiles\instructor_tests.dir\treeNode.cpp.s

CMakeFiles/instructor_tests.dir/prefixTree.cpp.obj: CMakeFiles/instructor_tests.dir/flags.make
CMakeFiles/instructor_tests.dir/prefixTree.cpp.obj: C:/Users/coach/Desktop/3514/project4-PrestonXPitzer/prefixTree.cpp
CMakeFiles/instructor_tests.dir/prefixTree.cpp.obj: CMakeFiles/instructor_tests.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=C:\Users\coach\Desktop\3514\project4-PrestonXPitzer\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/instructor_tests.dir/prefixTree.cpp.obj"
	C:\msys64\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/instructor_tests.dir/prefixTree.cpp.obj -MF CMakeFiles\instructor_tests.dir\prefixTree.cpp.obj.d -o CMakeFiles\instructor_tests.dir\prefixTree.cpp.obj -c C:\Users\coach\Desktop\3514\project4-PrestonXPitzer\prefixTree.cpp

CMakeFiles/instructor_tests.dir/prefixTree.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/instructor_tests.dir/prefixTree.cpp.i"
	C:\msys64\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\coach\Desktop\3514\project4-PrestonXPitzer\prefixTree.cpp > CMakeFiles\instructor_tests.dir\prefixTree.cpp.i

CMakeFiles/instructor_tests.dir/prefixTree.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/instructor_tests.dir/prefixTree.cpp.s"
	C:\msys64\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\coach\Desktop\3514\project4-PrestonXPitzer\prefixTree.cpp -o CMakeFiles\instructor_tests.dir\prefixTree.cpp.s

CMakeFiles/instructor_tests.dir/hw4_datarecord.cpp.obj: CMakeFiles/instructor_tests.dir/flags.make
CMakeFiles/instructor_tests.dir/hw4_datarecord.cpp.obj: C:/Users/coach/Desktop/3514/project4-PrestonXPitzer/hw4_datarecord.cpp
CMakeFiles/instructor_tests.dir/hw4_datarecord.cpp.obj: CMakeFiles/instructor_tests.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=C:\Users\coach\Desktop\3514\project4-PrestonXPitzer\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/instructor_tests.dir/hw4_datarecord.cpp.obj"
	C:\msys64\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/instructor_tests.dir/hw4_datarecord.cpp.obj -MF CMakeFiles\instructor_tests.dir\hw4_datarecord.cpp.obj.d -o CMakeFiles\instructor_tests.dir\hw4_datarecord.cpp.obj -c C:\Users\coach\Desktop\3514\project4-PrestonXPitzer\hw4_datarecord.cpp

CMakeFiles/instructor_tests.dir/hw4_datarecord.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/instructor_tests.dir/hw4_datarecord.cpp.i"
	C:\msys64\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\coach\Desktop\3514\project4-PrestonXPitzer\hw4_datarecord.cpp > CMakeFiles\instructor_tests.dir\hw4_datarecord.cpp.i

CMakeFiles/instructor_tests.dir/hw4_datarecord.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/instructor_tests.dir/hw4_datarecord.cpp.s"
	C:\msys64\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\coach\Desktop\3514\project4-PrestonXPitzer\hw4_datarecord.cpp -o CMakeFiles\instructor_tests.dir\hw4_datarecord.cpp.s

# Object files for target instructor_tests
instructor_tests_OBJECTS = \
"CMakeFiles/instructor_tests.dir/.github/instructor_tests.cpp.obj" \
"CMakeFiles/instructor_tests.dir/treeNode.cpp.obj" \
"CMakeFiles/instructor_tests.dir/prefixTree.cpp.obj" \
"CMakeFiles/instructor_tests.dir/hw4_datarecord.cpp.obj"

# External object files for target instructor_tests
instructor_tests_EXTERNAL_OBJECTS =

instructor_tests.exe: CMakeFiles/instructor_tests.dir/.github/instructor_tests.cpp.obj
instructor_tests.exe: CMakeFiles/instructor_tests.dir/treeNode.cpp.obj
instructor_tests.exe: CMakeFiles/instructor_tests.dir/prefixTree.cpp.obj
instructor_tests.exe: CMakeFiles/instructor_tests.dir/hw4_datarecord.cpp.obj
instructor_tests.exe: CMakeFiles/instructor_tests.dir/build.make
instructor_tests.exe: CMakeFiles/instructor_tests.dir/linkLibs.rsp
instructor_tests.exe: CMakeFiles/instructor_tests.dir/objects1.rsp
instructor_tests.exe: CMakeFiles/instructor_tests.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=C:\Users\coach\Desktop\3514\project4-PrestonXPitzer\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Linking CXX executable instructor_tests.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\instructor_tests.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/instructor_tests.dir/build: instructor_tests.exe
.PHONY : CMakeFiles/instructor_tests.dir/build

CMakeFiles/instructor_tests.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\instructor_tests.dir\cmake_clean.cmake
.PHONY : CMakeFiles/instructor_tests.dir/clean

CMakeFiles/instructor_tests.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\Users\coach\Desktop\3514\project4-PrestonXPitzer C:\Users\coach\Desktop\3514\project4-PrestonXPitzer C:\Users\coach\Desktop\3514\project4-PrestonXPitzer\build C:\Users\coach\Desktop\3514\project4-PrestonXPitzer\build C:\Users\coach\Desktop\3514\project4-PrestonXPitzer\build\CMakeFiles\instructor_tests.dir\DependInfo.cmake "--color=$(COLOR)"
.PHONY : CMakeFiles/instructor_tests.dir/depend
