/**
 *      Created on: 06 July 2018
 *   Last modified: 06 July 2018
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
 */

#include "VectorNd.h"

/**
 *
 * @tparam N
 * @tparam T
 * @param InitValue
 */
template <ULLI N, typename T>
Geometry::VectorNd<N, T, typename EnableNumbers>::VectorNd(const T &InitValue)
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
Geometry::VectorNd<N, T, typename EnableNumbers>::VectorNd(const VectorNd<N, T> &Vector)
{

}

/**
 *
 * @tparam N
 * @tparam T
 * @param Value
 */
template <ULLI N, typename T>
void
Geometry::VectorNd<N, T, typename EnableNumbers>::Fill(const T &Value)
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
Geometry::VectorNd<N, T, typename EnableNumbers>::Distance(const VectorNd<N, T> &OtherVector)
{
    double answer = 0.0;
    for (ULLI index = 0; index < N; ++index)
    {
        answer += sqrt((this->CoOrd[index] * this->CoOrd[index])
                    + (OtherVector.CoOrd[index] * OtherVector.CoOrd[index]));
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
Geometry::VectorNd<N, T, typename EnableNumbers>::Normalize()
{
    double length = 0.0;
    for (ULLI index = 0; index < N; ++index)
    {
        length += sqrt((this->CoOrd[index] * this->CoOrd[index]));
    }
    Geometry::VectorNd<N, double> UnitVector;
    for (ULLI index = 0; index < N; ++index)
    {
        UnitVector.CoOrd[index] = this->CoOrd[index] / length;
    }
    return UnitVector;
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
Geometry::VectorNd<N, T, typename EnableNumbers>::GetNthCoOrdinate(ULLI index)
{
    return this->CoOrd[index];
}

/**
 *
 * @tparam N
 * @tparam T
 * @return
 */
template <ULLI N, typename T>
std::string
Geometry::VectorNd<N, T, typename EnableNumbers>::ToString()
{
    std::string answer = "{ ";
    for (ULLI index = 0; index < N; ++index)
    {
        if (index < N-1)
            answer += std::to_string(this->CoOrd[index]) + ", ";
        else
            answer += std::to_string(this->CoOrd[index]);
    }
    answer += " }";
    return answer;
}

/*template class Geometry::VectorNd<(ULLI)2, int>;
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
template class Geometry::VectorNd<(ULLI)4, LLI>;*/

// https://stackoverflow.com/questions/38907087/c-template-partial-explicit-instantiation
// template<ULLI N> class Geometry::VectorNd<N, int>;
// template<ULLI N> class Geometry::VectorNd<N, int>;