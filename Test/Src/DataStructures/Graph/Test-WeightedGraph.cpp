/**
 *      Created on: 24 July 2018
 *   Last modified: 15 August 2018
 *          Author: Sona Praneeth Akula
 *         Details: Tests for Weighted graph
 */

/**
 * Changelog
 *
 * Date (DD-MM-YYYY)            Author               Update
 * 24-07-2018             Sona Praneeth Akula   - Creation of file
 *                                              - Added NoSourceNodeTest
 * 15-08-2018             Sona Praneeth Akula   - Updated NoSourceNodeTest to SourceNodeTest
 *                                                as the source code for no source node for directed
 *                                                graph is not updated
 */

#include "WeightedGraph.h"
#include "gtest/gtest.h"
#include "gmock/gmock.h"

using namespace std;

class WeightedGraphTest : public ::testing::Test
{
protected:
    virtual void SetUp()
    {

    }

    virtual void TearDown()
    {

    }

    std::vector< std::pair< std::pair<int, int>, int> > _DirectedGraph_01 \
            = { {{1, 2}, 1}, {{1, 3}, 2}, {{2, 3}, 3}, {{3, 1}, 4},
                {{3, 4}, 5}, {{4, 4}, 6}, {{5, 6}, 7}
    };
    WeightedGraph<int> *_Graph_01 = new WeightedGraph<int>(_DirectedGraph_01);

};

class WeightedGraphBFSTest: public WeightedGraphTest
{};


TEST_F(WeightedGraphBFSTest, DirectedGraphSourceNodeTest)
{
    std::vector<int> BFS, BFS_ans({1, 2, 3, 4});
    _Graph_01->BreadthFirstTraversal(1, BFS);
    EXPECT_THAT(BFS_ans,
                ::testing::ContainerEq(BFS));
}