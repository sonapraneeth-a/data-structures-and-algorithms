# Version of CMAke project is compatible with
cmake_minimum_required(VERSION 3.9)
# Name of the project
project(algorithms)
# C++ Standard used
set(CMAKE_CXX_STANDARD 11)

message("--   Generating CMake for Algorithms")

set(CMAKE_SHARED_LIBRARY_PREFIX "")
set(CMAKE_STATIC_LIBRARY_PREFIX "")

add_subdirectory(numbers)
include_directories(numbers)

# Debug libraries are prefixed with "d"
set(CMAKE_DEBUG_POSTFIX "_debug")

add_library(algo_shared SHARED algo.cpp)
add_library(algo_static STATIC algo.cpp)

target_link_libraries(algo_shared numbers_shared)
target_link_libraries(algo_static numbers_static)

message("--   Completing generation of CMake files for Algorithms")
