# Version of CMAke project is compatible with
cmake_minimum_required(VERSION 3.9)
# Name of the project
project(data_structures)
# C++ Standard used
set(CMAKE_CXX_STANDARD 11)

message("--   Generating CMake for Data Structures")

set(CMAKE_SHARED_LIBRARY_PREFIX "")
set(CMAKE_STATIC_LIBRARY_PREFIX "")

add_subdirectory(list)
include_directories(list)

# Debug libraries are prefixed with "d"
set(CMAKE_DEBUG_POSTFIX "_debug")

add_library(ds_shared SHARED ds.cpp)
add_library(ds_static STATIC ds.cpp)

target_link_libraries(ds_shared list_shared)
target_link_libraries(ds_static list_static)

message("--   Completing generation of CMake files for Data Structures")
