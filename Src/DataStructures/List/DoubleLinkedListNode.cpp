#include "DoubleLinkedListNode.h"

template <typename T>
DoubleLinkedListNode<T>::DoubleLinkedListNode(T Value)
{
    this->_Data = Value;
    this->_Next = nullptr;
    this->_Prev = nullptr;
}

template <typename T>
T DoubleLinkedListNode<T>::Data() const
{
    return this->_Data;
}

template <typename T>
DoubleLinkedListNode<T>* DoubleLinkedListNode<T>::Next() const
{
    return this->_Next;
}

template <typename T>
DoubleLinkedListNode<T>* DoubleLinkedListNode<T>::Prev() const
{
    return this->_Prev;
}

template <typename T>
void DoubleLinkedListNode<T>::Data(T Value)
{
    this->_Data = Value;
}

template <typename T>
void DoubleLinkedListNode<T>::Next(DoubleLinkedListNode<T> *NextLink)
{
    this->_Next = NextLink;
}

template <typename T>
void DoubleLinkedListNode<T>::Prev(DoubleLinkedListNode<T> *PrevLink)
{
    this->_Prev = PrevLink;
}

template <typename T>
std::string DoubleLinkedListNode<T>::ToString()
{
    std::stringstream out;
    out << this->_Data << " <-> " << this->_Next;
    return out.str();
}

template <typename T>
DoubleLinkedListNode<T>::~DoubleLinkedListNode()
{
    _Next = nullptr;
}

template class DoubleLinkedListNode<int>;
template class DoubleLinkedListNode<double>;
template class DoubleLinkedListNode<char>;
template class DoubleLinkedListNode<std::string>;
