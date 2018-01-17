#include "single_linked_list_node.h"

template <typename T>
single_linked_list_node<T>::single_linked_list_node(T value)
{
    data = value;
    next = nullptr;
}

template <typename T>
T single_linked_list_node<T>::get_data()
{
    return this->data;
}

template <typename T>
single_linked_list_node<T>* single_linked_list_node<T>::get_next()
{
    return this->next;
}

template <typename T>
void single_linked_list_node<T>::set_data(T value)
{
    data = value;
}

template <typename T>
void single_linked_list_node<T>::set_next(single_linked_list_node<T> *next_link)
{
    next = next_link;
}

template <typename T>
std::string single_linked_list_node<T>::to_string()
{
    std::stringstream out;
    out << this->data << " -> " << this->next;
    return out.str();
}

template <typename T>
single_linked_list_node<T>::~single_linked_list_node()
{
    next = nullptr;
}

template class single_linked_list_node<int>;
template class single_linked_list_node<double>;
template class single_linked_list_node<char>;
template class single_linked_list_node<std::string>;
