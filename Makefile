# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.0

# Default target executed when no arguments are given to make.
default_target: all
.PHONY : default_target

# Allow only one "make -f Makefile2" at a time, but pass parallelism.
.NOTPARALLEL:
.PHONY : .NOTPARALLEL

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
CMAKE_SOURCE_DIR = /home/pi/git-repo/LBPH2

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/pi/git-repo/LBPH2

#=============================================================================
# Targets provided globally by CMake.

# Special rule for the target edit_cache
edit_cache:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Running CMake cache editor..."
	/usr/bin/ccmake -H$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR)
.PHONY : edit_cache

# Special rule for the target edit_cache
edit_cache/fast: edit_cache
.PHONY : edit_cache/fast

# Special rule for the target rebuild_cache
rebuild_cache:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Running CMake to regenerate build system..."
	/usr/bin/cmake -H$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR)
.PHONY : rebuild_cache

# Special rule for the target rebuild_cache
rebuild_cache/fast: rebuild_cache
.PHONY : rebuild_cache/fast

# The main all target
all: cmake_check_build_system
	$(CMAKE_COMMAND) -E cmake_progress_start /home/pi/git-repo/LBPH2/CMakeFiles /home/pi/git-repo/LBPH2/CMakeFiles/progress.marks
	$(MAKE) -f CMakeFiles/Makefile2 all
	$(CMAKE_COMMAND) -E cmake_progress_start /home/pi/git-repo/LBPH2/CMakeFiles 0
.PHONY : all

# The main clean target
clean:
	$(MAKE) -f CMakeFiles/Makefile2 clean
.PHONY : clean

# The main clean target
clean/fast: clean
.PHONY : clean/fast

# Prepare targets for installation.
preinstall: all
	$(MAKE) -f CMakeFiles/Makefile2 preinstall
.PHONY : preinstall

# Prepare targets for installation.
preinstall/fast:
	$(MAKE) -f CMakeFiles/Makefile2 preinstall
.PHONY : preinstall/fast

# clear depends
depend:
	$(CMAKE_COMMAND) -H$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR) --check-build-system CMakeFiles/Makefile.cmake 1
.PHONY : depend

#=============================================================================
# Target rules for targets named LBPH2

# Build rule for target.
LBPH2: cmake_check_build_system
	$(MAKE) -f CMakeFiles/Makefile2 LBPH2
.PHONY : LBPH2

# fast build rule for target.
LBPH2/fast:
	$(MAKE) -f CMakeFiles/LBPH2.dir/build.make CMakeFiles/LBPH2.dir/build
.PHONY : LBPH2/fast

default_run.o: default_run.cpp.o
.PHONY : default_run.o

# target to build an object file
default_run.cpp.o:
	$(MAKE) -f CMakeFiles/LBPH2.dir/build.make CMakeFiles/LBPH2.dir/default_run.cpp.o
.PHONY : default_run.cpp.o

default_run.i: default_run.cpp.i
.PHONY : default_run.i

# target to preprocess a source file
default_run.cpp.i:
	$(MAKE) -f CMakeFiles/LBPH2.dir/build.make CMakeFiles/LBPH2.dir/default_run.cpp.i
.PHONY : default_run.cpp.i

default_run.s: default_run.cpp.s
.PHONY : default_run.s

# target to generate assembly for a file
default_run.cpp.s:
	$(MAKE) -f CMakeFiles/LBPH2.dir/build.make CMakeFiles/LBPH2.dir/default_run.cpp.s
.PHONY : default_run.cpp.s

lbph.o: lbph.cpp.o
.PHONY : lbph.o

# target to build an object file
lbph.cpp.o:
	$(MAKE) -f CMakeFiles/LBPH2.dir/build.make CMakeFiles/LBPH2.dir/lbph.cpp.o
.PHONY : lbph.cpp.o

lbph.i: lbph.cpp.i
.PHONY : lbph.i

# target to preprocess a source file
lbph.cpp.i:
	$(MAKE) -f CMakeFiles/LBPH2.dir/build.make CMakeFiles/LBPH2.dir/lbph.cpp.i
.PHONY : lbph.cpp.i

lbph.s: lbph.cpp.s
.PHONY : lbph.s

# target to generate assembly for a file
lbph.cpp.s:
	$(MAKE) -f CMakeFiles/LBPH2.dir/build.make CMakeFiles/LBPH2.dir/lbph.cpp.s
.PHONY : lbph.cpp.s

testing.o: testing.cpp.o
.PHONY : testing.o

# target to build an object file
testing.cpp.o:
	$(MAKE) -f CMakeFiles/LBPH2.dir/build.make CMakeFiles/LBPH2.dir/testing.cpp.o
.PHONY : testing.cpp.o

testing.i: testing.cpp.i
.PHONY : testing.i

# target to preprocess a source file
testing.cpp.i:
	$(MAKE) -f CMakeFiles/LBPH2.dir/build.make CMakeFiles/LBPH2.dir/testing.cpp.i
.PHONY : testing.cpp.i

testing.s: testing.cpp.s
.PHONY : testing.s

# target to generate assembly for a file
testing.cpp.s:
	$(MAKE) -f CMakeFiles/LBPH2.dir/build.make CMakeFiles/LBPH2.dir/testing.cpp.s
.PHONY : testing.cpp.s

user_inputs.o: user_inputs.cpp.o
.PHONY : user_inputs.o

# target to build an object file
user_inputs.cpp.o:
	$(MAKE) -f CMakeFiles/LBPH2.dir/build.make CMakeFiles/LBPH2.dir/user_inputs.cpp.o
.PHONY : user_inputs.cpp.o

user_inputs.i: user_inputs.cpp.i
.PHONY : user_inputs.i

# target to preprocess a source file
user_inputs.cpp.i:
	$(MAKE) -f CMakeFiles/LBPH2.dir/build.make CMakeFiles/LBPH2.dir/user_inputs.cpp.i
.PHONY : user_inputs.cpp.i

user_inputs.s: user_inputs.cpp.s
.PHONY : user_inputs.s

# target to generate assembly for a file
user_inputs.cpp.s:
	$(MAKE) -f CMakeFiles/LBPH2.dir/build.make CMakeFiles/LBPH2.dir/user_inputs.cpp.s
.PHONY : user_inputs.cpp.s

# Help Target
help:
	@echo "The following are some of the valid targets for this Makefile:"
	@echo "... all (the default if no target is provided)"
	@echo "... clean"
	@echo "... depend"
	@echo "... LBPH2"
	@echo "... edit_cache"
	@echo "... rebuild_cache"
	@echo "... default_run.o"
	@echo "... default_run.i"
	@echo "... default_run.s"
	@echo "... lbph.o"
	@echo "... lbph.i"
	@echo "... lbph.s"
	@echo "... testing.o"
	@echo "... testing.i"
	@echo "... testing.s"
	@echo "... user_inputs.o"
	@echo "... user_inputs.i"
	@echo "... user_inputs.s"
.PHONY : help



#=============================================================================
# Special targets to cleanup operation of make.

# Special rule to run CMake to check the build system integrity.
# No rule that depends on this can have commands that come from listfiles
# because they might be regenerated.
cmake_check_build_system:
	$(CMAKE_COMMAND) -H$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR) --check-build-system CMakeFiles/Makefile.cmake 0
.PHONY : cmake_check_build_system

