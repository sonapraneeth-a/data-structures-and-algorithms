#include "SingleLinkedListNode.h"
#include "gtest/gtest.h"
using namespace std;

class SingleLinkedListNodeTest : public ::testing::Test
{

};


TEST_F(SingleLinkedListNodeTest, InitData)
{
    SingleLinkedListNode<int> node(15);
    EXPECT_EQ(15, node.get_data());
}

TEST_F(SingleLinkedListNodeTest, SetGetData)
{
    SingleLinkedListNode<int> node(15);
    node.set_data(23);
    EXPECT_EQ(23, node.get_data());
}

TEST_F(SingleLinkedListNodeTest, ToString)
{
    int num = 115;
    SingleLinkedListNode<int> node(num);
    std::string answer = node.to_string();
    EXPECT_EQ("115 -> 0", answer);
}
