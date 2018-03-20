cmake_minimum_required(VERSION 3.9)
project(Tree)

set(CMAKE_CXX_STANDARD 11)

message("--     Generating CMake for Tree")

set(SOURCE_FILES BinaryTreeNode.h BinaryTreeNode.cpp BinaryTree.cpp BinaryTree.h)
include_directories(List)

set(CMAKE_SHARED_LIBRARY_PREFIX "")
set(CMAKE_STATIC_LIBRARY_PREFIX "")

set(CMAKE_DEBUG_POSTFIX "_debug")

add_library(TreeShared SHARED ${SOURCE_FILES})
add_library(TreeStatic STATIC ${SOURCE_FILES})

add_executable(MainTree MainTree.cpp)
target_link_libraries(MainTree TreeStatic)

install(TARGETS TreeShared DESTINATION "${CMAKE_SOURCE_DIR}/../lib/")
install(TARGETS TreeStatic DESTINATION "${CMAKE_SOURCE_DIR}/../lib/")
install(FILES BinaryTreeNode.h BinaryTree.h DESTINATION "${CMAKE_SOURCE_DIR}/../include/")

message("--     Completing generation of CMake files for Tree")
