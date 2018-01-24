cmake_minimum_required(VERSION 3.9)
project(main_test)

add_subdirectory("./lib/googletest")
include_directories("./lib/googletest/googletest/include")
include_directories(../src/headers)
include_directories("../src/data_structures/list")
include_directories("../src/algorithms/numbers")

set(CMAKE_CXX_STANDARD 11)
SET(ALGO_DIR ./src/algorithms)
SET(DS_DIR ./src/data_structures)

set(LIST_SOURCE_FILES ${DS_DIR}/test_single_linked_list_node.cpp ${DS_DIR}/test_single_linked_list.cpp)
add_executable(ds_test ${DS_DIR}/ds_test.cpp ${LIST_SOURCE_FILES})
target_link_libraries(ds_test ds_static gtest)

set(BIG_INTEGER_SOURCE_FILES ${ALGO_DIR}/test_big_integer.cpp)
add_executable(algo_test ${ALGO_DIR}/algo_test.cpp ${BIG_INTEGER_SOURCE_FILES})
target_link_libraries(algo_test algo_static gtest)

