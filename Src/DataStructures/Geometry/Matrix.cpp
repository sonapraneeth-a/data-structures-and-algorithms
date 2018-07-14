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
    this->_NumberOfRows = Matrix.NumberOfRows();
    this->_NumberOfCols = Matrix.NumberOfColumns();
    this->_CoOrd = new T*[Matrix.NumberOfRows()];
    for(ULLI row_index = 0; row_index < Matrix.NumberOfRows(); ++row_index)
    {
        this->_CoOrd[row_index] = new T[Matrix.NumberOfColumns()];
    }
    for (ULLI row_index = 0; row_index < this->_NumberOfRows; ++row_index)
    {
        for (ULLI col_index = 0; col_index < this->_NumberOfCols; ++col_index)
        {
            this->_CoOrd[row_index][col_index] = Matrix(row_index+1, col_index+1);
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
Geometry::Matrix<T>::NumberOfRows() const
{
    return this->_NumberOfRows;
}

template <typename T>
ULLI
Geometry::Matrix<T>::NumberOfColumns() const
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
    assert(this->_NumberOfRows == SecondMatrix.NumberOfRows());
    assert(this->_NumberOfCols == SecondMatrix.NumberOfColumns());
    Geometry::Matrix<T> *Answer = new Geometry::Matrix<T>(this->_NumberOfRows, this->_NumberOfCols, 0);
    for (ULLI row_index = 0; row_index < this->_NumberOfRows; ++row_index)
    {
        for (ULLI col_index = 0; col_index < this->_NumberOfCols; ++col_index)
        {
            (*Answer)(row_index+1, col_index+1) = this->_CoOrd[row_index][col_index]
                                                    + SecondMatrix(row_index+1, col_index+1);
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
    assert(this->_NumberOfRows == SecondMatrix.NumberOfRows());
    assert(this->_NumberOfCols == SecondMatrix.NumberOfColumns());
    for (ULLI row_index = 0; row_index < this->_NumberOfRows; ++row_index)
    {
        for (ULLI col_index = 0; col_index < this->_NumberOfCols; ++col_index)
        {
            this->_CoOrd[row_index][col_index] = this->_CoOrd[row_index][col_index]
                                                   + SecondMatrix(row_index+1, col_index+1);
        }
    }
}

template <typename T>
Geometry::Matrix<T>
Geometry::Matrix<T>::operator - (Geometry::Matrix<T> const &SecondMatrix)
{
    assert(this->_NumberOfRows == SecondMatrix.NumberOfRows());
    assert(this->_NumberOfCols == SecondMatrix.NumberOfColumns());
    Geometry::Matrix<T> *Answer = new Geometry::Matrix<T>(this->_NumberOfRows, this->_NumberOfCols, 0);
    for (ULLI row_index = 0; row_index < this->_NumberOfRows; ++row_index)
    {
        for (ULLI col_index = 0; col_index < this->_NumberOfCols; ++col_index)
        {
            (*Answer)(row_index+1,col_index+1) = this->_CoOrd[row_index][col_index]
                                                   - SecondMatrix(row_index+1, col_index+1);
        }
    }
    return *Answer;
}

template <typename T>
void
Geometry::Matrix<T>::operator -= (Geometry::Matrix<T> const &SecondMatrix)
{
    assert(this->_NumberOfRows == SecondMatrix.NumberOfRows());
    assert(this->_NumberOfCols == SecondMatrix.NumberOfColumns());
    for (ULLI row_index = 0; row_index < this->_NumberOfRows; ++row_index)
    {
        for (ULLI col_index = 0; col_index < this->_NumberOfCols; ++col_index)
        {
            this->_CoOrd[row_index][col_index] = this->_CoOrd[row_index][col_index]
                                                 - SecondMatrix(row_index+1, col_index+1);
        }
    }
}

template <typename T>
Geometry::Matrix<T>
Geometry::Matrix<T>::operator * (Geometry::Matrix<T> const &SecondMatrix)
{
    assert(this->_NumberOfCols == SecondMatrix.NumberOfRows());
    Geometry::Matrix<T> *Answer =
            new Geometry::Matrix<T>(this->_NumberOfRows,
                                    SecondMatrix.NumberOfColumns(), 0);
    for (ULLI row_index = 0; row_index < this->_NumberOfRows; ++row_index)
    {
        for (ULLI col_index = 0; col_index < SecondMatrix.NumberOfColumns(); ++col_index)
        {
            T answer = 0;
            for (ULLI move_index = 0; move_index < this->_NumberOfCols; ++move_index)
            {
                answer += (this->_CoOrd[row_index][move_index]
                                       * SecondMatrix(move_index+1, col_index+1));
            }
            (*Answer)(row_index+1, col_index+1) = answer;
        }
    }
    return *Answer;
}

template <typename T>
void
Geometry::Matrix<T>::operator *= (Geometry::Matrix<T> const &SecondMatrix)
{
    assert(this->_NumberOfCols == SecondMatrix.NumberOfRows());
    for (ULLI row_index = 0; row_index < this->_NumberOfRows; ++row_index)
    {
        for (ULLI col_index = 0; col_index < this->_NumberOfCols; ++col_index)
        {
            T answer = 0;
            for (ULLI move_index = 0; move_index < this->_NumberOfCols; ++move_index)
            {
                answer += (this->_CoOrd[row_index][move_index]
                           * SecondMatrix(move_index+1, col_index+1));
            }
            this->_CoOrd[row_index][col_index] = answer;
        }
    }
}

template <typename T>
Geometry::Matrix<T>
Geometry::Matrix<T>::operator ^ (Geometry::Matrix<T> const &SecondMatrix)
{
    assert(this->_NumberOfRows == SecondMatrix.NumberOfRows());
    assert(this->_NumberOfCols == SecondMatrix.NumberOfColumns());
    Geometry::Matrix<T> *Answer = new Geometry::Matrix<T>(this->_NumberOfRows, this->_NumberOfCols, 0);
    for (ULLI row_index = 0; row_index < this->_NumberOfRows; ++row_index)
    {
        for (ULLI col_index = 0; col_index < this->_NumberOfCols; ++col_index)
        {
            (*Answer)(row_index+1,col_index+1) = this->_CoOrd[row_index][col_index]
                                                 * SecondMatrix(row_index+1, col_index+1);
        }
    }
    return *Answer;
}

template <typename T>
void
Geometry::Matrix<T>::operator ^= (Geometry::Matrix<T> const &SecondMatrix)
{
    assert(this->_NumberOfRows == SecondMatrix.NumberOfRows());
    assert(this->_NumberOfCols == SecondMatrix.NumberOfColumns());
    for (ULLI row_index = 0; row_index < this->_NumberOfRows; ++row_index)
    {
        for (ULLI col_index = 0; col_index < this->_NumberOfCols; ++col_index)
        {
            this->_CoOrd[row_index][col_index] = this->_CoOrd[row_index][col_index]
                                                 * SecondMatrix(row_index+1, col_index+1);
        }
    }
}

template <typename T>
Geometry::Matrix<T>
Geometry::Matrix<T>::operator * (const double &Value)
{
    Geometry::Matrix<T> *Answer = new Geometry::Matrix<T>(this->_NumberOfRows, this->_NumberOfCols, 0);
    for (ULLI row_index = 0; row_index < this->_NumberOfRows; ++row_index)
    {
        for (ULLI col_index = 0; col_index < this->_NumberOfCols; ++col_index)
        {
            (*Answer)(row_index+1,col_index+1) = this->_CoOrd[row_index][col_index]
                                                 * Value;
        }
    }
    return *Answer;
}

template <typename T>
void
Geometry::Matrix<T>::operator *= (const double &Value)
{
    for (ULLI row_index = 0; row_index < this->_NumberOfRows; ++row_index)
    {
        for (ULLI col_index = 0; col_index < this->_NumberOfCols; ++col_index)
        {
            this->_CoOrd[row_index][col_index] = this->_CoOrd[row_index][col_index]
                                                 * Value;
        }
    }
}

template <typename T>
Geometry::Matrix<T>
Geometry::Matrix<T>::operator / (const double &Value)
{
    assert(Value != 0);
    Geometry::Matrix<T> *Answer = new Geometry::Matrix<T>(this->_NumberOfRows, this->_NumberOfCols, 0);
    for (ULLI row_index = 0; row_index < this->_NumberOfRows; ++row_index)
    {
        for (ULLI col_index = 0; col_index < this->_NumberOfCols; ++col_index)
        {
            (*Answer)(row_index+1,col_index+1) = this->_CoOrd[row_index][col_index]
                                                 / Value;
        }
    }
    return *Answer;
}

template <typename T>
void
Geometry::Matrix<T>::operator /= (const double &Value)
{
    assert(Value != 0);
    for (ULLI row_index = 0; row_index < this->_NumberOfRows; ++row_index)
    {
        for (ULLI col_index = 0; col_index < this->_NumberOfCols; ++col_index)
        {
            this->_CoOrd[row_index][col_index] = this->_CoOrd[row_index][col_index]
                                                 / Value;
        }
    }
}

template <typename T>
Geometry::Matrix<T>&
Geometry::Matrix<T>::operator = (Geometry::Matrix<T> const &SecondMatrix)
{
    Geometry::Matrix<T> *Answer = new Geometry::Matrix<T>(this->_NumberOfRows, this->_NumberOfCols, 0);
    for (ULLI row_index = 0; row_index < this->_NumberOfRows; ++row_index)
    {
        for (ULLI col_index = 0; col_index < this->_NumberOfCols; ++col_index)
        {
            (*Answer)(row_index+1, col_index+1) = this->_CoOrd[row_index][col_index];
        }
    }
    return *Answer;
}

template <typename T>
bool
Geometry::Matrix<T>::operator == (Geometry::Matrix<T> const &SecondMatrix) const
{
    if (this->_NumberOfRows != SecondMatrix.NumberOfRows())
        return false;
    if (this->_NumberOfCols != SecondMatrix.NumberOfColumns())
        return false;
    bool IsEqual = true;
    for (ULLI row_index = 0; row_index < this->_NumberOfRows; ++row_index)
    {
        for (ULLI col_index = 0; col_index < this->_NumberOfCols; ++col_index)
        {
            if( this->_CoOrd[row_index][col_index] != SecondMatrix(row_index+1, col_index+1))
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
    Geometry::Matrix<T> *Answer = new Geometry::Matrix<T>(this->_NumberOfCols, this->_NumberOfRows, 0);
    for (ULLI row_index = 0; row_index < this->_NumberOfRows; ++row_index)
    {
        for (ULLI col_index = 0; col_index < this->_NumberOfCols; ++col_index)
        {
            (*Answer)(col_index+1, row_index+1) = this->_CoOrd[row_index][col_index];
        }
    }
    return *Answer;
}

template <typename T>
Geometry::Matrix<T>
Geometry::Matrix<T>::FirstOrderMinorSubMatrix(ULLI RowIndex, ULLI ColIndex)
{
    Geometry::Matrix<T> *Answer = new Geometry::Matrix<T>(this->_NumberOfRows-1, this->_NumberOfCols-1, 0);
    for (ULLI row_index = 0; row_index < this->_NumberOfRows; ++row_index)
    {
        if (row_index != RowIndex-1)
        {
            for (ULLI col_index = 0; col_index < this->_NumberOfCols; ++col_index)
            {
                if (col_index != ColIndex-1)
                {
                    ULLI updated_row_index = row_index < RowIndex-1 ? row_index : row_index-1;
                    ULLI updated_col_index = col_index < ColIndex-1 ? col_index : col_index-1;
                    (*Answer)(updated_row_index+1, updated_col_index+1) = this->_CoOrd[row_index][col_index];
                }
            }
        }
    }
    return *Answer;
}

template <typename T>
short int
Geometry::Matrix<T>::Cofactor(ULLI RowIndex, ULLI ColIndex)
{
    if ((RowIndex+ColIndex) % 2)
    {
        return -1;
    }
    else
    {
        return 1;
    }
}

template <typename T>
double
Geometry::Matrix<T>::Determinant()
{
    assert(this->_NumberOfRows == this->_NumberOfCols);
    double answer = 0.0;
    if(this->_NumberOfRows == 2)
    {
        answer += ((double)this->_CoOrd[0][0] * this->_CoOrd[1][1]);
        answer -= ((double)this->_CoOrd[1][0] * this->_CoOrd[0][1]);
        return answer;
    }
    else
    {
        for (ULLI col_index = 0; col_index < this->_NumberOfCols; ++col_index)
        {
            double determinant = this->FirstOrderMinorSubMatrix(1, col_index + 1).Determinant();
            double cofactor = (double) this->Cofactor(1, col_index + 1);
            answer += (cofactor * this->_CoOrd[0][col_index] * determinant);
        }
        return answer;
    }
}

template <typename T>
Geometry::Matrix<T>
Geometry::Matrix<T>::AdjointMatrix()
{
    return this->CofactorMatrix().Transpose();
}

template <typename T>
Geometry::Matrix<T>
Geometry::Matrix<T>::MinorMatrix()
{
    Geometry::Matrix<T> *Answer = new Geometry::Matrix<T>(this->_NumberOfRows, this->_NumberOfCols, 0);
    for (ULLI row_index = 0; row_index < this->_NumberOfRows; ++row_index)
    {
        for (ULLI col_index = 0; col_index < this->_NumberOfCols; ++col_index)
        {
            (*Answer)(row_index+1, col_index+1) =
                    this->FirstOrderMinorSubMatrix(row_index+1, col_index+1).Determinant();
        }
    }
    return *Answer;
}

template <typename T>
Geometry::Matrix<T>
Geometry::Matrix<T>::CofactorMatrix()
{
    Geometry::Matrix<T> *Answer = new Geometry::Matrix<T>(this->_NumberOfRows, this->_NumberOfCols, 0);
    Geometry::Matrix<T> MinorMatrix = this->MinorMatrix();
    for (ULLI row_index = 0; row_index < this->_NumberOfRows; ++row_index)
    {
        for (ULLI col_index = 0; col_index < this->_NumberOfCols; ++col_index)
        {
            (*Answer)(row_index+1, col_index+1) = this->Cofactor(row_index + 1, col_index + 1)
                                                    * MinorMatrix(row_index+1, col_index+1);
        }
    }
    return *Answer;
}

template <typename T>
Geometry::Matrix<double>
Geometry::Matrix<T>::Inverse()
{
    double determinant = this->Determinant();
    if (determinant == 0.0)
    {
        throw EmptyException();
    }
    Geometry::Matrix<double> *Answer = new Geometry::Matrix<double>(this->_NumberOfRows, this->_NumberOfCols, 0);
    Geometry::Matrix<T> AdjointMatrix = this->AdjointMatrix();
    for (ULLI row_index = 0; row_index < this->_NumberOfRows; ++row_index)
    {
        for (ULLI col_index = 0; col_index < this->_NumberOfCols; ++col_index)
        {
            (*Answer)(row_index+1, col_index+1) = AdjointMatrix(row_index+1, col_index+1) / determinant;
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
template class Geometry::Matrix<LLI>;