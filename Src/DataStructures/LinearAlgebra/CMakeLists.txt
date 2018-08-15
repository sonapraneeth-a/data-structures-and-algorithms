cmake_minimum_required(VERSION 3.5.1)
project(LinearAlgebra)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_FLAGS -fpermissive)

message("--     Generating CMake for LinearAlgebra")

SET(VECTOR_ND_SOURCE_FILES VectorNd.cpp VectorNd.h)
SET(VECTOR_3D_SOURCE_FILES Vector3d.cpp Vector3d.h)
SET(VECTOR_2D_SOURCE_FILES Vector2d.cpp Vector2d.h)
SET(MATRIX_ND_SOURCE_FILES MatrixNd.h MatrixNd.cpp)
SET(MATRIX_2D_SOURCE_FILES Matrix2d.h Matrix2d.cpp)
set(SOURCE_FILES ${VECTOR_ND_SOURCE_FILES} ${VECTOR_3D_SOURCE_FILES}
                    ${VECTOR_2D_SOURCE_FILES} #${MATRIX_ND_SOURCE_FILES}
                    ${MATRIX_2D_SOURCE_FILES})
include_directories(LinearAlgebra)

set(CMAKE_SHARED_LIBRARY_PREFIX "")
set(CMAKE_STATIC_LIBRARY_PREFIX "")

set(CMAKE_DEBUG_POSTFIX "_debug")

add_library(LinearAlgebraShared SHARED ${SOURCE_FILES})
add_library(LinearAlgebraStatic STATIC ${SOURCE_FILES})

add_executable(MainLinearAlgebra MainLinearAlgebra.cpp)
target_link_libraries(MainLinearAlgebra LinearAlgebraStatic)

install(TARGETS LinearAlgebraShared DESTINATION "${CMAKE_SOURCE_DIR}/Lib/")
install(TARGETS LinearAlgebraStatic DESTINATION "${CMAKE_SOURCE_DIR}/Lib/")
install(FILES VectorNd.h Vecto2d.h Vector3d.h Matrix2d.h DESTINATION "${CMAKE_SOURCE_DIR}/Include/")

message("--     Completing generation of CMake files for LinearAlgebra")
