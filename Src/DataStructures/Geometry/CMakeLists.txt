cmake_minimum_required(VERSION 3.5.1)
project(Geometry)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_FLAGS -fpermissive)

message("--     Generating CMake for Geometry")

set(SOURCE_FILES VectorNd.cpp VectorNd.h Vector2d.cpp Vector2d.h Vector3d.cpp Vector3d.h
                 Matrix.h Matrix.cpp)
include_directories(Geometry)

set(CMAKE_SHARED_LIBRARY_PREFIX "")
set(CMAKE_STATIC_LIBRARY_PREFIX "")

set(CMAKE_DEBUG_POSTFIX "_debug")

add_library(GeometryShared SHARED ${SOURCE_FILES})
add_library(GeometryStatic STATIC ${SOURCE_FILES})

add_executable(MainGeometry MainGeometry.cpp)
target_link_libraries(MainGeometry GeometryStatic)

install(TARGETS GeometryShared DESTINATION "${CMAKE_SOURCE_DIR}/Lib/")
install(TARGETS GeometryStatic DESTINATION "${CMAKE_SOURCE_DIR}/Lib/")
install(FILES VectorNd.h Vecto2d.h DESTINATION "${CMAKE_SOURCE_DIR}/Include/")

message("--     Completing generation of CMake files for Geometry")
