/**
 * File description
 *
 *      Created on: 06 May 2019
 *   Last modified: 06 May 2019
 *          Author: Sona Praneeth Akula
 *         Details: Tests for Static node
 */

/**
 * Changelog
 *
 * Date (DD-MM-YYYY)            Author               Update
 * 06-05-2019             Sona Praneeth Akula   - Creation of file
 *                                              - Addition of tests for Data()
 */

#include "Node.h"
#include "gtest/gtest.h"


/*! @class NodeTest
 *  @brief A Test class for Static Node.
 *
 *  @details This is a test class for Static Node
 */
class Node_Test : public ::testing::Test
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

    // Empty Node constructor of int type
    DS::Node<int> *_Node_int_000 = new DS::Node<int>();
    // Empty Node constructor of int type
    DS::Node<int>* _Node_int_001 = new DS::Node<int>();
    // Node constructor of int type filled with value 10 for int
    DS::Node<int> *_Node_int_100 = new DS::Node<int>(10);
    // Node constructor of int type filled with value 10 for int
    DS::Node<int>* _Node_int_101 = new DS::Node<int>(20);

};

/*! @class ArraySizeTest
 *  @brief A Test class for Static Array Size() function.
 *
 *  @details This is a test class for Static Array Size() function
 */
class Node_DataTest : public Node_Test
{};

/*! @class ArrayEmptyTest
 *  @brief A Test class for Static Array IsEmpty() function.
 *
 *  @details This is a test class for Static Array IsEmpty() function
 */
class Node_NextTest : public Node_Test
{};

/*! @class ArrayEmptyTest
 *  @brief A Test class for Static Array IsEmpty() function.
 *
 *  @details This is a test class for Static Array IsEmpty() function
 */
class Node_ToStringTest : public Node_Test
{};

/**
 * @brief   Testing if the node with default constructor of int type
 * @details
 */
TEST_F(Node_DataTest, DefaultConstructorIntTest)
{
    EXPECT_EQ(0, _Node_int_000->Data());
    ASSERT_STREQ("0 -> nullptr", (_Node_int_000->ToString()).c_str());
}

TEST_F(Node_DataTest, ConstructorIntTest)
{
    EXPECT_EQ(10, _Node_int_100->Data());
}

TEST_F(Node_NextTest, DefaultConstructorIntTest)
{
    EXPECT_EQ(nullptr, _Node_int_000->Next());
}

TEST_F(Node_NextTest, ConstructorIntNullNextTest)
{
    EXPECT_EQ(nullptr, _Node_int_100->Next());
}

TEST_F(Node_NextTest, ConstructorIntNotNullNextTest)
{
    _Node_int_100->Next(_Node_int_101);
    EXPECT_EQ(_Node_int_101, _Node_int_100->Next());
}

TEST_F(Node_ToStringTest, DefaultConstructorIntTest)
{
    ASSERT_STREQ("0 -> nullptr", (_Node_int_000->ToString()).c_str());
}

TEST_F(Node_ToStringTest, ConstructorIntNullNextTest)
{
    ASSERT_STREQ("10 -> nullptr", (_Node_int_100->ToString()).c_str());
}

TEST_F(Node_ToStringTest, ConstructorIntNotNullNextTest)
{
    _Node_int_100->Next(_Node_int_101);
    std::string output = "10 -> " + _Node_int_101->Address();
    ASSERT_STREQ(output.c_str(), (_Node_int_100->ToString()).c_str());
}
