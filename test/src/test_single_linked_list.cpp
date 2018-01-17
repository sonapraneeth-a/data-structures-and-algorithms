#include "single_linked_list.h"
#include "gtest/gtest.h"
using namespace std;

class SingleLinkedListTest : public ::testing::Test
{

};


TEST_F(SingleLinkedListTest, InitHead)
{
    single_linked_list<int> list(15);
    EXPECT_EQ(15, list.get_head()->get_data());
}

TEST_F(SingleLinkedListTest, InsertHeadValue)
{
    single_linked_list<int> list;
    list.insert(20);
    EXPECT_EQ(20, list.get_head()->get_data());
}

TEST_F(SingleLinkedListTest, PrintList)
{
    single_linked_list<int> list;
    list.insert(20);
    list.insert(15);
    std::string obtained_answer = list.to_string();
    std::string expected_answer = "20 -> 15 -> 0";
    EXPECT_EQ(expected_answer, expected_answer);
}
