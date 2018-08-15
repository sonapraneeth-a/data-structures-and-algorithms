/**
 *      Created on: 23 July 2018
 *   Last modified: 07 August 2018
 *          Author: Sona Praneeth Akula
 *         Details: Header for Weighted graph
 */

/**
 * Changelog
 *
 * Date (DD-MM-YYYY)            Author               Update
 * 23-07-2018             Sona Praneeth Akula   - Creation of the file
 * 24-07-2018             Sona Praneeth Akula   - Added function signatures for constructors,
 *                                                destructors, BreadthFirstTraversal, DepthFirstTraversal
 *                                                (2 variations), AddEdge, DeleteEdge, Print, ToString
 *                                              - Added function signatures for helper functions DeleteNode,
 *                                                DepthFirstTraversalHelper
 * 25-07-2018             Sona Praneeth Akula   - Added function signature for GetAdjacentVertices
 * 06-08-2018             Sona Praneeth Akula   - Added function signature for ShortestPath,
 *                                                NumberOfConnectedComponents, GetConnectedComponents,
 *                                                GetReverseGraph, GetStronglyConnectedComponents,
 *                                                TopologicalSort, DrawGraph, ShortestPathBFS
 *                                              - Moved map to unordered_map as unordered_map uses hashtable
 * 07-08-2018             Sona Praneeth Akula   - Added function signature for DrawGraph
 */

#ifndef WEIGHTED_GRAPH_H
#define WEIGHTED_GRAPH_H

#include "WeightedGraphNode.h"
#include "Queue.h"

template<typename T>
using GraphIterator = typename std::unordered_map<T, WeightedGraphNode<T>*>::const_iterator;

template <typename T>
class WeightedGraph
{
private:

    std::unordered_map<T, WeightedGraphNode<T>*> _List;
    bool _IsDirected = true;

    WeightedGraphNode<T>* DeleteNode(WeightedGraphNode<T> *Node, const T& ToDeleteNode);
    void DepthFirstTraversalHelper(const T& NodeValue, std::map<T, bool>& IsNodeVisited);
    void DepthFirstTraversalHelper(const T& NodeValue,
                                   std::map<T, bool>& IsNodeVisited,
                                   std::vector<T>& DepthRoute);

public:

    explicit WeightedGraph(bool IsDirected = true);
    explicit WeightedGraph(std::vector< std::pair< std::pair<T, T>, int> > &Array, bool IsDirected = true);
    explicit WeightedGraph(std::vector< std::pair<T, T> > &Array, bool IsDirected = true);

    void AddEdge(const T& FirstNode, const T& SecondNode, int Weight = 1);
    void DeleteEdge(const T& FirstNode, const T& SecondNode);
    void Print();
    std::string ToString() const;
    std::vector<T> GetAdjacentVertices(const T& NodeValue);

    void BreadthFirstTraversal();
    void BreadthFirstTraversal(std::vector<T> &BreadthRoute);
    void BreadthFirstTraversal(const T& InputNodeValue);
    void BreadthFirstTraversal(const T& InputNodeValue, std::vector<T> &BreadthRoute);
    void DepthFirstTraversal();
    void DepthFirstTraversal(std::vector<T> &DepthRoute);
    void DepthFirstTraversal(const T& NodeValue);
    void DepthFirstTraversal(const T& NodeValue, std::vector<T> &DepthRoute);

    unsigned int NumberOfConnectedComponents();
    std::vector< std::vector<T> > GetConnectedComponents();
    WeightedGraph<T> GetReverseGraph();
    std::vector< std::vector<T> > GetStronglyConnectedComponents();
    std::vector<T> TopologicalSort();

    std::vector< std::pair<T, int> > ShortestPathBFS(const T& SourceNode);
    std::pair< int, std::vector<T> > ShortestPath(const T& FirstNode, const T& SecondNode);
    // Reference: http://tonyballantyne.com/graphs.html
    void DrawGraph(std::string Filename="Graph.dot");

    ~WeightedGraph();
};

template<typename T>
std::ostream& operator <<(std::ostream& os, const WeightedGraph<T>& Graph)
{
    os << Graph.ToString();
    return os;
}

template<typename T>
std::ostream& operator <<(std::ostream& os, const WeightedGraph<T> *Graph)
{
    os << Graph->ToString();
    return os;
}


#endif //WEIGHTED_GRAPH_H
