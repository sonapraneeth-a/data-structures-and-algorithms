/**
 * File description
 *
 *      Created on: 14 December 2018
 *   Last modified: 07 May 2019
 *          Author: Sona Praneeth Akula
 *         Details: Tests for Static array
 */

/**
 * Changelog
 *
 * Date (DD-MM-YYYY)            Author               Update
 * 14-12-2018               sonapraneeth-a      - Creation of file
 *                                              - Addition of tests for Size(),
 *                                                Empty()
 *                                              - Added comments to test codes
 * 07-05-2019               sonapraneeth-a      - Added classes for Get(), Set(), Operator [],
 *                                                Insert(), Remove()
 */

#include "Array.h"
#include "gtest/gtest.h"


/*! @class ArrayTest
 *  @brief A Test class for Static Array.
 *
 *  @details This is a test class for Static Array
 */
class Array_Test : public ::testing::Test
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
    DS::Array<int> *_Array_int_000 = new DS::Array<int>();
    // Array constructor of int type of size 0 pre-filled with default value for
    // int
    DS::Array<int> *_Array_int_100 = new DS::Array<int>(0);
    // Array constructor of int type of size 1 pre-filled with default value for
    // int
    DS::Array<int> *_Array_int_101 = new DS::Array<int>(1);
    // Array constructor of int type of size 10 pre-filled with value 0
    DS::Array<int> *_Array_int_210_0 = new DS::Array<int>(10, 0);

};

/*! @class Array_SizeTest
 *  @brief A Test class for Fixed Array Size() function.
 *
 *  @details This is a test class for Fixed Array Size() function
 */
class Array_SizeTest: public Array_Test
{};

/*! @class Array_EmptyTest
 *  @brief A Test class for Fixed Array IsEmpty() function.
 *
 *  @details This is a test class for Fixed Array IsEmpty() function
 */
class Array_EmptyTest: public Array_Test
{};

/*! @class Array_GetElementTest
 *  @brief A Test class for Fixed Array Get() function.
 *
 *  @details This is a test class for Fixed Array Get() function
 */
class Array_GetElementTest : public Array_Test
{};

/*! @class Array_GetElementTest
 *  @brief A Test class for Fixed Array Get() function.
 *
 *  @details This is a test class for Fixed Array Get() function
 */
class Array_SetElementTest : public Array_Test
{};

/*! @class Array_GetElementTest
 *  @brief A Test class for Fixed Array Get() function.
 *
 *  @details This is a test class for Fixed Array Get() function
 */
class Array_InsertElementTest : public Array_Test
{};

/*! @class Array_GetElementTest
 *  @brief A Test class for Fixed Array Get() function.
 *
 *  @details This is a test class for Fixed Array Get() function
 */
class Array_RemoveElementTest : public Array_Test
{};

/*! @class Array_GetElementTest
 *  @brief A Test class for Fixed Array Get() function.
 *
 *  @details This is a test class for Fixed Array Get() function
 */
class Array_GetSetOperatorTest : public Array_Test
{};

/**
 * @brief   Testing if the size of array is zero after creation of array
 *          for various array constructors
 * @details
 */
TEST_F(Array_SizeTest, ConstructorZeroSizeTest)
{
    EXPECT_EQ(0, _Array_int_000->Size());
    EXPECT_EQ(0, _Array_int_100->Size());
}

/**
 * @brief   Testing if the size of array is greater than zero after creation
 *          of array for various array constructors
 * @details
 */
TEST_F(Array_SizeTest, ConstructorGreaterThanZeroSizeTest)
{
    EXPECT_EQ(1, _Array_int_101->Size());
    EXPECT_EQ(10, _Array_int_210_0->Size());
}

/**
 * @brief   Testing if the array is empty after creation of array for various
 *          array constructors
 * @details
 */
TEST_F(Array_EmptyTest, ConstructorEmptyTest)
{
    EXPECT_EQ(true, _Array_int_000->IsEmpty());
    EXPECT_EQ(true, _Array_int_100->IsEmpty());
}

/**
 * @brief   Testing if the array is not empty after creation of array for various
 *          array constructors
 * @details
 */
TEST_F(Array_EmptyTest, ConstructorNotEmptyTest)
{
    EXPECT_EQ(false, _Array_int_101->IsEmpty());
    EXPECT_EQ(false, _Array_int_210_0->IsEmpty());
}

