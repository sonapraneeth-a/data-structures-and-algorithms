#ifndef DS_LIST_DLL_H
#define DS_LIST_DLL_H

#include "DoubleLinkedListNode.h"

template <typename T>
class DoubleLinkedList
{
private:

    DoubleLinkedListNode<T> *_Head;
    DoubleLinkedListNode<T> *_Tail;
    unsigned int _Size;
    unsigned int _MaxSize;

public:

    explicit DoubleLinkedList();
    explicit DoubleLinkedList(T Value);

    DoubleLinkedListNode<T>* Head();
    void Head(DoubleLinkedListNode<T>* Node);
    DoubleLinkedListNode<T>* Tail();
    void Tail(DoubleLinkedListNode<T>* Node);
    void Print();
    std::string ToString();
    unsigned int Size();
    void DeleteHead();
    void DeleteTail();
    void Clear();
    void Insert(T Value);

};


#endif //DS_LIST_DLL_H
