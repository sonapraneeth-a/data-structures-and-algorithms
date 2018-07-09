cmake_minimum_required(VERSION 3.5.1)
project(SearchSort)

set(CMAKE_CXX_STANDARD 11)

message("--     Generating CMake for SearchSort")

set(COMMON_HEADER ../../Headers/DefaultHeaders.h)
set(SEARCH_SOURCE_FILES ${COMMON_HEADER} Search.h)
set(SORT_SOURCE_FILES ${COMMON_HEADER} Sort.h)
set(SOURCE_FILES ${SEARCH_SOURCE_FILES} ${SORT_SOURCE_FILES})

include_directories(../../Headers)
include_directories(SearchSort)

set(CMAKE_SHARED_LIBRARY_PREFIX "")
set(CMAKE_STATIC_LIBRARY_PREFIX "")

set(CMAKE_DEBUG_POSTFIX "_debug")

#add_library(SearchSortShared SHARED ${SOURCE_FILES})
#add_library(SearchSortStatic STATIC ${SOURCE_FILES})

add_executable(MainSearchSort MainSearchSort.cpp)
#target_link_libraries(MainSearchSort SearchSortStatic)

#install(TARGETS SearchSortShared DESTINATION "${CMAKE_SOURCE_DIR}/Lib/")
#install(TARGETS SearchSortStatic DESTINATION "${CMAKE_SOURCE_DIR}/Lib/")
install(FILES Sort.h Search.h DESTINATION "${CMAKE_SOURCE_DIR}/Include/")

message("--     Completing generation of CMake files for SearchSort")
