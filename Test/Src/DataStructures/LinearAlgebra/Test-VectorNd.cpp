/**
 *      Created on: 06 July 2018
 *   Last modified: 08 July 2018
 *          Author: Sona Praneeth Akula
 *         Details: Tests for VectorNd
 */

/**
 * Changelog
 *
 * Date (DD-MM-YYYY)            Author               Update
 * 06-07-2018             Sona Praneeth Akula   - Creation of file
 * 06-07-2018             Sona Praneeth Akula   - Adding tests for VectorNd - VectorNdNthCoOrdinateTest
 *                                                (OutOfRangeTest)
 * 08-07-2018             Sona Praneeth Akula   - Adding tests for VectorNd - VectorNdNthCoOrdinateTest
 *                                                (WithinRangeTest), VectorNdToStringTest(StringTest),
 */

#include "VectorNd.h"
#include "gtest/gtest.h"
#include "gmock/gmock.h"

using namespace std;

class VectorNdTest : public ::testing::Test
{
protected:
    virtual void SetUp()
    {
    }

    virtual void TearDown()
    {
    }

    LinAlg::VectorNd<1, int> _VectorNd_int_1;
    LinAlg::VectorNd<2, int> _VectorNd_int_2;
    LinAlg::VectorNd<3, int> _VectorNd_int_3;
    LinAlg::VectorNd<4, int> *_VectorNd_int_4 = new LinAlg::VectorNd<4, int>(10);
    LinAlg::VectorNd<5, int> _VectorNd_int_5;
    LinAlg::VectorNd<4, int> *_VectorNd_origin = new LinAlg::VectorNd<4, int>(0);;
    LinAlg::VectorNd<4, int> *_VectorNd_answer;


};

class VectorNdConstructorTest: public VectorNdTest
{};

class VectorNdFillTest: public VectorNdTest
{};

class VectorNdDistanceTest: public VectorNdTest
{};

class VectorNdNormalizeTest: public VectorNdTest
{};

class VectorNdElementAccessTest: public VectorNdTest
{};

class VectorNdNthCoOrdinateTest: public VectorNdTest
{};

class VectorNdOperatorTest: public VectorNdTest
{};

class VectorNdToStringTest: public VectorNdTest
{};

TEST_F(VectorNdNthCoOrdinateTest, OutOfRangeTest)
{
    // Reference: https://stackoverflow.com/questions/23270078/test-a-specific-exception-type-is-thrown-and-the-exception-has-the-right-propert
    try
    {
        int coOrd = _VectorNd_int_4->GetNthCoOrdinate(6);
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
}

TEST_F(VectorNdNthCoOrdinateTest, WithinRangeTest)
{
    EXPECT_EQ(10, _VectorNd_int_4->GetNthCoOrdinate(0));
    EXPECT_EQ(10, _VectorNd_int_4->GetNthCoOrdinate(1));
    EXPECT_EQ(10, _VectorNd_int_4->GetNthCoOrdinate(2));
    EXPECT_EQ(10, _VectorNd_int_4->GetNthCoOrdinate(3));

    EXPECT_EQ(0, _VectorNd_int_5.GetNthCoOrdinate(0));
    EXPECT_EQ(0, _VectorNd_int_5.GetNthCoOrdinate(1));
    EXPECT_EQ(0, _VectorNd_int_5.GetNthCoOrdinate(2));
    EXPECT_EQ(0, _VectorNd_int_5.GetNthCoOrdinate(3));
    EXPECT_EQ(0, _VectorNd_int_5.GetNthCoOrdinate(4));
}

TEST_F(VectorNdToStringTest, StringTest)
{
    EXPECT_EQ("(0)", _VectorNd_int_1.ToString());
    _VectorNd_int_2[1] = 2;
    EXPECT_EQ("(0, 2)", _VectorNd_int_2.ToString());
    EXPECT_EQ("(0, 0, 0)", _VectorNd_int_3.ToString());
    EXPECT_EQ("(10, 10, 10, 10)", _VectorNd_int_4->ToString());
    EXPECT_EQ("(0, 0, 0, 0, 0)", _VectorNd_int_5.ToString());
}

TEST_F(VectorNdOperatorTest, AdditionTest)
{
    _VectorNd_answer = new LinAlg::VectorNd<4, int>(10);
    EXPECT_EQ(*_VectorNd_answer, *_VectorNd_int_4 + *_VectorNd_origin);
}

TEST_F(VectorNdOperatorTest, AdditionEqualTest)
{
    LinAlg::VectorNd<4, int> *_VectorNd_addend = new LinAlg::VectorNd<4, int>(10);
    _VectorNd_answer = new LinAlg::VectorNd<4, int>(10);
    *_VectorNd_origin += *_VectorNd_addend;
    EXPECT_EQ(*_VectorNd_answer, *_VectorNd_origin);
}

TEST_F(VectorNdOperatorTest, SubtractionTest)
{
    _VectorNd_answer = new LinAlg::VectorNd<4, int>(-10);
    EXPECT_EQ(*_VectorNd_answer, *_VectorNd_origin - *_VectorNd_int_4);
}

TEST_F(VectorNdOperatorTest, SubtractionEqualTest)
{
    LinAlg::VectorNd<4, int> *_VectorNd_subtrahend = new LinAlg::VectorNd<4, int>(10);
    _VectorNd_answer = new LinAlg::VectorNd<4, int>(-10);
    *_VectorNd_origin -= *_VectorNd_subtrahend;
    EXPECT_EQ(*_VectorNd_answer, *_VectorNd_origin);
}

TEST_F(VectorNdOperatorTest, DotProductTest)
{
    _VectorNd_answer = new LinAlg::VectorNd<4, int>(-20);
    _VectorNd_origin = new LinAlg::VectorNd<4, int>(2);
    LinAlg::VectorNd<4, int> *_VectorNd_multiplicand = new LinAlg::VectorNd<4, int>(-10);
    EXPECT_EQ(*_VectorNd_answer, *_VectorNd_origin * *_VectorNd_multiplicand);
}

TEST_F(VectorNdOperatorTest, DotProductEqualTest)
{
    LinAlg::VectorNd<4, int> *_VectorNd_multiplicand = new LinAlg::VectorNd<4, int>(10);
    LinAlg::VectorNd<4, int> *_VectorNd_multiplier = new LinAlg::VectorNd<4, int>(-10);
    _VectorNd_answer = new LinAlg::VectorNd<4, int>(-100);
    *_VectorNd_multiplier *= *_VectorNd_multiplicand;
    EXPECT_EQ(*_VectorNd_answer, *_VectorNd_multiplier);
}

