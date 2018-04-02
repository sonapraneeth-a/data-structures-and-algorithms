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

#include "Queue.h"
#include "Exceptions/Exceptions.h"

/**
 *
 * @tparam T
 */
template <typename T>
Queue<T>::Queue()
{
    this->Head = nullptr;
    this->Tail = nullptr;
    this->Size = 0;
    this->MaxSize = 0;
}

/**
 *
 * @tparam T
 * @param Value
 */
template <typename T>
Queue<T>::Queue(T Value)
{
    this->Head = this->Tail = new QueueNode<T>(Value);
    this->Size++;
}

/**
 *
 * @tparam T
 * @return
 */
template <typename T>
T Queue<T>::Dequeue()
{
    if (this->Head != nullptr)
    {
        QueueNode<T> *TempNode = this->Head;
        this->Head = this->Head->GetNext();
        T Value = TempNode->GetData();
        this->Size--;
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
    if(this->Head == nullptr)
    {
        this->Head = this->Tail = new QueueNode<T>(Value);
    }
    else
    {
        QueueNode<T> *TempNode = new QueueNode<T>(Value);
        this->Tail->SetNext(TempNode);
        this->Tail = TempNode;
    }
    this->Size++;
}

/**
 *
 * @tparam T
 * @return
 */
template <typename T>
bool Queue<T>::IsEmpty()
{
    return this->Head == nullptr;
}

/**
 *
 * @tparam T
 */
template <typename T>
Queue<T>::~Queue()
{
    QueueNode<T> *TempNode = this->Head;
    while(TempNode != nullptr)
    {
        this->Dequeue();
        TempNode = this->Head;
    }
    this->MaxSize = 0;
}


template class Queue<int>;