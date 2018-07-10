/**
 *      Created on: 23 March 2018
 *   Last modified: 23 March 2018
 *          Author: Sona Praneeth Akula
 *         Details: Header for queue node
 */

/**
 * Changelog
 *
 * Date (DD-MM-YYYY)            Author               Update
 * 23-03-2018             Sona Praneeth Akula   - Creation of the file
 *                                              - Added function signatures
 */

#ifndef QUEUE_NODE_H
#define QUEUE_NODE_H

#include "DefaultHeaders.h"
#include <iostream>
#include <sstream>
#include "../../DataStructures/Tree/BinaryTreeNode.h"

template <typename T>
class QueueNode
{
public:
    T Data;
    QueueNode<T> *Next;

    QueueNode();
    QueueNode(T Value);

    T GetData();
    QueueNode<T>* GetNext();
    void SetData(T Value);
    void SetNext(QueueNode<T> *NextLink);

    std::string ToString();

    ~QueueNode();

};

#include "QueueNode.cpp"

#endif //QUEUE_NODE_H
