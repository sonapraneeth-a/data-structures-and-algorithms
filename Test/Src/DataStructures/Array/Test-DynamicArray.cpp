/**
 *      Created on: 01 April 2018
 *   Last modified: 02 April 2018
 *          Author: Sona Praneeth Akula
 *         Details: Tests for Dynamic array
 */

/**
 * Changelog
 *
 * Date (DD-MM-YYYY)            Author               Update
 * 01-04-2018             Sona Praneeth Akula   - Creation of file
 *                                              - Added tests for dynamic arrays
 * 02-04-2018             Sona Praneeth Akula   - Added tests for element access functions
 */

#include "DynamicArray.h"
#include "gtest/gtest.h"

using namespace std;

class DynamicArrayTest : public ::testing::Test
{
protected:
    virtual void SetUp()
    {
        _Array_int_1.PushBack(10);
    }

    virtual void TearDown()
    {

    }

    DynamicArray<int> _Array_int_0;
    DynamicArray<int> _Array_int_1;
    DynamicArray<int> *_Array_int_10 = new DynamicArray<int>(10, 0);

};

class DynamicArraySizeTest: public DynamicArrayTest
{};

class DynamicArrayElementAccessTest: public DynamicArrayTest
{};

TEST_F(DynamicArraySizeTest, ZeroSizeTest)
{
    EXPECT_EQ(0, _Array_int_0.GetSize());
    EXPECT_EQ(true, _Array_int_0.IsEmpty());
    _Array_int_1.Remove(0);
    EXPECT_EQ(0, _Array_int_1.GetSize());
    EXPECT_EQ(true, _Array_int_1.IsEmpty());
}

TEST_F(DynamicArraySizeTest, GreaterThanZeroSizeTest)
{
    _Array_int_0.PushBack(10);
    EXPECT_EQ(1, _Array_int_0.GetSize());
    EXPECT_EQ(1, _Array_int_1.GetSize());
    EXPECT_EQ(10, _Array_int_10->GetSize());
    _Array_int_10->PushBack(10);
    EXPECT_EQ(11, _Array_int_10->GetSize());
}

TEST_F(DynamicArrayElementAccessTest, GetFrontTest)
{
    EXPECT_EQ(10, _Array_int_1.GetFront());
    EXPECT_EQ(0, _Array_int_10->GetFront());
}

TEST_F(DynamicArrayElementAccessTest, GetBackTest)
{
    EXPECT_EQ(10, _Array_int_1.GetBack());
    EXPECT_EQ(0, _Array_int_10->GetBack());
}

TEST_F(DynamicArrayElementAccessTest, OperatorTest)
{
    EXPECT_EQ(10, _Array_int_1[0]);
    EXPECT_EQ(0, (*_Array_int_10)[2]);
}