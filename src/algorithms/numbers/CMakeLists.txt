cmake_minimum_required(VERSION 3.9)
project(list)

set(CMAKE_CXX_STANDARD 11)

message("--     Generating CMake for Numbers")

set(COMMON_HEADER ../../headers/default_headers.h)
set(SOURCE_FILES ${COMMON_HEADER} big_integer.h big_integer.cpp)
include_directories(numbers)

set(CMAKE_SHARED_LIBRARY_PREFIX "")
set(CMAKE_STATIC_LIBRARY_PREFIX "")

set(CMAKE_DEBUG_POSTFIX "_debug")

add_library(numbers_shared SHARED ${SOURCE_FILES})
add_library(numbers_static STATIC ${SOURCE_FILES})

add_executable(numbers_main numbers_main.cpp)
target_link_libraries(numbers_main numbers_static)

install(TARGETS numbers_shared DESTINATION "${CMAKE_SOURCE_DIR}/../lib/")
install(TARGETS numbers_static DESTINATION "${CMAKE_SOURCE_DIR}/../lib/")
install(FILES big_integer.h DESTINATION "${CMAKE_SOURCE_DIR}/../include/")

message("--     Completing generation of CMake files for Numbers")
