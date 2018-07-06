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
        _VectorNd_int_1;
    }

    virtual void TearDown()
    {

    }

    Geometry::VectorNd<2, int> _VectorNd_int_2;
    Geometry::VectorNd<2, int> _VectorNd_int_1;
    Geometry::VectorNd<2, int> *_VectorNd_int_10 = new Geometry::VectorNd<2, int>(10);

};

class VectorNdDistanceTest: public VectorNdTest
{};

class VectorNdConstructorTest: public VectorNdTest
{};

