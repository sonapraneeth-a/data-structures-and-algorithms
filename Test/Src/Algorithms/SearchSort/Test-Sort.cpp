//
// Created by pranas on 7/9/2018.
//

#include "Sort.h"
#include "gtest/gtest.h"
#include "gmock/gmock.h"

class SortTest : public ::testing::Test
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
    int UnsortedArray_05[5] = {2, 1, 4, 3, 5};
    int SortedArray_00[0] = {};
    int SortedArray_01[1] = {1};
    int SortedArray_02[2] = {1, 2};
    int SortedArray_Asc_05[5] = {1, 2, 3, 4, 5};
    int SortedArray_Desc_05[5] = {5, 4, 3, 2, 1};

};

class BubbleSortTest: public SortTest
{};

class InsertionSortTest: public SortTest
{};

TEST_F(BubbleSortTest, SmallArrayTest)
{
    BubbleSort(UnsortedArray_01);
    EXPECT_THAT(SortedArray_01,
                ::testing::ContainerEq(UnsortedArray_01));
    BubbleSort(UnsortedArray_02);
    EXPECT_THAT(SortedArray_02,
                ::testing::ContainerEq(UnsortedArray_02));
    BubbleSort(UnsortedArray_05);
    EXPECT_THAT(SortedArray_Asc_05,
                ::testing::ContainerEq(UnsortedArray_05));
    BubbleSort(SortedArray_Desc_05);
    EXPECT_THAT(SortedArray_Asc_05,
                ::testing::ContainerEq(SortedArray_Desc_05));
}

TEST_F(InsertionSortTest, SmallArrayTest)
{
    InsertionSort(UnsortedArray_01);
    EXPECT_THAT(SortedArray_01,
                ::testing::ContainerEq(UnsortedArray_01));
    InsertionSort(UnsortedArray_02);
    EXPECT_THAT(SortedArray_02,
                ::testing::ContainerEq(UnsortedArray_02));
    InsertionSort(UnsortedArray_05);
    EXPECT_THAT(SortedArray_Asc_05,
                ::testing::ContainerEq(UnsortedArray_05));
    InsertionSort(SortedArray_Desc_05);
    EXPECT_THAT(SortedArray_Asc_05,
                ::testing::ContainerEq(SortedArray_Desc_05));
}