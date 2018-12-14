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
 *                                              - Added comments to test codes
 */

#include "Array.h"
#include "gtest/gtest.h"


/*! @class ArrayTest
 *  @brief A Test class for Static Array.
 *
 *  @details This is a test class for Static Array
 */
class ArrayTest : public ::testing::Test
{

protected:

    /**
     * @brief Setting up array objects for the test
     */
    virtual void SetUp()
    {

    }

    /**
     * @brief Cleaning all array objects after completion of test
     */
    virtual void TearDown()
    {

    }

    // Empty Array constructor of int type
    Array<int> *_Array_int_000 = new Array<int>();
    // Array constructor of int type of size 0 pre-filled with default value for
    // int
    Array<int> *_Array_int_100 = new Array<int>(0);
    // Array constructor of int type of size 1 pre-filled with default value for
    // int
    Array<int> *_Array_int_101 = new Array<int>(1);
    // Array constructor of int type of size 10 pre-filled with value 0
    Array<int> *_Array_int_210_0 = new Array<int>(10, 0);

};

/*! @class ArraySizeTest
 *  @brief A Test class for Static Array Size() function.
 *
 *  @details This is a test class for Static Array Size() function
 */
class ArraySizeTest: public ArrayTest
{};

/*! @class ArrayEmptyTest
 *  @brief A Test class for Static Array IsEmpty() function.
 *
 *  @details This is a test class for Static Array IsEmpty() function
 */
class ArrayEmptyTest: public ArrayTest
{};

/**
 * @brief   Testing if the size of array is zero after creation of array
 *          for various array constructors
 * @details
 */
TEST_F(ArraySizeTest, ConstructorZeroSizeTest)
{
    EXPECT_EQ(0, _Array_int_000->Size());
    EXPECT_EQ(0, _Array_int_100->Size());
}

/**
 * @brief   Testing if the size of array is greater than zero after creation
 *          of array for various array constructors
 * @details
 */
TEST_F(ArraySizeTest, ConstructorGreaterThanZeroSizeTest)
{
    EXPECT_EQ(1, _Array_int_101->Size());
    EXPECT_EQ(10, _Array_int_210_0->Size());
}

/**
 * @brief   Testing if the array is empty after creation of array for various
 *          array constructors
 * @details
 */
TEST_F(ArrayEmptyTest, ConstructorEmptyTest)
{
    EXPECT_EQ(true, _Array_int_000->IsEmpty());
    EXPECT_EQ(true, _Array_int_100->IsEmpty());
}

/**
 * @brief   Testing if the array is not empty after creation of array for various
 *          array constructors
 * @details
 */
TEST_F(ArrayEmptyTest, ConstructorNotEmptyTest)
{
    EXPECT_EQ(false, _Array_int_101->IsEmpty());
    EXPECT_EQ(false, _Array_int_210_0->IsEmpty());
}

