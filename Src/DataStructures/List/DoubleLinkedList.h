#ifndef DS_LIST_DLL_H
#define DS_LIST_DLL_H

#include "DoubleLinkedListNode.h"

template <typename T>
class DoubleLinkedList
{
public:

    DoubleLinkedListNode<T> *Head;
    DoubleLinkedListNode<T> *Tail;
    unsigned int Size;
    unsigned int MaxSize;

    DoubleLinkedList();
    DoubleLinkedList(T Value);

    DoubleLinkedListNode<T>* GetHead();
    DoubleLinkedListNode<T>* GetTail();
    void PrintList();
    std::string ToString();
    unsigned int GetSize();
    void DeleteHead();
    void DeleteTail();
    void Clear();
    void Insert(T Value);

};


#endif //DATA_STRUCTURES_AND_ALGORITHMS_Double_LINKED_LIST_H
