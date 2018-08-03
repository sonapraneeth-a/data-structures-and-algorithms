cmake_minimum_required(VERSION 3.5.1)
project(BigNumber)

set(CMAKE_CXX_STANDARD 11)

message("--     Generating CMake for BigNumber")

set(BIG_NUMBER_SOURCE_FILES BigNumber.h BigNumber.cpp)
set(SOURCE_FILES ${BIG_NUMBER_SOURCE_FILES})

include_directories(BigNumber)
include_directories(../../Headers)

set(CMAKE_SHARED_LIBRARY_PREFIX "")
set(CMAKE_STATIC_LIBRARY_PREFIX "")

set(CMAKE_DEBUG_POSTFIX "_debug")

add_library(BigNumberShared SHARED ${SOURCE_FILES})
add_library(BigNumberStatic STATIC ${SOURCE_FILES})

add_executable(MainBigNumber MainBigNumber.cpp)
target_link_libraries(MainBigNumber BigNumberStatic)

install(TARGETS BigNumberShared DESTINATION "${CMAKE_SOURCE_DIR}/Lib/")
install(TARGETS BigNumberStatic DESTINATION "${CMAKE_SOURCE_DIR}/Lib/")
install(FILES BigNumber.h DESTINATION "${CMAKE_SOURCE_DIR}/Include/")

message("--     Completing generation of CMake files for BigNumber")

        