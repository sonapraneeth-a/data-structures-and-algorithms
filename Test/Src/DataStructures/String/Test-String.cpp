/**
 *      Created on: 17 April 2018
 *   Last modified: 17 August 2018
 *          Author: Sona Praneeth Akula
 *         Details: Tests for String
 */

/**
 * Changelog
 *
 * Date (DD-MM-YYYY)            Author               Update
 * 17-04-2018             Sona Praneeth Akula   - Creation of file
 * 17-08-2018             Sona Praneeth Akula   - Added test for IsPalindrome()
 */

#include "gtest/gtest.h"
#include "MyString.h"

using namespace std;

class StringTest : public ::testing::Test
{
protected:
    virtual void SetUp()
    {
        _String_00 = new MyString("");
        _String_01 = new MyString("T");
        _String_02 = new MyString("madam");
        _String_03 = new MyString("mad");
        _String_04 = new MyString("addm");
        _String_05 = new MyString("not a palindrome");
        _String_06 = new MyString("rac e car");
    }

    virtual void TearDown()
    {

    }

    MyString *_String_00, *_String_01;
    MyString *_String_02, *_String_03, *_String_04;
    MyString *_String_05, *_String_06;

};

class StringSizeTest: public StringTest
{};

class StringIsPalindromeTest: public StringTest
{};

class StringIsIsomorphicTest: public StringTest
{};

TEST_F(StringSizeTest, ZeroSizeTest)
{
    EXPECT_EQ(0, _String_00->Size());
    EXPECT_EQ(true, _String_00->IsEmpty());
    EXPECT_EQ(1, _String_01->Size());
    EXPECT_EQ(false, _String_01->IsEmpty());
}

TEST_F(StringSizeTest, GreaterThanZeroSizeTest)
{
    _String_00->PushBack('T');
    EXPECT_EQ(1, _String_00->Size());
    EXPECT_EQ(1, _String_01->Size());
}

TEST_F(StringIsPalindromeTest, ZeroSizeTest)
{
    EXPECT_EQ(true, _String_00->IsPalindrome());
}

TEST_F(StringIsPalindromeTest, NonZeroSizeTest)
{
    EXPECT_EQ(true, _String_01->IsPalindrome());
    EXPECT_EQ(true, _String_02->IsPalindrome());
    EXPECT_EQ(true, _String_06->IsPalindrome());
}

TEST_F(StringIsPalindromeTest, NotPalindromeTest)
{
    EXPECT_EQ(false, _String_03->IsPalindrome());
    EXPECT_EQ(false, _String_04->IsPalindrome());
    EXPECT_EQ(false, _String_05->IsPalindrome());
}

// aab -> ccd is isomorphic
// aab -> dcc is not isomorphic
TEST_F(StringIsIsomorphicTest, ZeroSizeTest)
{
    EXPECT_EQ(true, _String_00);
}

TEST_F(StringIsIsomorphicTest, NonZeroSizeTestTrueIsomorphic)
{
//    EXPECT_EQ(true, new MyString("")->IsIsomorphic(new MyString("")));
}