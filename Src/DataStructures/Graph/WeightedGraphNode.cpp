/**
 *      Created on: 23 July 2018
 *   Last modified: 24 July 2018
 *          Author: Sona Praneeth Akula
 *         Details: Header for Weighted graph node
 */

/**
 * Changelog
 *
 * Date (DD-MM-YYYY)            Author               Update
 * 23-07-2018             Sona Praneeth Akula   - Creation of the file
 *                                              - Added function implementation for constructor,
 *                                                destructor, Data, Weight, Next
 * 24-07-2018             Sona Praneeth Akula   - Minor update to ToString (const)
 */

#include "WeightedGraphNode.h"

template <typename T>
WeightedGraphNode<T>::WeightedGraphNode(const T& Data, int Weight)
{
    _Data = Data;
    _Next = nullptr;
    _Weight = Weight;
}

template <typename T>
T WeightedGraphNode<T>::Data() const
{
    return this->_Data;
}

template <typename T>
WeightedGraphNode<T>* WeightedGraphNode<T>::Next() const
{
    return this->_Next;
}

template <typename T>
void WeightedGraphNode<T>::Data(T Value)
{
    _Data = Value;
}

template <typename T>
void WeightedGraphNode<T>::Next(WeightedGraphNode<T> *NextLink)
{
    _Next = NextLink;
}

template <typename T>
int
WeightedGraphNode<T>::Weight() const
{
    return this->_Weight;
}

template <typename T>
void
WeightedGraphNode<T>::Weight(int Weight)
{
    this->_Weight = Weight;
}

template <typename T>
std::string WeightedGraphNode<T>::ToString() const
{
    std::stringstream out;
    if (this->Next() != nullptr)
        out << "( " << this->Data() << ", " << this->Weight() << " ) -> ";
    else
        out << "( " << this->Data() << ", " << this->Weight() << " ) -> NULL";
    return out.str();
}

template <typename T>
WeightedGraphNode<T>::~WeightedGraphNode()
{
    _Next = nullptr;
}

template class WeightedGraphNode<int>;
template class WeightedGraphNode<double>;
template class WeightedGraphNode<char>;
template class WeightedGraphNode<std::string>;
