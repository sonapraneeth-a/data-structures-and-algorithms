cmake_minimum_required(VERSION 3.9)
project(List)

set(CMAKE_CXX_STANDARD 11)

message("--     Generating CMake for Numbers")

set(COMMON_HEADER ../../Headers/DefaultHeaders.h)
set(BIG_INTEGER_SOURCE_FILES ${COMMON_HEADER} BigInteger.h BigInteger.cpp)
set(RANDOM_NUMBER_SOURCE_FILES ${COMMON_HEADER} RandomNumber.h RandomNumber.cpp)
set(SOURCE_FILES ${BIG_INTEGER_SOURCE_FILES} ${RANDOM_NUMBER_SOURCE_FILES})
include_directories(Numbers)

set(CMAKE_SHARED_LIBRARY_PREFIX "")
set(CMAKE_STATIC_LIBRARY_PREFIX "")

set(CMAKE_DEBUG_POSTFIX "_debug")

add_library(NumbersShared SHARED ${SOURCE_FILES})
add_library(NumbersStatic STATIC ${SOURCE_FILES})

add_executable(MainNumbers MainNumbers.cpp)
target_link_libraries(MainNumbers NumbersStatic)

install(TARGETS NumbersShared DESTINATION "${CMAKE_SOURCE_DIR}/../Lib/")
install(TARGETS NumbersStatic DESTINATION "${CMAKE_SOURCE_DIR}/../Lib/")
install(FILES BigInteger.h RandomNumber.h DESTINATION "${CMAKE_SOURCE_DIR}/../Include/")

message("--     Completing generation of CMake files for Numbers")
