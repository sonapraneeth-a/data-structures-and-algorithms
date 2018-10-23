/**
 *      Created on: 16 August 2018
 *   Last modified: 16 August 2018
 *          Author: Sona Praneeth Akula
 *         Details: Tests for Static array
 */

/**
 * Changelog
 *
 * Date (DD-MM-YYYY)            Author               Update
 * 16-08-2018             Sona Praneeth Akula   - Creation of file
 */

#include "Array.h"
#include "gtest/gtest.h"

using namespace std;

class ArrayTest : public ::testing::Test
{
protected:
    virtual void SetUp()
    {
        (*_Array_int_01)[0] = 10;
    }

    virtual void TearDown()
    {

    }

    Array<int> *_Array_int_00 = new Array<int>(0);
    Array<int> *_Array_int_01 = new Array<int>(1);
    Array<int> *_Array_int_10 = new Array<int>(10, 0);

};

class ArraySizeTest: public ArrayTest
{};

class ArrayElementAccessTest: public ArrayTest
{};

TEST_F(ArraySizeTest, ZeroSizeTest)
{
    EXPECT_EQ(0, _Array_int_00->Size());
    EXPECT_EQ(true, _Array_int_00->IsEmpty());
//    _Array_int_01->Remove(0);
//    EXPECT_EQ(0, _Array_int_01->Size());
//    EXPECT_EQ(true, _Array_int_01->IsEmpty());
}

TEST_F(ArraySizeTest, GreaterThanZeroSizeTest)
{
//    EXPECT_EQ(1, _Array_int_01->Size());
//    EXPECT_EQ(10, _Array_int_10->Size());
}

TEST_F(ArrayElementAccessTest, GetFrontTest)
{
//    EXPECT_EQ(10, _Array_int_01[0]);
//    EXPECT_EQ(0, _Array_int_10[0]);
}
