//
// Created by pranas on 7/6/2018.
//

#ifndef VECTOR3D_H
#define VECTOR3D_H

#include "VectorNd.h"

namespace Geometry
{
    template<typename T>
    class Vector3d: public VectorNd<(ULLI)3, T>
    {
    public:
        explicit Vector3d<T>(const T &InitValue = 0): VectorNd<3, T>(InitValue) {}

        Vector3d<T>(const VectorNd<3, T> &Vector): VectorNd<3, T>(Vector) {}

        T
        GetX();

        T
        GetY();

        T
        GetZ();
    };
}

#endif //VECTOR3D_H
