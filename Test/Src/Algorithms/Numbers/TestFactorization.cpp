#include "Factorization.h"
#include "gtest/gtest.h"

class FactorizationTest : public ::testing::Test
{
protected:
    virtual void SetUp()
    {}

    virtual void TearDown()
    {}

};

TEST_F(FactorizationTest, NaiveGCD_ZeroNumberTest)
{
    EXPECT_EQ(10, NaiveGCD(0, 10));
    EXPECT_EQ(10, NaiveGCD(10, 0));
    EXPECT_EQ(0, NaiveGCD(0, 0));
}

TEST_F(FactorizationTest, NaiveGCD_PositiveCompositeNumberTest)
{
    EXPECT_EQ(2, NaiveGCD(2, 10));
    EXPECT_EQ(10, NaiveGCD(10, 10));
    EXPECT_EQ(2, NaiveGCD(10, 2));
}

TEST_F(FactorizationTest, NaiveGCD_PositivePrimeNumberTest)
{
    EXPECT_EQ(1, NaiveGCD(3, 7));
    EXPECT_EQ(1, NaiveGCD(5, 12));
    EXPECT_EQ(1, NaiveGCD(1, 1));
}

TEST_F(FactorizationTest, EuclideanGCD_ZeroNumberTest)
{
    EXPECT_EQ(10, EuclideanGCD(0, 10));
    EXPECT_EQ(10, EuclideanGCD(10, 0));
    EXPECT_EQ(0, EuclideanGCD(0, 0));
}

TEST_F(FactorizationTest, EuclideanGCD_PositiveCompositeNumberTest)
{
    EXPECT_EQ(2, EuclideanGCD(2, 10));
    EXPECT_EQ(10, EuclideanGCD(10, 10));
    EXPECT_EQ(2, EuclideanGCD(10, 2));
}

TEST_F(FactorizationTest, EuclideanGCD_PositivePrimeNumberTest)
{
    EXPECT_EQ(1, EuclideanGCD(3, 7));
    EXPECT_EQ(1, EuclideanGCD(5, 12));
    EXPECT_EQ(1, EuclideanGCD(1, 1));
}

