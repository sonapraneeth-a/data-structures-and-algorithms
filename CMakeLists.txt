## File description
##
##         Project: Data Structures and Algorithms
##         Authors: sonapraneeth-a
##      Created on: 10 December 2018
##   Last modified: 10 December 2018
##         Details: File for compiling source directory

## Changelog
##
## Date (DD-MM-YYYY)            Author               Update
## 10-12-2018               sonapraneeth-a      - Creation of the file
##                                              - Including Src sub-directory


# Minimum version of CMake project is compatible with
cmake_minimum_required(VERSION 3.5.1)

# Name of the project
project(DataStructuresAndAlgorithms)

# C++ Standard used
set(CMAKE_CXX_STANDARD 11)

# Reference: https://stackoverflow.com/questions/13550153/no-tests-found-when-using-gtest-with-cmake-ctest/13551858
# Need to call enable_testing on top level CMakeLists.txt
enable_testing()

# Adding google test directory
add_subdirectory("Lib/googletest")

# Adding source directory
add_subdirectory(Src)

# Adding source directory
add_subdirectory(Test)

