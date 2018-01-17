#include "single_linked_list_node.h"
#include "gtest/gtest.h"
using namespace std;

class SingleLinkedListNodeTest : public ::testing::Test
{

};


TEST_F(SingleLinkedListNodeTest, InitData)
{
    single_linked_list_node<int> node(15);
    EXPECT_EQ(15, node.get_data());
}

TEST_F(SingleLinkedListNodeTest, SetGetData)
{
    single_linked_list_node<int> node(15);
    node.set_data(23);
    EXPECT_EQ(23, node.get_data());
}

TEST_F(SingleLinkedListNodeTest, StringNode)
{
    int num = 115;
    single_linked_list_node<int> node(num);
    std::string answer = node.to_string();
    EXPECT_EQ("115 -> 0", answer);
}
