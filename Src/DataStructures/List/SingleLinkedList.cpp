#include "SingleLinkedList.h"
#include <iostream>

template <typename T>
SingleLinkedList<T>::SingleLinkedList()
{
    head = nullptr;
    this->size = 0;
}

template <typename T>
SingleLinkedList<T>::SingleLinkedList(T value)
{
    head = new SingleLinkedListNode<T>(value);
    this->size = 1;
}

template <typename T>
SingleLinkedListNode<T>* SingleLinkedList<T>::get_head()
{
    return head;
}

template <typename T>
void SingleLinkedList<T>::print_List()
{
    SingleLinkedListNode<T> *temp = this->head;
    while (temp)
    {
        std::cout << temp->get_data() << " ";
        temp = temp->get_next();
    }
    std::cout << "\n";
    return;
}

template <typename T>
std::string SingleLinkedList<T>::to_string()
{
    SingleLinkedListNode<T> *temp = this->head;
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
void SingleLinkedList<T>::insert(T value)
{
    SingleLinkedListNode<T> *temp = this->head;
    if(temp == nullptr)
    {
        this->head = new SingleLinkedListNode<T>(value);
        this->size = 1;
        return;
    }
    while (temp->get_next() != nullptr)
    {
        temp = temp->get_next();
    }
    temp->set_next(new SingleLinkedListNode<T>(value));
    this->size++;
    return;
}

template <typename T>
unsigned int SingleLinkedList<T>::get_size()
{
    return this->size;
}

template <typename T>
void SingleLinkedList<T>::delete_head()
{
    SingleLinkedListNode<T> *temp = this->head;
    if(temp == nullptr)
    {
        exit(-1);
    }
    this->head = temp->get_next();
    this->size--;
    delete temp;
}

template <typename T>
void SingleLinkedList<T>::clear()
{
    SingleLinkedListNode<T> *temp = this->head;
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

template class SingleLinkedList<int>;
template class SingleLinkedList<double>;
template class SingleLinkedList<char>;
template class SingleLinkedList<std::string>;
