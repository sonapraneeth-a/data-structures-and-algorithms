/**
 *      Created on: 01 April 2018
 *   Last modified: 14 July 2018
 *          Author: Sona Praneeth Akula
 *         Details: Implementation for Matrix functions
 */

/**
 * Changelog
 *
 * Date (DD-MM-YYYY)            Author               Update
 * 01-04-2018             Sona Praneeth Akula    - Creation of file
 * 13-07-2018             Sona Praneeth Akula    - Added function implementations for functions
 *                                                 Transpose, GetCellData, SetCellData,
 *                                                 Fill, GetNumberOfRows, GetNumberOfColumns,
 *                                                 ToString, Copy constructor and operators +, -,
 *                                                 +=, -=, (), ==, =, <<
 * 14-07-2018             Sona Praneeth Akula    - Added function implementations for functions
 *                                                 AdjacentMatrix, MinorMatrix, CofactorMatrix,
 *                                                 Inverse, Determinant, Cofactor, FirstOrderMinorSubMatrix
 *                                                 operators *, *=, ^, ^=, /, /=
 *                                               - Fixed an issue in copy constructor as memory
 *                                                 was not getting allocated
 *                                               - Renamed functions GetNumberOfRows, GetNumberOfColumns
 */

#include "Matrix.h"

template <typename T>
LinAlg::Matrix<T>::Matrix(const size_t &NumberOfRows,
                            const size_t &NumberOfCols,
                            const T &InitValue)
{
    this->_NumberOfRows = NumberOfRows;
    this->_NumberOfCols = NumberOfCols;
    this->_CoOrd = new T*[NumberOfRows];
    for(ULLI row_index = 0; row_index < NumberOfRows; ++row_index)
    {
        this->_CoOrd[row_index] = new T[NumberOfCols];
    }
    LinAlg::Matrix<T>::Fill(InitValue);
}

template <typename T>
LinAlg::Matrix<T>::Matrix(const size_t &NumberOfRows,
                            const T &InitValue)
{
    this->_NumberOfRows = NumberOfRows;
    this->_NumberOfCols = NumberOfRows;
    this->_CoOrd = new T*[NumberOfRows];
    for(ULLI row_index = 0; row_index < NumberOfRows; ++row_index)
    {
        this->_CoOrd[row_index] = new T[NumberOfRows];
    }
    LinAlg::Matrix<T>::Fill(InitValue);
}

template <typename T>
LinAlg::Matrix<T>::Matrix(const size_t NumberOfRows,
                            const size_t NumberOfCols,
                            std::vector<T> Array, bool IsRowMajor)
{
    assert(NumberOfRows*NumberOfCols == Array.size());
    this->_NumberOfRows = NumberOfRows;
    this->_NumberOfCols = NumberOfCols;
    this->_CoOrd = new T*[NumberOfRows];
    for(ULLI row_index = 0; row_index < NumberOfRows; ++row_index)
    {
        this->_CoOrd[row_index] = new T[NumberOfCols];
    }
    size_t array_index = 0;
    size_t NumRows = this->_NumberOfRows;
    size_t NumCols = this->_NumberOfCols;
    if (!IsRowMajor)
    {
        NumRows = this->_NumberOfCols;
        NumCols = this->_NumberOfRows;
    }
    for (ULLI row_index = 0; row_index < NumRows; ++row_index)
    {
        for (ULLI col_index = 0; col_index < NumCols; ++col_index)
        {
            if (IsRowMajor)
                this->_CoOrd[row_index][col_index] = Array[array_index];
            else
                this->_CoOrd[col_index][row_index] = Array[array_index];
            array_index++;
        }
    }
}

template <typename T>
LinAlg::Matrix<T>::Matrix(const size_t NumberOfRows,
                            std::vector<T> Array, bool IsRowMajor)
{
    assert(NumberOfRows*NumberOfRows == Array.size());
    this->_NumberOfRows = NumberOfRows;
    this->_NumberOfCols = NumberOfRows;
    this->_CoOrd = new T*[NumberOfRows];
    for(ULLI row_index = 0; row_index < NumberOfRows; ++row_index)
    {
        this->_CoOrd[row_index] = new T[NumberOfRows];
    }
    size_t array_index = 0;
    size_t NumRows = this->_NumberOfRows;
    size_t NumCols = this->_NumberOfCols;
    if (!IsRowMajor)
    {
        NumRows = this->_NumberOfCols;
        NumCols = this->_NumberOfRows;
    }
    for (ULLI row_index = 0; row_index < NumRows; ++row_index)
    {
        for (ULLI col_index = 0; col_index < NumCols; ++col_index)
        {
            if (IsRowMajor)
                this->_CoOrd[row_index][col_index] = Array[array_index];
            else
                this->_CoOrd[col_index][row_index] = Array[array_index];
            array_index++;
        }
    }
}

template <typename T>
LinAlg::Matrix<T>::Matrix(const Matrix<T> &Matrix)
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
LinAlg::Matrix<T>::ToString() const
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
LinAlg::Matrix<T>::Fill(const T &Value)
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
LinAlg::Matrix<T>::operator ()(ULLI RowIndex, ULLI ColIndex) const
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
LinAlg::Matrix<T>::operator ()(ULLI RowIndex, ULLI ColIndex)
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
LinAlg::Matrix<T>::NumberOfRows() const
{
    return this->_NumberOfRows;
}

template <typename T>
ULLI
LinAlg::Matrix<T>::NumberOfColumns() const
{
    return this->_NumberOfCols;
}

template <typename T>
T
LinAlg::Matrix<T>::GetCellData(ULLI RowIndex, ULLI ColIndex)
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
LinAlg::Matrix<T>::SetCellData(ULLI RowIndex, ULLI ColIndex, T Value)
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
LinAlg::Matrix<T>
LinAlg::Matrix<T>::operator + (LinAlg::Matrix<T> const &SecondMatrix)
{
    assert(this->_NumberOfRows == SecondMatrix.NumberOfRows());
    assert(this->_NumberOfCols == SecondMatrix.NumberOfColumns());
    LinAlg::Matrix<T> *Answer = new LinAlg::Matrix<T>(this->_NumberOfRows, this->_NumberOfCols, 0);
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
LinAlg::Matrix<T>::operator += (LinAlg::Matrix<T> const &SecondMatrix)
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
LinAlg::Matrix<T>
LinAlg::Matrix<T>::operator - (LinAlg::Matrix<T> const &SecondMatrix)
{
    assert(this->_NumberOfRows == SecondMatrix.NumberOfRows());
    assert(this->_NumberOfCols == SecondMatrix.NumberOfColumns());
    LinAlg::Matrix<T> *Answer = new LinAlg::Matrix<T>(this->_NumberOfRows, this->_NumberOfCols, 0);
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
LinAlg::Matrix<T>::operator -= (LinAlg::Matrix<T> const &SecondMatrix)
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
LinAlg::Matrix<T>
LinAlg::Matrix<T>::operator * (LinAlg::Matrix<T> const &SecondMatrix)
{
    assert(this->_NumberOfCols == SecondMatrix.NumberOfRows());
    LinAlg::Matrix<T> *Answer =
            new LinAlg::Matrix<T>(this->_NumberOfRows,
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
LinAlg::Matrix<T>::operator *= (LinAlg::Matrix<T> const &SecondMatrix)
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
LinAlg::Matrix<T>
LinAlg::Matrix<T>::operator ^ (LinAlg::Matrix<T> const &SecondMatrix)
{
    assert(this->_NumberOfRows == SecondMatrix.NumberOfRows());
    assert(this->_NumberOfCols == SecondMatrix.NumberOfColumns());
    LinAlg::Matrix<T> *Answer = new LinAlg::Matrix<T>(this->_NumberOfRows, this->_NumberOfCols, 0);
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
LinAlg::Matrix<T>::operator ^= (LinAlg::Matrix<T> const &SecondMatrix)
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
LinAlg::Matrix<T>
LinAlg::Matrix<T>::operator * (const double &Value)
{
    LinAlg::Matrix<T> *Answer = new LinAlg::Matrix<T>(this->_NumberOfRows, this->_NumberOfCols, 0);
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
LinAlg::Matrix<T>::operator *= (const double &Value)
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
LinAlg::Matrix<T>
LinAlg::Matrix<T>::operator / (const double &Value)
{
    assert(Value != 0);
    LinAlg::Matrix<T> *Answer = new LinAlg::Matrix<T>(this->_NumberOfRows, this->_NumberOfCols, 0);
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
LinAlg::Matrix<T>::operator /= (const double &Value)
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
LinAlg::Matrix<T>&
LinAlg::Matrix<T>::operator = (LinAlg::Matrix<T> const &SecondMatrix)
{
    LinAlg::Matrix<T> *Answer = new LinAlg::Matrix<T>(this->_NumberOfRows, this->_NumberOfCols, 0);
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
LinAlg::Matrix<T>::operator == (LinAlg::Matrix<T> const &SecondMatrix) const
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
LinAlg::Matrix<T>
LinAlg::Matrix<T>::Transpose()
{
    LinAlg::Matrix<T> *Answer = new LinAlg::Matrix<T>(this->_NumberOfCols, this->_NumberOfRows, 0);
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
LinAlg::Matrix<T>
LinAlg::Matrix<T>::FirstOrderMinorSubMatrix(ULLI RowIndex, ULLI ColIndex)
{
    LinAlg::Matrix<T> *Answer = new LinAlg::Matrix<T>(this->_NumberOfRows-1, this->_NumberOfCols-1, 0);
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
LinAlg::Matrix<T>::Cofactor(ULLI RowIndex, ULLI ColIndex)
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
LinAlg::Matrix<T>::Determinant()
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
LinAlg::Matrix<T>
LinAlg::Matrix<T>::AdjointMatrix()
{
    return this->CofactorMatrix().Transpose();
}

template <typename T>
LinAlg::Matrix<T>
LinAlg::Matrix<T>::MinorMatrix()
{
    LinAlg::Matrix<T> *Answer = new LinAlg::Matrix<T>(this->_NumberOfRows, this->_NumberOfCols, 0);
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
LinAlg::Matrix<T>
LinAlg::Matrix<T>::CofactorMatrix()
{
    LinAlg::Matrix<T> *Answer = new LinAlg::Matrix<T>(this->_NumberOfRows, this->_NumberOfCols, 0);
    LinAlg::Matrix<T> MinorMatrix = this->MinorMatrix();
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
LinAlg::Matrix<double>
LinAlg::Matrix<T>::Inverse()
{
    double determinant = this->Determinant();
    if (determinant == 0.0)
    {
        throw EmptyException();
    }
    LinAlg::Matrix<double> *Answer = new LinAlg::Matrix<double>(this->_NumberOfRows, this->_NumberOfCols, 0);
    LinAlg::Matrix<T> AdjointMatrix = this->AdjointMatrix();
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
LinAlg::Matrix<T>::~Matrix()
{
    for(ULLI row_index = 0; row_index < this->_NumberOfRows; ++row_index)
    {
        delete[] this->_CoOrd[row_index];
    }
    this->_NumberOfRows = 0;
    this->_NumberOfCols = 0;
};

template class LinAlg::Matrix<int>;
template class LinAlg::Matrix<double>;
template class LinAlg::Matrix<float>;
template class LinAlg::Matrix<LLI>;
template class LinAlg::Matrix<ULLI>;