/**
 *      Created on: 03 May 2018
 *   Last modified: 03 May 2018
 *          Author: Sona Praneeth Akula
 *         Details: Implmentation for binary search tree
 */

/**
 * Changelog
 *
 * Date (DD-MM-YYYY)            Author               Update
 * 03-05-2018             Sona Praneeth Akula   - Creation of the file
 */

#include "BinarySearchTree.h"

template <typename T>
BinarySearchTree::BinarySearchTree()
{
    this->_Root = nullptr;
}

template <typename T>
void
BinarySearchTree::Insert(T Value)
{
    if(this->_Root == nullptr)
    {
        this->_Root = new BinaryTreeNode(Value);
    }
    else
    {

    }
}