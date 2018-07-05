cmake_minimum_required(VERSION 3.5.1)
project(Numbers)

set(CMAKE_CXX_STANDARD 11)

message("--     Generating CMake for Numbers")

include_directories(../../Headers)

set(BIG_INTEGER_SOURCE_FILES BigInteger.h BigInteger.cpp)
set(FIBONACCI_SOURCE_FILES Fibonacci.h Fibonacci.cpp)
set(MATH_SOURCE_FILES Math.h Math.cpp)
set(RANDOM_NUMBER_SOURCE_FILES RandomNumber.h RandomNumber.cpp)
set(FACTORIZATION_SOURCE_FILES Factorization.h Factorization.cpp)
set(SOURCE_FILES ${BIG_INTEGER_SOURCE_FILES} ${RANDOM_NUMBER_SOURCE_FILES} ${FIBONACCI_SOURCE_FILES}
                ${FACTORIZATION_SOURCE_FILES} ${MATH_SOURCE_FILES})
include_directories(Numbers)

set(CMAKE_SHARED_LIBRARY_PREFIX "")
set(CMAKE_STATIC_LIBRARY_PREFIX "")

set(CMAKE_DEBUG_POSTFIX "_debug")

add_library(NumbersShared SHARED ${SOURCE_FILES})
add_library(NumbersStatic STATIC ${SOURCE_FILES})

add_executable(MainNumbers MainNumbers.cpp)
target_link_libraries(MainNumbers NumbersStatic)

install(TARGETS NumbersShared DESTINATION "${CMAKE_SOURCE_DIR}/../Lib/")
install(TARGETS NumbersStatic DESTINATION "${CMAKE_SOURCE_DIR}/../Lib/")
install(FILES BigInteger.h RandomNumber.h DESTINATION "${CMAKE_SOURCE_DIR}/../Include/")

message("--     Completing generation of CMake files for Numbers")
