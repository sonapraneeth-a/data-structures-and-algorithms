cmake_minimum_required(VERSION 3.9)
project(main_test)


add_subdirectory("./lib/googletest")
include_directories("./lib/googletest/googletest/include")
include_directories("../src/data_structures/list")

set(CMAKE_CXX_STANDARD 11)

set(LIST_SOURCE_FILES src/test_single_linked_list_node.cpp src/test_single_linked_list.cpp)
add_executable(main_test main.cpp ${LIST_SOURCE_FILES})
target_link_libraries(main_test ds_static gtest)
