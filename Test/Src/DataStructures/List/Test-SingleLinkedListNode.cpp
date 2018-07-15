#include "SingleLinkedListNode.h"
#include "gtest/gtest.h"
using namespace std;

class SingleLinkedListNodeTest : public ::testing::Test
{

};


TEST_F(SingleLinkedListNodeTest, InitData)
{
    SingleLinkedListNode<int> node(15);
    EXPECT_EQ(15, node.Data());
}

TEST_F(SingleLinkedListNodeTest, SetGetData)
{
    SingleLinkedListNode<int> node(15);
    node.Data(23);
    EXPECT_EQ(23, node.Data());
}

TEST_F(SingleLinkedListNodeTest, ToString)
{
    int num = 115;
    SingleLinkedListNode<int> node(num);
    std::string answer = node.ToString();
    EXPECT_EQ("115 -> 0", answer);
}
