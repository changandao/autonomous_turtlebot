# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.5

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
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /nas/ei/home/ga84zes/angelina

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /nas/ei/home/ga84zes/angelina

# Include any dependencies generated for this target.
include hermes/CMakeFiles/referee.dir/depend.make

# Include the progress variables for this target.
include hermes/CMakeFiles/referee.dir/progress.make

# Include the compile flags for this target's objects.
include hermes/CMakeFiles/referee.dir/flags.make

hermes/moc_hermes.cxx: hermes/hermes.h
hermes/moc_hermes.cxx: hermes/moc_hermes.cxx_parameters
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=/nas/ei/home/ga84zes/angelina/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Generating moc_hermes.cxx"
	cd /nas/ei/home/ga84zes/angelina/hermes && /usr/lib/x86_64-linux-gnu/qt4/bin/moc @/nas/ei/home/ga84zes/angelina/hermes/moc_hermes.cxx_parameters

hermes/moc_referee.cxx: hermes/referee.h
hermes/moc_referee.cxx: hermes/moc_referee.cxx_parameters
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=/nas/ei/home/ga84zes/angelina/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Generating moc_referee.cxx"
	cd /nas/ei/home/ga84zes/angelina/hermes && /usr/lib/x86_64-linux-gnu/qt4/bin/moc @/nas/ei/home/ga84zes/angelina/hermes/moc_referee.cxx_parameters

hermes/CMakeFiles/referee.dir/hermes.cpp.o: hermes/CMakeFiles/referee.dir/flags.make
hermes/CMakeFiles/referee.dir/hermes.cpp.o: hermes/hermes.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/nas/ei/home/ga84zes/angelina/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object hermes/CMakeFiles/referee.dir/hermes.cpp.o"
	cd /nas/ei/home/ga84zes/angelina/hermes && /usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/referee.dir/hermes.cpp.o -c /nas/ei/home/ga84zes/angelina/hermes/hermes.cpp

hermes/CMakeFiles/referee.dir/hermes.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/referee.dir/hermes.cpp.i"
	cd /nas/ei/home/ga84zes/angelina/hermes && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /nas/ei/home/ga84zes/angelina/hermes/hermes.cpp > CMakeFiles/referee.dir/hermes.cpp.i

hermes/CMakeFiles/referee.dir/hermes.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/referee.dir/hermes.cpp.s"
	cd /nas/ei/home/ga84zes/angelina/hermes && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /nas/ei/home/ga84zes/angelina/hermes/hermes.cpp -o CMakeFiles/referee.dir/hermes.cpp.s

hermes/CMakeFiles/referee.dir/hermes.cpp.o.requires:

.PHONY : hermes/CMakeFiles/referee.dir/hermes.cpp.o.requires

hermes/CMakeFiles/referee.dir/hermes.cpp.o.provides: hermes/CMakeFiles/referee.dir/hermes.cpp.o.requires
	$(MAKE) -f hermes/CMakeFiles/referee.dir/build.make hermes/CMakeFiles/referee.dir/hermes.cpp.o.provides.build
.PHONY : hermes/CMakeFiles/referee.dir/hermes.cpp.o.provides

hermes/CMakeFiles/referee.dir/hermes.cpp.o.provides.build: hermes/CMakeFiles/referee.dir/hermes.cpp.o


hermes/CMakeFiles/referee.dir/referee.cpp.o: hermes/CMakeFiles/referee.dir/flags.make
hermes/CMakeFiles/referee.dir/referee.cpp.o: hermes/referee.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/nas/ei/home/ga84zes/angelina/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object hermes/CMakeFiles/referee.dir/referee.cpp.o"
	cd /nas/ei/home/ga84zes/angelina/hermes && /usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/referee.dir/referee.cpp.o -c /nas/ei/home/ga84zes/angelina/hermes/referee.cpp

hermes/CMakeFiles/referee.dir/referee.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/referee.dir/referee.cpp.i"
	cd /nas/ei/home/ga84zes/angelina/hermes && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /nas/ei/home/ga84zes/angelina/hermes/referee.cpp > CMakeFiles/referee.dir/referee.cpp.i

hermes/CMakeFiles/referee.dir/referee.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/referee.dir/referee.cpp.s"
	cd /nas/ei/home/ga84zes/angelina/hermes && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /nas/ei/home/ga84zes/angelina/hermes/referee.cpp -o CMakeFiles/referee.dir/referee.cpp.s

hermes/CMakeFiles/referee.dir/referee.cpp.o.requires:

.PHONY : hermes/CMakeFiles/referee.dir/referee.cpp.o.requires

hermes/CMakeFiles/referee.dir/referee.cpp.o.provides: hermes/CMakeFiles/referee.dir/referee.cpp.o.requires
	$(MAKE) -f hermes/CMakeFiles/referee.dir/build.make hermes/CMakeFiles/referee.dir/referee.cpp.o.provides.build
.PHONY : hermes/CMakeFiles/referee.dir/referee.cpp.o.provides

hermes/CMakeFiles/referee.dir/referee.cpp.o.provides.build: hermes/CMakeFiles/referee.dir/referee.cpp.o


hermes/CMakeFiles/referee.dir/moc_hermes.cxx.o: hermes/CMakeFiles/referee.dir/flags.make
hermes/CMakeFiles/referee.dir/moc_hermes.cxx.o: hermes/moc_hermes.cxx
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/nas/ei/home/ga84zes/angelina/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object hermes/CMakeFiles/referee.dir/moc_hermes.cxx.o"
	cd /nas/ei/home/ga84zes/angelina/hermes && /usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/referee.dir/moc_hermes.cxx.o -c /nas/ei/home/ga84zes/angelina/hermes/moc_hermes.cxx

hermes/CMakeFiles/referee.dir/moc_hermes.cxx.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/referee.dir/moc_hermes.cxx.i"
	cd /nas/ei/home/ga84zes/angelina/hermes && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /nas/ei/home/ga84zes/angelina/hermes/moc_hermes.cxx > CMakeFiles/referee.dir/moc_hermes.cxx.i

hermes/CMakeFiles/referee.dir/moc_hermes.cxx.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/referee.dir/moc_hermes.cxx.s"
	cd /nas/ei/home/ga84zes/angelina/hermes && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /nas/ei/home/ga84zes/angelina/hermes/moc_hermes.cxx -o CMakeFiles/referee.dir/moc_hermes.cxx.s

hermes/CMakeFiles/referee.dir/moc_hermes.cxx.o.requires:

.PHONY : hermes/CMakeFiles/referee.dir/moc_hermes.cxx.o.requires

hermes/CMakeFiles/referee.dir/moc_hermes.cxx.o.provides: hermes/CMakeFiles/referee.dir/moc_hermes.cxx.o.requires
	$(MAKE) -f hermes/CMakeFiles/referee.dir/build.make hermes/CMakeFiles/referee.dir/moc_hermes.cxx.o.provides.build
.PHONY : hermes/CMakeFiles/referee.dir/moc_hermes.cxx.o.provides

hermes/CMakeFiles/referee.dir/moc_hermes.cxx.o.provides.build: hermes/CMakeFiles/referee.dir/moc_hermes.cxx.o


hermes/CMakeFiles/referee.dir/moc_referee.cxx.o: hermes/CMakeFiles/referee.dir/flags.make
hermes/CMakeFiles/referee.dir/moc_referee.cxx.o: hermes/moc_referee.cxx
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/nas/ei/home/ga84zes/angelina/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object hermes/CMakeFiles/referee.dir/moc_referee.cxx.o"
	cd /nas/ei/home/ga84zes/angelina/hermes && /usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/referee.dir/moc_referee.cxx.o -c /nas/ei/home/ga84zes/angelina/hermes/moc_referee.cxx

hermes/CMakeFiles/referee.dir/moc_referee.cxx.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/referee.dir/moc_referee.cxx.i"
	cd /nas/ei/home/ga84zes/angelina/hermes && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /nas/ei/home/ga84zes/angelina/hermes/moc_referee.cxx > CMakeFiles/referee.dir/moc_referee.cxx.i

hermes/CMakeFiles/referee.dir/moc_referee.cxx.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/referee.dir/moc_referee.cxx.s"
	cd /nas/ei/home/ga84zes/angelina/hermes && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /nas/ei/home/ga84zes/angelina/hermes/moc_referee.cxx -o CMakeFiles/referee.dir/moc_referee.cxx.s

hermes/CMakeFiles/referee.dir/moc_referee.cxx.o.requires:

.PHONY : hermes/CMakeFiles/referee.dir/moc_referee.cxx.o.requires

hermes/CMakeFiles/referee.dir/moc_referee.cxx.o.provides: hermes/CMakeFiles/referee.dir/moc_referee.cxx.o.requires
	$(MAKE) -f hermes/CMakeFiles/referee.dir/build.make hermes/CMakeFiles/referee.dir/moc_referee.cxx.o.provides.build
.PHONY : hermes/CMakeFiles/referee.dir/moc_referee.cxx.o.provides

hermes/CMakeFiles/referee.dir/moc_referee.cxx.o.provides.build: hermes/CMakeFiles/referee.dir/moc_referee.cxx.o


# Object files for target referee
referee_OBJECTS = \
"CMakeFiles/referee.dir/hermes.cpp.o" \
"CMakeFiles/referee.dir/referee.cpp.o" \
"CMakeFiles/referee.dir/moc_hermes.cxx.o" \
"CMakeFiles/referee.dir/moc_referee.cxx.o"

# External object files for target referee
referee_EXTERNAL_OBJECTS =

hermes/libreferee.a: hermes/CMakeFiles/referee.dir/hermes.cpp.o
hermes/libreferee.a: hermes/CMakeFiles/referee.dir/referee.cpp.o
hermes/libreferee.a: hermes/CMakeFiles/referee.dir/moc_hermes.cxx.o
hermes/libreferee.a: hermes/CMakeFiles/referee.dir/moc_referee.cxx.o
hermes/libreferee.a: hermes/CMakeFiles/referee.dir/build.make
hermes/libreferee.a: hermes/CMakeFiles/referee.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/nas/ei/home/ga84zes/angelina/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Linking CXX static library libreferee.a"
	cd /nas/ei/home/ga84zes/angelina/hermes && $(CMAKE_COMMAND) -P CMakeFiles/referee.dir/cmake_clean_target.cmake
	cd /nas/ei/home/ga84zes/angelina/hermes && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/referee.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
hermes/CMakeFiles/referee.dir/build: hermes/libreferee.a

.PHONY : hermes/CMakeFiles/referee.dir/build

hermes/CMakeFiles/referee.dir/requires: hermes/CMakeFiles/referee.dir/hermes.cpp.o.requires
hermes/CMakeFiles/referee.dir/requires: hermes/CMakeFiles/referee.dir/referee.cpp.o.requires
hermes/CMakeFiles/referee.dir/requires: hermes/CMakeFiles/referee.dir/moc_hermes.cxx.o.requires
hermes/CMakeFiles/referee.dir/requires: hermes/CMakeFiles/referee.dir/moc_referee.cxx.o.requires

.PHONY : hermes/CMakeFiles/referee.dir/requires

hermes/CMakeFiles/referee.dir/clean:
	cd /nas/ei/home/ga84zes/angelina/hermes && $(CMAKE_COMMAND) -P CMakeFiles/referee.dir/cmake_clean.cmake
.PHONY : hermes/CMakeFiles/referee.dir/clean

hermes/CMakeFiles/referee.dir/depend: hermes/moc_hermes.cxx
hermes/CMakeFiles/referee.dir/depend: hermes/moc_referee.cxx
	cd /nas/ei/home/ga84zes/angelina && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /nas/ei/home/ga84zes/angelina /nas/ei/home/ga84zes/angelina/hermes /nas/ei/home/ga84zes/angelina /nas/ei/home/ga84zes/angelina/hermes /nas/ei/home/ga84zes/angelina/hermes/CMakeFiles/referee.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : hermes/CMakeFiles/referee.dir/depend

