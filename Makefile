# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.5

# Default target executed when no arguments are given to make.
default_target: all

.PHONY : default_target

# Allow only one "make -f Makefile2" at a time, but pass parallelism.
.NOTPARALLEL:


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
CMAKE_SOURCE_DIR = /home/andy/busestorage

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/andy/busestorage

#=============================================================================
# Targets provided globally by CMake.

# Special rule for the target rebuild_cache
rebuild_cache:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Running CMake to regenerate build system..."
	/usr/bin/cmake -H$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR)
.PHONY : rebuild_cache

# Special rule for the target rebuild_cache
rebuild_cache/fast: rebuild_cache

.PHONY : rebuild_cache/fast

# Special rule for the target edit_cache
edit_cache:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "No interactive CMake dialog available..."
	/usr/bin/cmake -E echo No\ interactive\ CMake\ dialog\ available.
.PHONY : edit_cache

# Special rule for the target edit_cache
edit_cache/fast: edit_cache

.PHONY : edit_cache/fast

# The main all target
all: cmake_check_build_system
	$(CMAKE_COMMAND) -E cmake_progress_start /home/andy/busestorage/CMakeFiles /home/andy/busestorage/CMakeFiles/progress.marks
	$(MAKE) -f CMakeFiles/Makefile2 all
	$(CMAKE_COMMAND) -E cmake_progress_start /home/andy/busestorage/CMakeFiles 0
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
# Target rules for targets named abstorage

# Build rule for target.
abstorage: cmake_check_build_system
	$(MAKE) -f CMakeFiles/Makefile2 abstorage
.PHONY : abstorage

# fast build rule for target.
abstorage/fast:
	$(MAKE) -f CMakeFiles/abstorage.dir/build.make CMakeFiles/abstorage.dir/build
.PHONY : abstorage/fast

ABStorage.o: ABStorage.cpp.o

.PHONY : ABStorage.o

# target to build an object file
ABStorage.cpp.o:
	$(MAKE) -f CMakeFiles/abstorage.dir/build.make CMakeFiles/abstorage.dir/ABStorage.cpp.o
.PHONY : ABStorage.cpp.o

ABStorage.i: ABStorage.cpp.i

.PHONY : ABStorage.i

# target to preprocess a source file
ABStorage.cpp.i:
	$(MAKE) -f CMakeFiles/abstorage.dir/build.make CMakeFiles/abstorage.dir/ABStorage.cpp.i
.PHONY : ABStorage.cpp.i

ABStorage.s: ABStorage.cpp.s

.PHONY : ABStorage.s

# target to generate assembly for a file
ABStorage.cpp.s:
	$(MAKE) -f CMakeFiles/abstorage.dir/build.make CMakeFiles/abstorage.dir/ABStorage.cpp.s
.PHONY : ABStorage.cpp.s

ASBlockDevice.o: ASBlockDevice.cpp.o

.PHONY : ASBlockDevice.o

# target to build an object file
ASBlockDevice.cpp.o:
	$(MAKE) -f CMakeFiles/abstorage.dir/build.make CMakeFiles/abstorage.dir/ASBlockDevice.cpp.o
.PHONY : ASBlockDevice.cpp.o

ASBlockDevice.i: ASBlockDevice.cpp.i

.PHONY : ASBlockDevice.i

# target to preprocess a source file
ASBlockDevice.cpp.i:
	$(MAKE) -f CMakeFiles/abstorage.dir/build.make CMakeFiles/abstorage.dir/ASBlockDevice.cpp.i
.PHONY : ASBlockDevice.cpp.i

ASBlockDevice.s: ASBlockDevice.cpp.s

.PHONY : ASBlockDevice.s

# target to generate assembly for a file
ASBlockDevice.cpp.s:
	$(MAKE) -f CMakeFiles/abstorage.dir/build.make CMakeFiles/abstorage.dir/ASBlockDevice.cpp.s
.PHONY : ASBlockDevice.cpp.s

ASFSEnv.o: ASFSEnv.cpp.o

.PHONY : ASFSEnv.o

# target to build an object file
ASFSEnv.cpp.o:
	$(MAKE) -f CMakeFiles/abstorage.dir/build.make CMakeFiles/abstorage.dir/ASFSEnv.cpp.o
.PHONY : ASFSEnv.cpp.o

ASFSEnv.i: ASFSEnv.cpp.i

.PHONY : ASFSEnv.i

# target to preprocess a source file
ASFSEnv.cpp.i:
	$(MAKE) -f CMakeFiles/abstorage.dir/build.make CMakeFiles/abstorage.dir/ASFSEnv.cpp.i
.PHONY : ASFSEnv.cpp.i

ASFSEnv.s: ASFSEnv.cpp.s

.PHONY : ASFSEnv.s

# target to generate assembly for a file
ASFSEnv.cpp.s:
	$(MAKE) -f CMakeFiles/abstorage.dir/build.make CMakeFiles/abstorage.dir/ASFSEnv.cpp.s
.PHONY : ASFSEnv.cpp.s

PathUtils.o: PathUtils.cpp.o

.PHONY : PathUtils.o

# target to build an object file
PathUtils.cpp.o:
	$(MAKE) -f CMakeFiles/abstorage.dir/build.make CMakeFiles/abstorage.dir/PathUtils.cpp.o
.PHONY : PathUtils.cpp.o

PathUtils.i: PathUtils.cpp.i

.PHONY : PathUtils.i

# target to preprocess a source file
PathUtils.cpp.i:
	$(MAKE) -f CMakeFiles/abstorage.dir/build.make CMakeFiles/abstorage.dir/PathUtils.cpp.i
.PHONY : PathUtils.cpp.i

PathUtils.s: PathUtils.cpp.s

.PHONY : PathUtils.s

# target to generate assembly for a file
PathUtils.cpp.s:
	$(MAKE) -f CMakeFiles/abstorage.dir/build.make CMakeFiles/abstorage.dir/PathUtils.cpp.s
.PHONY : PathUtils.cpp.s

SinglePageBlobAdapter.o: SinglePageBlobAdapter.cpp.o

.PHONY : SinglePageBlobAdapter.o

# target to build an object file
SinglePageBlobAdapter.cpp.o:
	$(MAKE) -f CMakeFiles/abstorage.dir/build.make CMakeFiles/abstorage.dir/SinglePageBlobAdapter.cpp.o
.PHONY : SinglePageBlobAdapter.cpp.o

SinglePageBlobAdapter.i: SinglePageBlobAdapter.cpp.i

.PHONY : SinglePageBlobAdapter.i

# target to preprocess a source file
SinglePageBlobAdapter.cpp.i:
	$(MAKE) -f CMakeFiles/abstorage.dir/build.make CMakeFiles/abstorage.dir/SinglePageBlobAdapter.cpp.i
.PHONY : SinglePageBlobAdapter.cpp.i

SinglePageBlobAdapter.s: SinglePageBlobAdapter.cpp.s

.PHONY : SinglePageBlobAdapter.s

# target to generate assembly for a file
SinglePageBlobAdapter.cpp.s:
	$(MAKE) -f CMakeFiles/abstorage.dir/build.make CMakeFiles/abstorage.dir/SinglePageBlobAdapter.cpp.s
.PHONY : SinglePageBlobAdapter.cpp.s

buse.o: buse.cpp.o

.PHONY : buse.o

# target to build an object file
buse.cpp.o:
	$(MAKE) -f CMakeFiles/abstorage.dir/build.make CMakeFiles/abstorage.dir/buse.cpp.o
.PHONY : buse.cpp.o

buse.i: buse.cpp.i

.PHONY : buse.i

# target to preprocess a source file
buse.cpp.i:
	$(MAKE) -f CMakeFiles/abstorage.dir/build.make CMakeFiles/abstorage.dir/buse.cpp.i
.PHONY : buse.cpp.i

buse.s: buse.cpp.s

.PHONY : buse.s

# target to generate assembly for a file
buse.cpp.s:
	$(MAKE) -f CMakeFiles/abstorage.dir/build.make CMakeFiles/abstorage.dir/buse.cpp.s
.PHONY : buse.cpp.s

# Help Target
help:
	@echo "The following are some of the valid targets for this Makefile:"
	@echo "... all (the default if no target is provided)"
	@echo "... clean"
	@echo "... depend"
	@echo "... rebuild_cache"
	@echo "... edit_cache"
	@echo "... abstorage"
	@echo "... ABStorage.o"
	@echo "... ABStorage.i"
	@echo "... ABStorage.s"
	@echo "... ASBlockDevice.o"
	@echo "... ASBlockDevice.i"
	@echo "... ASBlockDevice.s"
	@echo "... ASFSEnv.o"
	@echo "... ASFSEnv.i"
	@echo "... ASFSEnv.s"
	@echo "... PathUtils.o"
	@echo "... PathUtils.i"
	@echo "... PathUtils.s"
	@echo "... SinglePageBlobAdapter.o"
	@echo "... SinglePageBlobAdapter.i"
	@echo "... SinglePageBlobAdapter.s"
	@echo "... buse.o"
	@echo "... buse.i"
	@echo "... buse.s"
.PHONY : help



#=============================================================================
# Special targets to cleanup operation of make.

# Special rule to run CMake to check the build system integrity.
# No rule that depends on this can have commands that come from listfiles
# because they might be regenerated.
cmake_check_build_system:
	$(CMAKE_COMMAND) -H$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR) --check-build-system CMakeFiles/Makefile.cmake 0
.PHONY : cmake_check_build_system

