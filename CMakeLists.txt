cmake_minimum_required(VERSION 2.7)

project(YASM_VM)
project(YASM_COMPILER)

set_property(GLOBAL PROPERTY USE_FOLDERS ON)

option(test "Build all tests." OFF)

if(UNIX)
set(CMAKE_CXX_FLAGS "-g -Wall ")
else(WIN32)
set(CMAKE_C_FLAGS_DEBUG "${CMAKE_C_FLAGS_DEBUG} /W3 /MTd")
SET(CMAKE_CXX_FLAGS_DEBUG "/MTd")
endif()


set(RANGE_CHECK  1 CACHE STRING "Range check 1 - on 0 - off")
set(STACK_SIZE 128 CACHE STRING "Stack size, default:128")


if(UNIX)
    set(CMAKE_CXX_FLAGS "-g -Wno-narrowing ")
else(WIN32)
    set(CMAKE_C_FLAGS_DEBUG "${CMAKE_C_FLAGS_DEBUG} /W3 /MTd")
    set(CMAKE_CXX_FLAGS_DEBUG "/MTd")

endif()



find_package(FLEX  REQUIRED)
find_package(BISON REQUIRED)




file(GLOB STACK_VM "YASM_VM/src/stack.c")
file(GLOB VM  "YASM_VM/src/vm.c")
file(GLOB HEADERS_VM "YASM_VM/src/*.h")
file(GLOB MAIN_VM "YASM_VM/src/main.c")
file(GLOB COMMANDS_VM "YASM_VM/src/command.h")


BISON_TARGET(MyParser "YASM_COMPILER/src/parcer.y" ${CMAKE_SOURCE_DIR}/YASM_COMPILER/src/parser.c)
FLEX_TARGET(MyScanner "YASM_COMPILER/src/yasm.lex" ${CMAKE_SOURCE_DIR}/YASM_COMPILER/src/lexer.c )
file(GLOB COMPILER "YASM_COMPILER/src/*.c")
file(GLOB HEADER_COMPILER "YASM_COMPILER/src/*h")
ADD_FLEX_BISON_DEPENDENCY(MyScanner MyParser)

# configure a header file to pass some of the CMake settings
# to the source code
configure_file (
  "${PROJECT_SOURCE_DIR}/config/Config.h.in"
  "${PROJECT_SOURCE_DIR}/YASM_VM/src/CMakeConfig.h"
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
        set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++1y")
  endif()  
  enable_testing()

  # Include the gtest library. gtest_SOURCE_DIR is available due to
  # 'project(gtest)' above.
  

  ##############
  # Unit Tests
  ##############
   
  file(GLOB TEST_VM "YASM_VM/tests/*.cpp")
  add_executable(runUnitTests ${TEST_VM} ${STACK_VM} ${VM}  ${HEADERS_VM})
 
  target_link_libraries(runUnitTests gtest gtest_main pthread)

  add_test(NAME stack-test COMMAND runUnitTests)
  # You can also omit NAME and COMMAND. The second argument could be some other
  # test executable.
  # add_test(stack-test runUnitTests)
endif()


add_executable(YASM_COMPILER
    ${COMPILER} ${COMMNADS_VM}
    ${HEADER_COMPILER}
    ${FLEX_MyScanner_OUTPUTS}
    ${BISON_MyParser_OUTPUTS})
add_executable(YASM_VM ${MAIN_VM} ${VM} ${HEADERS_VM} ${STACK_VM})



