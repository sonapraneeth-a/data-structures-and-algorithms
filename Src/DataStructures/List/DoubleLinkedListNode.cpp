#include "DoubleLinkedListNode.h"

template <typename T>
DoubleLinkedListNode<T>::DoubleLinkedListNode(T Value)
{
    this->Data = Value;
    this->Next = nullptr;
    this->Prev = nullptr;
}

template <typename T>
T DoubleLinkedListNode<T>::GetData()
{
    return this->Data;
}

template <typename T>
DoubleLinkedListNode<T>* DoubleLinkedListNode<T>::GetNext()
{
    return this->Next;
}

template <typename T>
DoubleLinkedListNode<T>* DoubleLinkedListNode<T>::GetPrev()
{
    return this->Prev;
}

template <typename T>
void DoubleLinkedListNode<T>::SetData(T Value)
{
    this->Data = Value;
}

template <typename T>
void DoubleLinkedListNode<T>::SetNext(DoubleLinkedListNode<T> *NextLink)
{
    this->Next = NextLink;
}

template <typename T>
void DoubleLinkedListNode<T>::SetPrev(DoubleLinkedListNode<T> *PrevLink)
{
    this->Prev = PrevLink;
}

template <typename T>
std::string DoubleLinkedListNode<T>::ToString()
{
    std::stringstream out;
    out << this->Data << " <-> " << this->Next;
    return out.str();
}

template <typename T>
DoubleLinkedListNode<T>::~DoubleLinkedListNode()
{
    Next = nullptr;
}

template class DoubleLinkedListNode<int>;
template class DoubleLinkedListNode<double>;
template class DoubleLinkedListNode<char>;
template class DoubleLinkedListNode<std::string>;
