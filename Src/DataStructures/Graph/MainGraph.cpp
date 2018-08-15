//
// Created by pranas on 7/24/2018.
//

#include "WeightedGraph.h"

void RunDirectedWeightedGraph()
{
    /*WeightedGraph<int> *Graph = new WeightedGraph<int>();
    Graph->AddEdge(1, 2, 1);
    Graph->AddEdge(1, 3, 2);
    Graph->AddEdge(2, 3, 3);
    Graph->AddEdge(3, 1, 4);
    Graph->AddEdge(3, 4, 5);
    Graph->AddEdge(4, 4, 6);
    Graph->AddEdge(5, 6, 7);*/
    // Reference: https://stackoverflow.com/questions/11103652/c-vector-of-pairs-initialization
    std::vector< std::pair< std::pair<int, int>, int> > array \
            = { {{1, 2}, 1}, {{1, 3}, 2}, {{2, 3}, 3}, {{3, 1}, 4},
                {{3, 4}, 5}, {{4, 4}, 6}, {{5, 6}, 7}
              };
    WeightedGraph<int> *Graph = new WeightedGraph<int>(array);
    std::cout << "Graph after creation\n";
    Graph->Print();
    //Graph->DeleteEdge(2, 3);
    //std::cout << "Graph after deleting edge (3, 2)\n";
    //Graph->Print();
    std::cout << "Breadth first traversal of graph: ";
    std::vector<int> BFS;
    Graph->BreadthFirstTraversal(BFS);
    for (unsigned int index = 0; index < BFS.size(); ++index)
    {
        std::cout << BFS[index] << " ";
    }
    std::cout << "\n";
    std::cout << "Depth first traversal of graph: ";
    std::vector<int> DFS;
    Graph->DepthFirstTraversal(3, DFS);
    for (unsigned int index = 0; index < DFS.size(); ++index)
    {
        std::cout << DFS[index] << " ";
    }
    std::cout << "\n";
    Graph->DrawGraph();
}

int main()
{
    RunDirectedWeightedGraph();
    return 0;
}