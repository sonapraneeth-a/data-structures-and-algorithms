/**
 *      Created on: 20 March 2018
 *   Last modified: 17 April 2018
 *          Author: Sona Praneeth Akula
 *         Details: Header for binary tree node
 */

/**
 * Changelog
 *
 * Date (DD-MM-YYYY)            Author               Update
 * 20-03-2018             Sona Praneeth Akula   - Creation of the file
 * 17-04-2018             Sona Praneeth Akula   - Added function signatures for binary tree node
 */

#ifndef BINARY_TREE_NODE_H
#define BINARY_TREE_NODE_H

template <typename T>
class BinaryTreeNode
{
private:

    T _Data;
    BinaryTreeNode<T>* _Left;
    BinaryTreeNode<T>* _Right;

public:

    BinaryTreeNode(T Value);

    BinaryTreeNode* GetLeftChild();
    void SetLeftChild(BinaryTreeNode* Node);
    BinaryTreeNode* GetRightChild();
    void SetRightChild(BinaryTreeNode* Node);
    T GetData();
    void SetData(T Value);

    ~BinaryTreeNode();
};


#endif // BINARY_TREE_NODE_H
