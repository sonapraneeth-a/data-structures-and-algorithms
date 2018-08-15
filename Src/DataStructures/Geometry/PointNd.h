//
// Created by pranas on 7/15/2018.
//

#ifndef POINT_H
#define POINT_H

#include "VectorNd.h"

namespace Geometry
{
    template<ULLI N, typename T>
    class PointNd: public VectorNd<N, T>
    {
    public:
        explicit PointNd<N, T>(const T &InitValue = 0): VectorNd<N, T>(InitValue) {}

        PointNd<T>(const PointNd<N, T> &Point): VectorNd<N, T>(Vector) {}
    };

}


#endif //POINT_H
