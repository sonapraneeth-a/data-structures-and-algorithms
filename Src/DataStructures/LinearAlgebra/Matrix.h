/**
 *      Created on: 01 April 2018
 *   Last modified: 14 July 2018
 *          Author: Sona Praneeth Akula
 *         Details: Header for Matrix
 */

/**
 * Changelog
 *
 * Date (DD-MM-YYYY)            Author               Update
 * 01-04-2018             Sona Praneeth Akula    - Creation of file
 * 13-07-2018             Sona Praneeth Akula    - Added function signatures for functions
 *                                                 Transpose, Inverse, Determinant, GetCellData,
 *                                                 SetCellData, Fill, GetNumberOfRows, GetNumberOfColumns,
 *                                                 ToString, Copy constructor and operators +, -,
 *                                                 *, +=, -=, *=, (), ==, =, <<
 * 14-07-2018             Sona Praneeth Akula    - Added function signatures for functions
 *                                                 AdjacentMatrix, MinorMatrix, CofactorMatrix,
 *                                                 Inverse, Determinant, Cofactor, FirstOrderMinorSubMatrix
 *                                                 operators *, *=, ^, ^=, /, /=
 */

#ifndef MATRIX_H
#define MATRIX_H

#include "DefaultHeaders.h"

namespace LinAlg
{
    template<typename T>
    class Matrix
    {
    private:

        std::string _Matrix_Print_Start = "|";
        std::string _Matrix_Print_End = "|";
        T **_CoOrd;
        ULLI _NumberOfRows = 0;
        ULLI _NumberOfCols = 0;

    public:

        explicit Matrix(const size_t &NumberOfRows, const size_t &NumberOfCols, const T &InitValue = 0);

        explicit Matrix(const size_t &NumberOfRows, const T &InitValue = 0);

        explicit Matrix(const size_t NumberOfRows, const size_t NumberOfCols,
                        std::vector<T> Array, bool IsRowMajor = true);

        explicit Matrix(const size_t NumberOfRows, std::vector<T> Array, bool IsRowMajor = true);

        Matrix(const Matrix<T> &Matrix);

        void
        Fill(const T &Value);

        T
        GetCellData(ULLI RowIndex, ULLI ColIndex);

        void
        SetCellData(ULLI RowIndex, ULLI ColIndex, T Value);

        ULLI
        NumberOfRows() const;

        ULLI
        NumberOfColumns() const;

        std::string
        ToString() const;

        friend std::ostream &
        operator<<(std::ostream & os, Matrix<T> const &Matrix)
        {
            return os << Matrix.ToString();
        }

        Matrix<T> operator + (Matrix<T> const &SecondMatrix);
        void operator += (Matrix<T> const &SecondMatrix);

        Matrix<T> operator - (Matrix<T> const &SecondMatrix);
        void operator -= (Matrix<T> const &SecondVector);

        Matrix<T> operator * (Matrix<T> const &SecondMatrix);
        void operator *= (Matrix<T> const &SecondMatrix);

        Matrix<T> operator * (const double &Value);
        void operator *= (const double &Value);

        Matrix<T> operator ^ (Matrix<T> const &SecondMatrix);
        void operator ^= (Matrix<T> const &SecondMatrix);

        Matrix<T> operator / (const double &Value);
        void operator /= (const double &Value);

        T operator ()(ULLI RowIndex, ULLI ColIndex) const;
        T& operator ()(ULLI RowIndex, ULLI ColIndex);

        Matrix<T>& operator = (Matrix<T> const &SecondMatrix);

        bool operator == (Matrix<T> const &SecondMatrix) const;

        // Reference: https://www.mathsisfun.com/algebra/matrix-inverse-minors-cofactors-adjugate.html
        double
        Determinant();

        Matrix<double>
        Inverse();

        Matrix<T>
        FirstOrderMinorSubMatrix(ULLI RowIndex, ULLI ColIndex);

        Matrix<T>
        AdjointMatrix();

        Matrix<T>
        MinorMatrix();

        Matrix<T>
        CofactorMatrix();

        short int
        Cofactor(ULLI RowIndex, ULLI ColIndex);

        Matrix<T>
        Transpose();

        ~Matrix();

    };
}

#endif //MATRIX_H
