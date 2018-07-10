/**
 *      Created on: 20 March 2018
 *   Last modified: 17 April 2018
 *          Author: Sona Praneeth Akula
 *         Details: Header for binary tree
 */

/**
 * Changelog
 *
 * Date (DD-MM-YYYY)            Author               Update
 * 20-03-2018             Sona Praneeth Akula   - Creation of the file
 * 17-04-2018             Sona Praneeth Akula   - Added function signatures for binary tree
 */

#ifndef BINARY_TREE_H
#define BINARY_TREE_H

#include "BinaryTreeNode.h"

template <typename T>
class BinaryTree
{
private:

    BinaryTreeNode<T> *_Root;

public:

    BinaryTree();

    void Insert(T Value);
    void Insert(BinaryTreeNode<T>* Node);
    void Delete(T Value);
    void Delete(BinaryTreeNode<T>* Node);
    void Find(T Value);

    ~BinaryTree();

};


#endif // BINARY_TREE_H
