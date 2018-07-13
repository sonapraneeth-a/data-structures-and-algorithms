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
 *                                                 Transpose, GetCellData, SetCellData,
 *                                                 Fill, GetNumberOfRows, GetNumberOfColumns,
 *                                                 ToString, Copy constructor and operators +, -,
 *                                                 +=, -=, (), ==, =, <<
 */

#include "Matrix.h"

template <typename T>
Geometry::Matrix<T>::Matrix(const ULLI &NumberOfRows,
                          const ULLI &NumberOfCols,
                          const T &InitValue)
{
    this->_NumberOfRows = NumberOfRows;
    this->_NumberOfCols = NumberOfCols;
    this->_CoOrd = new T*[NumberOfRows];
    for(ULLI row_index = 0; row_index < NumberOfRows; ++row_index)
    {
        this->_CoOrd[row_index] = new T[NumberOfCols];
    }
    Geometry::Matrix<T>::Fill(InitValue);
}

template <typename T>
Geometry::Matrix<T>::Matrix(const ULLI &NumberOfRows,
                          const T &InitValue)
{
    this->_NumberOfRows = NumberOfRows;
    this->_NumberOfCols = NumberOfRows;
    this->_CoOrd = new T*[NumberOfRows];
    for(ULLI row_index = 0; row_index < NumberOfRows; ++row_index)
    {
        this->_CoOrd[row_index] = new T[NumberOfRows];
    }
    Geometry::Matrix<T>::Fill(InitValue);
}

template <typename T>
Geometry::Matrix<T>::Matrix(const Matrix<T> &Matrix)
{
    for (ULLI row_index = 0; row_index < this->_NumberOfRows; ++row_index)
    {
        for (ULLI col_index = 0; col_index < this->_NumberOfCols; ++col_index)
        {
            this->_CoOrd[row_index][col_index] = Matrix(row_index, col_index);
        }
    }
}

template <typename T>
std::string
Geometry::Matrix<T>::ToString() const
{
    std::string answer = "";
    for (ULLI row_index = 0; row_index < this->_NumberOfRows; ++row_index)
    {
        answer += _Matrix_Print_Start + " ";
        for (ULLI col_index = 0; col_index < this->_NumberOfCols; ++col_index)
        {
            if (col_index < this->_NumberOfCols-1)
                answer += std::to_string(this->_CoOrd[row_index][col_index]) + ", ";
            else
                answer += std::to_string(this->_CoOrd[row_index][col_index]);
        }
        answer += " " + _Matrix_Print_End + "\n";
    }
    return answer;
}

template <typename T>
void
Geometry::Matrix<T>::Fill(const T &Value)
{
    for (ULLI row_index = 0; row_index < this->_NumberOfRows; ++row_index)
    {
        for (ULLI col_index = 0; col_index < this->_NumberOfCols; ++col_index)
        {
            this->_CoOrd[row_index][col_index] = Value;
        }
    }
}

template <typename T>
T
Geometry::Matrix<T>::operator ()(ULLI RowIndex, ULLI ColIndex) const
{
    if (RowIndex >= 1 && RowIndex <= this->_NumberOfRows &&
        ColIndex >= 1 && ColIndex <= this->_NumberOfCols )
        return this->_CoOrd[RowIndex-1][ColIndex-1];
    std::string exceptionMessage = "IndexOutOfBounds. Requesting ("
                                   + std::to_string(RowIndex) + ", " + std::to_string(ColIndex)
                                   + ") of (" + std::to_string(this->_NumberOfRows) + ", "
                                   + std::to_string(this->_NumberOfCols) + ")";
    throw OutOfBoundsException();
}

template <typename T>
T&
Geometry::Matrix<T>::operator ()(ULLI RowIndex, ULLI ColIndex)
{
    if (RowIndex >= 1 && RowIndex <= this->_NumberOfRows &&
        ColIndex >= 1 && ColIndex <= this->_NumberOfCols )
        return this->_CoOrd[RowIndex-1][ColIndex-1];
    std::string exceptionMessage = "IndexOutOfBounds. Requesting ("
                                   + std::to_string(RowIndex) + ", " + std::to_string(ColIndex)
                                   + ") of (" + std::to_string(this->_NumberOfRows) + ", "
                                   + std::to_string(this->_NumberOfCols) + ")";
    throw OutOfBoundsException();
}

template <typename T>
ULLI
Geometry::Matrix<T>::GetNumberOfRows() const
{
    return this->_NumberOfRows;
}

template <typename T>
ULLI
Geometry::Matrix<T>::GetNumberOfColumns() const
{
    return this->_NumberOfCols;
}

template <typename T>
T
Geometry::Matrix<T>::GetCellData(ULLI RowIndex, ULLI ColIndex)
{
    if (RowIndex >= 1 && RowIndex <= this->_NumberOfRows &&
        ColIndex >= 1 && ColIndex <= this->_NumberOfCols )
        return this->_CoOrd[RowIndex-1][ColIndex-1];
    std::string exceptionMessage = "IndexOutOfBounds. Requesting ("
                                   + std::to_string(RowIndex) + ", " + std::to_string(ColIndex)
                                   + ") of (" + std::to_string(this->_NumberOfRows) + ", "
                                   + std::to_string(this->_NumberOfCols) + ")";
    throw OutOfBoundsException();
}

template <typename T>
void
Geometry::Matrix<T>::SetCellData(ULLI RowIndex, ULLI ColIndex, T Value)
{
    if (RowIndex >= 1 && RowIndex <= this->_NumberOfRows &&
        ColIndex >= 1 && ColIndex <= this->_NumberOfCols )
        this->_CoOrd[RowIndex-1][ColIndex-1] = Value;
    std::string exceptionMessage = "IndexOutOfBounds. Requesting ("
                                   + std::to_string(RowIndex) + ", " + std::to_string(ColIndex)
                                   + ") of (" + std::to_string(this->_NumberOfRows) + ", "
                                   + std::to_string(this->_NumberOfCols) + ")";
    throw OutOfBoundsException();
}

template <typename T>
Geometry::Matrix<T>
Geometry::Matrix<T>::operator + (Geometry::Matrix<T> const &SecondMatrix)
{
    assert(this->_NumberOfRows == SecondMatrix.GetNumberOfRows());
    assert(this->_NumberOfCols == SecondMatrix.GetNumberOfColumns());
    Geometry::Matrix<T> *Answer = new Geometry::Matrix<T>(this->_NumberOfCols, this->_NumberOfRows);
    for (ULLI row_index = 0; row_index < this->_NumberOfRows; ++row_index)
    {
        for (ULLI col_index = 0; col_index < this->_NumberOfCols; ++col_index)
        {
            Answer->_CoOrd[row_index][col_index] = this->_CoOrd[row_index][col_index]
                                                   + SecondMatrix(row_index, col_index);
        }
    }
    return *Answer;
}

/**
 *
 * @tparam T
 * @param SecondVector
 * @return
 */
template <typename T>
void
Geometry::Matrix<T>::operator += (Geometry::Matrix<T> const &SecondMatrix)
{
    assert(this->_NumberOfRows == SecondMatrix.GetNumberOfRows());
    assert(this->_NumberOfCols == SecondMatrix.GetNumberOfColumns());
    for (ULLI row_index = 0; row_index < this->_NumberOfRows; ++row_index)
    {
        for (ULLI col_index = 0; col_index < this->_NumberOfCols; ++col_index)
        {
            this->_CoOrd[row_index][col_index] = this->_CoOrd[row_index][col_index]
                                                   + SecondMatrix(row_index, col_index);
        }
    }
}

template <typename T>
Geometry::Matrix<T>
Geometry::Matrix<T>::operator - (Geometry::Matrix<T> const &SecondMatrix)
{
    assert(this->_NumberOfRows == SecondMatrix.GetNumberOfRows());
    assert(this->_NumberOfCols == SecondMatrix.GetNumberOfColumns());
    Geometry::Matrix<T> *Answer = new Geometry::Matrix<T>(this->_NumberOfCols, this->_NumberOfRows);
    for (ULLI row_index = 0; row_index < this->_NumberOfRows; ++row_index)
    {
        for (ULLI col_index = 0; col_index < this->_NumberOfCols; ++col_index)
        {
            Answer->_CoOrd[row_index][col_index] = this->_CoOrd[row_index][col_index]
                                                   - SecondMatrix(row_index, col_index);
        }
    }
    return *Answer;
}

/**
 *
 * @tparam T
 * @param SecondVector
 * @return
 */
template <typename T>
void
Geometry::Matrix<T>::operator -= (Geometry::Matrix<T> const &SecondMatrix)
{
    assert(this->_NumberOfRows == SecondMatrix.GetNumberOfRows());
    assert(this->_NumberOfCols == SecondMatrix.GetNumberOfColumns());
    for (ULLI row_index = 0; row_index < this->_NumberOfRows; ++row_index)
    {
        for (ULLI col_index = 0; col_index < this->_NumberOfCols; ++col_index)
        {
            this->_CoOrd[row_index][col_index] = this->_CoOrd[row_index][col_index]
                                                 - SecondMatrix(row_index, col_index);
        }
    }
}

template <typename T>
Geometry::Matrix<T>&
Geometry::Matrix<T>::operator = (Geometry::Matrix<T> const &SecondMatrix)
{
    Geometry::Matrix<T> *Answer = new Geometry::Matrix<T>(this->_NumberOfCols, this->_NumberOfRows);
    for (ULLI row_index = 0; row_index < this->_NumberOfRows; ++row_index)
    {
        for (ULLI col_index = 0; col_index < this->_NumberOfCols; ++col_index)
        {
            (*Answer)(row_index, col_index) = this->_CoOrd[row_index][col_index];
        }
    }
    return *Answer;
}

template <typename T>
bool
Geometry::Matrix<T>::operator == (Geometry::Matrix<T> const &SecondMatrix) const
{
    if (this->_NumberOfRows != SecondMatrix.GetNumberOfRows())
        return false;
    if (this->_NumberOfCols != SecondMatrix.GetNumberOfColumns())
        return false;
    bool IsEqual = true;
    for (ULLI row_index = 0; row_index < this->_NumberOfRows; ++row_index)
    {
        for (ULLI col_index = 0; col_index < this->_NumberOfCols; ++col_index)
        {
            if( this->_CoOrd[row_index][col_index] != SecondMatrix(row_index, col_index))
            {
                IsEqual = false;
                break;
            }
        }
        if (!IsEqual) break;
    }
    return IsEqual;
}

template <typename T>
Geometry::Matrix<T>
Geometry::Matrix<T>::Transpose()
{
    Geometry::Matrix<T> *Answer = new Geometry::Matrix<T>(this->_NumberOfCols, this->_NumberOfRows);
    for (ULLI row_index = 0; row_index < this->_NumberOfRows; ++row_index)
    {
        for (ULLI col_index = 0; col_index < this->_NumberOfCols; ++col_index)
        {
            (*Answer)(col_index, row_index) = this->_CoOrd[row_index][col_index];
        }
    }
    return *Answer;
}


template <typename T>
Geometry::Matrix<T>::~Matrix()
{
    for(ULLI row_index = 0; row_index < this->_NumberOfRows; ++row_index)
    {
        delete[] this->_CoOrd[row_index];
    }
    this->_NumberOfRows = 0;
    this->_NumberOfCols = 0;
};

template class Geometry::Matrix<int>;
template class Geometry::Matrix<double>;
template class Geometry::Matrix<float>;
template class Geometry::Matrix<ULLI>;
template class Geometry::Matrix<LLI>;