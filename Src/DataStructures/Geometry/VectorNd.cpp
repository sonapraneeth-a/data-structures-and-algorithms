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
 */

#include "VectorNd.h"

/**
 *
 * @tparam N
 * @tparam T
 * @param InitValue
 */
template <ULLI N, typename T>
Geometry::VectorNd<N, T>::VectorNd(const T &InitValue)
{
    Geometry::VectorNd<N, T>::Fill(InitValue);
}

/**
 *
 * @tparam N
 * @tparam T
 * @param Vector
 */
template <ULLI N, typename T>
Geometry::VectorNd<N, T>::VectorNd(const VectorNd<N, T> &Vector)
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
Geometry::VectorNd<N, T>::Fill(const T &Value)
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
Geometry::VectorNd<N, T>::Distance(const VectorNd<N, T> &OtherVector)
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
Geometry::VectorNd<N, double>
Geometry::VectorNd<N, T>::Normalize()
{
    double length = 0.0;
    for (ULLI index = 0; index < N; ++index)
    {
        length += sqrt((this->CoOrd[index] * this->CoOrd[index]));
    }
    Geometry::VectorNd<N, double> *UnitVector = new Geometry::VectorNd<N, double>(0.0);
    for (ULLI index = 0; index < N; ++index)
    {
        (*UnitVector)[index] = this->CoOrd[index] / length;
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
Geometry::VectorNd<N, T>::GetNthCoOrdinate(ULLI index)
{
    if (index < N)
        return this->CoOrd[index];
    std::string exceptionMessage = "IndexOutOfBounds. Requesting "
                                   + std::to_string(index) + " of " + std::to_string(N);
    throw OutOfBoundsException();
}

template <ULLI N, typename T>
void
Geometry::VectorNd<N, T>::SetNthCoOrdinate(ULLI index, T Value)
{
    if (index < N)
        this->CoOrd[index] = Value;
    std::string exceptionMessage = "IndexOutOfBounds. Requesting "
                                   + std::to_string(index) + " of " + std::to_string(N);
    throw OutOfBoundsException();
}

template <ULLI N, typename T>
T
Geometry::VectorNd<N, T>::operator [](ULLI index) const
{
    if (index < N)
        return this->CoOrd[index];
    std::string exceptionMessage = "IndexOutOfBounds. Requesting "
                                   + std::to_string(index) + " of " + std::to_string(N);
    throw OutOfBoundsException();
}

template <ULLI N, typename T>
T&
Geometry::VectorNd<N, T>::operator [](ULLI index)
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
Geometry::VectorNd<N, T>::ToString() const
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
Geometry::VectorNd<N, T>
Geometry::VectorNd<N, T>::operator + (Geometry::VectorNd<N, T> const &SecondVector)
{
    Geometry::VectorNd<N, T> *Answer = new Geometry::VectorNd<N, T>(0);
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
Geometry::VectorNd<N, T>::operator += (Geometry::VectorNd<N, T> const &SecondVector)
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
Geometry::VectorNd<N, T>
Geometry::VectorNd<N, T>::operator - (Geometry::VectorNd<N, T> const &SecondVector)
{
    Geometry::VectorNd<N, T> *Answer = new Geometry::VectorNd<N, T>(0);
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
Geometry::VectorNd<N, T>::operator -= (Geometry::VectorNd<N, T> const &SecondVector)
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
Geometry::VectorNd<N, T>
Geometry::VectorNd<N, T>::operator * (Geometry::VectorNd<N, T> const &SecondVector)
{
    Geometry::VectorNd<N, T> *Answer = new Geometry::VectorNd<N, T>(0);
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
Geometry::VectorNd<N, T>::operator *= (Geometry::VectorNd<N, T> const &SecondVector)
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
template <ULLI N, typename T>
Geometry::VectorNd<N, T>
Geometry::VectorNd<N, T>::operator ^ (Geometry::VectorNd<N, T> const &SecondVector)
{
    Geometry::VectorNd<N, T> *Answer = new Geometry::VectorNd<N, T>(0);
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
Geometry::VectorNd<N, T>&
Geometry::VectorNd<N, T>::operator = (Geometry::VectorNd<N, T> const &SecondVector)
{
    Geometry::VectorNd<N, T> *Answer = new Geometry::VectorNd<N, T>(0);
    for (ULLI index = 0; index < N; ++index)
    {
        (*Answer)[index] = SecondVector[index];
    }
    return *Answer;
}

template <ULLI N, typename T>
bool
Geometry::VectorNd<N, T>::operator == (Geometry::VectorNd<N, T> const &SecondVector) const
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
Geometry::VectorNd<N, T>::~VectorNd()
{
    delete[] CoOrd;
};

/*template <ULLI N, typename T>
friend std::ostream&
Geometry::VectorNd<N, T>::operator<<(std::ostream & os,
                                     Geometry::VectorNd<N, T>::VectorNd<N, T> const &Vec)
{
    return os << Vec.ToString();
}*/

template class Geometry::VectorNd<(ULLI)1, int>;
template class Geometry::VectorNd<(ULLI)1, double>;
template class Geometry::VectorNd<(ULLI)1, float>;
template class Geometry::VectorNd<(ULLI)1, ULLI>;
template class Geometry::VectorNd<(ULLI)1, LLI>;

template class Geometry::VectorNd<(ULLI)2, int>;
template class Geometry::VectorNd<(ULLI)2, double>;
template class Geometry::VectorNd<(ULLI)2, float>;
template class Geometry::VectorNd<(ULLI)2, ULLI>;
template class Geometry::VectorNd<(ULLI)2, LLI>;

template class Geometry::VectorNd<(ULLI)3, int>;
template class Geometry::VectorNd<(ULLI)3, double>;
template class Geometry::VectorNd<(ULLI)3, float>;
template class Geometry::VectorNd<(ULLI)3, ULLI>;
template class Geometry::VectorNd<(ULLI)3, LLI>;

template class Geometry::VectorNd<(ULLI)4, int>;
template class Geometry::VectorNd<(ULLI)4, double>;
template class Geometry::VectorNd<(ULLI)4, float>;
template class Geometry::VectorNd<(ULLI)4, ULLI>;
template class Geometry::VectorNd<(ULLI)4, LLI>;

template class Geometry::VectorNd<(ULLI)5, int>;
template class Geometry::VectorNd<(ULLI)5, double>;
template class Geometry::VectorNd<(ULLI)5, float>;
template class Geometry::VectorNd<(ULLI)5, ULLI>;
template class Geometry::VectorNd<(ULLI)5, LLI>;

// https://stackoverflow.com/questions/38907087/c-template-partial-explicit-instantiation
// template<ULLI N> class Geometry::VectorNd<N, int>;
// template<ULLI N> class Geometry::VectorNd<N, int>;