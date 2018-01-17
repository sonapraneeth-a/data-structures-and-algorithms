#include "single_linked_list.h"
#include "gtest/gtest.h"
using namespace std;

class SingleLinkedListTest : public ::testing::Test
{
protected:
    virtual void SetUp()
    {
        _list_int_1.insert(10);
        _list_int_2.insert(10);
        _list_int_2.insert(20);
    }

    /*virtual void TearDown()
    {

    }*/

    // List with size 0 initially
    single_linked_list<int> _list_int_0;
    // List with size 1 initially
    single_linked_list<int> _list_int_1;
    // List with size 2 initially
    single_linked_list<int> _list_int_2;

};

TEST_F(SingleLinkedListTest, InitHead)
{
    single_linked_list<int> list(10);
    EXPECT_EQ(10, list.get_head()->get_data());
}

TEST_F(SingleLinkedListTest, InsertHeadValue)
{
    EXPECT_EQ(10, _list_int_1.get_head()->get_data());
}

TEST_F(SingleLinkedListTest, PrintList)
{
    std::string obtained_answer = _list_int_2.to_string();
    std::string expected_answer = "10 -> 20 -> 0";
    EXPECT_EQ(expected_answer, obtained_answer);
}

