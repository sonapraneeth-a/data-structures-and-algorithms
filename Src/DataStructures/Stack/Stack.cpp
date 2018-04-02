/**
 *      Created on: 22 March 2018
 *   Last modified: 01 April 2018
 *          Author: Sona Praneeth Akula
 *         Details: Implementation for stack
 */

/**
 * Changelog
 *
 * Date (DD-MM-YYYY)            Author               Update
 * 22-03-2018             Sona Praneeth Akula   - Creation of the file
 *                                              - Added implementation of stack functions
 * 24-04-2018             Sona Praneeth Akula   - Fixed a problem with destructor
 *                                              - Updated condition for IsEmpty() function
 *                                              - Updated exception string for Pop()
 * 01-04-2018             Sona Praneeth Akula   - Fixed the Exceptions header path
 */

#include "Stack.h"
#include "Exceptions/Exceptions.h"

/**
 *
 * @tparam T
 */
template <typename T>
Stack<T>::Stack()
{
    this->Top = nullptr;
    this->Size = 0;
    this->MaxSize = 0;
}

/**
 *
 * @tparam T
 * @param Value
 */
template <typename T>
Stack<T>::Stack(T Value)
{
    this->Top = new StackNode<T>(Value);
    this->Size++;
}

/**
 *
 * @tparam T
 * @return
 */
template <typename T>
T Stack<T>::Peek()
{
    if(this->Top != nullptr)
    {
        return this->Top->GetData();
    }
    throw EmptyException("Stack is empty. Cannot retrieve elements from empty stack");
}

/**
 *
 * @tparam T
 * @return
 */
template <typename T>
T Stack<T>::Pop()
{
    if (this->Top != nullptr)
    {
        StackNode<T> *TempNode = this->Top;
        this->Top = this->Top->GetNext();
        delete TempNode;
    }
    else
    {
        throw EmptyException("Stack is empty. Cannot further pop elements.");
    }
}

/**
 *
 * @tparam T
 * @param Value
 */
template <typename T>
void Stack<T>::Push(T Value)
{
    if(this->Top == nullptr)
    {
        this->Top = new StackNode<T>(Value);
    }
    else
    {
        StackNode<T> *TempNode = new StackNode<T>(Value);
        TempNode->SetNext(this->Top);
        this->Top = TempNode;
    }
    this->Size++;
}

/**
 *
 * @tparam T
 * @return
 */
template <typename T>
bool Stack<T>::IsEmpty()
{
    return this->Top == nullptr;
}

/**
 *
 * @tparam T
 */
template <typename T>
Stack<T>::~Stack()
{
    StackNode<T> *TempNode = this->Top;
    while(TempNode != nullptr)
    {
        this->Pop();
        TempNode = this->Top;
    }
    this->MaxSize = 0;
}


template class Stack<int>;