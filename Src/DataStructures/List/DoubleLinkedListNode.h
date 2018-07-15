#ifndef DS_LIST_DLL_NODE_H
#define DS_LIST_DLL_NODE_H

#include <iostream>
#include <sstream>

template<typename T>
class DoubleLinkedListNode
{
private:

    T _Data;
    DoubleLinkedListNode<T> *_Next;
    DoubleLinkedListNode<T> *_Prev;


public:

    explicit DoubleLinkedListNode(T Value);

    T Data() const;
    DoubleLinkedListNode<T>* Next() const;
    DoubleLinkedListNode<T>* Prev() const;

    void Data(T Value);
    void Next(DoubleLinkedListNode<T> *NextLink);
    void Prev(DoubleLinkedListNode<T> *PrevLink);

    std::string ToString();

    ~DoubleLinkedListNode();
};

template<typename T>
std::ostream& operator <<(std::ostream& os, const DoubleLinkedListNode<T>& Node)
{
    os << Node.Data() << " <-> " << Node.Next() << "\n";
    return os;
}

#endif