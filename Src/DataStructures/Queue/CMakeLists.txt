cmake_minimum_required(VERSION 3.5.1)
project(Queue)

set(CMAKE_CXX_STANDARD 11)

message("--     Generating CMake for Queue")

set(SOURCE_FILES Queue.cpp Queue.h QueueNode.cpp QueueNode.h)
include_directories(Queue)

set(CMAKE_SHARED_LIBRARY_PREFIX "")
set(CMAKE_STATIC_LIBRARY_PREFIX "")

set(CMAKE_DEBUG_POSTFIX "_debug")

add_library(QueueShared SHARED ${SOURCE_FILES})
add_library(QueueStatic STATIC ${SOURCE_FILES})

add_executable(MainQueue MainQueue.cpp)
target_link_libraries(MainQueue QueueStatic)

install(TARGETS QueueShared DESTINATION "${CMAKE_SOURCE_DIR}/../lib/")
install(TARGETS QueueStatic DESTINATION "${CMAKE_SOURCE_DIR}/../lib/")
install(FILES Queue.h DESTINATION "${CMAKE_SOURCE_DIR}/../include/")

message("--     Completing generation of CMake files for Queue")
