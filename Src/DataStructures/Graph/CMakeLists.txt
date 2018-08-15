cmake_minimum_required(VERSION 3.5.1)
project(Graph)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_FLAGS -fpermissive)

message("--     Generating CMake for Graph")

set(WEIGHTED_GRAPH_SOURCE_FILES WeightedGraph.cpp WeightedGraph.h
                                WeightedGraphNode.cpp WeightedGraphNode.h)
set(VERTEX_SOURCE_FILES Vertex.cpp Vertex.h)
set(EDGE_SOURCE_FILES Edge.cpp Edge.h)
set(SOURCE_FILES ${WEIGHTED_GRAPH_SOURCE_FILES} ${VERTEX_SOURCE_FILES}
                    ${EDGE_SOURCE_FILES})
include_directories(../../Headers)
include_directories(Graph)
include_directories(../Queue)

set(CMAKE_SHARED_LIBRARY_PREFIX "")
set(CMAKE_STATIC_LIBRARY_PREFIX "")

set(CMAKE_DEBUG_POSTFIX "_debug")

add_library(GraphShared SHARED ${SOURCE_FILES})
add_library(GraphStatic STATIC ${SOURCE_FILES})

add_executable(MainGraph MainGraph.cpp)
target_link_libraries(MainGraph GraphStatic)

install(TARGETS GraphShared DESTINATION "${CMAKE_SOURCE_DIR}/Lib/")
install(TARGETS GraphStatic DESTINATION "${CMAKE_SOURCE_DIR}/Lib/")
install(FILES WeightedGraph.h WeightedGraphNode.h DESTINATION "${CMAKE_SOURCE_DIR}/Include/")

message("--     Completing generation of CMake files for Graph")
