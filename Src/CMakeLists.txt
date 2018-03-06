# Version of CMake project is compatible with
cmake_minimum_required(VERSION 3.9)
# Name of the project
project(DataStructuresAndAlgorithms)
# C++ Standard used
set(CMAKE_CXX_STANDARD 11)

message("-- Generating CMake for Data Structures and Algorithms")

include_directories(Headers)

add_subdirectory(DataStructures)
include_directories(DataStructures)
include_directories(DataStructures/List)

add_subdirectory(Algorithms)
include_directories(Algorithms)
include_directories(Algorithms/Numbers)

# Debug libraries are prefixed with "d"
set(CMAKE_DEBUG_POSTFIX "_debug")

# Adding the source code for executable
add_executable(DataStructuresAndAlgorithms main.cpp)
target_link_libraries(DataStructuresAndAlgorithms DsStatic)

message("-- Completing generation of CMake files for Data Structures and Algorithms")