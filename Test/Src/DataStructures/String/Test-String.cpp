/**
 *      Created on: 17 April 2018
 *   Last modified: 17 April 2018
 *          Author: Sona Praneeth Akula
 *         Details: Tests for Sttring
 */

/**
 * Changelog
 *
 * Date (DD-MM-YYYY)            Author               Update
 * 17-04-2018             Sona Praneeth Akula   - Creation of file
 */

#include "String.h"
#include "gtest/gtest.h"

using namespace std;

class StringTest : public ::testing::Test
{
protected:
    virtual void SetUp()
    {

    }

    virtual void TearDown()
    {

    }

    String _String_0;
    String _String_1;

};

class StringSizeTest: public StringTest
{};

TEST_F(StringSizeTest, ZeroSizeTest)
{
    EXPECT_EQ(0, _String_0.GetSize());
    EXPECT_EQ(true, _String_0.IsEmpty());
    EXPECT_EQ(0, _String_1.GetSize());
    EXPECT_EQ(true, _String_1.IsEmpty());
}

TEST_F(StringSizeTest, GreaterThanZeroSizeTest)
{
    EXPECT_EQ(1, _String_0.GetSize());
    EXPECT_EQ(1, _String_1.GetSize());
}
