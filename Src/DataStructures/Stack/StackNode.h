/**
 *      Created on: 21 March 2018
 *   Last modified: 22 March 2018
 *          Author: Sona Praneeth Akula
 *         Details: Header for stack node
 */

/**
 * Changelog
 *
 * Date (DD-MM-YYYY)            Author               Update
 * 21-03-2018             Sona Praneeth Akula   - Creation of the file
 * 22-03-2018             Sona Praneeth Akula   - Added function signatures
 */

#ifndef STACK_NODE_H
#define STACK_NODE_H

#include "DefaultHeaders.h"
#include <iostream>
#include <sstream>

template<typename T>
class StackNode
{
private:

    T _Data;
    StackNode<T> *_Next;

public:

    explicit StackNode();
    explicit StackNode(T Value);

    T Data() const;
    StackNode<T>* Next() const;
    void Data(T Value);
    void Next(StackNode<T> *NextLink);

    std::string ToString();

    ~StackNode();

};


#endif //STACK_NODE_H
