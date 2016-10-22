cmake_minimum_required(VERSION 2.7)

project(YASM)

set_property(GLOBAL PROPERTY USE_FOLDERS ON)

option(UNIT_TESTS "UNIT_TESTS" OFF)


if(UNIT_TESTS)
	set(UNITTESTS 1)
else(UNIT_TESTS)
	set(UNITTESTS 0)
endif(UNIT_TESTS)

file(GLOB SOURCES "src/*.c")
file(GLOB HEADERS "src/*.h")
 
# configure a header file to pass some of the CMake settings
# to the source code
configure_file (
  "${PROJECT_SOURCE_DIR}/Config.h.in"
  "${PROJECT_SOURCE_DIR}/src/CMakeConfig.h"
  )


add_executable(YASM ${SOURCES} ${HEADERS})

