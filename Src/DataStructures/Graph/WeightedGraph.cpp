/**
 *      Created on: 23 July 2018
 *   Last modified: 25 July 2018
 *          Author: Sona Praneeth Akula
 *         Details: Implementation for Weighted graph
 */

/**
 * Changelog
 *
 * Date (DD-MM-YYYY)            Author               Update
 * 23-07-2018             Sona Praneeth Akula   - Creation of the file
 * 24-07-2018             Sona Praneeth Akula   - Added function implementation for constructors,
 *                                                BreadthFirstTraversal, DepthFirstTraversal
 *                                                (2 variations), AddEdge, DeleteEdge, Print, ToString
 *                                              - Added function implementation for helper functions
 *                                                DeleteNode, DepthFirstTraversalHelper
 * 25-07-2018             Sona Praneeth Akula   - Added function implementation for GetAdjacentVertices
 */

#include "WeightedGraph.h"

template <typename T>
WeightedGraph<T>::WeightedGraph(bool IsDirected)
{
    this->_IsDirected = IsDirected;
}

template <typename T>
WeightedGraph<T>::WeightedGraph(std::vector< std::pair<T, T> > &Array,
                                bool IsDirected)
{
    this->_IsDirected = IsDirected;
    unsigned long int NumberOfEdges = Array.size();
    for (unsigned long int edgeNo = 0; edgeNo < NumberOfEdges; ++edgeNo)
    {
        this->AddEdge(Array[edgeNo].first, Array[edgeNo].second);
    }
}

template <typename T>
WeightedGraph<T>::WeightedGraph(std::vector< std::pair< std::pair<T, T>, int> > &Array,
                                bool IsDirected)
{
    this->_IsDirected = IsDirected;
    unsigned long int NumberOfEdges = Array.size();
    for (unsigned long int edgeNo = 0; edgeNo < NumberOfEdges; ++edgeNo)
    {
        this->AddEdge(Array[edgeNo].first.first,
                      Array[edgeNo].first.second,
                      Array[edgeNo].second);
    }
}

template <typename T>
void
WeightedGraph<T>::AddEdge(const T& FirstNode, const T& SecondNode, int Weight)
{
    if (_List.find(FirstNode) != _List.end() && _List[FirstNode] != nullptr)
    {
        WeightedGraphNode<T> *Node = _List[FirstNode];
        bool IsSecondNodeAvailable = true;
        while( Node != nullptr )
        {
            if (Node->Data() != SecondNode && Node->Next() != nullptr)
            {
                Node = Node->Next();
            }
            else if(Node->Next() == nullptr)
            {
                Node->Next(new WeightedGraphNode<T>(SecondNode, Weight));
                IsSecondNodeAvailable = false;
                break;
            }
            else
            {
                Node->Weight(Weight);
                break;
            }
        }
        if(!IsSecondNodeAvailable)
        {
            _List.insert(std::make_pair(SecondNode, nullptr));
        }
    }
    else
    {
        if (_List.find(FirstNode) == _List.end())
        {
            _List.insert(std::make_pair(FirstNode,
                                        new WeightedGraphNode<T>(SecondNode, Weight)));
        }
        else
        {
            _List[FirstNode] = new WeightedGraphNode<T>(SecondNode, Weight);
        }
        if (_List.find(SecondNode) == _List.end())
        {
            _List.insert(std::make_pair(SecondNode, nullptr));
        }
    }
    if(!this->_IsDirected)
    {
        if (_List.find(SecondNode) != _List.end() && _List[SecondNode] != nullptr)
        {
            WeightedGraphNode<T> *Node = _List[SecondNode];
            bool IsFirstNodeAvailable = true;
            while( Node != nullptr )
            {
                if (Node->Data() != FirstNode && Node->Next() != nullptr)
                {
                    Node = Node->Next();
                }
                else if(Node->Next() == nullptr)
                {
                    Node->Next(new WeightedGraphNode<T>(FirstNode, Weight));
                    IsFirstNodeAvailable = false;
                    break;
                }
                else
                {
                    Node->Weight(Weight);
                    break;
                }
            }
            if(!IsFirstNodeAvailable)
            {
                _List.insert(std::make_pair(FirstNode, nullptr));
            }
        }
        else
        {
            if (_List.find(SecondNode) == _List.end())
            {
                _List.insert(std::make_pair(SecondNode,
                                            new WeightedGraphNode<T>(FirstNode, Weight)));
            }
            else
            {
                _List[SecondNode] = new WeightedGraphNode<T>(FirstNode, Weight);
            }
            if (_List.find(FirstNode) == _List.end())
            {
                _List.insert(std::make_pair(FirstNode, nullptr));
            }
        }
    }
}

template <typename T>
WeightedGraphNode<T>*
WeightedGraph<T>::DeleteNode(WeightedGraphNode<T> *Node, const T& ToDeleteNode)
{
    WeightedGraphNode<T>* PrevNode = Node, *Head = Node;
    WeightedGraphNode<T>* NextNode = Node->Next();
    if(PrevNode->Data() == ToDeleteNode && PrevNode == Node)
    {
        Head = Node->Next();
        delete PrevNode;
    }
    else
    {
        while(NextNode != nullptr && NextNode->Data() != ToDeleteNode)
        {
            NextNode = NextNode->Next();
            PrevNode = PrevNode->Next();
        }
        if(NextNode != nullptr && NextNode->Data() == ToDeleteNode)
        {
            PrevNode->Next(NextNode->Next());
            delete NextNode;
        }
    }
    return Head;
}

template <typename T>
void
WeightedGraph<T>::DeleteEdge(const T& FirstNode, const T& SecondNode)
{
    if (_List.find(FirstNode) != _List.end() && _List[FirstNode] != nullptr)
    {
        WeightedGraphNode<T> *Node = _List[FirstNode];
        _List[FirstNode] = this->DeleteNode(Node, SecondNode);
    }
    if (!this->_IsDirected &&
        _List.find(SecondNode) != _List.end() &&
        _List[SecondNode] != nullptr)
    {
        WeightedGraphNode<T> *Node = _List[SecondNode];
        _List[SecondNode] = this->DeleteNode(Node, FirstNode);
    }
}

template <typename T>
void
WeightedGraph<T>::Print()
{
    for (GraphIterator<T> iter = _List.begin(); iter != _List.end(); ++iter)
    {
        WeightedGraphNode<T> *Node = iter->second;
        std::cout << iter->first << " => ";
        if (Node == nullptr)
        {
            std::cout << "NULL";
        }
        while( Node != nullptr )
        {
            std::cout << Node;
            Node = Node->Next();
        }
        std::cout << "\n";
    }
}

template <typename T>
std::vector<T>
WeightedGraph<T>::GetAdjacentVertices(const T& NodeValue)
{
    WeightedGraphNode<T> *Node = _List[NodeValue];
    std::vector<T> Edges;
    while(Node != nullptr)
    {
        Edges.push_back(Node->Data());
        Node = Node->Next();
    }
    delete Node;
    return Edges;
}

template <typename T>
std::string
WeightedGraph<T>::ToString() const
{
    std::stringstream answer;
    for (GraphIterator<T> iter = _List.begin(); iter != _List.end(); ++iter)
    {
        WeightedGraphNode<T> *Node = iter->second;
        answer << iter->first << " => ";
        if (Node == nullptr)
        {
            answer << "NULL";
        }
        while( Node != nullptr )
        {
            answer << Node->ToString();
            Node = Node->Next();
        }
        answer << "\n";
    }
    return answer.str();
}

template <typename T>
void
WeightedGraph<T>::BreadthFirstTraversal()
{
    Queue<T> TempGraphNodes;
    std::map<T, bool> IsNodeVisited;
    for (GraphIterator<T> iter = _List.begin(); iter != _List.end(); ++iter)
    {
        IsNodeVisited[iter->first] = false;
    }
    TempGraphNodes.Enqueue(_List.begin()->first);
    while(!TempGraphNodes.IsEmpty())
    {
        T NodeValue = TempGraphNodes.Dequeue();
        IsNodeVisited[NodeValue] = true;
        std::cout << NodeValue << " ";
        WeightedGraphNode<T> *Node = _List[NodeValue];
        while(Node != nullptr)
        {
            if (!IsNodeVisited[Node->Data()])
            {
                TempGraphNodes.Enqueue(Node->Data());
                IsNodeVisited[Node->Data()] = true;
            }
            Node = Node->Next();
        }
    }
    std::cout << "\n";
}

template <typename T>
void
WeightedGraph<T>::BreadthFirstTraversal(std::vector<T> &BreadthRoute)
{
    Queue<T> TempGraphNodes;
    std::map<T, bool> IsNodeVisited;
    for (GraphIterator<T> iter = _List.begin(); iter != _List.end(); ++iter)
    {
        IsNodeVisited[iter->first] = false;
    }
    TempGraphNodes.Enqueue(_List.begin()->first);
    while(!TempGraphNodes.IsEmpty())
    {
        T NodeValue = TempGraphNodes.Dequeue();
        IsNodeVisited[NodeValue] = true;
        BreadthRoute.push_back(NodeValue);
        WeightedGraphNode<T> *Node = _List[NodeValue];
        while(Node != nullptr)
        {
            if (!IsNodeVisited[Node->Data()])
            {
                TempGraphNodes.Enqueue(Node->Data());
                IsNodeVisited[Node->Data()] = true;
            }
            Node = Node->Next();
        }
    }
}

template <typename T>
void
WeightedGraph<T>::BreadthFirstTraversal(const T& InputNodeValue)
{
    Queue<T> TempGraphNodes;
    std::map<T, bool> IsNodeVisited;
    for (GraphIterator<T> iter = _List.begin(); iter != _List.end(); ++iter)
    {
        IsNodeVisited[iter->first] = false;
    }
    TempGraphNodes.Enqueue(InputNodeValue);
    while(!TempGraphNodes.IsEmpty())
    {
        T NodeValue = TempGraphNodes.Dequeue();
        IsNodeVisited[NodeValue] = true;
        std::cout << NodeValue << " ";
        WeightedGraphNode<T> *Node = _List[NodeValue];
        while(Node != nullptr)
        {
            if (!IsNodeVisited[Node->Data()])
            {
                TempGraphNodes.Enqueue(Node->Data());
                IsNodeVisited[Node->Data()] = true;
            }
            Node = Node->Next();
        }
    }
    std::cout << "\n";
}

template <typename T>
void
WeightedGraph<T>::BreadthFirstTraversal(const T& InputNodeValue, std::vector<T> &BreadthRoute)
{
    Queue<T> TempGraphNodes;
    std::map<T, bool> IsNodeVisited;
    for (GraphIterator<T> iter = _List.begin(); iter != _List.end(); ++iter)
    {
        IsNodeVisited[iter->first] = false;
    }
    TempGraphNodes.Enqueue(InputNodeValue);
    while(!TempGraphNodes.IsEmpty())
    {
        T NodeValue = TempGraphNodes.Dequeue();
        IsNodeVisited[NodeValue] = true;
        BreadthRoute.push_back(NodeValue);
        WeightedGraphNode<T> *Node = _List[NodeValue];
        while(Node != nullptr)
        {
            if (!IsNodeVisited[Node->Data()])
            {
                TempGraphNodes.Enqueue(Node->Data());
                IsNodeVisited[Node->Data()] = true;
            }
            Node = Node->Next();
        }
    }
}

template <typename T>
void
WeightedGraph<T>::DepthFirstTraversal()
{
    std::map<T, bool> IsNodeVisited;
    for (GraphIterator<T> iter = _List.begin(); iter != _List.end(); ++iter)
    {
        IsNodeVisited[iter->first] = false;
    }
    DepthFirstTraversalHelper(_List.begin()->first, IsNodeVisited);
    std::cout << "\n";
}

template <typename T>
void
WeightedGraph<T>::DepthFirstTraversal(std::vector<T>& DepthRoute)
{
    std::map<T, bool> IsNodeVisited;
    for (GraphIterator<T> iter = _List.begin(); iter != _List.end(); ++iter)
    {
        IsNodeVisited[iter->first] = false;
    }
    DepthFirstTraversalHelper(_List.begin()->first, IsNodeVisited, DepthRoute);
}

template <typename T>
void
WeightedGraph<T>::DepthFirstTraversal(const T& NodeValue)
{
    std::map<T, bool> IsNodeVisited;
    for (GraphIterator<T> iter = _List.begin(); iter != _List.end(); ++iter)
    {
        IsNodeVisited[iter->first] = false;
    }
    DepthFirstTraversalHelper(NodeValue, IsNodeVisited);
    std::cout << "\n";
}

template <typename T>
void
WeightedGraph<T>::DepthFirstTraversal(const T& NodeValue, std::vector<T>& DepthRoute)
{
    std::map<T, bool> IsNodeVisited;
    for (GraphIterator<T> iter = _List.begin(); iter != _List.end(); ++iter)
    {
        IsNodeVisited[iter->first] = false;
    }
    DepthFirstTraversalHelper(NodeValue, IsNodeVisited, DepthRoute);
}

template <typename T>
void
WeightedGraph<T>::DepthFirstTraversalHelper(const T& NodeValue, std::map<T, bool>& IsNodeVisited)
{
    std::cout << NodeValue << " ";
    IsNodeVisited[NodeValue] = true;
    WeightedGraphNode<T> *Node = _List[NodeValue];
    while(Node != nullptr)
    {
        if (!IsNodeVisited[Node->Data()])
        {
            DepthFirstTraversalHelper(Node->Data(), IsNodeVisited);
        }
        Node = Node->Next();
    }
}

template <typename T>
void
WeightedGraph<T>::DepthFirstTraversalHelper(const T& NodeValue,
                                            std::map<T, bool>& IsNodeVisited,
                                            std::vector<T>& DepthRoute)
{
    DepthRoute.push_back(NodeValue);
    IsNodeVisited[NodeValue] = true;
    WeightedGraphNode<T> *Node = _List[NodeValue];
    while(Node != nullptr)
    {
        if (!IsNodeVisited[Node->Data()])
        {
            DepthFirstTraversalHelper(Node->Data(), IsNodeVisited, DepthRoute);
        }
        Node = Node->Next();
    }
}

template <typename T>
WeightedGraph<T>::~WeightedGraph()
{

}

template class WeightedGraph<int>;
template class WeightedGraph<double>;
template class WeightedGraph<char>;
template class WeightedGraph<std::string>;
