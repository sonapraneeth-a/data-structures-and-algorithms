cmake_minimum_required(VERSION 3.5.1)
project(String)

set(CMAKE_CXX_STANDARD 11)

message("--     Generating CMake for String")

set(SOURCE_FILES String.cpp String.h)
include_directories(String)

set(CMAKE_SHARED_LIBRARY_PREFIX "")
set(CMAKE_STATIC_LIBRARY_PREFIX "")

set(CMAKE_DEBUG_POSTFIX "_debug")

add_library(StringShared SHARED ${SOURCE_FILES})
add_library(StringStatic STATIC ${SOURCE_FILES})

add_executable(MainString MainString.cpp)
target_link_libraries(MainString StringStatic)

install(TARGETS StringShared DESTINATION "${CMAKE_SOURCE_DIR}/../lib/")
install(TARGETS StringStatic DESTINATION "${CMAKE_SOURCE_DIR}/../lib/")
install(FILES String.h DESTINATION "${CMAKE_SOURCE_DIR}/../include/")

message("--     Completing generation of CMake files for String")
