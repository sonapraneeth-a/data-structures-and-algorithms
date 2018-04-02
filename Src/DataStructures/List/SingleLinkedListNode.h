#ifndef DS_LIST_SLL_NODE_H
#define DS_LIST_SLL_NODE_H

#include <iostream>
#include <sstream>

template<typename T>
class SingleLinkedListNode
{
public:
    T Data;
    SingleLinkedListNode<T> *Next;

    SingleLinkedListNode();
    SingleLinkedListNode(T Value);

    T GetData();
    SingleLinkedListNode<T>* GetNext();
    void SetData(T Value);
    void SetNext(SingleLinkedListNode<T> *NextLink);

    std::string ToString();

    ~SingleLinkedListNode();
};

template<typename T>
std::ostream& operator <<(std::ostream& os, const SingleLinkedListNode<T>& Node)
{
    os << Node.Data << " -> " << Node.Next << "\n";
    return os;
}

#endif