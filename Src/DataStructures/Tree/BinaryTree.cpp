/**
 *      Created on: 20 March 2018
 *   Last modified: 10 July 2018
 *          Author: Sona Praneeth Akula
 *         Details: Implementation for binary tree
 */

/**
 * Changelog
 *
 * Date (DD-MM-YYYY)            Author               Update
 * 20-03-2018             Sona Praneeth Akula   - Creation of the file
 * 17-04-2018             Sona Praneeth Akula   - Added function implementations for binary tree
 *                                                Insert (partially completed)
 * 10-07-2018             Sona Praneeth Akula   - Added function implementations for binary tree
 *                                                Insert, InOrder, PreOrder, PostOrder, LevelOrder,
 *                                                IsPresent, GetRoot, GetRootValue, LevelOrderNodes
 */

#include "BinaryTree.h"

template <typename T>
BinaryTree<T>::BinaryTree()
{
    this->_Root = nullptr;
}

template <typename T>
BinaryTree<T>::BinaryTree(std::vector<T> &Array)
{
    for (ULLI index = 0; index < Array.size(); ++index)
    {
        this->Insert(Array[index], this->_Root);
    }
}

template <typename T>
void
BinaryTree<T>::Insert(T Value, BinaryTreeNode<T>* Node)
{
    // std::cout << "Inserting " << Value << " in Binary Tree\n";
    if ( Node == nullptr )
    {
        this->_Root = new BinaryTreeNode<T>(Value);
        this->_NumberOfNodes++;
        return ;
    }
    else if ( Node != nullptr &&
              Node->GetLeftChild() == nullptr &&
              Node->GetRightChild() == nullptr )
    {
        BinaryTreeNode<T> *NewNode = new BinaryTreeNode<T>(Value);
        Node->SetLeftChild(NewNode);
        // std::cout << Value << " inserted as left child to " << Node->GetData() << "\n";
        this->_NumberOfNodes++;
        return ;
    }
    else if ( Node != nullptr &&
              Node->GetLeftChild() != nullptr &&
              Node->GetRightChild() == nullptr )
    {
        BinaryTreeNode<T> *NewNode = new BinaryTreeNode<T>(Value);
        Node->SetRightChild(NewNode);
        // std::cout << Value << " inserted as right child to " << Node->GetData() << "\n";
        this->_NumberOfNodes++;
        return ;
    }
    else
    {
        this->_NumberOfNodes++;
        ULLI height = (ULLI)floor(log2(this->_NumberOfNodes)), minRange = (ULLI)pow(2,height);
        ULLI diff = this->_NumberOfNodes - minRange;
        std::string Route = Math::ToBinary(diff, height);
        ULLI LengthOfRoute = (ULLI)Route.size(), RouteIndex = 0;
        BinaryTreeNode<T> *NewNode = new BinaryTreeNode<T>(Value);
        BinaryTreeNode<T> *Temp = Node;
        // std::cout << "Size: " << this->_NumberOfNodes << " Route: " << Route << "\n";
        while( RouteIndex != LengthOfRoute-1 )
        {
            if( Route[RouteIndex] == '0' )
            {
                // std::cout << "Looking at left child of " << Temp->GetData() << "\n";
                Temp = Temp->GetLeftChild();
            }
            else
            {
                // std::cout << "Looking at right child of " << Temp->GetData() << "\n";
                Temp = Temp->GetRightChild();
            }
            RouteIndex++;
        }
        if( Route[RouteIndex] == '0' )
        {
            // std::cout << Value << " inserted as left child to " << Temp->GetData() << "\n";
            Temp->SetLeftChild(NewNode);
        }
        else
        {
            // std::cout << Value << " inserted as right child to " << Temp->GetData() << "\n";
            Temp->SetRightChild(NewNode);
        }
    }
    return;
}

template <typename T>
void
BinaryTree<T>::PrintInOrderTraversal(BinaryTreeNode<T> *Node)
{
    if ( Node != nullptr )
    {
        PrintInOrderTraversal(Node->GetLeftChild());
        std::cout << Node->GetData() << " ";
        PrintInOrderTraversal(Node->GetRightChild());
    }
}

template <typename T>
void
BinaryTree<T>::PrintPreOrderTraversal(BinaryTreeNode<T> *Node)
{
    if ( Node != nullptr )
    {
        PrintPreOrderTraversal(Node->GetLeftChild());
        PrintPreOrderTraversal(Node->GetRightChild());
        std::cout << Node->GetData() << " ";
    }
}

template <typename T>
void
BinaryTree<T>::PrintPostOrderTraversal(BinaryTreeNode<T> *Node)
{
    if ( Node != nullptr )
    {
        std::cout << Node->GetData() << " ";
        PrintPostOrderTraversal(Node->GetLeftChild());
        PrintPostOrderTraversal(Node->GetRightChild());
    }
}

template <class T>
Queue<BinaryTreeNode<T>*>
BinaryTree<T>::LevelOrderTraversalNodes(BinaryTreeNode<T> *Node)
{
    // std::cout << "Level order traversal for nodes\n";
    Queue<BinaryTreeNode<T>*> TreeNodes, TempTreeNodes;
    // std::cout << "Root: " << this->_Root << "\n";
    // std::cout << "Root Null: " << (this->_Root != nullptr) << "\n";
    if(this->_Root != nullptr)
    {
        TreeNodes.Enqueue(this->_Root);
        TempTreeNodes.Enqueue(this->_Root);
        while(!TempTreeNodes.IsEmpty())
        {
            BinaryTreeNode<T> *TreeNode = TempTreeNodes.Dequeue();
            if(TreeNode->GetLeftChild() != nullptr)
            {
                TreeNodes.Enqueue(TreeNode->GetLeftChild());
                TempTreeNodes.Enqueue(TreeNode->GetLeftChild());
            }
            if(TreeNode->GetRightChild() != nullptr)
            {
                TreeNodes.Enqueue(TreeNode->GetRightChild());
                TempTreeNodes.Enqueue(TreeNode->GetRightChild());
            }
        }
    }
    // std::cout << "Total size: " << TreeNodes.GetSize() << "\n";
    return TreeNodes;
}

template <class T>
std::vector<T>
BinaryTree<T>::LevelOrderTraversal(BinaryTreeNode<T> *Node)
{
    // std::cout << "Level order traversal for nodes\n";
    Queue<BinaryTreeNode<T>*> TempTreeNodes;
    std::vector<T> Nodes;
    // std::cout << "Root: " << this->_Root << "\n";
    // std::cout << "Root Null: " << (this->_Root != nullptr) << "\n";
    if(this->_Root != nullptr)
    {
        Nodes.push_back(this->_Root->GetData());
        TempTreeNodes.Enqueue(this->_Root);
        while (!TempTreeNodes.IsEmpty())
        {
            BinaryTreeNode<T> *TreeNode = TempTreeNodes.Dequeue();
            if (TreeNode->GetLeftChild() != nullptr)
            {
                TempTreeNodes.Enqueue(TreeNode->GetLeftChild());
                Nodes.push_back(TreeNode->GetLeftChild()->GetData());
            }
            if (TreeNode->GetRightChild() != nullptr)
            {
                TempTreeNodes.Enqueue(TreeNode->GetRightChild());
                Nodes.push_back(TreeNode->GetRightChild()->GetData());
            }
        }
    }
    // std::cout << "Total size: " << TreeNodes.GetSize() << "\n";
    return Nodes;
}

template <typename T>
BinaryTreeNode<T>*
BinaryTree<T>::GetRoot()
{
    return this->_Root;
}

template <typename T>
T
BinaryTree<T>::GetRootValue()
{
    if( this->_Root != nullptr )
    {
        return this->_Root->GetData();
    }
    else
    {
        return -1;
    }
}

template <typename T>
void
BinaryTree<T>::DrawTree(std::string Filename, bool IsNullRequired)
{
    // Reference: https://eli.thegreenplace.net/2009/11/23/visualizing-binary-trees-with-graphviz
    // Reference: http://xlong88.github.io/draw-binary-tree-latex/
    std::map<BinaryTreeNode<T>*, ULLI> NodeAddressToNumber;
    Queue<BinaryTreeNode<T>*> BinaryTreeNodesQueue = LevelOrderTraversalNodes(this->_Root);
    ULLI TreeNodeIndex = 1;
    // std::cout << "Queue size: " << BinaryTreeNodesQueue.GetSize() << "\n";
    while( !BinaryTreeNodesQueue.IsEmpty() )
    {
        BinaryTreeNode<T> *TempTreeNode = BinaryTreeNodesQueue.Dequeue();
        NodeAddressToNumber[TempTreeNode] = TreeNodeIndex;
        // std::cout << TempTreeNode << "::" << TreeNodeIndex << "\n";
        TreeNodeIndex++;
    }
    std::ofstream OutputDotFile;
    OutputDotFile.open(Filename, std::ofstream::out);
    std::streambuf *coutbuf = std::cout.rdbuf();
    std::cout.rdbuf(OutputDotFile.rdbuf());
    typename std::map<int, BinaryTreeNode<T>*>::iterator it;
    std::cout << "// Author: Sona Praneeth Akula\n";
    std::cout << "// Running Instruction: dot -Tpng tree.dot -o tree.png\n";
    std::cout << "strict digraph G \n{\n";
    std::cout << "\tnodesep = 1.0 // increases the separation between Nodes\n";
    std::cout << "\tnode [color=Red, fontname=\"Ubuntu Mono\", shape=circle]";
    std::cout << " //All Nodes will have this shape and colour\n";
    std::cout << "\tedge [dir=none, color=blue]\n";
    /*for (it=nodeNumberToAddress.begin(); it!=nodeNumberToAddress.end(); ++it)
        std::cout << "\t" << it->first << " [ label = \"" << (it->second)->GetData() << "\" ]\n";*/
    Queue<T> Nodes;
    Queue<BinaryTreeNode<T>*> TreeNodes;
    ULLI NullNodes = 0;
    if(this->_Root != nullptr)
    {
        Nodes.Enqueue(this->_Root->GetData());
        TreeNodes.Enqueue(this->_Root);
        while(!TreeNodes.IsEmpty())
        {
            BinaryTreeNode<T> *TreeNode = TreeNodes.Dequeue();
            std::cout << "\t"
                      << NodeAddressToNumber[TreeNode]
                      << " [ label = \"" << TreeNode->GetData() << "\" ]\n";
            if( ( TreeNode->GetLeftChild() != nullptr ) &&
                ( TreeNode->GetRightChild() != nullptr ))
            {
                std::cout << "\t"
                          << NodeAddressToNumber[TreeNode->GetLeftChild()]
                          << " [ label = \""
                          << TreeNode->GetLeftChild()->GetData() << "\" ]\n";
                std::cout << "\t"
                          << NodeAddressToNumber[TreeNode->GetRightChild()]
                          << " [ label = \""
                          << TreeNode->GetRightChild()->GetData() << "\" ]\n";
                std::cout << "\t" << NodeAddressToNumber[TreeNode] << " -> { ";
                std::cout << NodeAddressToNumber[TreeNode->GetLeftChild()] << ", ";
                std::cout << NodeAddressToNumber[TreeNode->GetRightChild()] << " }\n";
                TreeNodes.Enqueue(TreeNode->GetLeftChild());
                TreeNodes.Enqueue(TreeNode->GetRightChild());
            }
            else if( TreeNode->GetRightChild() != nullptr )
            {
                std::cout << "\tNULL"
                          << NullNodes << " [ label = \"NULL"
                          << NullNodes << "\", shape = point ]\n";
                std::cout << "\t"
                          << NodeAddressToNumber[TreeNode->GetRightChild()]
                          << " [ label = \""
                          << TreeNode->GetRightChild()->GetData() << "\" ]\n";
                std::cout << "\t" << NodeAddressToNumber[TreeNode] << " -> { ";
                std::cout << "NULL" << NullNodes  << ", ";
                std::cout << NodeAddressToNumber[TreeNode->GetRightChild()] << " }\n";
                TreeNodes.Enqueue(TreeNode->GetRightChild()); NullNodes++;
            }
            else if( TreeNode->GetLeftChild() != nullptr )
            {
                std::cout << "\t"
                          << NodeAddressToNumber[TreeNode->GetLeftChild()]
                          << " [ label = \""
                          << TreeNode->GetLeftChild()->GetData() << "\" ]\n";
                std::cout << "\tNULL" << NullNodes
                          << " [ label = \"NULL" << NullNodes << "\", shape = point ]\n";
                std::cout << "\t" << NodeAddressToNumber[TreeNode] << " -> { ";
                std::cout << NodeAddressToNumber[TreeNode->GetLeftChild()] << ", ";
                std::cout << "NULL" << NullNodes  << " }\n";
                TreeNodes.Enqueue(TreeNode->GetLeftChild()); NullNodes++;
            }
            else
            {
                if (IsNullRequired)
                {
                    std::cout << "\tNULL" << NullNodes
                              << " [ label = \"NULL" << NullNodes << "\", shape = point ]\n";
                    std::cout << "\tNULL" << NullNodes + 1
                              << " [ label = \"NULL" << NullNodes + 1 << "\", shape = point ]\n";
                    std::cout << "\t" << NodeAddressToNumber[TreeNode] << " -> { ";
                    std::cout << "NULL" << NullNodes << ", ";
                    std::cout << "NULL" << NullNodes + 1 << " }\n";
                    NullNodes += 2;
                }
            }
        }
    }

    std::cout << "}\n";
    std::cout.rdbuf(coutbuf);
    return;

}

template <typename T>
bool
BinaryTree<T>::IsPresent(T Value)
{
    Queue<BinaryTreeNode<T>*> TempTreeNodes;
    if(this->_Root != nullptr)
    {
        TempTreeNodes.Enqueue(this->_Root);
        while (!TempTreeNodes.IsEmpty())
        {
            BinaryTreeNode<T> *TreeNode = TempTreeNodes.Dequeue();
            if (TreeNode->GetData() == Value)
            {
                return true;
            }
            if (TreeNode->GetLeftChild() != nullptr)
            {
                TempTreeNodes.Enqueue(TreeNode->GetLeftChild());
            }
            if (TreeNode->GetRightChild() != nullptr)
            {
                TempTreeNodes.Enqueue(TreeNode->GetRightChild());
            }
        }
    }
    // std::cout << "Total size: " << TreeNodes.GetSize() << "\n";
    return false;
}

template <typename T>
LLI
BinaryTree<T>::GetHeightOfTree(BinaryTreeNode<T>* Node)
{
    if(Node == nullptr)
    {
        return 0;
    }
    else if (Node->GetLeftChild() == nullptr &&
             Node->GetRightChild() == nullptr)
    {
        return 1;
    }
    else if (Node->GetLeftChild() != nullptr &&
             Node->GetRightChild() != nullptr)
    {
        return 1 + std::max(GetHeightOfTree(Node->GetLeftChild()),
                            GetHeightOfTree(Node->GetRightChild()));
    }
    else if (Node->GetLeftChild() != nullptr &&
             Node->GetRightChild() == nullptr)
    {
        return 1 + GetHeightOfTree(Node->GetLeftChild());
    }
    else
    {
        return 1 + GetHeightOfTree(Node->GetRightChild());
    }

}

template class BinaryTree<int>;