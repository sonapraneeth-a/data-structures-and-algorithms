# Version of CMAke project is compatible with
cmake_minimum_required(VERSION 3.9)
# Name of the project
project(DataStructures)
# C++ Standard used
set(CMAKE_CXX_STANDARD 11)

message("--   Generating CMake for Data Structures")

set(CMAKE_SHARED_LIBRARY_PREFIX "")
set(CMAKE_STATIC_LIBRARY_PREFIX "")

add_subdirectory(List)
include_directories(List)

# Debug libraries are prefixed with "d"
set(CMAKE_DEBUG_POSTFIX "_debug")

add_library(DsShared SHARED Ds.cpp)
add_library(DsStatic STATIC Ds.cpp)

target_link_libraries(DsShared ListShared)
target_link_libraries(DsStatic ListStatic)

message("--   Completing generation of CMake files for Data Structures")
