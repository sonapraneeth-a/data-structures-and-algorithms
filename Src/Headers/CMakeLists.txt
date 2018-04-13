# Version of CMAke project is compatible with
cmake_minimum_required(VERSION 3.5.1)
# Name of the project
project(Headers)
# C++ Standard used
set(CMAKE_CXX_STANDARD 11)

message("--   Generating CMake for Headers")

set(CMAKE_SHARED_LIBRARY_PREFIX "")
set(CMAKE_STATIC_LIBRARY_PREFIX "")

set(HEADER_FILES DefaultHeaders.h Exceptions/Exceptions.h OpCodes.h)

# Debug libraries are prefixed with "d"
set(CMAKE_DEBUG_POSTFIX "_debug")

add_library(HeadersShared SHARED Utilities.cpp ${HEADER_FILES})
add_library(HeadersStatic STATIC Utilities.cpp ${HEADER_FILES})

message("--   Completing generation of CMake files for Headers")
