/**
 *      Created on: 03 April 2018
 *   Last modified: 09 July 2018
 *          Author: Sona Praneeth Akula
 *         Details: Tests for Queue
 */

/**
 * Changelog
 *
 * Date (DD-MM-YYYY)            Author               Update
 * 03-04-2018             Sona Praneeth Akula   - Creation of file
 * 09-07-2018             Sona Praneeth Akula   - Adding tests for Queue
 */

#include "Queue.h"
#include "gtest/gtest.h"

using namespace std;

class QueueTest : public ::testing::Test
{
protected:
    virtual void SetUp()
    {
        _Queue_int_1.Enqueue(10);
    }

    virtual void TearDown()
    {

    }

    Queue<int> _Queue_int_0;
    Queue<int> _Queue_int_1;
    Queue<int> *_Queue_int_10 = new Queue<int>(10);

};

class QueueSizeTest: public QueueTest
{};

class QueueElementAccessTest: public QueueTest
{};

TEST_F(QueueSizeTest, ZeroSizeTest)
{
    EXPECT_EQ(0, _Queue_int_0.Size());
    EXPECT_EQ(true, _Queue_int_0.IsEmpty());
    _Queue_int_1.Dequeue();
    EXPECT_EQ(0, _Queue_int_1.Size());
    EXPECT_EQ(true, _Queue_int_1.IsEmpty());
}

TEST_F(QueueSizeTest, GreaterThanZeroSizeTest)
{
    _Queue_int_0.Enqueue(10);
    EXPECT_EQ(1, _Queue_int_0.Size());
    EXPECT_EQ(1, _Queue_int_1.Size());
}

TEST_F(QueueElementAccessTest, HeadTest)
{
    EXPECT_EQ(10, _Queue_int_1.HeadValue());
}
