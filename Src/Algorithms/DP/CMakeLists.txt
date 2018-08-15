cmake_minimum_required(VERSION 3.5.1)
project(DP)

set(CMAKE_CXX_STANDARD 11)

message("--     Generating CMake for DP")

include_directories(../../Headers)

set(DP_SOURCE_FILES DP.h DP.cpp)
set(SOURCE_FILES ${DP_SOURCE_FILES})
include_directories(DP)

set(CMAKE_SHARED_LIBRARY_PREFIX "")
set(CMAKE_STATIC_LIBRARY_PREFIX "")

set(CMAKE_DEBUG_POSTFIX "_debug")

add_library(DPShared SHARED ${SOURCE_FILES})
add_library(DPStatic STATIC ${SOURCE_FILES})

add_executable(MainDP MainDP.cpp)
target_link_libraries(MainDP DPStatic)

install(TARGETS DPShared DESTINATION "${CMAKE_SOURCE_DIR}/Lib/")
install(TARGETS DPStatic DESTINATION "${CMAKE_SOURCE_DIR}/Lib/")
install(FILES DP.h DESTINATION "${CMAKE_SOURCE_DIR}/Include/")

message("--     Completing generation of CMake files for DP")
