# Version of CMake project is compatible with
cmake_minimum_required(VERSION 3.5.1)
# Name of the project
project(DataStructuresAndAlgorithms)
# C++ Standard used
set(CMAKE_CXX_STANDARD 11)

message("Using CMake Version "
        ${CMAKE_MAJOR_VERSION}.${CMAKE_MINOR_VERSION}.${CMAKE_PATCH_VERSION})
STRING(TOLOWER "${CMAKE_BUILD_TYPE}" CMAKE_BUILD_TYPE_LOWER)
if("${CMAKE_SIZEOF_VOID_P}" EQUAL "8")
    set(BIT "64")
else()
    set(BIT "32")
endif()
if(WIN32)
    set(OS "Win")
elseif(UNIX AND NOT APPLE)
    set(OS "Linux")
endif()
if(CMAKE_BUILD_TYPE_LOWER STREQUAL "debug")
    message("Generating Makefiles for " ${CMAKE_BUILD_TYPE} " configuration")
elseif(CMAKE_BUILD_TYPE_LOWER STREQUAL "release")
    message("Generating Makefiles for " ${CMAKE_BUILD_TYPE} " configuration")
elseif(CMAKE_BUILD_TYPE_LOWER STREQUAL "relwithdebinfo")
    message("Generating Makefiles for " ${CMAKE_BUILD_TYPE} " configuration")
endif()
if(CMAKE_BUILD_TYPE_LOWER STREQUAL "debug")
    set(CMAKE_DEBUG_POSTFIX "_debug")
elseif(CMAKE_BUILD_TYPE_LOWER STREQUAL "release")
    set(CMAKE_DEBUG_POSTFIX "_release")
elseif(CMAKE_BUILD_TYPE_LOWER STREQUAL "relwithdebinfo")
    set(CMAKE_DEBUG_POSTFIX "_relwithdebinfo")
endif()

set(SOURCE_DIR ./Src)
set(HEADERS_DIR ./Src/Headers)
if(${TEST})
    message("Installation of files would happen in: " ${CMAKE_SOURCE_DIR})
    set(INSTALL_BINARY_DIR ${CMAKE_SOURCE_DIR}/Bin)
    set(INSTALL_LIB_DIR ${CMAKE_SOURCE_DIR}/Lib/${OS}${BIT})
    set(INSTALL_INCLUDE_DIR ${CMAKE_SOURCE_DIR}/Include)
else()
    message("Installation of files would happen in: " ${CMAKE_INSTALL_PREFIX})
    set(INSTALL_BINARY_DIR ${CMAKE_INSTALL_PREFIX}/Bin)
    set(INSTALL_LIB_DIR ${CMAKE_INSTALL_PREFIX}/Lib/${OS}${BIT})
    set(INSTALL_INCLUDE_DIR ${CMAKE_INSTALL_PREFIX}/Include)
endif()
set(ALGO_DIR ${SOURCE_DIR}/Algorithms)
set(NUMBERS_DIR ${ALGO_DIR}/Numbers)
set(DS_DIR ${SOURCE_DIR}/DataStructures)
set(STACK_DIR ${DS_DIR}/Stack)
set(GEOMETRY_DIR ${DS_DIR}/Geometry)

set(COMMON_HEADER ${HEADERS_DIR}/DefaultHeaders.h)

include_directories(${HEADERS_DIR})
include_directories(${NUMBERS_DIR})
include_directories(${STACK_DIR})
include_directories(${GEOMETRY_DIR})

set(NUMBERS_HEADER_FILES ${NUMBERS_DIR}/Factorization.h ${NUMBERS_DIR}/Fibonacci.h)
set(NUMBERS_SRC_FILES ${NUMBERS_DIR}/Factorization.cpp ${NUMBERS_DIR}/Fibonacci.cpp)

set(ALGO_HEADER_FILES ${NUMBERS_HEADER_FILES})
set(ALGO_SRC_FILES ${NUMBERS_SRC_FILES})

set(STACK_HEADER_FILES ${STACK_DIR}/Stack.h ${STACK_DIR}/StackNode.h)
set(STACK_SRC_FILES ${STACK_DIR}/Stack.cpp ${STACK_DIR}/StackNode.cpp)

set(GEOMETRY_HEADER_FILES ${GEOMETRY_DIR}/VectorNd.h ${GEOMETRY_DIR}/Vector2d.h
                            ${GEOMETRY_DIR}/Vector3d.h)
set(GEOMETRY_SRC_FILES ${GEOMETRY_DIR}/VectorNd.cpp ${GEOMETRY_DIR}/Vector2d.cpp
                        ${GEOMETRY_DIR}/Vector3d.cpp)

set(DS_HEADER_FILES ${STACK_HEADER_FILES} ${STACK_SRC_FILES} ${GEOMETRY_HEADER_FILES} ${GEOMETRY_SRC_FILES})

set(CMAKE_SHARED_LIBRARY_PREFIX "lib")
set(CMAKE_STATIC_LIBRARY_PREFIX "lib")

set(HEADER_FILES ${COMMON_HEADER} ${HEADERS_DIR}/Utilities.h
                    ${HEADERS_DIR}/Exceptions.h ${DS_HEADER_FILES} ${ALGO_HEADER_FILES}
                    ${GEOMETRY_HEADER_FILES})
set(SOURCE_FILES ${DS_SRC_FILES} ${ALGO_SRC_FILES})# ${GEOMETRY_SRC_FILES})

add_library(DSA_Shared SHARED ${SOURCE_FILES})
add_library(DSA_Static STATIC ${SOURCE_FILES})

add_library(DS_Interface INTERFACE)
target_sources(DS_Interface INTERFACE ${DS_HEADER_FILES})

add_library(Algo_Shared SHARED ${ALGO_SRC_FILES})
add_library(Algo_Static STATIC ${ALGO_SRC_FILES})

add_executable(Main_Static Main.cpp)
target_link_libraries(Main_Static DSA_Static)
add_executable(Main_Shared Main.cpp)
target_link_libraries(Main_Shared DSA_Shared)

install(TARGETS Main_Static DESTINATION ${INSTALL_BINARY_DIR})
install(TARGETS Main_Shared DESTINATION ${INSTALL_BINARY_DIR})
install(TARGETS DSA_Static DESTINATION ${INSTALL_LIB_DIR})
install(TARGETS DSA_Shared DESTINATION ${INSTALL_LIB_DIR})
install(TARGETS DS_Interface DESTINATION ${INSTALL_LIB_DIR})
install(TARGETS Algo_Static DESTINATION ${INSTALL_LIB_DIR})
install(TARGETS Algo_Shared DESTINATION ${INSTALL_LIB_DIR})
install(FILES ${HEADER_FILES} DESTINATION ${INSTALL_INCLUDE_DIR})

add_subdirectory(Test)
