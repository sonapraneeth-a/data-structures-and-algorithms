/**
 *      Created on: 21 March 2018
 *   Last modified: 22 March 2018
 *          Author: Sona Praneeth Akula
 *         Details: Implementation for stack node
 */

/**
 * Changelog
 *
 * Date (DD-MM-YYYY)            Author               Update
 * 21-03-2018             Sona Praneeth Akula   - Creation of the file
 * 22-03-2018             Sona Praneeth Akula   - Completed function signatures
 */

#include "StackNode.h"

/**
 *
 * @tparam T
 * @param Value
 */
template <typename T>
StackNode<T>::StackNode(T Value)
{
    _Data = Value;
    _Next = nullptr;
}

/**
 *
 * @tparam T
 * @return
 */
template <typename T>
T StackNode<T>::Data() const
{
    return this->_Data;
}

/**
 *
 * @tparam T
 * @return
 */
template <typename T>
StackNode<T>* StackNode<T>::Next() const
{
    return this->_Next;
}

/**
 *
 * @tparam T
 * @param Value
 */
template <typename T>
void StackNode<T>::Data(T Value)
{
    _Data = Value;
}

/**
 *
 * @tparam T
 * @param NextLink
 */
template <typename T>
void StackNode<T>::Next(StackNode<T> *NextLink)
{
    _Next = NextLink;
}

/**
 *
 * @tparam T
 * @return
 */
template <typename T>
std::string StackNode<T>::ToString()
{
    std::stringstream out;
    out << this->_Data << " -> " << this->_Next;
    return out.str();
}

/**
 *
 * @tparam T
 */
template <typename T>
StackNode<T>::~StackNode()
{
    _Next = nullptr;
}

template class StackNode<int>;