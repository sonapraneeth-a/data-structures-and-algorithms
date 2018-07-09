/**
 *      Created on: 06 July 2018
 *   Last modified: 06 July 2018
 *          Author: Sona Praneeth Akula
 *         Details: Tests for Vector3d
 */

/**
 * Changelog
 *
 * Date (DD-MM-YYYY)            Author               Update
 * 06-07-2018             Sona Praneeth Akula   - Creation of file
 *                                              - Adding tests for Vector2d GetX, GetY
 */

#include "Vector3d.h"
#include "gtest/gtest.h"

class Vector3dTest : public ::testing::Test
{
protected:
    virtual void SetUp()
    {

    }

    virtual void TearDown()
    {

    }

    Geometry::Vector3d<int> *InitiatedVector = new Geometry::Vector3d<int>(10);
    Geometry::Vector3d<int> UninitiatedVector;

};

class Vector3dElementTest: public Vector3dTest
{};

class Vector3dConstructorTest: public Vector3dTest
{};

TEST_F(Vector3dElementTest, XTest)
{
    ASSERT_EQ(10, InitiatedVector->GetX());
    ASSERT_EQ(0, UninitiatedVector.GetX());
}

TEST_F(Vector3dElementTest, YTest)
{
    ASSERT_EQ(10, InitiatedVector->GetY());
    ASSERT_EQ(0, UninitiatedVector.GetY());
}

