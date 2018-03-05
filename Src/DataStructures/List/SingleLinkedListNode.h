#ifndef DS_LIST_SLL_NODE_H
#define DS_LIST_SLL_NODE_H

#include <iostream>
#include <sstream>

template<typename T>
class SingleLinkedListNode
{
public:
    T data;
    SingleLinkedListNode<T> *next;

    SingleLinkedListNode();
    SingleLinkedListNode(T value);

    T get_data();
    SingleLinkedListNode<T>* get_next();
    void set_data(T value);
    void set_next(SingleLinkedListNode<T> *next_link);

    std::string to_string();

    ~SingleLinkedListNode();
};

template<typename T>
std::ostream& operator <<(std::ostream& os, const SingleLinkedListNode<T>& node)
{
    os << node.data << " -> " << node.next << "\n";
    return os;
}

#endif