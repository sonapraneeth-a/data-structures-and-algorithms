#include "BigInteger.h"
#include "gtest/gtest.h"

class BigIntegerTest : public ::testing::Test
{
protected:
    virtual void SetUp()
    {}

    virtual void TearDown()
    {}

    BigInteger test1;

};

class BigIntegerValidStringTest : public BigIntegerTest
{};

TEST_F(BigIntegerValidStringTest, PlusSignPositiveTest)
{
    /*std::string positive_signInteger_one = "123";
    std::string positive_signInteger_two = "+123";
    std::string positive_signInteger_three = " +123";
    EXPECT_EQ(true, test1.validate_string(positive_signInteger_one));
    EXPECT_EQ(true, test1.validate_string(positive_signInteger_two));
    EXPECT_EQ(true, test1.validate_string(positive_signInteger_three));*/
}

TEST_F(BigIntegerValidStringTest, PlusSignNegativeTest)
{
    /*std::string positive_signInteger_one = "++123";
    std::string positive_signInteger_two = " +1 23";
    EXPECT_NE(true, test1.validate_string(positive_signInteger_one));
    EXPECT_NE(true, test1.validate_string(positive_signInteger_two));*/
}

TEST_F(BigIntegerValidStringTest, NegativeTest)
{
    /*std::string string_one = "!123";
    std::string string_two = " 1! 23";
    std::string string_three = "+91 457340";
    EXPECT_NE(true, test1.validate_string(string_one));
    EXPECT_NE(true, test1.validate_string(string_two));
    EXPECT_NE(true, test1.validate_string(string_three));*/
}