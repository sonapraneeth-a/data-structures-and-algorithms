//
// Created by pranas on 7/6/2018.
//

#ifndef VECTOR2D_H
#define VECTOR2D_H

#include "VectorNd.h"

namespace LinAlg
{
    template<typename T>
    class Vector2d: public VectorNd<(ULLI)2, T>
    {
    public:
        explicit Vector2d<T>(const T &InitValue = 0): VectorNd<2, T>(InitValue) {}

        Vector2d<T>(const VectorNd<2, T> &Vector): VectorNd<2, T>(Vector) {}

        T
        GetX();

        T
        GetY();
    };

}

#endif //VECTOR2D_H
