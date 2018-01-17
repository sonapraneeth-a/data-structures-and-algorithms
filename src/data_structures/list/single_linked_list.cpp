#include "single_linked_list.h"
#include <iostream>

template <typename T>
single_linked_list<T>::single_linked_list()
{
    head = nullptr;
}

template <typename T>
single_linked_list<T>::single_linked_list(T value)
{
    head = new single_linked_list_node<T>(value);
}

template <typename T>
single_linked_list_node<T>* single_linked_list<T>::get_head()
{
    return head;
}

template <typename T>
void single_linked_list<T>::print_list()
{
    single_linked_list_node<T> *temp = this->head;
    while (temp)
    {
        std::cout << temp->get_data() << " ";
        temp = temp->get_next();
    }
    std::cout << "\n";
    return;
}

template <typename T>
std::string single_linked_list<T>::to_string()
{
    single_linked_list_node<T> *temp = this->head;
    std::stringstream out;
    while (temp)
    {
        out << temp->get_data() << " -> ";
        temp = temp->get_next();
    }
    out << temp;
    return out.str();
}

template <typename T>
void single_linked_list<T>::insert(T value)
{
    single_linked_list_node<T> *temp = this->head;
    if(temp == nullptr)
    {
        this->head = new single_linked_list_node<T>(value);
        return;
    }
    while (temp->get_next() != nullptr)
    {
        temp = temp->get_next();
    }
    temp->set_next(new single_linked_list_node<T>(value));
    return;
}


template class single_linked_list<int>;
template class single_linked_list<double>;
template class single_linked_list<char>;
template class single_linked_list<std::string>;
