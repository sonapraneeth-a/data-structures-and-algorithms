# Version of CMake project is compatible with
cmake_minimum_required(VERSION 3.5.1)
# Name of the project
project(Algorithms)
# C++ Standard used
set(CMAKE_CXX_STANDARD 11)

message("--   Generating CMake for Algorithms")

set(CMAKE_SHARED_LIBRARY_PREFIX "")
set(CMAKE_STATIC_LIBRARY_PREFIX "")

add_subdirectory(Numbers)
include_directories(Numbers)

add_subdirectory(SearchSort)
include_directories(SearchSort)

# Debug libraries are prefixed with "d"
set(CMAKE_DEBUG_POSTFIX "_debug")

add_library(AlgoShared SHARED Algo.cpp)
add_library(AlgoStatic STATIC Algo.cpp)

target_link_libraries(AlgoShared NumbersShared)
target_link_libraries(AlgoStatic NumbersStatic)

message("--   Completing generation of CMake files for Algorithms")
