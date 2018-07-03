# Version of CMake project is compatible with
cmake_minimum_required(VERSION 3.5.1)
# Name of the project
project(DataStructuresAndAlgorithms)
# C++ Standard used
set(CMAKE_CXX_STANDARD 11)

set(SOURCE_DIR ./Src)
set(ALGORITHMS_DIR ${SOURCE_DIR}/Algorithms)
set(NUMBERS_DIR ${ALGORITHMS_DIR}/Numbers)

set(COMMON_HEADER ./Src/Headers/DefaultHeaders.h)

include_directories(./Src/Headers)
include_directories(${NUMBERS_DIR})

set(NUMBERS_HEADER_FILES ${NUMBERS_DIR}/Factorization.h)
set(NUMBERS_SRC_FILES ${NUMBERS_DIR}/Factorization.cpp)

set(CMAKE_SHARED_LIBRARY_PREFIX "")
set(CMAKE_STATIC_LIBRARY_PREFIX "")

set(HEADER_FILES ${COMMON_HEADER} ./Src/Headers/Utilities.h Src/Headers/Exceptions.h ${NUMBERS_HEADER_FILES})
set(SOURCE_FILES ${NUMBERS_SRC_FILES})

set(CMAKE_DEBUG_POSTFIX "_debug")

add_library(DSA_Shared SHARED ${SOURCE_FILES})
add_library(DSA_Static STATIC ${SOURCE_FILES})

install(TARGETS DSA_Static DESTINATION "${CMAKE_SOURCE_DIR}/Lib/")
install(TARGETS DSA_Shared DESTINATION "${CMAKE_SOURCE_DIR}/Lib/")
install(FILES ${HEADER_FILES} DESTINATION "${CMAKE_SOURCE_DIR}/Include/")


