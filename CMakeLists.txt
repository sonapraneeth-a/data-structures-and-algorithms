# Version of CMake project is compatible with
cmake_minimum_required(VERSION 3.9)
# Name of the project
project(DataStructuresAndAlgorithms)
# C++ Standard used
set(CMAKE_CXX_STANDARD 11)

# Adding source directory
add_subdirectory(Src)
add_subdirectory(Test)
