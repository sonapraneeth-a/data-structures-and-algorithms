#include "SingleLinkedList.h"
#include "Utilities.h"
#include "gtest/gtest.h"
using namespace std;

class SingleLinkedListTest : public ::testing::Test
{
protected:
    virtual void SetUp()
    {
        _List_int_1.Insert(100);
        _List_int_2.Insert(1000);
        _List_int_2.Insert(2000);
    }

    virtual void TearDown()
    {}

    // List with Size 0 initially
    SingleLinkedList<int> _List_int_0;
    // List with Size 1 initially
    SingleLinkedList<int> _List_int_1;
    // List with Size 2 initially
    SingleLinkedList<int> _List_int_2;

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
    int number = get_Random_int();
    SingleLinkedList<int> List(number);
    EXPECT_EQ(number, List.GetHead()->get_data());
}

TEST_F(SingleLinkedListTest, InitHeadInsert)
{
    int number = get_Random_int();
    SingleLinkedList<int> List;
    List.Insert(number);
    EXPECT_EQ(number, List.GetHead()->get_data());
}

TEST_F(SingleLinkedListTest, ClearList)
{
    _List_int_2.Clear();
    EXPECT_EQ(nullptr, _List_int_2.GetHead());
    EXPECT_EQ(0, _List_int_2.GetSize());
}

TEST_F(SingleLinkedListStringTest, StringListZero)
{
    std::string obtained_answer = _List_int_0.ToString();
    std::string expected_answer = "0";
    EXPECT_EQ(expected_answer, obtained_answer);
}

TEST_F(SingleLinkedListStringTest, StringListOne)
{
    std::string obtained_answer = _List_int_1.ToString();
    std::string expected_answer = "100 -> 0";
    EXPECT_EQ(expected_answer, obtained_answer);
}

TEST_F(SingleLinkedListStringTest, StringListTwo)
{
    std::string obtained_answer = _List_int_2.ToString();
    std::string expected_answer = "1000 -> 2000 -> 0";
    EXPECT_EQ(expected_answer, obtained_answer);
}

TEST_F(SingleLinkedListInsertTest, InsertHead)
{
    int number = get_Random_int();
    _List_int_0.Insert(number);
    EXPECT_EQ(number, _List_int_0.GetHead()->get_data());
}

TEST_F(SingleLinkedListSizeTest, ZeroListSize)
{
    unsigned int expected_answer, obtained_answer;
    //
    expected_answer = 0;
    obtained_answer = _List_int_0.GetSize();
    EXPECT_EQ(expected_answer, obtained_answer) << "Test name: List with Size 0";
}

TEST_F(SingleLinkedListSizeTest, OneListSize)
{
    unsigned int expected_answer, obtained_answer;
    _List_int_0.Insert(10);
    expected_answer = 1;
    obtained_answer = _List_int_0.GetSize();
    EXPECT_EQ(expected_answer, obtained_answer) << "Test name: List with Size 1 after inserting into empty List";
    expected_answer = 1;
    obtained_answer = _List_int_1.GetSize();
    EXPECT_EQ(expected_answer, obtained_answer) << "Test name: List with Size 1";
}

TEST_F(SingleLinkedListDeleteTest, DeleteHead)
{
    _List_int_1.DeleteHead();
    EXPECT_EQ(nullptr, _List_int_1.GetHead());
}

