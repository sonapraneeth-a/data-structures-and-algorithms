cmake_minimum_required(VERSION 3.9)
project(mainTest)

add_subdirectory("./Lib/googletest")
include_directories("./Lib/googletest/googletest/include")
include_directories(../Src/Headers)
include_directories("../Src/DataStructures/List")
include_directories("../Src/Algorithms/Numbers")

set(CMAKE_CXX_STANDARD 11)
SET(ALGO_DIR ./Src/Algorithms)
SET(DS_DIR ./Src/DataStructures)

set(LIST_SOURCE_FILES ${DS_DIR}/TestSingleLinkedListNode.cpp ${DS_DIR}/TestSingleLinkedList.cpp)
add_executable(DsTest ${DS_DIR}/DsTest.cpp ${LIST_SOURCE_FILES})
target_link_libraries(DsTest DsStatic gtest)

set(BIG_INTEGER_SOURCE_FILES ${ALGO_DIR}/TestBigInteger.cpp)
add_executable(AlgoTest ${ALGO_DIR}/AlgoTest.cpp ${BIG_INTEGER_SOURCE_FILES})
target_link_libraries(AlgoTest AlgoStatic gtest)

