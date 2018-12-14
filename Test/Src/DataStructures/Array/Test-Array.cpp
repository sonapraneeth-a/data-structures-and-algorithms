/**
 * File description
 *
 *      Created on: 14 December 2018
 *   Last modified: 14 December 2018
 *          Author: Sona Praneeth Akula
 *         Details: Tests for Static array
 */

/**
 * Changelog
 *
 * Date (DD-MM-YYYY)            Author               Update
 * 14-12-2018             Sona Praneeth Akula   - Creation of file
 *                                              - Addition of tests for Size(),
 *                                                Empty()
 */

#include "Array.h"
#include "gtest/gtest.h"

using namespace std;

class ArrayTest : public ::testing::Test
{

protected:
    virtual void SetUp()
    {

    }

    virtual void TearDown()
    {

    }

    Array<int> *_Array_int_000 = new Array<int>();
    Array<int> *_Array_int_100 = new Array<int>(0);
    Array<int> *_Array_int_101 = new Array<int>(1);
    Array<int> *_Array_int_210_0 = new Array<int>(10, 0);

};

class ArraySizeTest: public ArrayTest
{};

class ArrayEmptyTest: public ArrayTest
{};

TEST_F(ArraySizeTest, ZeroSizeTest)
{
    EXPECT_EQ(0, _Array_int_000->Size());
    EXPECT_EQ(0, _Array_int_100->Size());
}

TEST_F(ArraySizeTest, GreaterThanZeroSizeTest)
{
    EXPECT_EQ(1, _Array_int_101->Size());
    EXPECT_EQ(10, _Array_int_210_0->Size());
}

TEST_F(ArrayEmptyTest, EmptyTest)
{
    EXPECT_EQ(true, _Array_int_000->IsEmpty());
    EXPECT_EQ(true, _Array_int_100->IsEmpty());
}

TEST_F(ArrayEmptyTest, NotEmptyTest)
{
    EXPECT_EQ(false, _Array_int_101->IsEmpty());
    EXPECT_EQ(false, _Array_int_210_0->IsEmpty());
}

