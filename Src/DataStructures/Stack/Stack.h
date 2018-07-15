/**
 *      Created on: 21 March 2018
 *   Last modified: 17 April 2018
 *          Author: Sona Praneeth Akula
 *         Details: Header for stack
 */

/**
 * Changelog
 *
 * Date (DD-MM-YYYY)            Author               Update
 * 21-03-2018             Sona Praneeth Akula   - Creation of the file
 * 22-03-2018             Sona Praneeth Akula   - Added function signatures
 * 17-04-2018             Sona Praneeth Akula   - Added function signature to get size of the stack
 */

#ifndef STACK_H
#define STACK_H

#include "StackNode.h"
#include "Exceptions.h"

template <typename T>
class Stack
{
private:
    
    StackNode<T> *_Top;
    ULLI _Size = 0;
    ULLI _MaxSize = 0;

public:

    explicit Stack();
    explicit Stack(T Value);

    T Peek();
    T Pop();
    void Push(T Value);
    ULLI Size() const;
    bool IsEmpty();

    ~Stack();

};

#endif //STACK_H
