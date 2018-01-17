#ifndef DS_LIST_SLL_NODE_H
#define DS_LIST_SLL_NODE_H

#include <iostream>
#include <sstream>

template<typename T>
class single_linked_list_node
{
public:
    T data;
    single_linked_list_node<T> *next;

    single_linked_list_node();
    single_linked_list_node(T value);

    T get_data();
    single_linked_list_node<T>* get_next();
    void set_data(T value);
    void set_next(single_linked_list_node<T> *next_link);

    std::string to_string();

    ~single_linked_list_node();
};

template<typename T>
std::ostream& operator <<(std::ostream& os, const single_linked_list_node<T>& node)
{
    os << node.data << " -> " << node.next << "\n";
    return os;
}

#endif