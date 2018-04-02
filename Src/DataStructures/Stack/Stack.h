/**
 *      Created on: 21 March 2018
 *   Last modified: 22 March 2018
 *          Author: Sona Praneeth Akula
 *         Details: Header for stack
 */

/**
 * Changelog
 *
 * Date (DD-MM-YYYY)            Author               Update
 * 21-03-2018             Sona Praneeth Akula   - Creation of the file
 * 22-03-2018             Sona Praneeth Akula   - Added function signatures
 */

#ifndef STACK_H
#define STACK_H

#include "StackNode.h"

template <typename T>
class Stack
{
public:

    StackNode<T> *Top;
    ULLI Size = 0;
    ULLI MaxSize = 0;

    Stack();
    Stack(T Value);

    T Peek();
    T Pop();
    void Push(T Value);
    bool IsEmpty();

    ~Stack();

};


#endif //STACK_H
