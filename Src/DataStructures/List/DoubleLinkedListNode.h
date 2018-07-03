#ifndef DS_LIST_DLL_NODE_H
#define DS_LIST_DLL_NODE_H

#include <iostream>
#include <sstream>

template<typename T>
class DoubleLinkedListNode
{
public:
    T Data;
    DoubleLinkedListNode<T> *Next;
    DoubleLinkedListNode<T> *Prev;

    DoubleLinkedListNode();
    DoubleLinkedListNode(T Value);

    T GetData();
    DoubleLinkedListNode<T>* GetNext();
    DoubleLinkedListNode<T>* GetPrev();
    void SetData(T Value);
    void SetNext(DoubleLinkedListNode<T> *NextLink);
    void SetPrev(DoubleLinkedListNode<T> *PrevLink);

    std::string ToString();

    ~DoubleLinkedListNode();
};

template<typename T>
std::ostream& operator <<(std::ostream& os, const DoubleLinkedListNode<T>& Node)
{
    os << Node.Data << " <-> " << Node.Next << "\n";
    return os;
}

#endif