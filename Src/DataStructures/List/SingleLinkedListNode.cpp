#include "SingleLinkedListNode.h"

template <typename T>
SingleLinkedListNode<T>::SingleLinkedListNode(T Value)
{
    Data = Value;
    Next = nullptr;
}

template <typename T>
T SingleLinkedListNode<T>::GetData()
{
    return this->Data;
}

template <typename T>
SingleLinkedListNode<T>* SingleLinkedListNode<T>::GetNext()
{
    return this->Next;
}

template <typename T>
void SingleLinkedListNode<T>::SetData(T Value)
{
    Data = Value;
}

template <typename T>
void SingleLinkedListNode<T>::SetNext(SingleLinkedListNode<T> *NextLink)
{
    Next = NextLink;
}

template <typename T>
std::string SingleLinkedListNode<T>::ToString()
{
    std::stringstream out;
    out << this->Data << " -> " << this->Next;
    return out.str();
}

template <typename T>
SingleLinkedListNode<T>::~SingleLinkedListNode()
{
    Next = nullptr;
}

template class SingleLinkedListNode<int>;
template class SingleLinkedListNode<double>;
template class SingleLinkedListNode<char>;
template class SingleLinkedListNode<std::string>;
