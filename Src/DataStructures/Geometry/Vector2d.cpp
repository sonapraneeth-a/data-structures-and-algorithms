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
 *                                                 GetX, GetY
 */

#include "Vector2d.h"

template <typename T>
T
Geometry::Vector2d<T>::GetX()
{
    return this->GetNthCoOrdinate(0);
}

template <typename T>
T
Geometry::Vector2d<T>::GetY()
{
    return this->GetNthCoOrdinate(1);
}

/*template class Geometry::Vector2d<int>;
template class Geometry::Vector2d<double>;
template class Geometry::Vector2d<float>;
template class Geometry::Vector2d<ULLI>;
template class Geometry::Vector2d<LLI>;*/