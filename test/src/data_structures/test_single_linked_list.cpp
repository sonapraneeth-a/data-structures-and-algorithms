#include "single_linked_list.h"
#include "utilities.h"
#include "gtest/gtest.h"
using namespace std;

class SingleLinkedListTest : public ::testing::Test
{
protected:
    virtual void SetUp()
    {
        _list_int_1.insert(100);
        _list_int_2.insert(1000);
        _list_int_2.insert(2000);
    }

    virtual void TearDown()
    {}

    // List with size 0 initially
    single_linked_list<int> _list_int_0;
    // List with size 1 initially
    single_linked_list<int> _list_int_1;
    // List with size 2 initially
    single_linked_list<int> _list_int_2;

};

class SingleLinkedListInsertTest : public SingleLinkedListTest
{};

class SingleLinkedListDeleteTest : public SingleLinkedListTest
{};

class SingleLinkedListSizeTest : public SingleLinkedListTest
{};

class SingleLinkedListStringTest : public SingleLinkedListTest
{};

TEST_F(SingleLinkedListTest, InitHeadDefault)
{
    int number = get_random_int();
    single_linked_list<int> list(number);
    EXPECT_EQ(number, list.get_head()->get_data());
}

TEST_F(SingleLinkedListTest, InitHeadInsert)
{
    int number = get_random_int();
    single_linked_list<int> list;
    list.insert(number);
    EXPECT_EQ(number, list.get_head()->get_data());
}

TEST_F(SingleLinkedListTest, ClearList)
{
    _list_int_2.clear();
    EXPECT_EQ(nullptr, _list_int_2.get_head());
    EXPECT_EQ(0, _list_int_2.get_size());
}

TEST_F(SingleLinkedListStringTest, StringListZero)
{
    std::string obtained_answer = _list_int_0.to_string();
    std::string expected_answer = "0";
    EXPECT_EQ(expected_answer, obtained_answer);
}

TEST_F(SingleLinkedListStringTest, StringListOne)
{
    std::string obtained_answer = _list_int_1.to_string();
    std::string expected_answer = "100 -> 0";
    EXPECT_EQ(expected_answer, obtained_answer);
}

TEST_F(SingleLinkedListStringTest, StringListTwo)
{
    std::string obtained_answer = _list_int_2.to_string();
    std::string expected_answer = "1000 -> 2000 -> 0";
    EXPECT_EQ(expected_answer, obtained_answer);
}

TEST_F(SingleLinkedListInsertTest, InsertHead)
{
    int number = get_random_int();
    _list_int_0.insert(number);
    EXPECT_EQ(number, _list_int_0.get_head()->get_data());
}

TEST_F(SingleLinkedListSizeTest, ZeroListSize)
{
    unsigned int expected_answer, obtained_answer;
    //
    expected_answer = 0;
    obtained_answer = _list_int_0.get_size();
    EXPECT_EQ(expected_answer, obtained_answer) << "Test name: List with size 0";
}

TEST_F(SingleLinkedListSizeTest, OneListSize)
{
    unsigned int expected_answer, obtained_answer;
    _list_int_0.insert(10);
    expected_answer = 1;
    obtained_answer = _list_int_0.get_size();
    EXPECT_EQ(expected_answer, obtained_answer) << "Test name: List with size 1 after inserting into empty list";
    expected_answer = 1;
    obtained_answer = _list_int_1.get_size();
    EXPECT_EQ(expected_answer, obtained_answer) << "Test name: List with size 1";
}

TEST_F(SingleLinkedListDeleteTest, DeleteHead)
{
    _list_int_1.delete_head();
    EXPECT_EQ(nullptr, _list_int_1.get_head());
}

