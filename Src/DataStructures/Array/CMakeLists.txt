## File description
##
##         Project: Data Structures
##         Authors: sonapraneeth-a
##      Created on: 12 December 2018
##   Last modified: 14 December 2018
##         Details: File for main executable for data structures project
##

## Changelog
##
## Date (DD-MM-YYYY)            Author               Update
## 12-12-2018               sonapraneeth-a      - Creation of the file
##                                              - Including Headers directory
##                                              - Adding MainArray.cpp to executable
## 14-12-2018               sonapraneeth-a      - Minor updates to commenting style
##                                              - Removed unecessary code
##


# Version of CMake project is compatible with
cmake_minimum_required(VERSION 3.5.1)

# Name of the project
project(Array)

# C++ Standard used
set(CMAKE_CXX_STANDARD 11)

message("--   Generating CMake for ${PROJECT_NAME}")

# Include Array directory for *.h files
include_directories(Array)

# Create executable for the sample array code
add_executable(Source-Main${PROJECT_NAME} Main${PROJECT_NAME}.cpp)

message("--   Completing generation of CMake files for ${PROJECT_NAME}")
