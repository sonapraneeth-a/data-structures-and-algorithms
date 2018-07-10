/**
 *      Created on: 03 May 2018
 *   Last modified: 03 May 2018
 *          Author: Sona Praneeth Akula
 *         Details: Header for binary search tree
 */

/**
 * Changelog
 *
 * Date (DD-MM-YYYY)            Author               Update
 * 03-05-2018             Sona Praneeth Akula   - Creation of the file
 *                                              - Added function signatures for binary search tree
 */

#ifndef BINARYSEARCHTREE_H
#define BINARYSEARCHTREE_H

#include "BinaryTreeNode.h"

template <typename T>
class BinarySearchTree
{
private:

    BinaryTreeNode<T> *_Root;

public:

    BinarySearchTree();

    void Insert(T Value);
    void Insert(BinaryTreeNode<T>* Node);
    void Delete(T Value);
    void Delete(BinaryTreeNode<T>* Node);
    void Find(T Value);

    ~BinarySearchTree();
};


#endif // BINARYSEARCHTREE_H
