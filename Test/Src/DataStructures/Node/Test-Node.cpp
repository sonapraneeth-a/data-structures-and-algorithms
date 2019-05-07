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
class NodeTest : public ::testing::Test
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
    // Node constructor of int type filled with value 10 for int
    DS::Node<int> *_Node_int_001 = new DS::Node<int>(10);

};

/**
 * @brief   Testing if the node with default constructor of int type
 * @details
 */
TEST_F(NodeTest, DefaultConstructorIntTest)
{
    EXPECT_EQ(0, _Node_int_000->Data());
    EXPECT_EQ(nullptr, _Node_int_000->Next());
    ASSERT_STREQ("0 -> nullptr", (_Node_int_000->ToString()).c_str());
}

/**
 * @brief   Testing if the node with constructor of int type
 * @details
 */
TEST_F(NodeTest, ConstructorIntTest)
{
    EXPECT_EQ(10, _Node_int_001->Data());
    EXPECT_EQ(nullptr, _Node_int_001->Next());
    ASSERT_STREQ("10 -> nullptr", (_Node_int_001->ToString()).c_str());
}
