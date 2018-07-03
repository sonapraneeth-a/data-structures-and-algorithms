# Version of CMAke project is compatible with
cmake_minimum_required(VERSION 3.5.1)
# Name of the project
project(Algorithms)
# C++ Standard used
set(CMAKE_CXX_STANDARD 11)

message("--   Generating CMake for Algorithms")

set(CMAKE_SHARED_LIBRARY_PREFIX "lib")
set(CMAKE_STATIC_LIBRARY_PREFIX "lib")

set(NUMBERS_DIR Numbers)
set(HEADERS_DIR ../Headers)

set(COMMON_HEADER ${HEADERS_DIR}/DefaultHeaders.h)

include_directories(${HEADERS_DIR})
include_directories(${NUMBERS_DIR})

set(NUMBERS_HEADER_FILES ${NUMBERS_DIR}/Factorization.h)
set(NUMBERS_SRC_FILES ${NUMBERS_DIR}/Factorization.cpp)


# Debug libraries are prefixed with "d"
set(CMAKE_DEBUG_POSTFIX "_debug")

set(HEADER_FILES ${COMMON_HEADER} ${HEADERS_DIR}/Utilities.h ${HEADERS_DIR}/Exceptions.h ${NUMBERS_HEADER_FILES})
set(SOURCE_FILES ${NUMBERS_SRC_FILES})

add_library(AlgoShared SHARED ${SOURCE_FILES})
add_library(AlgoStatic STATIC ${SOURCE_FILES})

install(TARGETS Algo_Static DESTINATION "${CMAKE_SOURCE_DIR}/Lib/")
install(TARGETS Algo_Shared DESTINATION "${CMAKE_SOURCE_DIR}/Lib/")
install(FILES ${HEADER_FILES} DESTINATION "${CMAKE_SOURCE_DIR}/Include/")

message("--   Completing generation of CMake files for Algorithms")
