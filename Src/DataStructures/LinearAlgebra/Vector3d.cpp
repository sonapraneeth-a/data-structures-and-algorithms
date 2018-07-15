/**
 *      Created on: 07 July 2018
 *   Last modified: 07 July 2018
 *          Author: Sona Praneeth Akula
 *         Details: Implementation code for 3 dimensional vector
 */

/**
 * Changelog
 *
 * Date (DD-MM-YYYY)            Author               Update
 * 06-07-2018             Sona Praneeth Akula    - Creation of file
 *                                               - Added implementations for the functions
 *                                                 GetX, GetY, GetZ
 */

#include "Vector3d.h"

template <typename T>
T
Geometry::Vector3d<T>::GetX()
{
    return this->GetNthCoOrdinate(0);
}

template <typename T>
T
Geometry::Vector3d<T>::GetY()
{
    return this->GetNthCoOrdinate(1);
}

template <typename T>
T
Geometry::Vector3d<T>::GetZ()
{
    return this->GetNthCoOrdinate(2);
}

template class Geometry::Vector3d<int>;
template class Geometry::Vector3d<double>;
template class Geometry::Vector3d<float>;
template class Geometry::Vector3d<ULLI>;
template class Geometry::Vector3d<LLI>;
