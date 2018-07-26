/**
 *      Created on: 24 July 2018
 *   Last modified: 24 July 2018
 *          Author: Sona Praneeth Akula
 *         Details: Tests for Weighted graph
 */

/**
 * Changelog
 *
 * Date (DD-MM-YYYY)            Author               Update
 * 24-07-2018             Sona Praneeth Akula   - Creation of file
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

    std::vector< std::pair< std::pair<int, int>, int> > _Array_one \
            = { {{1, 2}, 1}, {{1, 3}, 2}, {{2, 3}, 3}, {{3, 1}, 4},
                {{3, 4}, 5}, {{4, 4}, 6}, {{5, 6}, 7}
    };
    WeightedGraph<int> *_Graph_one = new WeightedGraph<int>(_Array_one);

};

class WeightedGraphBFSTest: public WeightedGraphTest
{};


TEST_F(WeightedGraphBFSTest, NoSourceNodeTest)
{
    std::vector<int> BFS, BFS_ans({1, 2, 3, 4});
    _Graph_one->BreadthFirstTraversal(BFS);
    EXPECT_THAT(BFS_ans,
                ::testing::ContainerEq(BFS));
}