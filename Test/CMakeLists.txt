cmake_minimum_required(VERSION 3.5.1)
project(MainTest)

set(CMAKE_CXX_STANDARD 11)

add_subdirectory("./Lib/googletest")
include_directories("./Lib/googletest/googletest/include")
include_directories("./Lib/googletest/googlemock/include")

SET(TEST_PREFIX Test-)

SET(SRC_HEADERS_DIR ../Src/Headers)
SET(SRC_LOG_HEADERS_DIR ../Src/Logging/Plog/include)
SET(SRC_ALGO_DIR ../Src/Algorithms)

SET(TEST_ALGO_DIR ./Src/Algorithms)
SET(TEST_NUMBERS_DIR ${TEST_ALGO_DIR}/Numbers)
SET(TEST_SEARCHSORT_DIR ${TEST_ALGO_DIR}/SearchSort)

SET(TEST_HEADERS_DIR ./Src/Headers)

include_directories("${SRC_HEADERS_DIR}")
include_directories("${SRC_LOG_HEADERS_DIR}")
include_directories("${TEST_HEADERS_DIR}")

include_directories("${SRC_ALGO_DIR}/Numbers")
include_directories("${SRC_ALGO_DIR}/SearchSort")

set(FIBONACCI_TEST_FILES ${TEST_NUMBERS_DIR}/${TEST_PREFIX}Fibonacci.cpp)
set(FACTORIZATION_TEST_FILES ${TEST_NUMBERS_DIR}/${TEST_PREFIX}Factorization.cpp)
set(MATH_TEST_FILES ${TEST_NUMBERS_DIR}/${TEST_PREFIX}Math.cpp)
set(SEARCH_TEST_FILES ${TEST_SEARCHSORT_DIR}/${TEST_PREFIX}Search.cpp)
set(SORT_TEST_FILES ${TEST_SEARCHSORT_DIR}/${TEST_PREFIX}Sort.cpp)

set(ALGORITHM_TEST_FILES ${FIBONACCI_TEST_FILES} ${FACTORIZATION_TEST_FILES}
                         ${MATH_TEST_FILES} ${SEARCH_TEST_FILES} ${SORT_TEST_FILES})
add_executable(AlgorithmsTest ${TEST_ALGO_DIR}/Test-Algorithms.cpp ${ALGORITHM_TEST_FILES})
target_link_libraries(AlgorithmsTest AlgoStatic gtest gtest_main)
target_link_libraries(AlgorithmsTest AlgoStatic gmock gmock_main)


SET(SRC_DS_DIR ../Src/DataStructures)
include_directories("${SRC_DS_DIR}/List")


SET(TEST_DS_DIR ./Src/DataStructures)
SET(TEST_LIST_DIR ${TEST_DS_DIR}/List)
SET(TEST_ARRAY_DIR ${TEST_DS_DIR}/Array)
SET(TEST_BIGNUMBER_DIR ${TEST_DS_DIR}/BigNumber)
SET(TEST_STACK_DIR ${TEST_DS_DIR}/Stack)
SET(TEST_QUEUE_DIR ${TEST_DS_DIR}/Queue)
SET(TEST_LIN_ALG_DIR ${TEST_DS_DIR}/LinearAlgebra)
SET(TEST_GRAPH_DIR ${TEST_DS_DIR}/Graph)
SET(TEST_STRING_DIR ${TEST_DS_DIR}/String)

include_directories("${SRC_DS_DIR}/List")
include_directories("${SRC_DS_DIR}/Array")
include_directories("${SRC_DS_DIR}/BigNumber")
include_directories("${SRC_DS_DIR}/Stack")
include_directories("${SRC_DS_DIR}/Queue")
include_directories("${SRC_DS_DIR}/LinearAlgebra")
include_directories("${SRC_DS_DIR}/Graph")
include_directories("${SRC_DS_DIR}/String")

set(LIST_TEST_FILES ${TEST_LIST_DIR}/${TEST_PREFIX}SingleLinkedListNode.cpp
                    ${TEST_LIST_DIR}/${TEST_PREFIX}SingleLinkedList.cpp)
set(DYNAMIC_ARRAY_TEST_FILES ${TEST_ARRAY_DIR}/${TEST_PREFIX}DynamicArray.cpp)
set(ARRAY_TEST_FILES ${TEST_ARRAY_DIR}/${TEST_PREFIX}Array.cpp)
set(BIGNUMBER_TEST_FILES ${TEST_BIGNUMBER_DIR}/${TEST_PREFIX}BigNumber.cpp)
set(STACK_TEST_FILES ${TEST_STACK_DIR}/${TEST_PREFIX}Stack.cpp)
set(QUEUE_TEST_FILES ${TEST_QUEUE_DIR}/${TEST_PREFIX}Queue.cpp)
set(LIN_ALG_TEST_FILES ${TEST_LIN_ALG_DIR}/${TEST_PREFIX}VectorNd.cpp
        ${TEST_LIN_ALG_DIR}/${TEST_PREFIX}Vector2d.cpp
        ${TEST_LIN_ALG_DIR}/${TEST_PREFIX}Vector3d.cpp)
set(GRAPH_TEST_FILES ${TEST_GRAPH_DIR}/${TEST_PREFIX}WeightedGraph.cpp)
set(STRING_TEST_FILES ${TEST_STRING_DIR}/${TEST_PREFIX}String.cpp)


set(DS_TEST_FILES ${LIST_TEST_FILES} ${ARRAY_TEST_FILES}
                  ${STACK_TEST_FILES} ${QUEUE_TEST_FILES}
                  ${LIN_ALG_TEST_FILES} ${GRAPH_TEST_FILES}
                  ${DYNAMIC_ARRAY_TEST_FILES})
add_executable(DataStructuresTest ${TEST_DS_DIR}/Test-DataStructures.cpp ${DS_TEST_FILES})
target_link_libraries(DataStructuresTest DsStatic gtest gtest_main)
target_link_libraries(DataStructuresTest DsStatic gmock gmock_main)


add_executable(MainTest MainTest.cpp ${ALGORITHM_TEST_FILES} ${DS_TEST_FILES})
target_link_libraries(MainTest AlgoStatic DsStatic gtest gtest_main)
target_link_libraries(MainTest AlgoStatic DsStatic gmock gmock_main)