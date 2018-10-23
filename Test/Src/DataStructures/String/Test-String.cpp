/**
 *      Created on: 17 April 2018
 *   Last modified: 29 August 2018
 *          Author: Sona Praneeth Akula
 *         Details: Tests for MyString
 */

/**
 * Author Details
 *
 * sonapraneeth-a --- Sona Praneeth Akula <sonapraneeth.akula@gmail.com>
 */

/**
 * Changelog
 *
 * Date (DD-MM-YYYY)            Author               Update
 * 17-04-2018               sonapraneeth-a      - Creation of file
 * 17-08-2018               sonapraneeth-a      - Added test for IsPalindrome()
 * 24-08-2018               sonapraneeth-a      - Added test for IsIsomorphic()
 *                                              - Added updated tests for StringSizeTest
 *                                              - Fixed an issue with IsIsomorphic() test
 * 28-08-2018               sonapraneeth-a      - Added Constructors for String tests
 *                                              - Change StringTest to MyStringTest to suite
 *                                                the class name
 * 29-08-2018               sonapraneeth-a      - Added some new tests for Size()
 *                                              - Renamed some variables in Setup()
 *                                              - Added some new tests for Clear()
 */

#include "gtest/gtest.h"
#include "MyString.h"

using namespace std;

class MyStringTest : public ::testing::Test
{
protected:
    virtual void SetUp()
    {
        _String_Size_00 = new MyString("");
        _String_Size_01 = new MyString("T");
        _String_Size_02 = new MyString("Ta");
        _String_Size_03 = new MyString("Tar");
        _String_Size_04 = new MyString("Tara");
        _String_Size_05 = new MyString("Tarak");
        _String_Palindrome_01 = new MyString("madam");
        _String_Palindrome_02 = new MyString("addm");
        _String_Palindrome_03 = new MyString("rac e car");
        _String_03 = new MyString("mad");
        _String_05 = new MyString("not a palindrome");
        _String_07 = new MyString("aab");
        _String_08 = new MyString("ccd");
        _String_09 = new MyString("dcc");
        _String_10 = new MyString("abc");
        _String_11 = new MyString("dde");
    }

    virtual void TearDown()
    {

    }

    // Size strings
    MyString *_String_Size_00, *_String_Size_01, *_String_Size_02;
    MyString *_String_Size_03, *_String_Size_04, *_String_Size_05;
    // Palindrome strings
    MyString *_String_Palindrome_01, *_String_03, *_String_Palindrome_02;
    MyString *_String_05, *_String_Palindrome_03;
    // For Isomorphic strings
    MyString *_String_07, *_String_08, *_String_09;
    MyString *_String_10, *_String_11;
    // General strings

};

// Test for MyString::Size()
class MyStringTest_Size: public MyStringTest
{};

// Test for MyString::Clear()
class MyStringTest_Clear: public MyStringTest
{};

class MyStringTest_IsEmpty: public MyStringTest
{};

class MyStringTest_Append: public MyStringTest
{};

class MyStringTest_Front: public MyStringTest
{};

class MyStringTest_PushFront: public MyStringTest_Front
{};

class MyStringTest_PopFront: public MyStringTest_Front
{};

class MyStringTest_FrontAccess: public MyStringTest_Front
{};

class MyStringTest_Back: public MyStringTest
{};

class MyStringTest_PushBack: public MyStringTest_Back
{};

class MyStringTest_PopBack: public MyStringTest_Back
{};

class MyStringTest_BackAccess: public MyStringTest_Back
{};

class MyStringTest_Insert: public MyStringTest
{};

class MyStringTest_Delete: public MyStringTest
{};

class MyStringTest_Get: public MyStringTest
{};

class MyStringTest_Substring: public MyStringTest
{};

class MyStringTest_Operators: public MyStringTest
{};

class MyStringTest_IndexOperator: public MyStringTest_Operators
{};

class MyStringTest_PlusOperator: public MyStringTest_Operators
{};

class MyStringTest_PlusEqualsOperator: public MyStringTest_Operators
{};

class MyStringTest_EqualsOperator: public MyStringTest_Operators
{};

class MyStringTest_AssignmentOperator: public MyStringTest_Operators
{};

class MyStringTest_IsPalindrome: public MyStringTest
{};

class MyStringTest_IsIsomorphic: public MyStringTest
{};

class MyStringTest_Compare: public MyStringTest
{};

TEST_F(MyStringTest_Size, ZeroSizeTest)
{
    EXPECT_EQ(0, _String_Size_00->Size());
}

TEST_F(MyStringTest_Size, ZeroSizeTest_PopBack)
{
    _String_Size_01->PopBack();
    EXPECT_EQ(0, _String_Size_01->Size());
}

TEST_F(MyStringTest_Size, ZeroSizeTest_Delete)
{
    _String_Size_01->Delete(0);
    EXPECT_EQ(0, _String_Size_01->Size());
}

TEST_F(MyStringTest_Size, ZeroSizeTest_Clear)
{
    _String_Size_00->Clear();
    EXPECT_EQ(0, _String_Size_00->Size());
    _String_Size_01->Clear();
    EXPECT_EQ(0, _String_Size_01->Size());
    _String_Size_02->Clear();
    EXPECT_EQ(0, _String_Size_02->Size());
}

TEST_F(MyStringTest_Size, GreaterThanZeroSizeTest)
{
    EXPECT_EQ(1, _String_Size_01->Size());
    EXPECT_EQ(2, _String_Size_02->Size());
    EXPECT_EQ(3, _String_Size_03->Size());
    EXPECT_EQ(4, _String_Size_04->Size());
    EXPECT_EQ(5, _String_Size_05->Size());
}

TEST_F(MyStringTest_Size, GreaterThanZeroSizeTest_Insert)
{
    _String_Size_00->Insert('T', 0);
    EXPECT_EQ(1, _String_Size_00->Size());
    _String_Size_01->Insert('T', 1);
    EXPECT_EQ(2, _String_Size_01->Size());
    _String_Size_02->Insert('T', 1);
    EXPECT_EQ(3, _String_Size_02->Size());
}

TEST_F(MyStringTest_Size, GreaterThanZeroSizeTest_Delete)
{
    _String_Size_02->Delete(0);
    EXPECT_EQ(1, _String_Size_02->Size());
    _String_Size_03->Delete(2);
    EXPECT_EQ(2, _String_Size_03->Size());
    _String_Size_04->Delete(1);
    EXPECT_EQ(3, _String_Size_04->Size());
}

TEST_F(MyStringTest_Size, GreaterThanZeroSizeTest_PushBack)
{
    _String_Size_00->PushBack('T');
    EXPECT_EQ(1, _String_Size_00->Size());
    _String_Size_01->PushBack('T');
    EXPECT_EQ(2, _String_Size_01->Size());
}

TEST_F(MyStringTest_Size, GreaterThanZeroSizeTest_PopBack)
{
    _String_Size_02->PopBack();
    EXPECT_EQ(1, _String_Size_02->Size());
}

TEST_F(MyStringTest_Clear, ClearTest)
{
    _String_Size_00->Clear();
    EXPECT_EQ("", _String_Size_00);
    _String_Size_01->Clear();
    EXPECT_EQ("", _String_Size_01);
    _String_Size_02->Clear();
    EXPECT_EQ("", _String_Size_02);
}

TEST_F(MyStringTest_IsEmpty, EmptyTest)
{
    EXPECT_EQ(true, _String_Size_00);
}

TEST_F(MyStringTest_IsEmpty, NonEmptyTest)
{
    EXPECT_EQ(false, _String_Size_01);
    EXPECT_EQ(false, _String_Size_02);
    EXPECT_EQ(false, _String_Size_03);
    EXPECT_EQ(false, _String_Size_04);
    EXPECT_EQ(false, _String_Size_05);
}

TEST_F(MyStringTest_Get, GeneralTest)
{
    EXPECT_EQ('T', _String_Size_01->Get(0));
}

TEST_F(MyStringTest_IsPalindrome, ZeroSizeTest)
{
    EXPECT_EQ(true, _String_Size_00->IsPalindrome());
}

TEST_F(MyStringTest_IsPalindrome, NonZeroSizeTest_TruePalindrome)
{
    EXPECT_EQ(true, _String_Size_01->IsPalindrome());
    EXPECT_EQ(true, _String_Palindrome_01->IsPalindrome());
    EXPECT_EQ(true, _String_Palindrome_03->IsPalindrome());
}

TEST_F(MyStringTest_IsPalindrome, NonZeroSizeTest_FalsePalindrome)
{
    EXPECT_EQ(false, _String_03->IsPalindrome());
    EXPECT_EQ(false, _String_Palindrome_02->IsPalindrome());
    EXPECT_EQ(false, _String_05->IsPalindrome());
}

TEST_F(MyStringTest_IsIsomorphic, ZeroSizeTest)
{
    EXPECT_EQ(true, _String_Size_00->IsIsomorphic(*_String_Size_00));
}

TEST_F(MyStringTest_IsIsomorphic, NonZeroSizeTest_TrueIsomorphic)
{
    EXPECT_EQ(true, _String_07->IsIsomorphic(*_String_08));
}

TEST_F(MyStringTest_IsIsomorphic, NonZeroSizeTest_FalseIsomorphic)
{
    EXPECT_EQ(false, _String_07->IsIsomorphic(*_String_09));
    EXPECT_EQ(false, _String_10->IsIsomorphic(*_String_11));
}