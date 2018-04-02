cmake_minimum_required(VERSION 3.9)
project(List)

set(CMAKE_CXX_STANDARD 11)

message("--     Generating CMake for List")

set(SLL_SOURCE_FILES SingleLinkedListNode.h SingleLinkedListNode.cpp SingleLinkedList.cpp SingleLinkedList.h)
set(DLL_SOURCE_FILES DoubleLinkedListNode.h DoubleLinkedListNode.cpp DoubleLinkedList.cpp DoubleLinkedList.h)
set(SOURCE_FILES ${SLL_SOURCE_FILES} ${DLL_SOURCE_FILES})
include_directories(List)

set(CMAKE_SHARED_LIBRARY_PREFIX "")
set(CMAKE_STATIC_LIBRARY_PREFIX "")

set(CMAKE_DEBUG_POSTFIX "_debug")

add_library(ListShared SHARED ${SOURCE_FILES})
add_library(ListStatic STATIC ${SOURCE_FILES})

add_executable(MainList MainList.cpp)
target_link_libraries(MainList ListStatic)

install(TARGETS ListShared DESTINATION "${CMAKE_SOURCE_DIR}/../lib/")
install(TARGETS ListStatic DESTINATION "${CMAKE_SOURCE_DIR}/../lib/")
install(FILES SingleLinkedListNode.h SingleLinkedList.h DESTINATION "${CMAKE_SOURCE_DIR}/../include/")

message("--     Completing generation of CMake files for List")
