/**
 *      Created on: 06 July 2018
 *   Last modified: 15 July 2018
 *          Author: Sona Praneeth Akula
 *         Details: Implementation code for 2 dimensional vector
 */

/**
 * Changelog
 *
 * Date (DD-MM-YYYY)            Author               Update
 * 06-07-2018             Sona Praneeth Akula    - Creation of file
 *                                               - Added function signatures for the functions
 *                                                 GetX, GetY
 * 15-07-2018             Sona Praneeth Akula    - Moved from namespace Geometry to LinAlg
 */

#ifndef VECTOR2D_H
#define VECTOR2D_H

#include "VectorNd.h"

namespace LinAlg
{
    template<typename T>
    class Vector2d: public VectorNd<T>
    {
    public:
        explicit Vector2d<T>(const T &InitValue = 0): VectorNd<T>(2, InitValue) {}

        Vector2d<T>(const VectorNd<T> &Vector): VectorNd<T>(2, Vector) {}

        T
        GetX();

        T
        GetY();
    };

}

#endif //VECTOR2D_H
