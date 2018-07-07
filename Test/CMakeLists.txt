cmake_minimum_required(VERSION 3.5.1)
project(MainTest)

add_subdirectory("./Lib/googletest")
include_directories("./Lib/googletest/googletest/include")
include_directories("./Lib/googletest/googlemock/include")
include_directories(../Src/Headers)
include_directories("../Src/DataStructures/Stack")
include_directories("../Src/DataStructures/Geometry")
include_directories("../Src/Algorithms/Numbers")

set(CMAKE_CXX_STANDARD 11)

set(TEST_PREFIX Test-)

set(HEADERS_DIR ../Src/Headers)
set(ALGO_DIR ./Src/Algorithms)
set(NUMBERS_DIR ${ALGO_DIR}/Numbers)
set(DS_DIR ./Src/DataStructures)
set(STACK_DIR ${DS_DIR}/Stack)
set(GEOMETRY_DIR ${DS_DIR}/Geometry)

set(STACK_TEST_FILES ${STACK_DIR}/${TEST_PREFIX}Stack.cpp)
set(VECTOR_TEST_FILES ${GEOMETRY_DIR}/${TEST_PREFIX}VectorNd.cpp
                        ${GEOMETRY_DIR}/${TEST_PREFIX}Vector2d.cpp)
add_executable(DataStructuresTest ${DS_DIR}/Test-DataStructures.cpp
                        ${STACK_TEST_FILES} ${VECTOR_TEST_FILES})
target_link_libraries(DataStructuresTest DSA_Static gtest gmock)

set(FIBONACCI_TEST_FILES ${NUMBERS_DIR}/${TEST_PREFIX}Fibonacci.cpp)
set(FACTORIZATION_TEST_FILES ${NUMBERS_DIR}/${TEST_PREFIX}Factorization.cpp)
add_executable(AlgorithmsTest ${ALGO_DIR}/Test-Algorithms.cpp
                        ${FIBONACCI_TEST_FILES}
                        ${FACTORIZATION_TEST_FILES})
target_link_libraries(AlgorithmsTest DSA_Static gtest gmock)

