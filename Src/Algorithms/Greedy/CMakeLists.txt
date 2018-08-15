cmake_minimum_required(VERSION 3.5.1)
project(Greedy)

set(CMAKE_CXX_STANDARD 11)

message("--     Generating CMake for Greedy")

include_directories(../../Headers)

set(GREEDY_SOURCE_FILES Greedy.h Greedy.cpp)
set(SOURCE_FILES ${GREEDY_SOURCE_FILES})
include_directories(Greedy)

set(CMAKE_SHARED_LIBRARY_PREFIX "")
set(CMAKE_STATIC_LIBRARY_PREFIX "")

set(CMAKE_DEBUG_POSTFIX "_debug")

add_library(GreedyShared SHARED ${SOURCE_FILES})
add_library(GreedyStatic STATIC ${SOURCE_FILES})

add_executable(MainGreedy MainGreedy.cpp)
target_link_libraries(MainGreedy GreedyStatic)

install(TARGETS GreedyShared DESTINATION "${CMAKE_SOURCE_DIR}/Lib/")
install(TARGETS GreedyStatic DESTINATION "${CMAKE_SOURCE_DIR}/Lib/")
install(FILES Greedy.h DESTINATION "${CMAKE_SOURCE_DIR}/Include/")

message("--     Completing generation of CMake files for Greedy")
