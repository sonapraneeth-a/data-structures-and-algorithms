#include "BigNumber.h"
#include "gtest/gtest.h"

class BigNumberTest : public ::testing::Test
{
protected:
    virtual void SetUp()
    {}

    virtual void TearDown()
    {}

    BigNumber test1;

};

class BigNumberValidStringTest : public BigNumberTest
{};

TEST_F(BigNumberValidStringTest, PlusSignPositiveTest)
{
    /*std::string positive_signNumber_one = "123";
    std::string positive_signNumber_two = "+123";
    std::string positive_signNumber_three = " +123";
    EXPECT_EQ(true, test1.validate_string(positive_signNumber_one));
    EXPECT_EQ(true, test1.validate_string(positive_signNumber_two));
    EXPECT_EQ(true, test1.validate_string(positive_signNumber_three));*/
}

TEST_F(BigNumberValidStringTest, PlusSignNegativeTest)
{
    /*std::string positive_signNumber_one = "++123";
    std::string positive_signNumber_two = " +1 23";
    EXPECT_NE(true, test1.validate_string(positive_signNumber_one));
    EXPECT_NE(true, test1.validate_string(positive_signNumber_two));*/
}

TEST_F(BigNumberValidStringTest, NegativeTest)
{
    /*std::string string_one = "!123";
    std::string string_two = " 1! 23";
    std::string string_three = "+91 457340";
    EXPECT_NE(true, test1.validate_string(string_one));
    EXPECT_NE(true, test1.validate_string(string_two));
    EXPECT_NE(true, test1.validate_string(string_three));*/
}