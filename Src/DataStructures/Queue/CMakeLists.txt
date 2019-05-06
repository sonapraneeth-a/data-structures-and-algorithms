## File description
##
##         Project: Data Structures -> Queue
##         Authors: sonapraneeth-a
##      Created on: 18 January 2019
##   Last modified: 18 January 2019
##         Details: File for main executable for data structures -> queue project
##

## Changelog
##
## Date (DD-MM-YYYY)            Author               Update
## 18-01-2019               sonapraneeth-a      - Creation of the file
##                                              - Adding MainQueue.cpp to executable
##


# Version of CMake project is compatible with
cmake_minimum_required(VERSION 3.5.1)

# Name of the project
project(Queue)

# C++ Standard used
set(CMAKE_CXX_STANDARD 11)

message("--     Generating CMake for ${PROJECT_NAME}")

# Include Queue directory for *.h files
include_directories(Queue)

# Create executable for the sample stack code
add_executable(Source-Main${PROJECT_NAME} Main${PROJECT_NAME}.cpp)

message("--     Completing generation of CMake files for ${PROJECT_NAME}")
