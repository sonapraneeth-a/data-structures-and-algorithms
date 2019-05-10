/**
 * File description
 *
 *      Created on: 09 May 2019
 *   Last modified: 09 May 2019
 *          Author: sonapraneeth-a
 *         Details: Tests for Dynamic array array
 */

 /**
  * Changelog
  *
  * Date (DD-MM-YYYY)            Author               Update
  * 09-05-2019               sonapraneeth-a      - Creation of file
  *                                              - Addition of tests for Size(),
  *                                                Empty()
  *                                              - Added comments to test codes
  * 07-05-2019               sonapraneeth-a      - Added classes for Get(), Set(), Operator [],
  *                                                Insert(), Remove()
  */

#include "DynamicArray.h"
#include "gtest/gtest.h"


  /*! @class ArrayTest
   *  @brief A Test class for Static Array.
   *
   *  @details This is a test class for Static Array
   */
class DynamicArray_Test : public ::testing::Test
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
    DS::DynamicArray<int>* _DynamicArray_int_000 = new DS::DynamicArray<int>();
    // Array constructor of int type of size 0 pre-filled with default value for
    // int
    DS::DynamicArray<int>* _DynamicArray_int_100 = new DS::DynamicArray<int>(0);
    // Array constructor of int type of size 1 pre-filled with default value for
    // int
    DS::DynamicArray<int>* _DynamicArray_int_101 = new DS::DynamicArray<int>(1);
    // Array constructor of int type of size 10 pre-filled with value 0
    DS::DynamicArray<int>* _DynamicArray_int_210_0 = new DS::DynamicArray<int>(10, 0);

};

/*! @class DynamicArray_SizeTest
 *  @brief A Test class for Fixed Array Size() function.
 *
 *  @details This is a test class for Fixed Array Size() function
 */
class DynamicArray_SizeTest : public DynamicArray_Test
{};

/*! @class DynamicArray_EmptyTest
 *  @brief A Test class for Fixed Array IsEmpty() function.
 *
 *  @details This is a test class for Fixed Array IsEmpty() function
 */
class DynamicArray_EmptyTest : public DynamicArray_Test
{};

/*! @class DynamicArray_GetElementTest
 *  @brief A Test class for Fixed Array Get() function.
 *
 *  @details This is a test class for Fixed Array Get() function
 */
class DynamicArray_GetElementTest : public DynamicArray_Test
{};

/*! @class DynamicArray_GetElementTest
 *  @brief A Test class for Fixed Array Get() function.
 *
 *  @details This is a test class for Fixed Array Get() function
 */
class DynamicArray_SetElementTest : public DynamicArray_Test
{};

/*! @class DynamicArray_GetElementTest
 *  @brief A Test class for Fixed Array Get() function.
 *
 *  @details This is a test class for Fixed Array Get() function
 */
class DynamicArray_InsertElementTest : public DynamicArray_Test
{};

/*! @class DynamicArray_GetElementTest
 *  @brief A Test class for Fixed Array Get() function.
 *
 *  @details This is a test class for Fixed Array Get() function
 */
class DynamicArray_RemoveElementTest : public DynamicArray_Test
{};

/*! @class DynamicArray_GetElementTest
 *  @brief A Test class for Fixed Array Get() function.
 *
 *  @details This is a test class for Fixed Array Get() function
 */
class DynamicArray_GetSetOperatorTest : public DynamicArray_Test
{};

/**
 * @brief   Testing if the size of array is zero after creation of array
 *          for various array constructors
 * @details
 */
TEST_F(DynamicArray_SizeTest, ConstructorZeroSizeTest)
{
    EXPECT_EQ(0, _DynamicArray_int_000->Size());
    EXPECT_EQ(0, _DynamicArray_int_100->Size());
}

/**
 * @brief   Testing if the size of array is greater than zero after creation
 *          of array for various array constructors
 * @details
 */
TEST_F(DynamicArray_SizeTest, ConstructorGreaterThanZeroSizeTest)
{
    EXPECT_EQ(1, _DynamicArray_int_101->Size());
    EXPECT_EQ(10, _DynamicArray_int_210_0->Size());
}

/**
 * @brief   Testing if the array is empty after creation of array for various
 *          array constructors
 * @details
 */
TEST_F(DynamicArray_EmptyTest, ConstructorEmptyTest)
{
    EXPECT_EQ(true, _DynamicArray_int_000->IsEmpty());
    EXPECT_EQ(true, _DynamicArray_int_100->IsEmpty());
}

/**
 * @brief   Testing if the array is not empty after creation of array for various
 *          array constructors
 * @details
 */
TEST_F(DynamicArray_EmptyTest, ConstructorNotEmptyTest)
{
    EXPECT_EQ(false, _DynamicArray_int_101->IsEmpty());
    EXPECT_EQ(false, _DynamicArray_int_210_0->IsEmpty());
}

