cmake_minimum_required(VERSION 3.9)
project(list)

set(CMAKE_CXX_STANDARD 11)

message("--     Generating CMake for List")

set(SOURCE_FILES single_linked_list_node.h single_linked_list_node.cpp single_linked_list.cpp single_linked_list.h)
include_directories(list)

set(CMAKE_SHARED_LIBRARY_PREFIX "")
set(CMAKE_STATIC_LIBRARY_PREFIX "")

set(CMAKE_DEBUG_POSTFIX "_debug")

add_library(list_shared SHARED ${SOURCE_FILES})
add_library(list_static STATIC ${SOURCE_FILES})

add_executable(list_main list_main.cpp)
target_link_libraries(list_main list_static)

install(TARGETS list_shared DESTINATION "${CMAKE_SOURCE_DIR}/../lib/")
install(TARGETS list_static DESTINATION "${CMAKE_SOURCE_DIR}/../lib/")
install(FILES single_linked_list_node.h DESTINATION "${CMAKE_SOURCE_DIR}/../include/")

message("--     Completing generation of CMake files for List")
