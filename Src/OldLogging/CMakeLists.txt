cmake_minimum_required(VERSION 3.5.1)
project(Stack)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_FLAGS -fpermissive)

message("--   Generating CMake for Logging module")

set(SOURCE_FILES BaseLogging.cpp BaseLogging.h)
include_directories(../Headers)
include_directories(Logging)

set(CMAKE_SHARED_LIBRARY_PREFIX "")
set(CMAKE_STATIC_LIBRARY_PREFIX "")

set(CMAKE_DEBUG_POSTFIX "_debug")

add_library(LoggingShared SHARED ${SOURCE_FILES})
add_library(LoggingStatic STATIC ${SOURCE_FILES})

add_executable(MainLogging MainLogging.cpp)
target_link_libraries(MainLogging LoggingStatic)

install(TARGETS LoggingShared DESTINATION "${CMAKE_SOURCE_DIR}/Lib/")
install(TARGETS LoggingStatic DESTINATION "${CMAKE_SOURCE_DIR}/Lib/")
install(FILES BaseLogging.h DESTINATION "${CMAKE_SOURCE_DIR}/Include/")

message("--   Completing generation of CMake files for Logging module")
