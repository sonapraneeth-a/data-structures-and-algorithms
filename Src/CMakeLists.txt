## File description
##
##         Project: Data Structures and Algorithms
##         Authors: sonapraneeth-a
##      Created on: 10 December 2018
##   Last modified: 13 December 2018
##         Details: File for main executable for the project
##

## Changelog
##
## Date (DD-MM-YYYY)            Author               Update
## 10-12-2018               sonapraneeth-a      - Creation of the file
##                                              - Including Headers directory
##                                              - Adding Main.cpp to
##                                                DataStructuresAndAlgorithms executable
## 13-12-2018               sonapraneeth-a      - Added DataStructures module
##                                                to the project
##


## Version of CMake project is compatible with
cmake_minimum_required(VERSION 3.5.1)

## Name of the project
project(Source-DataStructuresAndAlgorithms)

## C++ Standard used
set(CMAKE_CXX_STANDARD 11)

message("-- Generating CMake for Source of Data Structures and Algorithms")

include_directories(Headers)

include_directories(Exception)

add_subdirectory(DataStructures)
include_directories(DataStructures)

## Debug libraries are prefixed with "d"
set(CMAKE_DEBUG_POSTFIX "_debug")

## Adding the source code for executable
add_executable(${PROJECT_NAME} Main.cpp)

message("-- Completing generation of CMake files for Source of Data Structures and Algorithms")
