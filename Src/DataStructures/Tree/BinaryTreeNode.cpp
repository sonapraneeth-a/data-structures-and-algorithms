/**
 *      Created on: 20 March 2018
 *   Last modified: 17 April 2018
 *          Author: Sona Praneeth Akula
 *         Details: Implementation for binary tree node
 */

/**
 * Changelog
 *
 * Date (DD-MM-YYYY)            Author               Update
 * 20-03-2018             Sona Praneeth Akula   - Creation of the file
 * 17-04-2018             Sona Praneeth Akula   - Added function implementation for binary tree node
 */

#include "BinaryTreeNode.h"


template <typename T>
BinaryTreeNode<T>::BinaryTreeNode(T Value)
{
    this->_Data = Value;
    this->_Left = nullptr;
    this->_Right = nullptr;
}

template <typename T>
BinaryTreeNode<T>::BinaryTreeNode(T Value, BinaryTreeNode<T>* LeftChild, BinaryTreeNode<T>* RightChild)
{
    this->_Data = Value;
    this->_Left = LeftChild;
    this->_Right = RightChild;
}

template <typename T>
BinaryTreeNode<T>*
BinaryTreeNode<T>::GetLeftChild()
{
    return this->_Left;
}

template <typename T>
void
BinaryTreeNode<T>::SetLeftChild(BinaryTreeNode* Node)
{
    this->_Left = Node;
}

template <typename T>
BinaryTreeNode<T>*
BinaryTreeNode<T>::GetRightChild()
{
    return this->_Right;
}

template <typename T>
void
BinaryTreeNode<T>::SetRightChild(BinaryTreeNode* Node)
{
    this->_Right = Node;
}

template <typename T>
T
BinaryTreeNode<T>::GetData()
{
    return this->_Data;
}

template <typename T>
void
BinaryTreeNode<T>::SetData(T Value)
{
    this->_Data = Value;
}

template <typename T>
bool
BinaryTreeNode<T>::IsLeaf()
{
    return this->_Left == nullptr && this->_Right == nullptr;
}

template <typename T>
BinaryTreeNode<T>::~BinaryTreeNode()
{

}

template class BinaryTreeNode<int>;