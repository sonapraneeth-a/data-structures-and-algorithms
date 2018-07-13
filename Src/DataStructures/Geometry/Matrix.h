/**
 *      Created on: 01 April 2018
 *   Last modified: 13 July 2018
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
 */

#ifndef MATRIX_H
#define MATRIX_H

#include "DefaultHeaders.h"

namespace Geometry
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

        explicit Matrix(const ULLI &NumberOfRows, const ULLI &NumberOfCols, const T &InitValue = 0);

        explicit Matrix(const ULLI &NumberOfRows, const T &InitValue = 0);

        Matrix(const Matrix<T> &Matrix);

        void
        Fill(const T &Value);

        T
        GetCellData(ULLI RowIndex, ULLI ColIndex);

        void
        SetCellData(ULLI RowIndex, ULLI ColIndex, T Value);

        ULLI
        GetNumberOfRows() const;

        ULLI
        GetNumberOfColumns() const;

        std::string
        ToString() const;

        friend std::ostream &
        operator<<(std::ostream & os, Matrix<T> const &Matrix)
        {
            return os << Matrix.ToString() << "\n";
        }

        Matrix<T> operator + (Matrix<T> const &SecondMatrix);
        void operator += (Matrix<T> const &SecondMatrix);

        Matrix<T> operator - (Matrix<T> const &SecondMatrix);
        void operator -= (Matrix<T> const &SecondVector);

        Matrix<T> operator * (Matrix<T> const &SecondMatrix);
        void operator *= (Matrix<T> const &SecondMatrix);

        T operator ()(ULLI RowIndex, ULLI ColIndex) const;
        T& operator ()(ULLI RowIndex, ULLI ColIndex);

        Matrix<T>& operator = (Matrix<T> const &SecondMatrix);

        bool operator == (Matrix<T> const &SecondMatrix) const;

        double
        Determinant();

        Matrix<T>
        Inverse();

        Matrix<T>
        Transpose();

        ~Matrix();

    };
}

#endif //MATRIX_H
