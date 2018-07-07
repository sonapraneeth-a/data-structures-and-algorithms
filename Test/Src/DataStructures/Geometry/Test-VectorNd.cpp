/**
 *      Created on: 06 July 2018
 *   Last modified: 06 July 2018
 *          Author: Sona Praneeth Akula
 *         Details: Tests for VectorNd
 */

/**
 * Changelog
 *
 * Date (DD-MM-YYYY)            Author               Update
 * 06-07-2018             Sona Praneeth Akula   - Creation of file
 * 06-07-2018             Sona Praneeth Akula   - Adding tests for VectorNd
 */

#include "VectorNd.h"
#include "gtest/gtest.h"

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

    Geometry::VectorNd<4, int> *_VectorNd_int_4 = new Geometry::VectorNd<4, int>(10);

};

class VectorNdNthCoOrdinateTest: public VectorNdTest
{};

class VectorNdConstructorTest: public VectorNdTest
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