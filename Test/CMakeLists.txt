cmake_minimum_required(VERSION 3.9)
project(MainTest)

add_subdirectory("./Lib/googletest")
include_directories("./Lib/googletest/googletest/include")
include_directories("./Lib/googletest/googlemock/include")
include_directories(../Src/Headers)
include_directories("../Src/DataStructures/List")
include_directories("../Src/DataStructures/Array")
include_directories("../Src/Algorithms/Numbers")

set(CMAKE_CXX_STANDARD 11)

SET(TEST_PREFIX Test)

SET(HEADERS_DIR ../Src/Headers)

SET(DS_DIR ./Src/DataStructures)
SET(NUMBERS_DIR Numbers)

SET(ALGO_DIR ./Src/Algorithms)
SET(LIST_DIR List)
SET(ARRAY_DIR Array)

set(LIST_TEST_FILES ${DS_DIR}/${LIST_DIR}/${TEST_PREFIX}-SingleLinkedListNode.cpp
                    ${DS_DIR}/${LIST_DIR}/${TEST_PREFIX}-SingleLinkedList.cpp)
set(ARRAY_TEST_FILES ${DS_DIR}/${ARRAY_DIR}/${TEST_PREFIX}-DynamicArray.cpp)
add_executable(DataStructuresTest ${DS_DIR}/Test-DataStructures.cpp ${LIST_TEST_FILES} ${ARRAY_TEST_FILES}
                ${HEADERS_DIR}/Utilities.cpp)
target_link_libraries(DataStructuresTest DsStatic gtest gmock)

set(BIG_INTEGER_TEST_FILES ${ALGO_DIR}/${NUMBERS_DIR}/${TEST_PREFIX}-BigInteger.cpp)
set(FIBONACCI_TEST_FILES ${ALGO_DIR}/${NUMBERS_DIR}/${TEST_PREFIX}-Fibonacci.cpp)
set(FACTORIZATION_TEST_FILES ${ALGO_DIR}/${NUMBERS_DIR}/${TEST_PREFIX}-Factorization.cpp)
add_executable(AlgorithmsTest ${ALGO_DIR}/Test-Algorithms.cpp ${BIG_INTEGER_TEST_FILES} ${FIBONACCI_TEST_FILES}
                            ${FACTORIZATION_TEST_FILES})
target_link_libraries(AlgorithmsTest AlgoStatic gtest)

