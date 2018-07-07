/**
 *      Created on: 03 April 2018
 *   Last modified: 12 April 2018
 *          Author: Sona Praneeth Akula
 *         Details: Tests for Stack
 */

/**
 * Changelog
 *
 * Date (DD-MM-YYYY)            Author               Update
 * 03-04-2018             Sona Praneeth Akula   - Creation of file
 * 12-04-2018             Sona Praneeth Akula   - Adding tests for stack
 */

#include "Stack.h"
#include "gtest/gtest.h"

using namespace std;

class StackTest : public ::testing::Test
{
protected:
    virtual void SetUp()
    {
        _Stack_int_1.Push(10);
    }

    virtual void TearDown()
    {

    }

    Stack<int> _Stack_int_0;
    Stack<int> _Stack_int_1;
    Stack<int> *_Stack_int_10 = new Stack<int>(10);

};

class StackSizeTest: public StackTest
{};

class StackElementAccessTest: public StackTest
{};

TEST_F(StackSizeTest, ZeroSizeTest)
{
    EXPECT_EQ(0, _Stack_int_0.GetSize());
    EXPECT_EQ(true, _Stack_int_0.IsEmpty());
    _Stack_int_1.Pop();
    EXPECT_EQ(0, _Stack_int_1.GetSize());
    EXPECT_EQ(true, _Stack_int_1.IsEmpty());
}

TEST_F(StackSizeTest, GreaterThanZeroSizeTest)
{
    _Stack_int_0.Push(10);
    EXPECT_EQ(1, _Stack_int_0.GetSize());
    EXPECT_EQ(1, _Stack_int_1.GetSize());
}

TEST_F(StackElementAccessTest, PeekTest)
{
    EXPECT_EQ(10, _Stack_int_1.Peek());
}
