cmake_minimum_required(VERSION 3.9)
project(Array)

set(CMAKE_CXX_STANDARD 11)

message("--     Generating CMake for Array")

set(SOURCE_FILES DynamicArray.cpp DynamicArray.h)
include_directories(Array)

set(CMAKE_SHARED_LIBRARY_PREFIX "")
set(CMAKE_STATIC_LIBRARY_PREFIX "")

set(CMAKE_DEBUG_POSTFIX "_debug")

add_library(ArrayShared SHARED ${SOURCE_FILES})
add_library(ArrayStatic STATIC ${SOURCE_FILES})

add_executable(MainArray MainArray.cpp)
target_link_libraries(MainArray ArrayStatic)

install(TARGETS ArrayShared DESTINATION "${CMAKE_SOURCE_DIR}/../lib/")
install(TARGETS ArrayStatic DESTINATION "${CMAKE_SOURCE_DIR}/../lib/")
install(FILES DynamicArray.h DESTINATION "${CMAKE_SOURCE_DIR}/../include/")

message("--     Completing generation of CMake files for Array")
