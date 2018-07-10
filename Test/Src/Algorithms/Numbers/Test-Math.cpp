/**
 *      Created on: 10 July 2018
 *   Last modified: 10 July 2018
 *          Author: Sona Praneeth Akula
 *         Details: Tests for math algorithms
 */

/**
 * Changelog
 *
 * Date (DD-MM-YYYY)            Author               Update
 * 10-07-2018             Sona Praneeth Akula   - Creation of file
 */

#include "Math.h"
#include "gtest/gtest.h"
#include "gmock/gmock.h"

/**
 *
 */
class ExponentNumber
{
public:
    ULLI answer;
    LLI number;
    LLI exponent;
    /**
     *
     * @param answer
     * @param number
     * @param exponent
     */
    ExponentNumber(ULLI answer, LLI number, LLI exponent)
    {
        this->answer = answer;
        this->number = number;
        this->exponent = exponent;
    }
};

class MathTest : public ::testing::Test
{
protected:
    virtual void SetUp()
    {
        Exponent_Zero_Exponent.push_back({1, 2, 0});
    }

    virtual void TearDown()
    {
        Exponent_Zero_Exponent.clear();
        Exponent_Positive_SmallNumber.clear();
        Exponent_Positive_LargeNumber.clear();
        Exponent_Negative_SmallNumber.clear();
        Exponent_Negative_LargeNumber.clear();
    }

    std::vector<ExponentNumber> Exponent_Zero_Exponent;
    std::vector<ExponentNumber> Exponent_Positive_SmallNumber;
    std::vector<ExponentNumber> Exponent_Positive_LargeNumber;
    std::vector<ExponentNumber> Exponent_Negative_SmallNumber;
    std::vector<ExponentNumber> Exponent_Negative_LargeNumber;

};

class ExponentationTestRecursiveTest: public MathTest
{};

class ExponentationTestIterativeTest: public MathTest
{};

TEST_F(ExponentationTestRecursiveTest, SmallNumberTest)
{
    EXPECT_EQ(8, Math::ExponentiationRecursive(2, 3));
    EXPECT_EQ(1, Math::ExponentiationRecursive(2, 0));
    EXPECT_EQ(1024, Math::ExponentiationRecursive(2, 10));
}

TEST_F(ExponentationTestIterativeTest, SmallNumberTest)
{
    EXPECT_EQ(8, Math::ExponentiationIterative(2, 3));
    EXPECT_EQ(1, Math::ExponentiationIterative(2, 0));
    EXPECT_EQ(1024, Math::ExponentiationIterative(2, 10));
}
