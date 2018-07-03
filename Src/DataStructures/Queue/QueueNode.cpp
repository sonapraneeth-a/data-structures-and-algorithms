//
// Created by pranas on 3/23/2018.
//

#include "QueueNode.h"

/**
 *
 * @tparam T
 * @param Value
 */
template <typename T>
QueueNode<T>::QueueNode(T Value)
{
    Data = Value;
    Next = nullptr;
}

/**
 *
 * @tparam T
 * @return
 */
template <typename T>
T QueueNode<T>::GetData()
{
    return this->Data;
}

/**
 *
 * @tparam T
 * @return
 */
template <typename T>
QueueNode<T>* QueueNode<T>::GetNext()
{
    return this->Next;
}

/**
 *
 * @tparam T
 * @param Value
 */
template <typename T>
void QueueNode<T>::SetData(T Value)
{
    Data = Value;
}

/**
 *
 * @tparam T
 * @param NextLink
 */
template <typename T>
void QueueNode<T>::SetNext(QueueNode<T> *NextLink)
{
    Next = NextLink;
}

/**
 *
 * @tparam T
 * @return
 */
template <typename T>
std::string QueueNode<T>::ToString()
{
    std::stringstream out;
    out << this->Data << " -> " << this->Next;
    return out.str();
}

/**
 *
 * @tparam T
 */
template <typename T>
QueueNode<T>::~QueueNode()
{
    Next = nullptr;
}

template class QueueNode<int>;