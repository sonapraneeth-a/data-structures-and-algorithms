/**
 *      Created on: 20 March 2018
 *   Last modified: 18 January 2019
 *          Author: sonapraneeth-a
 *         Details: Header for queue
 */

/**
 * Changelog
 *
 * Date (DD-MM-YYYY)            Author               Update
 * 20-03-2018               sonapraneeth-a      - Creation of the file
 * 23-03-2018               sonapraneeth-a      - Added function signatures
 * 18-01-2019               sonapraneeth-a      - Renamed _MaxSize to _Capacity
 *                                              - Moved code to DS namespace
 */

#ifndef QUEUE_H
#define QUEUE_H

#include "Node.h"
#include "AccessViolationException.h"

namespace DS
{
    template<typename T>
    class Queue
    {

    private:

        DS::Node<T> *_Head;      /*!< Variable containing the pointer to head of Queue */
        DS::Node<T> *_Tail;      /*!< Variable containing the pointer to tail of Queue */
        size_t _Size = 0;        /*!< Variable containing the size of the Queue */
        size_t _Capacity = 0;    /*!< Variable containing the maximum capacity of Queue */

    public:

        explicit Queue();
        explicit Queue(T Value);

        void Enqueue(T Value);
        T Dequeue();

        bool IsEmpty();
        size_t Size() const;

        T HeadValue() const;
        T TailValue() const;

        ~Queue();
    };

    #include "Queue.cpp"

}

#endif // QUEUE_H
