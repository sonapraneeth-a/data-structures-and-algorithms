/**
 *      Created on: 06 July 2018
 *   Last modified: 23 July 2018
 *          Author: Sona Praneeth Akula
 *         Details: Implementation code for N dimensional vector
 */

/**
 * Changelog
 *
 * Date (DD-MM-YYYY)            Author               Update
 * 06-07-2018             Sona Praneeth Akula    - Creation of file
 *                                               - Added implementations for the functions
 *                                                 Distance, Fill, Normalize, GetNthCoOrdinate,
 *                                                 ToString
 * 07-07-2018             Sona Praneeth Akula    - Added implementations for functions
 *                                                 SetNthCoOrdinate, Copy constructor and operators
 *                                                 +, -, *, +=, -=, *=, []
 * 08-07-2018             Sona Praneeth Akula    - Added implementation for operator ==
 * 14-07-2018             Sona Praneeth Akula    - Fixed an error in Normalize function
 * 15-07-2018             Sona Praneeth Akula    - Moved from namespace Geometry to LinAlg
 * 23-07-2018             Sona Praneeth Akula    - Moved from VectorNd<N, T> to VectorNd<T>
 *                                               - Updated constructor to accept dimension of the
 *                                                 vector
 */

#include "VectorNd.h"

/**
 *
 * @tparam N
 * @tparam T
 * @param InitValue
 */
template <typename T>
LinAlg::VectorNd<T>::VectorNd(unsigned int Dimension, const T &InitValue)
{
    this->N = (size_t)Dimension;
    CoOrd = new T[Dimension];
    LinAlg::VectorNd<T>::Fill(InitValue);
}

/**
 *
 * @tparam N
 * @tparam T
 * @param Vector
 */
template <typename T>
LinAlg::VectorNd<T>::VectorNd(const VectorNd<T> &Vector)
{
    CoOrd = new T[Vector.GetDimension()];
    for (ULLI index = 0; index < N; ++index)
    {
        this->CoOrd[index] = Vector[index];
    }
}

template <typename T>
size_t
LinAlg::VectorNd<T>::GetDimension() const
{
    return this->N;
}

/**
 *
 * @tparam N
 * @tparam T
 * @param Value
 */
template <typename T>
void
LinAlg::VectorNd<T>::Fill(const T &Value)
{
    for (size_t index = 0; index < N; ++index)
    {
        this->CoOrd[index] = Value;
    }
}

/**
 *
 * @tparam N
 * @tparam T
 * @param OtherVector
 * @return
 */
template <typename T>
double
LinAlg::VectorNd<T>::Distance(const VectorNd<T> &OtherVector)
{
    double answer = 0.0;
    for (ULLI index = 0; index < N; ++index)
    {
        answer += sqrt((this->CoOrd[index] * this->CoOrd[index])
                    + (OtherVector[index] * OtherVector[index]));
    }
    return answer;
}

/**
 *
 * @tparam N
 * @tparam T
 * @return
 */
template <typename T>
LinAlg::VectorNd<double>
LinAlg::VectorNd<T>::Normalize()
{
    double length = 0.0;
    for (ULLI index = 0; index < N; ++index)
    {
        length += ((double)this->CoOrd[index] * this->CoOrd[index]);
    }
    length = sqrt(length);
    LinAlg::VectorNd<double> *UnitVector = new LinAlg::VectorNd<double>(0.0);
    for (ULLI index = 0; index < N; ++index)
    {
        (*UnitVector)[index] = (double)this->CoOrd[index] / length;
    }
    return *UnitVector;
}

/**
 *
 * @tparam N
 * @tparam T
 * @param index
 * @return
 */
template <typename T>
T
LinAlg::VectorNd<T>::GetNthCoOrdinate(ULLI index)
{
    if (index < N)
        return this->CoOrd[index];
    std::string exceptionMessage = "IndexOutOfBounds. Requesting "
                                   + std::to_string(index) + " of " + std::to_string(N);
    throw OutOfBoundsException();
}

template <typename T>
void
LinAlg::VectorNd<T>::SetNthCoOrdinate(ULLI index, T Value)
{
    if (index < N)
        this->CoOrd[index] = Value;
    std::string exceptionMessage = "IndexOutOfBounds. Requesting "
                                   + std::to_string(index) + " of " + std::to_string(N);
    throw OutOfBoundsException();
}

template <typename T>
T
LinAlg::VectorNd<T>::operator [](ULLI index) const
{
    if (index < N)
        return this->CoOrd[index];
    std::string exceptionMessage = "IndexOutOfBounds. Requesting "
                                   + std::to_string(index) + " of " + std::to_string(N);
    throw OutOfBoundsException();
}

template <typename T>
T&
LinAlg::VectorNd<T>::operator [](ULLI index)
{
    if (index < N)
        return this->CoOrd[index];
    std::string exceptionMessage = "IndexOutOfBounds. Requesting "
                                   + std::to_string(index) + " of " + std::to_string(N);
    throw OutOfBoundsException();
}

/**
 *
 * @tparam N
 * @tparam T
 * @return
 */
template <typename T>
std::string
LinAlg::VectorNd<T>::ToString() const
{
    std::string answer = _Vector_Print_Start;
    for (ULLI index = 0; index < N; ++index)
    {
        if (index < N-1)
            answer += std::to_string(this->CoOrd[index]) + ", ";
        else
            answer += std::to_string(this->CoOrd[index]);
    }
    answer += _Vector_Print_End;
    return answer;
}

/**
 *
 * @tparam N
 * @tparam T
 * @param SecondVector
 * @return
 */
template <typename T>
LinAlg::VectorNd<T>
LinAlg::VectorNd<T>::operator + (LinAlg::VectorNd<T> const &SecondVector)
{
    LinAlg::VectorNd<T> *Answer = new LinAlg::VectorNd<T>(0);
    for (ULLI index = 0; index < N; ++index)
    {
        (*Answer)[index] = this->CoOrd[index] + SecondVector[index];
    }
    return *Answer;
}

/**
 *
 * @tparam N
 * @tparam T
 * @param SecondVector
 * @return
 */
template <typename T>
void
LinAlg::VectorNd<T>::operator += (LinAlg::VectorNd<T> const &SecondVector)
{
    for (ULLI index = 0; index < N; ++index)
    {
        this->CoOrd[index] = this->CoOrd[index] + SecondVector[index];
    }
}

/**
 *
 * @tparam N
 * @tparam T
 * @param SecondVector
 * @return
 */
template <typename T>
LinAlg::VectorNd<T>
LinAlg::VectorNd<T>::operator - (LinAlg::VectorNd<T> const &SecondVector)
{
    LinAlg::VectorNd<T> *Answer = new LinAlg::VectorNd<T>(0);
    for (ULLI index = 0; index < N; ++index)
    {
        (*Answer)[index] = this->CoOrd[index] - SecondVector[index];
    }
    return *Answer;
}

/**
 *
 * @tparam N
 * @tparam T
 * @param SecondVector
 * @return
 */
template <typename T>
void
LinAlg::VectorNd<T>::operator -= (LinAlg::VectorNd<T> const &SecondVector)
{
    for (ULLI index = 0; index < N; ++index)
    {
        this->CoOrd[index] = this->CoOrd[index] - SecondVector[index];
    }
}

/**
 *
 * @tparam N
 * @tparam T
 * @param SecondVector
 * @return
 */
template <typename T>
LinAlg::VectorNd<T>
LinAlg::VectorNd<T>::operator * (LinAlg::VectorNd<T> const &SecondVector)
{
    LinAlg::VectorNd<T> *Answer = new LinAlg::VectorNd<T>(0);
    for (ULLI index = 0; index < N; ++index)
    {
        (*Answer)[index] = this->CoOrd[index] * SecondVector[index];
    }
    return *Answer;
}

/**
 *
 * @tparam N
 * @tparam T
 * @param SecondVector
 * @return
 */
template <typename T>
void
LinAlg::VectorNd<T>::operator *= (LinAlg::VectorNd<T> const &SecondVector)
{
    for (ULLI index = 0; index < N; ++index)
    {
        this->CoOrd[index] = this->CoOrd[index] * SecondVector[index];
    }
}

/**
 *
 * @tparam N
 * @tparam T
 * @param SecondVector
 * @return
 */
/*template <typename T>
LinAlg::VectorNd<T>
LinAlg::VectorNd<T>::operator ^ (LinAlg::VectorNd<T> const &SecondVector)
{
    LinAlg::VectorNd<T> *Answer = new LinAlg::VectorNd<T>(0);
    for (ULLI index = 0; index < N; ++index)
    {
        (*Answer)[index] = this->CoOrd[index] * SecondVector[index];
    }
    return *Answer;
}*/

/**
 *
 * @tparam N
 * @tparam T
 * @param SecondVector
 * @return
 */
template <typename T>
LinAlg::VectorNd<T>&
LinAlg::VectorNd<T>::operator = (LinAlg::VectorNd<T> const &SecondVector)
{
    LinAlg::VectorNd<T> *Answer = new LinAlg::VectorNd<T>(0);
    for (ULLI index = 0; index < N; ++index)
    {
        (*Answer)[index] = SecondVector[index];
    }
    return *Answer;
}

template <typename T>
bool
LinAlg::VectorNd<T>::operator == (LinAlg::VectorNd<T> const &SecondVector) const
{
    bool IsEqual = true;
    for (ULLI index = 0; index < N; ++index)
    {
        if (this->CoOrd[index] != SecondVector[index])
        {
            IsEqual = false;
            break;
        }
    }
    return IsEqual;
}

/**
 *
 * @tparam N
 * @tparam T
 */
template <typename T>
LinAlg::VectorNd<T>::~VectorNd()
{
    delete[] CoOrd;
};

/*template <typename T>
friend std::ostream&
LinAlg::VectorNd<T>::operator<<(std::ostream & os,
                                     LinAlg::VectorNd<T>::VectorNd<T> const &Vec)
{
    return os << Vec.ToString();
}*/

template class LinAlg::VectorNd<int>;
template class LinAlg::VectorNd<double>;
template class LinAlg::VectorNd<float>;
template class LinAlg::VectorNd<ULLI>;
template class LinAlg::VectorNd<LLI>;

// https://stackoverflow.com/questions/38907087/c-template-partial-explicit-instantiation
// template<ULLI N> class LinAlg::VectorNd<N, int>;
// template<ULLI N> class LinAlg::VectorNd<N, int>;