cmake_minimum_required(VERSION 3.9)
project(MainTest)

add_subdirectory("./Lib/googletest")
include_directories("./Lib/googletest/googletest/include")
include_directories(../Src/Headers)
include_directories("../Src/DataStructures/List")
include_directories("../Src/Algorithms/Numbers")

set(CMAKE_CXX_STANDARD 11)

SET(DS_DIR ./Src/DataStructures)
SET(NUMBERS_DIR Numbers)

SET(ALGO_DIR ./Src/Algorithms)
SET(LIST_DIR List)

set(LIST_TEST_FILES ${DS_DIR}/${LIST_DIR}/TestSingleLinkedListNode.cpp ${DS_DIR}/${LIST_DIR}/TestSingleLinkedList.cpp)
add_executable(DataStructuresTest ${DS_DIR}/DataStructuresTest.cpp ${LIST_TEST_FILES})
target_link_libraries(DataStructuresTest DsStatic gtest)

set(BIG_INTEGER_TEST_FILES ${ALGO_DIR}/${NUMBERS_DIR}/TestBigInteger.cpp)
set(FIBONACCI_TEST_FILES ${ALGO_DIR}/${NUMBERS_DIR}/TestFibonacci.cpp)
set(FACTORIZATION_TEST_FILES ${ALGO_DIR}/${NUMBERS_DIR}/TestFactorization.cpp)
add_executable(AlgorithmsTest ${ALGO_DIR}/AlgorithmsTest.cpp ${BIG_INTEGER_TEST_FILES} ${FIBONACCI_TEST_FILES}
                            ${FACTORIZATION_TEST_FILES})
target_link_libraries(AlgorithmsTest AlgoStatic gtest)

