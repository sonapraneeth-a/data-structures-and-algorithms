//
// Created by pranas on 7/9/2018.
//

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

    int UnsortedArray_0[0] = {};
    int UnsortedArray_1[1] = {1};
    int UnsortedArray_2[2] = {2, 1};
    int SortedArray_0[0] = {};
    int SortedArray_1[1] = {1};
    int SortedArray_2[2] = {1, 2};

};

class LinearSearchTest: public SearchTest
{};

class BinarySearchRecursiveTest: public SearchTest
{};

class BinarySearchIterativeTest: public SearchTest
{};

TEST_F(LinearSearchTest, SmallArrayTest)
{
    try
    {
        LLI index = LinearSearch(UnsortedArray_1, 3, 0, 3);
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
    EXPECT_EQ(0, LinearSearch(UnsortedArray_1, 1));
    EXPECT_EQ(-1, LinearSearch(UnsortedArray_1, 3));
    EXPECT_EQ(0, LinearSearch(UnsortedArray_2, 2));
}

TEST_F(BinarySearchRecursiveTest, SmallArrayTest)
{
    // EXPECT_EQ(-1, BinarySearchRecursive(SortedArray_0, 0, 0, 0));
    EXPECT_EQ(0, BinarySearchRecursive(SortedArray_1, 1, 0, 1));
    EXPECT_EQ(1, BinarySearchRecursive(SortedArray_2, 2, 0, 2));
}

TEST_F(BinarySearchIterativeTest, SmallArrayTest)
{
    // EXPECT_EQ(-1, BinarySearchIterative(SortedArray_0, 0, 0, 0));
    EXPECT_EQ(0, BinarySearchIterative(SortedArray_1, 1, 0, 1));
    EXPECT_EQ(1, BinarySearchIterative(SortedArray_2, 2, 0, 2));
}