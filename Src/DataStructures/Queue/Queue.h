/**
 *      Created on: 20 March 2018
 *   Last modified: 23 March 2018
 *          Author: Sona Praneeth Akula
 *         Details: Header for queue
 */

/**
 * Changelog
 *
 * Date (DD-MM-YYYY)            Author               Update
 * 20-03-2018             Sona Praneeth Akula   - Creation of the file
 * 23-03-2018             Sona Praneeth Akula   - Added function signatures
 */

#ifndef QUEUE_H
#define QUEUE_H

#include "QueueNode.h"

template <typename T>
class Queue
{
private:

    QueueNode<T> *_Head;
    QueueNode<T> *_Tail;
    ULLI _Size = 0;
    ULLI _MaxSize = 0;

public:

    Queue();
    Queue(T Value);

    void Enqueue(T Value);
    T Dequeue();
    bool IsEmpty();
    T HeadValue() const;
    T TailValue() const;
    ULLI Size() const;

    ~Queue();
};

#include "Queue.cpp"

#endif //QUEUE_H
