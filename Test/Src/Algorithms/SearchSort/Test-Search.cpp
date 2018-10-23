/**
 *      Created on: 09 July 2018
 *   Last modified: 09 July 2018
 *          Author: Sona Praneeth Akula
 *         Details: Tests for searching algorithms
 */

/**
 * Changelog
 *
 * Date (DD-MM-YYYY)            Author               Update
 * 09-07-2018             Sona Praneeth Akula   - Creation of file
 *                                              - Adding tests for small arrays - Linear Search,
 *                                                BinarySearchRecursive, BinarySearchIterative
 */

#include "Search.h"
#include "gtest/gtest.h"
#include "gmock/gmock.h"

class SearchTest : public ::testing::Test
{
protected:
    virtual void SetUp()
    {

    }

    virtual void TearDown()
    {

    }

    int UnsortedArray_00[0] = {};
    int UnsortedArray_01[1] = {1};
    int UnsortedArray_02[2] = {2, 1};
    int SortedArray_00[0] = {};
    int SortedArray_01[1] = {1};
    int SortedArray_02[2] = {1, 2};
    int SortedArray_03[3] = {1, 2, 3};

};

class LinearSearchTest: public SearchTest
{};

class BinarySearchRecursiveTest: public SearchTest
{};

class BinarySearchIterativeTest: public SearchTest
{};

TEST_F(LinearSearchTest, SmallArray_OutOfBounds_Test)
{
    try
    {
        LLI index = LinearSearch(UnsortedArray_01, 3, 0, 3);
        FAIL() << "Expected OutOfBoundsException()\n";
    }
    catch(OutOfBoundsException const & err)
    {
        EXPECT_EQ(err.what(), std::string("OutOfBoundsException::Index out of bounds for the data structure."));
    }
    catch(...)
    {
        FAIL() << "Expected OutOfBoundsException()\n";
    }
}

TEST_F(LinearSearchTest, SmallArray_Found_Test)
{
    EXPECT_EQ(0, LinearSearch(UnsortedArray_01, 1));
    EXPECT_EQ(0, LinearSearch(UnsortedArray_02, 2));
}

TEST_F(LinearSearchTest, SmallArray_NotFound_Test)
{
    EXPECT_EQ(-1, LinearSearch(UnsortedArray_01, 3));
}

TEST_F(BinarySearchRecursiveTest, SmallArray_Found_Test)
{
    // EXPECT_EQ(-1, BinarySearchRecursive(SortedArray_00, 0, 0, 0));
    EXPECT_EQ(0, BinarySearchRecursive(SortedArray_01, 1, 0, 1));
    EXPECT_EQ(1, BinarySearchRecursive(SortedArray_02, 2, 0, 2));
}

TEST_F(BinarySearchRecursiveTest, SmallArray_NotFound_Test)
{
    // EXPECT_EQ(-1, BinarySearchRecursive(SortedArray_00, 0, 0, 0));
    EXPECT_EQ(0, BinarySearchRecursive(SortedArray_01, 1, 0, 1));
    EXPECT_EQ(1, BinarySearchRecursive(SortedArray_02, 2, 0, 2));
}

TEST_F(BinarySearchIterativeTest, SmallArrayTest)
{
    // EXPECT_EQ(-1, BinarySearchIterative(SortedArray_00, 0, 0, 0));
    EXPECT_EQ(0, BinarySearchIterative(SortedArray_01, 1, 0, 1));
    EXPECT_EQ(1, BinarySearchIterative(SortedArray_02, 2, 0, 2));
}