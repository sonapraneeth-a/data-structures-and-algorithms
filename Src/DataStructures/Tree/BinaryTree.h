/**
 *      Created on: 20 March 2018
 *   Last modified: 10 July 2018
 *          Author: Sona Praneeth Akula
 *         Details: Header for binary tree
 */

/**
 * Changelog
 *
 * Date (DD-MM-YYYY)            Author               Update
 * 20-03-2018             Sona Praneeth Akula   - Creation of the file
 * 17-04-2018             Sona Praneeth Akula   - Added function signatures for binary tree
 * 10-07-2018             Sona Praneeth Akula   - Added function signatures for binary tree
 *                                                Insert, InOrder, PreOrder, PostOrder, LevelOrder,
 *                                                IsPresent, GetRoot, GetRootValue, LevelOrderNodes
 */

#ifndef BINARY_TREE_H
#define BINARY_TREE_H

#include "BinaryTreeNode.h"
#include "Queue.h"

template <typename T>
class BinaryTree
{
private:

    BinaryTreeNode<T> *_Root;
    int _NumberOfNodes = 0;

    Queue<BinaryTreeNode<T>*> LevelOrderTraversalNodes(BinaryTreeNode<T> *Node);

public:

    explicit BinaryTree();
    explicit BinaryTree(std::vector<T> &Array);

    virtual void Insert(T Value, BinaryTreeNode<T>* Node);
    void Delete(T Value);
    virtual bool IsPresent(T Value);

    LLI GetHeightOfTree(BinaryTreeNode<T>* Node);

    void PrintInOrderTraversal(BinaryTreeNode<T>* Node);
    void PrintPreOrderTraversal(BinaryTreeNode<T>* Node);
    void PrintPostOrderTraversal(BinaryTreeNode<T>* Node);
    void PrintLevelOrderTraversal(BinaryTreeNode<T> *Node);

    std::vector<T> InOrderTraversal(BinaryTreeNode<T> *Node);
    std::vector<T> PreOrderTraversal(BinaryTreeNode<T> *Node);
    std::vector<T> PostOrderTraversal(BinaryTreeNode<T> *Node);
    std::vector<T> LevelOrderTraversal(BinaryTreeNode<T> *Node);


    T GetRootValue();
    BinaryTreeNode<T>* GetRoot();

    void DrawTree(std::string Filename="BinaryTree.dot", bool IsNullRequired=true);

    ~BinaryTree();

};


#endif // BINARY_TREE_H
