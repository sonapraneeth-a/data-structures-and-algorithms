# Version of CMAke project is compatible with
cmake_minimum_required(VERSION 3.9)
# Name of the project
project(data_structures_and_algorithms)
# C++ Standard used
set(CMAKE_CXX_STANDARD 11)

# Debug libraries are prefixed with "d"
if(NOT DEFINED CMAKE_DEBUG_POSTFIX)
    set(CMAKE_DEBUG_POSTFIX d)
endif()

# Adding the source code for executable
add_executable(data_structures_and_algorithms main.cpp)
