#ifndef DS_LIST_SLL_H
#define DS_LIST_SLL_H

#include "SingleLinkedListNode.h"

template <typename T>
class SingleLinkedList
{
public:

    SingleLinkedListNode<T> *Head;
    unsigned int Size;

    SingleLinkedList();
    SingleLinkedList(T Value);

    SingleLinkedListNode<T>* GetHead();
    void PrintList();
    std::string ToString();
    unsigned int GetSize();
    void DeleteHead();
    void Clear();
    void Insert(T Value);

};


#endif //DATA_STRUCTURES_AND_ALGORITHMS_SINGLE_LINKED_LIST_H
