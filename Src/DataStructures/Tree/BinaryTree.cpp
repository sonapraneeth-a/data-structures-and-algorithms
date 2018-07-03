/**
 *      Created on: 20 March 2018
 *   Last modified: 17 April 2018
 *          Author: Sona Praneeth Akula
 *         Details: Implementation for binary tree
 */

/**
 * Changelog
 *
 * Date (DD-MM-YYYY)            Author               Update
 * 20-03-2018             Sona Praneeth Akula   - Creation of the file
 * 17-04-2018             Sona Praneeth Akula   - Added function implementations for binary tree
 */

#include "BinaryTree.h"

template <typename T>
BinaryTree::BinaryTree()
{
    this->_Root = nullptr;
}

template <typename T>
void
BinaryTree::Insert(T Value)
{
    if(this->_Root == nullptr)
    {
        this->_Root = new BinaryTreeNode(Value);
    }
    else
    {

    }
}