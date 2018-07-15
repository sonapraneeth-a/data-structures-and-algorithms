/**
 *      Created on: 06 July 2018
 *   Last modified: 15 July 2018
 *          Author: Sona Praneeth Akula
 *         Details: Implementation code for 3 dimensional vector
 */

/**
 * Changelog
 *
 * Date (DD-MM-YYYY)            Author               Update
 * 06-07-2018             Sona Praneeth Akula    - Creation of file
 * 07-07-2018             Sona Praneeth Akula    - Added function signatures for the functions
 *                                                 GetX, GetY, GetZ
 * 15-07-2018             Sona Praneeth Akula    - Moved from namespace Geometry to LinAlg
 */

#ifndef VECTOR3D_H
#define VECTOR3D_H

#include "VectorNd.h"

namespace LinAlg
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
