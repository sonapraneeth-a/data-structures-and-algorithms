#include "Fibonacci.h"
#include "gtest/gtest.h"

class FibonacciTest : public ::testing::Test
{
protected:
    virtual void SetUp()
    {}

    virtual void TearDown()
    {}

};

TEST_F(FibonacciTest, SimpleIndexTestRecursive)
{
    EXPECT_EQ(0, GetNthFibonacciRecursive(0));
    EXPECT_EQ(1, GetNthFibonacciRecursive(1));
    EXPECT_EQ(1, GetNthFibonacciRecursive(2));
}

TEST_F(FibonacciTest, SimpleIndexTestIterative)
{
    EXPECT_EQ(0, GetNthFibonacciIterative(0));
    EXPECT_EQ(1, GetNthFibonacciIterative(1));
    EXPECT_EQ(1, GetNthFibonacciIterative(2));
}

