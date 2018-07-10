/**
 *      Created on: 14 March 2018
 *   Last modified: 02 April 2018
 *          Author: Sona Praneeth Akula
 *         Details: Tests for fibonacci number algorithms
 */

/**
 * Changelog
 *
 * Date (DD-MM-YYYY)            Author               Update
 * 14-03-2018             Sona Praneeth Akula   - Creation of file
 *                                              - Adding tests: SeriesTest, SimpleIndexIterativeTest
 * 02-04-2018             Sona Praneeth Akula   - Fixed a wrong test case in GetNthFibonacci number
 *                                                as the first element of fib series is 0
 */

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
    EXPECT_EQ(0, Math::GetNthFibonacciRecursive(0));
    EXPECT_EQ(1, Math::GetNthFibonacciRecursive(1));
    EXPECT_EQ(1, Math::GetNthFibonacciRecursive(2));
    EXPECT_EQ(21, Math::GetNthFibonacciRecursive(8));
}

TEST_F(FibonacciTest, SimpleIndexTestIterative)
{
    EXPECT_EQ(0, Math::GetNthFibonacciIterative(0));
    EXPECT_EQ(1, Math::GetNthFibonacciIterative(1));
    EXPECT_EQ(1, Math::GetNthFibonacciIterative(2));
    EXPECT_EQ(21, Math::GetNthFibonacciIterative(8));
}

TEST_F(FibonacciTest, SeriesTest)
{
    EXPECT_THAT(fibonacciLength_01,
                ::testing::ContainerEq(Math::FibonacciSeries(1)));
    EXPECT_THAT(fibonacciLength_02,
                ::testing::ContainerEq(Math::FibonacciSeries(2)));
    EXPECT_THAT(fibonacciLength_05,
                ::testing::ContainerEq(Math::FibonacciSeries(5)));
}
