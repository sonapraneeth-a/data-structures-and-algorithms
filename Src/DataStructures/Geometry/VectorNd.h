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

#ifndef POINT_H
#define POINT_H

#include "DefaultHeaders.h"

namespace Geometry
{

    template<ULLI N, typename T>
    class VectorNd
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

#endif //POINT_H
