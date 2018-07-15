/**
 *      Created on: 20 March 2018
 *   Last modified: 01 April 2018
 *          Author: Sona Praneeth Akula
 *         Details: Implementation of queue
 */

/**
 * Changelog
 *
 * Date (DD-MM-YYYY)            Author               Update
 * 20-03-2018             Sona Praneeth Akula   - Creation of the file
 * 24-03-2018             Sona Praneeth Akula   - Added implementations for queue functions
 * 01-04-2018             Sona Praneeth Akula   - Fixed the Exceptions header path
 */

#include "Exceptions.h"

/**
 *
 * @tparam T
 */
template <typename T>
Queue<T>::Queue()
{
    this->_Head = nullptr;
    this->_Tail = nullptr;
    this->_Size = 0;
    this->_MaxSize = 0;
}

/**
 *
 * @tparam T
 * @param Value
 */
template <typename T>
Queue<T>::Queue(T Value)
{
    this->_Head = this->_Tail = new QueueNode<T>(Value);
    this->_Size++;
}

/**
 *
 * @tparam T
 * @return
 */
template <typename T>
T Queue<T>::Dequeue()
{
    if (this->_Head != nullptr)
    {
        QueueNode<T> *TempNode = this->_Head;
        this->_Head = this->_Head->Next();
        T Value = TempNode->Data();
        this->_Size--;
        delete TempNode;
        return Value;
    }
    else
    {
        throw EmptyException("Queue is empty. Cannot further dequeue elements.");
    }
}

/**
 *
 * @tparam T
 * @param Value
 */
template <typename T>
void Queue<T>::Enqueue(T Value)
{
    if(this->_Head == nullptr)
    {
        this->_Head = this->_Tail = new QueueNode<T>(Value);
    }
    else
    {
        QueueNode<T> *TempNode = new QueueNode<T>(Value);
        this->_Tail->Next(TempNode);
        this->_Tail = TempNode;
    }
    this->_Size++;
}

/**
 *
 * @tparam T
 * @return
 */
template <typename T>
bool Queue<T>::IsEmpty()
{
    return this->_Head == nullptr;
}

/**
 *
 * @tparam T
 * @return
 */
template <typename T>
T Queue<T>::HeadValue() const
{
   return this->_Head->Data();
}

/**
 *
 * @tparam T
 * @return
 */
template <typename T>
T Queue<T>::TailValue() const
{
    return this->_Tail->Data();
}

/**
 *
 * @tparam T
 * @return
 */
template <typename T>
ULLI Queue<T>::Size() const
{
    return this->_Size;
}

/**
 *
 * @tparam T
 */
template <typename T>
Queue<T>::~Queue()
{
    QueueNode<T> *TempNode = this->_Head;
    while(TempNode != nullptr)
    {
        this->Dequeue();
        TempNode = this->_Head;
    }
    this->_MaxSize = 0;
}


//template class Queue<int>;
//template class Queue<BinaryTreeNode<int>*>;