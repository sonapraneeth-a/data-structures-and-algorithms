cmake_minimum_required(VERSION 3.9)
project(Stack)

set(CMAKE_CXX_STANDARD 11)

message("--     Generating CMake for Stack")

set(SOURCE_FILES Stack.cpp Stack.h)
include_directories(Stack)

set(CMAKE_SHARED_LIBRARY_PREFIX "")
set(CMAKE_STATIC_LIBRARY_PREFIX "")

set(CMAKE_DEBUG_POSTFIX "_debug")

add_library(StackShared SHARED ${SOURCE_FILES})
add_library(StackStatic STATIC ${SOURCE_FILES})

add_executable(MainStack MainStack.cpp)
target_link_libraries(MainStack StackStatic)

install(TARGETS StackShared DESTINATION "${CMAKE_SOURCE_DIR}/../lib/")
install(TARGETS StackStatic DESTINATION "${CMAKE_SOURCE_DIR}/../lib/")
install(FILES Stack.h DESTINATION "${CMAKE_SOURCE_DIR}/../include/")

message("--     Completing generation of CMake files for Stack")
