cmake_minimum_required(VERSION 3.5.1)
project(String)

set(CMAKE_CXX_STANDARD 11)

message("--     Generating CMake for String")

set(TREE_SOURCE_FILES MyString.cpp MyString.h)
set(TRIE_SOURCE_FILES Trie.cpp Trie.h)
set(SUFFIX_TREE_SOURCE_FILES SuffixTree.cpp SuffixTree.h)
set(SOURCE_FILES ${TREE_SOURCE_FILES} ${TRIE_SOURCE_FILES} ${SUFFIX_TREE_SOURCE_FILES})
include_directories(String)

set(CMAKE_SHARED_LIBRARY_PREFIX "")
set(CMAKE_STATIC_LIBRARY_PREFIX "")

set(CMAKE_DEBUG_POSTFIX "_debug")

add_library(StringShared SHARED ${SOURCE_FILES})
add_library(StringStatic STATIC ${SOURCE_FILES})

add_executable(MainString MainString.cpp)
target_link_libraries(MainString StringStatic)

install(TARGETS StringShared DESTINATION "${CMAKE_SOURCE_DIR}/../lib/")
install(TARGETS StringStatic DESTINATION "${CMAKE_SOURCE_DIR}/../lib/")
install(FILES MyString.h DESTINATION "${CMAKE_SOURCE_DIR}/../include/")

message("--     Completing generation of CMake files for String")
