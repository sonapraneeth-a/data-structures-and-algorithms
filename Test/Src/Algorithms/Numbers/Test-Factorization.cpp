#include "Factorization.h"
#include "gtest/gtest.h"
#include "gmock/gmock.h"
#include <vector>

class GCDNumber
{
public:
    ULLI answer;
    LLI numOne;
    LLI numTwo;
    GCDNumber(ULLI answer, LLI a, LLI b)
    {
        this->answer = answer;
        this->numOne = a;
        this->numTwo = b;
    }
};

class PrimeNumber
{
public:
    ULLI number;
    ULLI exponent;
    bool answer;
    PrimeNumber(ULLI number, bool answer)
    {
        this->answer = answer;
        this->number = number;
        this->exponent = 1;
    }
    PrimeNumber(ULLI number, ULLI exponent)
    {
        this->answer = true;
        this->number = number;
        this->exponent = exponent;
    }
};

class FactorizationTest : public ::testing::Test
{
protected:
    virtual void SetUp()
    {
        GCD_ZeroInput.emplace_back(10, 0, 10);
        GCD_ZeroInput.emplace_back(10, 10, 0);
        GCD_ZeroInput.emplace_back(0, 0, 0);

        GCD_PositiveCompositeNumber.emplace_back(2, 2, 10);
        GCD_PositiveCompositeNumber.emplace_back(10, 10, 10);
        GCD_PositiveCompositeNumber.emplace_back(2, 10, 2);
        GCD_PositiveCompositeNumber.emplace_back(6, 78, 66);

        GCD_PositivePrimeNumber.emplace_back(1, 3, 7);
        GCD_PositivePrimeNumber.emplace_back(1, 5, 12);
        GCD_PositivePrimeNumber.emplace_back(1, 1, 1);
        GCD_PositivePrimeNumber.emplace_back(1, 2345, 72);

        GCD_PositiveLargeNumber.emplace_back(18913, 624129, 2061517);
        GCD_PositiveLargeNumber.emplace_back(23445, 1406700, 164115);
        GCD_PositiveLargeNumber.emplace_back(31415, 30315475, 24440870);
        GCD_PositiveLargeNumber.emplace_back(2, 55534, 434334);
        GCD_PositiveLargeNumber.emplace_back(3, 1368, 339);
        GCD_PositiveLargeNumber.emplace_back(564958, 37279462087332, 366983722766);
    }

    virtual void TearDown()
    {
        GCD_ZeroInput.clear();
        GCD_PositiveCompositeNumber.clear();
        GCD_PositivePrimeNumber.clear();
        GCD_PositiveLargeNumber.clear();
    }

    std::vector<GCDNumber> GCD_ZeroInput;
    std::vector<GCDNumber> GCD_PositiveCompositeNumber;
    std::vector<GCDNumber> GCD_PositivePrimeNumber;
    std::vector<GCDNumber> GCD_PositiveLargeNumber;

    // std::vector<PrimeNumber> PrimeNumber;

};

// http://www.cs.iit.edu/~virgil/cs458/mail.spring2010/programmingAssignment-1.html
// http://cs.au.dk/~chili/PBI04/ExamplePrograms/gcd_function_test.py
class NaiveGCDTest : public FactorizationTest
{};

class EuclideanGCDRecursiveTest : public FactorizationTest
{};

class EuclideanGCDIterativeTest : public FactorizationTest
{};

class PrimeFactorizationTest : public FactorizationTest
{};

TEST_F(NaiveGCDTest, ZeroNumberTest)
{
    unsigned int numTests = GCD_ZeroInput.size();
    for(unsigned int index = 0; index < numTests; index++)
    {
        EXPECT_EQ(GCD_ZeroInput[index].answer,
                  NaiveGCD(GCD_ZeroInput[index].numOne,
                           GCD_ZeroInput[index].numTwo));
    }
}

TEST_F(NaiveGCDTest, PositiveCompositeNumberTest)
{
    unsigned int numTests = GCD_PositiveCompositeNumber.size();
    for(unsigned int index = 0; index < numTests; index++)
    {
        EXPECT_EQ(GCD_PositiveCompositeNumber[index].answer,
                  NaiveGCD(GCD_PositiveCompositeNumber[index].numOne,
                           GCD_PositiveCompositeNumber[index].numTwo));
    }
}

TEST_F(NaiveGCDTest, PositivePrimeNumberTest)
{
    unsigned int numTests = GCD_PositivePrimeNumber.size();
    for(unsigned int index = 0; index < numTests; index++)
    {
        EXPECT_EQ(GCD_PositivePrimeNumber[index].answer,
                  NaiveGCD(GCD_PositivePrimeNumber[index].numOne,
                           GCD_PositivePrimeNumber[index].numTwo));
    }
}

/*TEST_F(NaiveGCDTest, PositiveLargeNumberTest)
{
    unsigned int numTests = GCD_PositiveLargeNumber.size();
    for(unsigned int index = 0; index < numTests; index++)
    {
        EXPECT_EQ(GCD_PositiveLargeNumber[index].answer,
                  NaiveGCD(GCD_PositiveLargeNumber[index].numOne,
                           GCD_PositiveLargeNumber[index].numTwo));
    }
}*/

TEST_F(EuclideanGCDRecursiveTest, ZeroNumberTest)
{
    unsigned int numTests = GCD_ZeroInput.size();
    for(unsigned int index = 0; index < numTests; index++)
    {
        EXPECT_EQ(GCD_ZeroInput[index].answer,
                  EuclideanGCDRecursive(GCD_ZeroInput[index].numOne,
                                        GCD_ZeroInput[index].numTwo));
    }
}

TEST_F(EuclideanGCDRecursiveTest, PositiveCompositeNumberTest)
{
    unsigned int numTests = GCD_PositiveCompositeNumber.size();
    for(unsigned int index = 0; index < numTests; index++)
    {
        EXPECT_EQ(GCD_PositiveCompositeNumber[index].answer,
                  EuclideanGCDRecursive(GCD_PositiveCompositeNumber[index].numOne,
                                        GCD_PositiveCompositeNumber[index].numTwo));
    }
}

TEST_F(EuclideanGCDRecursiveTest, PositivePrimeNumberTest)
{
    unsigned int numTests = GCD_PositivePrimeNumber.size();
    for(unsigned int index = 0; index < numTests; index++)
    {
        EXPECT_EQ(GCD_PositivePrimeNumber[index].answer,
                  EuclideanGCDRecursive(GCD_PositivePrimeNumber[index].numOne,
                                        GCD_PositivePrimeNumber[index].numTwo));
    }
}

TEST_F(EuclideanGCDRecursiveTest, PositiveLargeNumberTest)
{
    unsigned int numTests = GCD_PositiveLargeNumber.size();
    for(unsigned int index = 0; index < numTests; index++)
    {
        EXPECT_EQ(GCD_PositiveLargeNumber[index].answer,
                  EuclideanGCDRecursive(GCD_PositiveLargeNumber[index].numOne,
                                        GCD_PositiveLargeNumber[index].numTwo));
    }
}

TEST_F(EuclideanGCDIterativeTest, ZeroNumberTest)
{
    unsigned int numTests = GCD_ZeroInput.size();
    for(unsigned int index = 0; index < numTests; index++)
    {
        EXPECT_EQ(GCD_ZeroInput[index].answer,
                  EuclideanGCDIterative(GCD_ZeroInput[index].numOne,
                                        GCD_ZeroInput[index].numTwo));
    }
}

TEST_F(EuclideanGCDIterativeTest, PositiveCompositeNumberTest)
{
    unsigned int numTests = GCD_PositiveCompositeNumber.size();
    for(unsigned int index = 0; index < numTests; index++)
    {
        EXPECT_EQ(GCD_PositiveCompositeNumber[index].answer,
                  EuclideanGCDIterative(GCD_PositiveCompositeNumber[index].numOne,
                                        GCD_PositiveCompositeNumber[index].numTwo));
    }
}

TEST_F(EuclideanGCDIterativeTest, PositivePrimeNumberTest)
{
    unsigned int numTests = GCD_PositivePrimeNumber.size();
    for(unsigned int index = 0; index < numTests; index++)
    {
        EXPECT_EQ(GCD_PositivePrimeNumber[index].answer,
                  EuclideanGCDIterative(GCD_PositivePrimeNumber[index].numOne,
                                        GCD_PositivePrimeNumber[index].numTwo));
    }
}

TEST_F(EuclideanGCDIterativeTest, PositiveLargeNumberTest)
{
    unsigned int numTests = GCD_PositiveLargeNumber.size();
    for(unsigned int index = 0; index < numTests; index++)
    {
        EXPECT_EQ(GCD_PositiveLargeNumber[index].answer,
                  EuclideanGCDIterative(GCD_PositiveLargeNumber[index].numOne,
                                        GCD_PositiveLargeNumber[index].numTwo));
    }
}

// https://stackoverflow.com/questions/12340470/compare-containers-with-googletest
TEST_F(PrimeFactorizationTest, SmallNumberCornerTest)
{
    std::vector< std::pair<ULLI, ULLI> > prime_factors_1;
    std::vector< std::pair<ULLI, ULLI> > prime_factors_0;
    EXPECT_THAT(prime_factors_0,
                ::testing::ContainerEq(PrimeFactorization(0)));
    EXPECT_THAT(prime_factors_1,
                ::testing::ContainerEq(PrimeFactorization(1)));
}

TEST_F(PrimeFactorizationTest, PrimeNumberTest)
{
    std::vector< std::pair<ULLI, ULLI> > prime_factors_2, prime_factors_3, prime_factors_5;
    prime_factors_2.emplace_back(2, 1);
    prime_factors_3.emplace_back(3, 1);
    prime_factors_5.emplace_back(5, 1);
    EXPECT_THAT(prime_factors_2,
                ::testing::ContainerEq(PrimeFactorization(2)));
    EXPECT_THAT(prime_factors_3,
                ::testing::ContainerEq(PrimeFactorization(3)));
    EXPECT_THAT(prime_factors_5,
                ::testing::ContainerEq(PrimeFactorization(5)));
}

TEST_F(PrimeFactorizationTest, CompositeNumberTest)
{
    std::vector< std::pair<ULLI, ULLI> > prime_factors_100;
    prime_factors_100.emplace_back(2, 2);
    prime_factors_100.emplace_back(5, 2);
    EXPECT_THAT(prime_factors_100,
                ::testing::ContainerEq(PrimeFactorization(100)));
}