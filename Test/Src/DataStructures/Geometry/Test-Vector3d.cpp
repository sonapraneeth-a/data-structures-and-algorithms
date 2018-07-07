//
// Created by pranas on 7/7/2018.
//

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

