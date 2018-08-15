cmake_minimum_required(VERSION 3.5.1)
project(Tree)

set(CMAKE_CXX_STANDARD 11)

message("--     Generating CMake for Tree")

set(BINARY_TREE_SOURCE_FILES BinaryTreeNode.h BinaryTreeNode.cpp BinaryTree.cpp BinaryTree.h)
set(BST_SOURCE_FILES BinarySearchTree.cpp BinarySearchTree.h)
set(BTREE_SOURCE_FILES BTree.cpp BTree.h)
set(NARY_TREE_SOURCE_FILES NaryTree.cpp NaryTree.h)
set(SOURCE_FILES ${BINARY_TREE_SOURCE_FILES} ${BST_SOURCE_FILES}
                    ${BTREE_SOURCE_FILES} ${NARY_TREE_SOURCE_FILES})
include_directories(Tree)
include_directories(../../Headers)

set(CMAKE_SHARED_LIBRARY_PREFIX "")
set(CMAKE_STATIC_LIBRARY_PREFIX "")

set(CMAKE_DEBUG_POSTFIX "_debug")

add_library(TreeShared SHARED ${SOURCE_FILES})
add_library(TreeStatic STATIC ${SOURCE_FILES})

add_executable(MainTree MainTree.cpp)
target_link_libraries(MainTree TreeStatic)

install(TARGETS TreeShared DESTINATION "${CMAKE_SOURCE_DIR}/Llib/")
install(TARGETS TreeStatic DESTINATION "${CMAKE_SOURCE_DIR}/Lib/")
install(FILES BinaryTreeNode.h BinaryTree.h DESTINATION "${CMAKE_SOURCE_DIR}/Include/")

message("--     Completing generation of CMake files for Tree")
