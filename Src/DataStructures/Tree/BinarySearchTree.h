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

#ifndef BINARY_SEARCHTREE_H
#define BINARY_SEARCHTREE_H

#include "BinaryTree.h"

template <typename T>
class BinarySearchTree: public BinaryTree<T>
{
private:

    BinaryTreeNode<T> *_Root;

public:

    explicit BinarySearchTree<T>(): BinarySearchTree<T>() {}

    void Insert(T Value, BinaryTreeNode<T>* Node);
    void Delete(T Value);
    bool IsPresent(T Value);

    ~BinarySearchTree();
};


#endif // BINARY_SEARCHTREE_H
