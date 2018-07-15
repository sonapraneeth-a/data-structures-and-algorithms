#ifndef DS_LIST_SLL_H
#define DS_LIST_SLL_H

#include "SingleLinkedListNode.h"

template <typename T>
class SingleLinkedList
{
private:

    SingleLinkedListNode<T> *_Head;
    unsigned int _Size;


public:

    SingleLinkedList();
    SingleLinkedList(T Value);

    SingleLinkedListNode<T>* Head();
    void Print();
    std::string ToString();
    unsigned int GetSize();
    void DeleteHead();
    void Clear();
    void Insert(T Value);

};


#endif //DS_LIST_SLL_H
