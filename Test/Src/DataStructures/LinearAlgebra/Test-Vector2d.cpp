/**
 *      Created on: 06 July 2018
 *   Last modified: 15 July 2018
 *          Author: Sona Praneeth Akula
 *         Details: Tests for Vector2d
 */

/**
 * Changelog
 *
 * Date (DD-MM-YYYY)            Author               Update
 * 06-07-2018             Sona Praneeth Akula   - Creation of file
 *                                              - Adding tests for Vector2d GetX, GetY
 * 15-07-2018             Sona Praneeth Akula    - Moved from namespace Geometry to LinAlg
 */

#include "Vector2d.h"
#include "gtest/gtest.h"

class Vector2dTest : public ::testing::Test
{
protected:
    virtual void SetUp()
    {

    }

    virtual void TearDown()
    {

    }

    LinAlg::Vector2d<int> *InitiatedVector = new LinAlg::Vector2d<int>(10);
    LinAlg::Vector2d<int> UninitiatedVector;

};

class Vector2dElementTest: public Vector2dTest
{};

class Vector2dConstructorTest: public Vector2dTest
{};

TEST_F(Vector2dElementTest, XTest)
{
    ASSERT_EQ(10, InitiatedVector->GetX());
    ASSERT_EQ(0, UninitiatedVector.GetX());
}

TEST_F(Vector2dElementTest, YTest)
{
    ASSERT_EQ(10, InitiatedVector->GetY());
    ASSERT_EQ(0, UninitiatedVector.GetY());
}

