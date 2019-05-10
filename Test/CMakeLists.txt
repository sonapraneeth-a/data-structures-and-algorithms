## File description
##
##         Project: Test Main
##         Authors: sonapraneeth-a
##      Created on: 14 December 2018
##   Last modified: 14 December 2018
##         Details: File for main executable for test project
##

## Changelog
##
## Date (DD-MM-YYYY)            Author               Update
## 14-12-2018               sonapraneeth-a      - Creation of the file
##                                              - Added googletest library
##                                              - Added code for testing Array
##                                                module in DataStructures
##                                              - Added code for testing all modules
##                                                in DataStructures
##                                              - Added code for testing all modules
##                                                in the project
##                                              - Added include directories for
##                                                Array module
##

# Version of CMake project is compatible with
cmake_minimum_required(VERSION 3.5.1)

# Name of the project
project(Test-DataStructuresAndAlgorithms)

# C++ Standard used
set(CMAKE_CXX_STANDARD 11)

include_directories("../Lib/googletest/googletest/include")
include_directories("../Lib/googletest/googlemock/include")

SET(TEST_PREFIX Test-)

include_directories("../Src/Exception")

SET(SRC_HEADERS_DIR ../Src/Headers)
include_directories("${SRC_HEADERS_DIR}")

SET(TEST_DS_DIR ./Src/DataStructures)
SET(TEST_ARRAY_DIR ${TEST_DS_DIR}/Array)
SET(TEST_NODE_DIR ${TEST_DS_DIR}/Node)

SET(SRC_DS_DIR ../Src/DataStructures)
include_directories("${SRC_DS_DIR}/Array")
include_directories("${SRC_DS_DIR}/Node")

set(ARRAY_TEST_FILES ${TEST_ARRAY_DIR}/${TEST_PREFIX}Array.cpp ${TEST_ARRAY_DIR}/${TEST_PREFIX}DynamicArray.cpp)
set(NODE_TEST_FILES ${TEST_NODE_DIR}/${TEST_PREFIX}Node.cpp)

set(DS_TEST_FILES ${ARRAY_TEST_FILES} ${NODE_TEST_FILES})

# Create executable for the data structures test
add_executable(${TEST_PREFIX}DataStructures ${TEST_DS_DIR}/${TEST_PREFIX}DataStructures.cpp ${DS_TEST_FILES})
target_link_libraries(${TEST_PREFIX}DataStructures gtest gtest_main)
target_link_libraries(${TEST_PREFIX}DataStructures gmock gmock_main)

# Create executable for all tests
add_executable(${PROJECT_NAME} ${PROJECT_NAME}.cpp ${DS_TEST_FILES})
target_link_libraries(${PROJECT_NAME} gtest gtest_main)
target_link_libraries(${PROJECT_NAME} gmock gmock_main)

add_test(DataStructures ${TEST_PREFIX}DataStructures)
