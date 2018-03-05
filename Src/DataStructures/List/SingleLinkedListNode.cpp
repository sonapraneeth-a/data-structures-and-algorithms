#include "SingleLinkedListNode.h"

template <typename T>
SingleLinkedListNode<T>::SingleLinkedListNode(T value)
{
    data = value;
    next = nullptr;
}

template <typename T>
T SingleLinkedListNode<T>::get_data()
{
    return this->data;
}

template <typename T>
SingleLinkedListNode<T>* SingleLinkedListNode<T>::get_next()
{
    return this->next;
}

template <typename T>
void SingleLinkedListNode<T>::set_data(T value)
{
    data = value;
}

template <typename T>
void SingleLinkedListNode<T>::set_next(SingleLinkedListNode<T> *next_link)
{
    next = next_link;
}

template <typename T>
std::string SingleLinkedListNode<T>::to_string()
{
    std::stringstream out;
    out << this->data << " -> " << this->next;
    return out.str();
}

template <typename T>
SingleLinkedListNode<T>::~SingleLinkedListNode()
{
    next = nullptr;
}

template class SingleLinkedListNode<int>;
template class SingleLinkedListNode<double>;
template class SingleLinkedListNode<char>;
template class SingleLinkedListNode<std::string>;
