//
// Created by pranas on 7/6/2018.
//

#include "Vector2d.h"
#include "Matrix2d.h"

void
RunVectorNd()
{
    std::cout << "====== Running code for VectorNd ======\n";
    LinAlg::VectorNd<int> v(10);
    LinAlg::VectorNd<int> v1(10, 1);
    /*LinAlg::VectorNd<int> v2 = v + v1;
    std::cout << "Vector v(0): " << v[0] << "\n";
    std::cout << "Vector v1(0): " << v1[0] << "\n";
    std::cout << " Vector v: " << v;
    std::cout << " Vector v1: " << v1;
    std::cout << " Vector v2: " << v2;
    std::cout << " Vector v2 (norm): " << v2.Normalize();
    std::cout << " Vector v2: " << v2[0] << ", " << v2[1] << "\n";
    std::cout << "Vector add: " << v + v2 << "\n";*/
    return ;
}

void
RunVector2d()
{
    std::cout << "====== Running code for Vector2d ======\n";
    LinAlg::Vector2d<int> v(10);
    LinAlg::Vector2d<int> v1;
    LinAlg::Vector2d<int> v2 = v + v1;
    std::cout << "Vector v(0): " << v.GetX() << "\n";
    std::cout << "Vector v1(0): " << v1.GetX() << "\n";
    std::cout << " Vector v: " << v;
    std::cout << " Vector v1: " << v1;
    std::cout << " Vector v2: " << v2;
    std::cout << " Vector v2 (norm): " << v2.Normalize();
    std::cout << " Vector v2: " << v2.GetX() << ", " << v2.GetY() << "\n";
    std::cout << "Vector add: " << v + v2 << "\n";
    return ;
}

void
RunMatrix()
{
    std::cout << "====== Running code for Matrix2d ======\n";
    /*LinAlg::Matrix2d<int> mat1(3, 0);
    mat1(1, 1) = 1; mat1(1, 2) = 2; mat1(1, 3) = 3;
    mat1(2, 1) = 4; mat1(2, 2) = 5; mat1(2, 3) = 6;
    mat1(3, 1) = 7; mat1(3, 2) = 8; mat1(3, 3) = 9;
    std::cout << mat1.GetFirstOrderMinorSubMatrix(1, 1) << "\n";
    std::cout << mat1.GetFirstOrderMinorSubMatrix(1, 1).Determinant() << "\n";
    std::cout << mat1.GetFirstOrderMinorSubMatrix(1, 2) << "\n";
    std::cout << mat1.GetFirstOrderMinorSubMatrix(1, 2).Determinant() << "\n";
    std::cout << mat1.GetFirstOrderMinorSubMatrix(1, 3) << "\n";
    std::cout << mat1.FirstOrderMinorSubMatrix(1, 3).Determinant() << "\n";
    std::cout << mat1.Determinant() << "\n";*/
    /*LinAlg::Matrix2d<int> mat2(3, 0);
    mat2(1, 1) = 3; mat2(1, 2) = 0; mat2(1, 3) = 2;
    mat2(2, 1) = 2; mat2(2, 2) = 0; mat2(2, 3) = -2;
    mat2(3, 1) = 0; mat2(3, 2) = 1; mat2(3, 3) = 1;
    std::cout << mat2.Determinant() << "\n";
    std::cout << mat2.MinorMatrix() << "\n";
    std::cout << mat2.CofactorMatrix() << "\n";
    std::cout << mat2.AdjointMatrix() << "\n";
    std::cout << mat2.Inverse() << "\n";*/
    // Reference: https://www.mathsisfun.com/algebra/matrix-multiplying.html
    /*LinAlg::Matrix2d<int> mat3(2, 3, 0), mat4(3, 2, 0);
    mat3(1, 1) = 1; mat3(1, 2) = 2; mat3(1, 3) = 3;
    mat3(2, 1) = 4; mat3(2, 2) = 5; mat3(2, 3) = 6;
    mat4(1, 1) = 7; mat4(1, 2) = 8;
    mat4(2, 1) = 9; mat4(2, 2) = 10;
    mat4(3, 1) = 11; mat4(3, 2) = 12;
    std::cout << mat3 * mat4 << "\n";*/
    LinAlg::Matrix2d<int> mat(3, 3, {1, 2, 3, 4, 5, 6});
    std::cout << mat << "\n";
}

int main()
{
    RunVectorNd();
    // RunVector2d();
    // RunMatrix();
    return 0;
}