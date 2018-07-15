#include "SingleLinkedListNode.h"

template <typename T>
SingleLinkedListNode<T>::SingleLinkedListNode(T Value)
{
    _Data = Value;
    _Next = nullptr;
}

template <typename T>
T SingleLinkedListNode<T>::Data() const
{
    return this->_Data;
}

template <typename T>
SingleLinkedListNode<T>* SingleLinkedListNode<T>::Next() const
{
    return this->_Next;
}

template <typename T>
void SingleLinkedListNode<T>::Data(T Value)
{
    _Data = Value;
}

template <typename T>
void SingleLinkedListNode<T>::Next(SingleLinkedListNode<T> *NextLink)
{
    _Next = NextLink;
}

template <typename T>
std::string SingleLinkedListNode<T>::ToString()
{
    std::stringstream out;
    out << this->_Data << " -> " << this->_Next;
    return out.str();
}

template <typename T>
SingleLinkedListNode<T>::~SingleLinkedListNode()
{
    _Next = nullptr;
}

template class SingleLinkedListNode<int>;
template class SingleLinkedListNode<double>;
template class SingleLinkedListNode<char>;
template class SingleLinkedListNode<std::string>;
