#ifndef DS_LIST_SLL_NODE_H
#define DS_LIST_SLL_NODE_H

#include <iostream>
#include <sstream>

template<typename T>
class SingleLinkedListNode
{
private:

    T _Data;
    SingleLinkedListNode<T> *_Next;

public:
    explicit SingleLinkedListNode();
    explicit SingleLinkedListNode(T Value);

    T Data() const;
    SingleLinkedListNode<T>* Next() const;
    void Data(T Value);
    void Next(SingleLinkedListNode<T> *NextLink);

    std::string ToString();

    ~SingleLinkedListNode();
};

template<typename T>
std::ostream& operator <<(std::ostream& os, const SingleLinkedListNode<T>& Node)
{
    os << Node.Data() << " -> " << Node.Next() << "\n";
    return os;
}

#endif