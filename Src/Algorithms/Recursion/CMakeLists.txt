cmake_minimum_required(VERSION 3.5.1)
project(Recursion)

set(CMAKE_CXX_STANDARD 11)

message("--     Generating CMake for Recursion")

include_directories(../../Headers)

set(RECURSION_SOURCE_FILES Recursion.h Recursion.cpp)
set(SOURCE_FILES ${RECURSION_SOURCE_FILES})
include_directories(Recursion)

set(CMAKE_SHARED_LIBRARY_PREFIX "")
set(CMAKE_STATIC_LIBRARY_PREFIX "")

set(CMAKE_DEBUG_POSTFIX "_debug")

add_library(RecursionShared SHARED ${SOURCE_FILES})
add_library(RecursionStatic STATIC ${SOURCE_FILES})

add_executable(MainRecursion MainRecursion.cpp)
target_link_libraries(MainRecursion RecursionStatic)

install(TARGETS RecursionShared DESTINATION "${CMAKE_SOURCE_DIR}/Lib/")
install(TARGETS RecursionStatic DESTINATION "${CMAKE_SOURCE_DIR}/Lib/")
install(FILES Recursion.h DESTINATION "${CMAKE_SOURCE_DIR}/Include/")

message("--     Completing generation of CMake files for Recursion")
