## File description
##
##         Project: Data Structures
##         Authors: sonapraneeth-a
##      Created on: 12 December 2018
##   Last modified: 12 December 2018
##         Details: File for main executable for data structures project
##

## Changelog
##
## Date (DD-MM-YYYY)            Author               Update
## 12-12-2018               sonapraneeth-a      - Creation of the file
##                                              - Including Headers directory
##                                              - Adding MainArray.cpp to executable
##


## Version of CMake project is compatible with
cmake_minimum_required(VERSION 3.5.1)

## Name of the project
project(Array)

## C++ Standard used
set(CMAKE_CXX_STANDARD 11)

message("--   Generating CMake for Data Structures")

## Debug libraries are prefixed with "d"
set(CMAKE_DEBUG_POSTFIX "_debug")

## Adding the source code for executable
add_executable(Main${PROJECT_NAME} MainArray.cpp)

message("--   Completing generation of CMake files for Data Structures")
