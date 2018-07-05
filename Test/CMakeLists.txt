cmake_minimum_required(VERSION 3.5.1)
project(MainTest)

add_subdirectory("./Lib/googletest")
include_directories("./Lib/googletest/googletest/include")
include_directories("./Lib/googletest/googlemock/include")
include_directories(./Src/Headers)
include_directories(../Src/Headers)
include_directories("../Src/DataStructures/List")
include_directories("../Src/DataStructures/Array")
include_directories("../Src/DataStructures/Stack")
include_directories("../Src/DataStructures/Queue")
include_directories("../Src/DataStructures/String")
include_directories("../Src/Algorithms/Numbers")

set(CMAKE_CXX_STANDARD 11)

SET(TEST_PREFIX Test)

SET(HEADERS_DIR ../Src/Headers)

SET(ALGO_DIR ./Src/Algorithms)
SET(NUMBERS_DIR Numbers)

SET(DS_DIR ./Src/DataStructures)
SET(LIST_DIR List)
SET(ARRAY_DIR Array)
SET(STACK_DIR Stack)
SET(QUEUE_DIR Queue)
SET(STRING_DIR String)

set(LIST_TEST_FILES ${DS_DIR}/${LIST_DIR}/${TEST_PREFIX}-SingleLinkedListNode.cpp
                    ${DS_DIR}/${LIST_DIR}/${TEST_PREFIX}-SingleLinkedList.cpp)
set(ARRAY_TEST_FILES ${DS_DIR}/${ARRAY_DIR}/${TEST_PREFIX}-DynamicArray.cpp)
set(STACK_TEST_FILES ${DS_DIR}/${STACK_DIR}/${TEST_PREFIX}-Stack.cpp)
set(STRING_TEST_FILES ${DS_DIR}/${STRING_DIR}/${TEST_PREFIX}-String.cpp)
add_executable(DataStructuresTest
                    ${DS_DIR}/Test-DataStructures.cpp ${LIST_TEST_FILES} ${ARRAY_TEST_FILES}
                    ${STACK_TEST_FILES} ${STRING_TEST_FILES})
target_link_libraries(DataStructuresTest DsStatic gtest gmock)

set(BIG_INTEGER_TEST_FILES ${ALGO_DIR}/${NUMBERS_DIR}/${TEST_PREFIX}-BigInteger.cpp)
set(FIBONACCI_TEST_FILES ${ALGO_DIR}/${NUMBERS_DIR}/${TEST_PREFIX}-Fibonacci.cpp)
set(FACTORIZATION_TEST_FILES ${ALGO_DIR}/${NUMBERS_DIR}/${TEST_PREFIX}-Factorization.cpp)
add_executable(AlgorithmsTest ${ALGO_DIR}/Test-Algorithms.cpp ${BIG_INTEGER_TEST_FILES} ${FIBONACCI_TEST_FILES}
                            ${FACTORIZATION_TEST_FILES})
target_link_libraries(AlgorithmsTest AlgoStatic gtest)

