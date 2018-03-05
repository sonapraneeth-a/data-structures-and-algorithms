#ifndef DS_LIST_SLL_H
#define DS_LIST_SLL_H

#include "SingleLinkedListNode.h"

template <typename T>
class SingleLinkedList
{
public:

    SingleLinkedListNode<T> *head;
    unsigned int size;

    SingleLinkedList();
    SingleLinkedList(T value);

    SingleLinkedListNode<T>* get_head();
    void print_List();
    std::string to_string();
    unsigned int get_size();
    void delete_head();
    void clear();
    void insert(T value);

};


#endif //DATA_STRUCTURES_AND_ALGORITHMS_SINGLE_LINKED_LIST_H
