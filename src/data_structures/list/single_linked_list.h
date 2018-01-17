#ifndef DS_LIST_SLL_H
#define DS_LIST_SLL_H

#include "single_linked_list_node.h"

template <typename T>
class single_linked_list
{
public:

    single_linked_list_node<T> *head;

    single_linked_list();
    single_linked_list(T value);

    single_linked_list_node<T>* get_head();
    void print_list();
    std::string to_string();
    void insert(T value);

};


#endif //DATA_STRUCTURES_AND_ALGORITHMS_SINGLE_LINKED_LIST_H
