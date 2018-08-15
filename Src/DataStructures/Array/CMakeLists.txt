cmake_minimum_required(VERSION 3.5.1)
project(Array)

set(CMAKE_CXX_STANDARD 11)
if(CMAKE_BUILD_TYPE STREQUAL "Debug")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -DDEBUG_PRINT")
endif()

message("--     Generating CMake for Array")

set(DYNAMIC_ARRAY_SOURCE_FILES DynamicArray.cpp DynamicArray.h)
set(ARRAY_SOURCE_FILES Array.cpp Array.h)
set(SOURCE_FILES ${DYNAMIC_ARRAY_SOURCE_FILES} ${ARRAY_SOURCE_FILES})
include_directories(Array)

set(CMAKE_SHARED_LIBRARY_PREFIX "")
set(CMAKE_STATIC_LIBRARY_PREFIX "")

set(CMAKE_DEBUG_POSTFIX "_debug")

add_library(ArrayShared SHARED ${SOURCE_FILES})
add_library(ArrayStatic STATIC ${SOURCE_FILES})

add_executable(MainArray MainArray.cpp)
target_link_libraries(MainArray ArrayStatic)

install(TARGETS ArrayShared DESTINATION "${CMAKE_SOURCE_DIR}/../lib/")
install(TARGETS ArrayStatic DESTINATION "${CMAKE_SOURCE_DIR}/../lib/")
install(FILES DynamicArray.h Array.h DESTINATION "${CMAKE_SOURCE_DIR}/../include/")

message("--     Completing generation of CMake files for Array")
