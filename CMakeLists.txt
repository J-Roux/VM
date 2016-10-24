cmake_minimum_required(VERSION 2.7)

project(YASM)

set_property(GLOBAL PROPERTY USE_FOLDERS ON)

option(test "Build all tests." OFF)
if(UNIX)
set(CMAKE_CXX_FLAGS "-g -Wall -lpthreads")
else(WIN32)
set(CMAKE_C_FLAGS_DEBUG "${CMAKE_C_FLAGS_DEBUG} /W3 /MTd")
SET(CMAKE_CXX_FLAGS_DEBUG "/MTd")
endif()


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
  include(ExternalProject)

  set(EXTERNAL_INSTALL_LOCATION ${CMAKE_BINARY_DIR}/external)

  ExternalProject_Add(googletest
     GIT_REPOSITORY https://github.com/google/googletest
     CMAKE_ARGS -DCMAKE_INSTALL_PREFIX=${EXTERNAL_INSTALL_LOCATION}
  )

  include_directories(${EXTERNAL_INSTALL_LOCATION}/include)
   
  if(WIN32) 
  	link_directories(${EXTERNAL_INSTALL_LOCATION}/lib ${CMAKE_SOURCE_DIR}/lib)
  else(UNIX)
	link_directories(${EXTERNAL_INSTALL_LOCATION}/lib)
  endif()  
  enable_testing()

  # Include the gtest library. gtest_SOURCE_DIR is available due to
  # 'project(gtest)' above.
  

  ##############
  # Unit Tests
  ##############

  add_executable(runUnitTests test.cpp ${STACK} ${VM}  ${HEADERS})
 
  target_link_libraries(runUnitTests gtest gtest_main pthreads)

  add_test(NAME stack-test COMMAND runUnitTests)
  # You can also omit NAME and COMMAND. The second argument could be some other
  # test executable.
  # add_test(stack-test runUnitTests)
endif()

add_executable(YASM ${MAIN} ${VM} ${HEADERS} ${STACK})



