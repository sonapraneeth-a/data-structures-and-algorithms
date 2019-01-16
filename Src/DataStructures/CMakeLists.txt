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
##                                              - Adding Main.cpp to executable
## 13-12-2018               sonapraneeth-a      - Added Array module to the project
##


## Version of CMake project is compatible with
cmake_minimum_required(VERSION 3.5.1)

## Name of the project
project(Source-DataStructures)

## C++ Standard used
set(CMAKE_CXX_STANDARD 11)

message("--   Generating CMake for Data Structures")

add_subdirectory(Array)
include_directories(Array)

add_subdirectory(Node)
include_directories(Node)

## Debug libraries are prefixed with "d"
set(CMAKE_DEBUG_POSTFIX "_debug")

## Adding the source code for executable
add_executable(${PROJECT_NAME} Main.cpp)

message("--   Completing generation of CMake files for Data Structures")
