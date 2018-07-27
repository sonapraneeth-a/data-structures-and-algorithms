/**
 *      Created on: 01 April 2018
 *   Last modified: 14 July 2018
 *          Author: Sona Praneeth Akula
 *         Details: Header for Matrix2d
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
 *                                                 AdjacentMatrix2d, MinorMatrix2d, CofactorMatrix2d,
 *                                                 Inverse, Determinant, Cofactor, FirstOrderMinorSubMatrix2d
 *                                                 operators *, *=, ^, ^=, /, /=
 */

#ifndef MATRIX_H
#define MATRIX_H

#include "DefaultHeaders.h"

namespace LinAlg
{
    template<typename T>
    class Matrix2d
    {
    private:

        std::string _Matrix2d_Print_Start = "|";
        std::string _Matrix2d_Print_End = "|";
        T **_CoOrd;
        ULLI _NumberOfRows = 0;
        ULLI _NumberOfCols = 0;

    public:

        explicit Matrix2d(const size_t &NumberOfRows, const size_t &NumberOfCols, const T &InitValue = 0);

        explicit Matrix2d(const size_t &NumberOfRows, const T &InitValue = 0);

        explicit Matrix2d(const size_t NumberOfRows, const size_t NumberOfCols,
                        std::vector<T> Array, bool IsRowMajor = true);

        explicit Matrix2d(const size_t NumberOfRows, std::vector<T> Array, bool IsRowMajor = true);

        Matrix2d(const Matrix2d<T> &Matrix2d);

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
        operator<<(std::ostream & os, Matrix2d<T> const &Matrix2d)
        {
            return os << Matrix2d.ToString();
        }

        Matrix2d<T> operator + (Matrix2d<T> const &SecondMatrix2d);
        void operator += (Matrix2d<T> const &SecondMatrix2d);

        Matrix2d<T> operator - (Matrix2d<T> const &SecondMatrix2d);
        void operator -= (Matrix2d<T> const &SecondVector);

        Matrix2d<T> operator * (Matrix2d<T> const &SecondMatrix2d);
        void operator *= (Matrix2d<T> const &SecondMatrix2d);

        Matrix2d<T> operator * (const double &Value);
        void operator *= (const double &Value);

        Matrix2d<T> operator ^ (Matrix2d<T> const &SecondMatrix2d);
        void operator ^= (Matrix2d<T> const &SecondMatrix2d);

        Matrix2d<T> operator / (const double &Value);
        void operator /= (const double &Value);

        T operator ()(ULLI RowIndex, ULLI ColIndex) const;
        T& operator ()(ULLI RowIndex, ULLI ColIndex);

        Matrix2d<T>& operator = (Matrix2d<T> const &SecondMatrix2d);

        bool operator == (Matrix2d<T> const &SecondMatrix2d) const;

        // Reference: https://www.mathsisfun.com/algebra/matrix-inverse-minors-cofactors-adjugate.html
        double
        Determinant();

        Matrix2d<double>
        Inverse();

        Matrix2d<T>
        FirstOrderMinorSubMatrix2d(ULLI RowIndex, ULLI ColIndex);

        Matrix2d<T>
        AdjointMatrix2d();

        Matrix2d<T>
        MinorMatrix2d();

        Matrix2d<T>
        CofactorMatrix2d();

        short int
        Cofactor(ULLI RowIndex, ULLI ColIndex);

        Matrix2d<T>
        Transpose();

        ~Matrix2d();

    };
}

#endif //MATRIX_H
