#include "single_linked_list.h"
#include <iostream>

template <typename T>
single_linked_list<T>::single_linked_list()
{
    head = nullptr;
    this->size = 0;
}

template <typename T>
single_linked_list<T>::single_linked_list(T value)
{
    head = new single_linked_list_node<T>(value);
    this->size = 1;
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
        this->size = 1;
        return;
    }
    while (temp->get_next() != nullptr)
    {
        temp = temp->get_next();
    }
    temp->set_next(new single_linked_list_node<T>(value));
    this->size++;
    return;
}

template <typename T>
unsigned int single_linked_list<T>::get_size()
{
    return this->size;
}

template <typename T>
void single_linked_list<T>::delete_head()
{
    single_linked_list_node<T> *temp = this->head;
    if(temp == nullptr)
    {
        exit(-1);
    }
    this->head = temp->get_next();
    this->size--;
    delete temp;
}

template <typename T>
void single_linked_list<T>::clear()
{
    single_linked_list_node<T> *temp = this->head;
    if(temp == nullptr)
    {
        return ;
    }
    while(this->head)
    {
        this->delete_head();
    }
    return ;
}

template class single_linked_list<int>;
template class single_linked_list<double>;
template class single_linked_list<char>;
template class single_linked_list<std::string>;
