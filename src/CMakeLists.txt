# Version of CMake project is compatible with
cmake_minimum_required(VERSION 3.9)
# Name of the project
project(data_structures_and_algorithms)
# C++ Standard used
set(CMAKE_CXX_STANDARD 11)

message("-- Generating CMake for Data Structures and Algorithms")

add_subdirectory(data_structures)
include_directories(data_structures)
include_directories(data_structures/list)

# Debug libraries are prefixed with "d"
set(CMAKE_DEBUG_POSTFIX "_debug")

# Adding the source code for executable
add_executable(data_structures_and_algorithms main.cpp)
target_link_libraries(data_structures_and_algorithms ds_static)

message("-- Completing generation of CMake files for Data Structures and Algorithms")
