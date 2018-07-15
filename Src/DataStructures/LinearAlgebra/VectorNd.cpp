/**
 *      Created on: 06 July 2018
 *   Last modified: 08 July 2018
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
 */

#include "VectorNd.h"

/**
 *
 * @tparam N
 * @tparam T
 * @param InitValue
 */
template <ULLI N, typename T>
LinAlg::VectorNd<N, T>::VectorNd(const T &InitValue)
{
    LinAlg::VectorNd<N, T>::Fill(InitValue);
}

/**
 *
 * @tparam N
 * @tparam T
 * @param Vector
 */
template <ULLI N, typename T>
LinAlg::VectorNd<N, T>::VectorNd(const VectorNd<N, T> &Vector)
{
    for (ULLI index = 0; index < N; ++index)
    {
        this->CoOrd[index] = Vector[index];
    }
}

/**
 *
 * @tparam N
 * @tparam T
 * @param Value
 */
template <ULLI N, typename T>
void
LinAlg::VectorNd<N, T>::Fill(const T &Value)
{
    for (ULLI index = 0; index < N; ++index)
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
template <ULLI N, typename T>
double
LinAlg::VectorNd<N, T>::Distance(const VectorNd<N, T> &OtherVector)
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
template <ULLI N, typename T>
LinAlg::VectorNd<N, double>
LinAlg::VectorNd<N, T>::Normalize()
{
    double length = 0.0;
    for (ULLI index = 0; index < N; ++index)
    {
        length += ((double)this->CoOrd[index] * this->CoOrd[index]);
    }
    length = sqrt(length);
    LinAlg::VectorNd<N, double> *UnitVector = new LinAlg::VectorNd<N, double>(0.0);
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
template <ULLI N, typename T>
T
LinAlg::VectorNd<N, T>::GetNthCoOrdinate(ULLI index)
{
    if (index < N)
        return this->CoOrd[index];
    std::string exceptionMessage = "IndexOutOfBounds. Requesting "
                                   + std::to_string(index) + " of " + std::to_string(N);
    throw OutOfBoundsException();
}

template <ULLI N, typename T>
void
LinAlg::VectorNd<N, T>::SetNthCoOrdinate(ULLI index, T Value)
{
    if (index < N)
        this->CoOrd[index] = Value;
    std::string exceptionMessage = "IndexOutOfBounds. Requesting "
                                   + std::to_string(index) + " of " + std::to_string(N);
    throw OutOfBoundsException();
}

template <ULLI N, typename T>
T
LinAlg::VectorNd<N, T>::operator [](ULLI index) const
{
    if (index < N)
        return this->CoOrd[index];
    std::string exceptionMessage = "IndexOutOfBounds. Requesting "
                                   + std::to_string(index) + " of " + std::to_string(N);
    throw OutOfBoundsException();
}

template <ULLI N, typename T>
T&
LinAlg::VectorNd<N, T>::operator [](ULLI index)
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
template <ULLI N, typename T>
std::string
LinAlg::VectorNd<N, T>::ToString() const
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
template <ULLI N, typename T>
LinAlg::VectorNd<N, T>
LinAlg::VectorNd<N, T>::operator + (LinAlg::VectorNd<N, T> const &SecondVector)
{
    LinAlg::VectorNd<N, T> *Answer = new LinAlg::VectorNd<N, T>(0);
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
template <ULLI N, typename T>
void
LinAlg::VectorNd<N, T>::operator += (LinAlg::VectorNd<N, T> const &SecondVector)
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
template <ULLI N, typename T>
LinAlg::VectorNd<N, T>
LinAlg::VectorNd<N, T>::operator - (LinAlg::VectorNd<N, T> const &SecondVector)
{
    LinAlg::VectorNd<N, T> *Answer = new LinAlg::VectorNd<N, T>(0);
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
template <ULLI N, typename T>
void
LinAlg::VectorNd<N, T>::operator -= (LinAlg::VectorNd<N, T> const &SecondVector)
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
template <ULLI N, typename T>
LinAlg::VectorNd<N, T>
LinAlg::VectorNd<N, T>::operator * (LinAlg::VectorNd<N, T> const &SecondVector)
{
    LinAlg::VectorNd<N, T> *Answer = new LinAlg::VectorNd<N, T>(0);
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
template <ULLI N, typename T>
void
LinAlg::VectorNd<N, T>::operator *= (LinAlg::VectorNd<N, T> const &SecondVector)
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
/*template <ULLI N, typename T>
LinAlg::VectorNd<N, T>
LinAlg::VectorNd<N, T>::operator ^ (LinAlg::VectorNd<N, T> const &SecondVector)
{
    LinAlg::VectorNd<N, T> *Answer = new LinAlg::VectorNd<N, T>(0);
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
template <ULLI N, typename T>
LinAlg::VectorNd<N, T>&
LinAlg::VectorNd<N, T>::operator = (LinAlg::VectorNd<N, T> const &SecondVector)
{
    LinAlg::VectorNd<N, T> *Answer = new LinAlg::VectorNd<N, T>(0);
    for (ULLI index = 0; index < N; ++index)
    {
        (*Answer)[index] = SecondVector[index];
    }
    return *Answer;
}

template <ULLI N, typename T>
bool
LinAlg::VectorNd<N, T>::operator == (LinAlg::VectorNd<N, T> const &SecondVector) const
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
template <ULLI N, typename T>
LinAlg::VectorNd<N, T>::~VectorNd()
{
    delete[] CoOrd;
};

/*template <ULLI N, typename T>
friend std::ostream&
LinAlg::VectorNd<N, T>::operator<<(std::ostream & os,
                                     LinAlg::VectorNd<N, T>::VectorNd<N, T> const &Vec)
{
    return os << Vec.ToString();
}*/

template class LinAlg::VectorNd<(ULLI)1, int>;
template class LinAlg::VectorNd<(ULLI)1, double>;
template class LinAlg::VectorNd<(ULLI)1, float>;
template class LinAlg::VectorNd<(ULLI)1, ULLI>;
template class LinAlg::VectorNd<(ULLI)1, LLI>;

template class LinAlg::VectorNd<(ULLI)2, int>;
template class LinAlg::VectorNd<(ULLI)2, double>;
template class LinAlg::VectorNd<(ULLI)2, float>;
template class LinAlg::VectorNd<(ULLI)2, ULLI>;
template class LinAlg::VectorNd<(ULLI)2, LLI>;

template class LinAlg::VectorNd<(ULLI)3, int>;
template class LinAlg::VectorNd<(ULLI)3, double>;
template class LinAlg::VectorNd<(ULLI)3, float>;
template class LinAlg::VectorNd<(ULLI)3, ULLI>;
template class LinAlg::VectorNd<(ULLI)3, LLI>;

template class LinAlg::VectorNd<(ULLI)4, int>;
template class LinAlg::VectorNd<(ULLI)4, double>;
template class LinAlg::VectorNd<(ULLI)4, float>;
template class LinAlg::VectorNd<(ULLI)4, ULLI>;
template class LinAlg::VectorNd<(ULLI)4, LLI>;

template class LinAlg::VectorNd<(ULLI)5, int>;
template class LinAlg::VectorNd<(ULLI)5, double>;
template class LinAlg::VectorNd<(ULLI)5, float>;
template class LinAlg::VectorNd<(ULLI)5, ULLI>;
template class LinAlg::VectorNd<(ULLI)5, LLI>;

// https://stackoverflow.com/questions/38907087/c-template-partial-explicit-instantiation
// template<ULLI N> class LinAlg::VectorNd<N, int>;
// template<ULLI N> class LinAlg::VectorNd<N, int>;