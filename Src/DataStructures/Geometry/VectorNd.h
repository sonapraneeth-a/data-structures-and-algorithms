/**
 *      Created on: 06 July 2018
 *   Last modified: 06 July 2018
 *          Author: Sona Praneeth Akula
 *         Details: Header for N dimensional vector
 */

/**
 * Changelog
 *
 * Date (DD-MM-YYYY)            Author               Update
 * 06-07-2018             Sona Praneeth Akula    - Creation of file
 *                                               - Added function signatures for the functions
 *                                                 Distance, Fill, Normalize, GetNthCoOrdinate,
 *                                                 ToString
 */

#ifndef VECTORND_H
#define VECTORND_H

#include "DefaultHeaders.h"
#include <type_traits>

// Reference: https://www.ideone.com/nztTgG
#define EnableNumbers std::enable_if<std::is_floating_point<T>::value||std::is_integral<T>::value>::type

namespace Geometry
{

    template <ULLI N, typename T, typename Enable = void>
    class VectorNd {};

    template<ULLI N, typename T>
    class VectorNd<N, T, typename EnableNumbers>
    {
    public:

        T CoOrd[N];

        explicit VectorNd(const T &InitValue = 0);

        VectorNd(const VectorNd<N, T> &Vector);

        void
        Fill(const T &Value);

        double
        Distance(const VectorNd<N, T> &OtherVector);

        VectorNd<N, double>
        Normalize();

        T
        GetNthCoOrdinate(ULLI index);

        std::string
        ToString();


    };
}

#include "VectorNd.cpp"

#endif //VECTORND_H
