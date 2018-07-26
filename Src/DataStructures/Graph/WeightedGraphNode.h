/**
 *      Created on: 23 July 2018
 *   Last modified: 24 July 2018
 *          Author: Sona Praneeth Akula
 *         Details: Header for Weighted graph node
 */

/**
 * Changelog
 *
 * Date (DD-MM-YYYY)            Author               Update
 * 23-07-2018             Sona Praneeth Akula   - Creation of the file
 *                                              - Added function signatures for constructor,
 *                                                destructor, Data, Weight, Next
 * 24-07-2018             Sona Praneeth Akula   - Minor update to ToString (const) and << operator
 */

#ifndef WEIGHTED_GRAPHNODE_H
#define WEIGHTED_GRAPHNODE_H

#include "DefaultHeaders.h"

template <typename T>
class WeightedGraphNode
{
private:

    T _Data;
    int _Weight;
    WeightedGraphNode<T>* _Next;

public:

    explicit WeightedGraphNode(const T& Data, int Weight = 0);

    T Data() const;
    WeightedGraphNode<T>* Next() const;
    int Weight() const;
    void Data(T Value);
    void Next(WeightedGraphNode<T> *NextLink);
    void Weight(int Weight);

    std::string ToString() const;

    ~WeightedGraphNode();
};

template<typename T>
std::ostream& operator <<(std::ostream& os, const WeightedGraphNode<T>& Node)
{
    os << Node.ToString();
}

template<typename T>
std::ostream& operator <<(std::ostream& os, const WeightedGraphNode<T> *Node)
{
    os << Node->ToString();
    return os;
}


#endif //WEIGHTED_GRAPHNODE_H
