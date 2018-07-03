#include "Fibonacci.h"
#include "gtest/gtest.h"
#include "gmock/gmock.h"

class FibonacciTest : public ::testing::Test
{
protected:
    virtual void SetUp()
    {
        fibonacciLength_01.push_back(0);

        fibonacciLength_02.push_back(0);
        fibonacciLength_02.push_back(1);

        fibonacciLength_05.push_back(0);
        fibonacciLength_05.push_back(1);
        fibonacciLength_05.push_back(1);
        fibonacciLength_05.push_back(2);
        fibonacciLength_05.push_back(3);
    }

    virtual void TearDown()
    {
        fibonacciLength_01.clear();
        fibonacciLength_02.clear();
        fibonacciLength_05.clear();
    }

    std::vector<ULLI> fibonacciLength_01;
    std::vector<ULLI> fibonacciLength_02;
    std::vector<ULLI> fibonacciLength_05;

};

TEST_F(FibonacciTest, SimpleIndexTestRecursive)
{
    EXPECT_EQ(0, GetNthFibonacciRecursive(0));
    EXPECT_EQ(1, GetNthFibonacciRecursive(1));
    EXPECT_EQ(1, GetNthFibonacciRecursive(2));
    EXPECT_EQ(21, GetNthFibonacciRecursive(8));
}

TEST_F(FibonacciTest, SimpleIndexTestIterative)
{
    EXPECT_EQ(0, GetNthFibonacciIterative(0));
    EXPECT_EQ(1, GetNthFibonacciIterative(1));
    EXPECT_EQ(1, GetNthFibonacciIterative(2));
    EXPECT_EQ(21, GetNthFibonacciIterative(8));
}

TEST_F(FibonacciTest, SeriesTest)
{
    EXPECT_THAT(fibonacciLength_01,
                ::testing::ContainerEq(FibonacciSeries(1)));
    EXPECT_THAT(fibonacciLength_02,
                ::testing::ContainerEq(FibonacciSeries(2)));
    EXPECT_THAT(fibonacciLength_05,
                ::testing::ContainerEq(FibonacciSeries(5)));
}
