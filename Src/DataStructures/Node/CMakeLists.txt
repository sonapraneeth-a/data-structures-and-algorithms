## File description
##
##         Project: Data Structures -> Node
##         Authors: sonapraneeth-a
##      Created on: 15 January 2019
##   Last modified: 15 January 2019
##         Details: File for main executable for data strucutures-> node project
##

## Changelog
##
## Date (DD-MM-YYYY)            Author               Update
## 15-01-2019               sonapraneeth-a      - Creation of the file
##


# Version of CMake project is compatible with
cmake_minimum_required(VERSION 3.5.1)

# Name of the project
project(Node)

# C++ Standard used
set(CMAKE_CXX_STANDARD 11)

message("--   Generating CMake for ${PROJECT_NAME}")

# Include Node directory for *.h files
include_directories(Node)

# Create executable for the sample array code
add_executable(Source-Main${PROJECT_NAME} Main${PROJECT_NAME}.cpp)

message("--   Completing generation of CMake files for ${PROJECT_NAME}")
