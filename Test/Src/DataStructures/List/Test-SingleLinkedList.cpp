/**
 *      Created on: 07 March 2018
 *   Last modified: 17 August 2018
 *          Author: Sona Praneeth Akula
 *         Details: Implementation for SingleLinkedList
 */

/**
 * Changelog
 *
 * Date (DD-MM-YYYY)            Author               Update
 * 07-03-2018           Sona Praneeth Akula   - Creation of file
 * 17-08-2018           Sona Praneeth Akula   - Renamed GetSize() to Size()
 *                                            - Added tests for InsertAtHead()
 */

#include "SingleLinkedList.h"
#include "Utilities.h"
#include "gtest/gtest.h"
using namespace std;

class SingleLinkedListTest : public ::testing::Test
{
protected:
    virtual void SetUp()
    {
        _List_int_01.Insert(100);
        _List_int_02.Insert(1000);
        _List_int_02.Insert(2000);
    }

    virtual void TearDown()
    {}

    // List with _Size 0 initially
    SingleLinkedList<int> _List_int_00;
    // List with _Size 1 initially
    SingleLinkedList<int> _List_int_01;
    // List with _Size 2 initially
    SingleLinkedList<int> _List_int_02;

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
    int number = GetRandomInt();
    SingleLinkedList<int> List(number);
    EXPECT_EQ(number, List.Head()->Data());
}

TEST_F(SingleLinkedListTest, InitHeadInsert)
{
    int number = GetRandomInt();
    SingleLinkedList<int> List;
    List.Insert(number);
    EXPECT_EQ(number, List.Head()->Data());
}

TEST_F(SingleLinkedListTest, ClearList)
{
    _List_int_02.Clear();
    EXPECT_EQ(nullptr, _List_int_02.Head());
    EXPECT_EQ(0, _List_int_02.Size());
}

TEST_F(SingleLinkedListStringTest, StringListZero)
{
    std::string obtained_answer = _List_int_00.ToString();
    std::string expected_answer = "0";
    EXPECT_EQ(expected_answer, obtained_answer);
}

TEST_F(SingleLinkedListStringTest, StringListOne)
{
    std::string obtained_answer = _List_int_01.ToString();
    std::string expected_answer = "100 -> 0";
    EXPECT_EQ(expected_answer, obtained_answer);
}

TEST_F(SingleLinkedListStringTest, StringListTwo)
{
    std::string obtained_answer = _List_int_02.ToString();
    std::string expected_answer = "1000 -> 2000 -> 0";
    EXPECT_EQ(expected_answer, obtained_answer);
}

TEST_F(SingleLinkedListInsertTest, InsertAtHead)
{
    int number = GetRandomInt();
    _List_int_00.InsertAtHead(number);
    EXPECT_EQ(number, _List_int_00.Head()->Data());
    _List_int_01.InsertAtHead(number);
    EXPECT_EQ(number, _List_int_01.Head()->Data());
    _List_int_02.InsertAtHead(number);
    EXPECT_EQ(number, _List_int_02.Head()->Data());
}

TEST_F(SingleLinkedListSizeTest, ZeroListSize)
{
    unsigned int expected_answer, obtained_answer;
    //
    expected_answer = 0;
    obtained_answer = _List_int_00.Size();
    EXPECT_EQ(expected_answer, obtained_answer) << "Test name: List with _Size 0";
}

TEST_F(SingleLinkedListSizeTest, OneListSize)
{
    unsigned int expected_answer, obtained_answer;
    _List_int_00.Insert(10);
    expected_answer = 1;
    obtained_answer = _List_int_00.Size();
    EXPECT_EQ(expected_answer, obtained_answer) << "Test name: List with _Size 1 after inserting into empty List";
    expected_answer = 1;
    obtained_answer = _List_int_01.Size();
    EXPECT_EQ(expected_answer, obtained_answer) << "Test name: List with _Size 1";
}

TEST_F(SingleLinkedListDeleteTest, DeleteHead)
{
    _List_int_01.DeleteHead();
    EXPECT_EQ(nullptr, _List_int_01.Head());
}

