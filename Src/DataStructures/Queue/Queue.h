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
public:

    QueueNode<T> *Head;
    QueueNode<T> *Tail;
    ULLI Size = 0;
    ULLI MaxSize = 0;

    Queue();
    Queue(T Value);

    void Enqueue(T Value);
    T Dequeue();
    bool IsEmpty();
    T GetHead();
    T GetTail();
    ULLI GetSize();

    ~Queue();
};


#endif //QUEUE_H
