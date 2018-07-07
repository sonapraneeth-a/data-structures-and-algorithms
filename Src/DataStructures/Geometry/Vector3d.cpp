//
// Created by pranas on 7/7/2018.
//

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
