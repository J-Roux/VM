cmake_minimum_required(VERSION 2.7)

project(YASM)

set_property(GLOBAL PROPERTY USE_FOLDERS ON)

option(test "Build all tests." OFF)

set(CMAKE_CXX_FLAGS "-g -Wall")



file(GLOB STACK "src/stack.c")
file(GLOB VM  "src/vm.c")
file(GLOB HEADERS "src/*.h")
file(GLOB MAIN "src/main.c")
# configure a header file to pass some of the CMake settings
# to the source code
configure_file (
  "${PROJECT_SOURCE_DIR}/Config.h.in"
  "${PROJECT_SOURCE_DIR}/src/CMakeConfig.h"
  )



if (test)
  # This adds another subdirectory, which has 'project(gtest)'.
  add_subdirectory(lib/gtest-1.6.0)

  enable_testing()

  # Include the gtest library. gtest_SOURCE_DIR is available due to
  # 'project(gtest)' above.
  include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})

  ##############
  # Unit Tests
  ##############

  add_executable(runUnitTests test.cpp ${STACK} ${VM}  ${HEADERS})
  target_link_libraries(runUnitTests gtest gtest_main)
  add_test(NAME stack-test COMMAND runUnitTests)
  # You can also omit NAME and COMMAND. The second argument could be some other
  # test executable.
  # add_test(stack-test runUnitTests)
endif()

add_executable(YASM ${MAIN} ${VM} ${HEADERS} ${STACK})
#target_link_libraries(YASM YASM_lib)

