#include "Factorization.h"
#include "gtest/gtest.h"
#include "gmock/gmock.h"
#include <vector>
#include <iterator>
#include "TimingHeader.h"

/**
 *
 */
class GCDNumber
{
public:
    ULLI answer;
    LLI numOne;
    LLI numTwo;
    /**
     *
     * @param answer
     * @param a
     * @param b
     */
    GCDNumber(ULLI answer, LLI a, LLI b)
    {
        this->answer = answer;
        this->numOne = a;
        this->numTwo = b;
    }
};

/**
 *
 */
class PrimeNumber
{
public:
    ULLI number;
    ULLI exponent;
    PrimeNumber(ULLI number, ULLI exponent)
    {
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

        // Reference: https://stackoverflow.com/questions/8777603/what-is-the-simplest-way-to-convert-array-to-vector
        std::vector<ULLI> prime_factors_until_0({ });
        std::vector<ULLI> prime_factors_until_1({ });
        std::vector<ULLI> prime_factors_until_2({ 2 });
        std::vector<ULLI> prime_factors_until_3({ 2, 3 });
        std::vector<ULLI> prime_factors_until_5({ 2, 3, 5 });
        std::vector<ULLI> prime_factors_until_9({ 2, 3, 5, 7 });
        std::vector<ULLI> prime_factors_until_783({ 2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97, 101, 103, 107, 109, 113, 127, 131, 137, 139, 149, 151, 157, 163, 167, 173, 179, 181, 191, 193, 197, 199, 211, 223, 227, 229, 233, 239, 241, 251, 257, 263, 269, 271, 277, 281, 283, 293, 307, 311, 313, 317, 331, 337, 347, 349, 353, 359, 367, 373, 379, 383, 389, 397, 401, 409, 419, 421, 431, 433, 439, 443, 449, 457, 461, 463, 467, 479, 487, 491, 499, 503, 509, 521, 523, 541, 547, 557, 563, 569, 571, 577, 587, 593, 599, 601, 607, 613, 617, 619, 631, 641, 643, 647, 653, 659, 661, 673, 677, 683, 691, 701, 709, 719, 727, 733, 739, 743, 751, 757, 761, 769, 773 });
        std::vector<ULLI> prime_factors_until_984({ 2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97, 101, 103, 107, 109, 113, 127, 131, 137, 139, 149, 151, 157, 163, 167, 173, 179, 181, 191, 193, 197, 199, 211, 223, 227, 229, 233, 239, 241, 251, 257, 263, 269, 271, 277, 281, 283, 293, 307, 311, 313, 317, 331, 337, 347, 349, 353, 359, 367, 373, 379, 383, 389, 397, 401, 409, 419, 421, 431, 433, 439, 443, 449, 457, 461, 463, 467, 479, 487, 491, 499, 503, 509, 521, 523, 541, 547, 557, 563, 569, 571, 577, 587, 593, 599, 601, 607, 613, 617, 619, 631, 641, 643, 647, 653, 659, 661, 673, 677, 683, 691, 701, 709, 719, 727, 733, 739, 743, 751, 757, 761, 769, 773, 787, 797, 809, 811, 821, 823, 827, 829, 839, 853, 857, 859, 863, 877, 881, 883, 887, 907, 911, 919, 929, 937, 941, 947, 953, 967, 971, 977, 983 });
        Sieve_SmallNumbers.push_back(std::make_pair(0, prime_factors_until_0));
        Sieve_SmallNumbers.push_back(std::make_pair(1, prime_factors_until_1));
        Sieve_SmallNumbers.push_back(std::make_pair(2, prime_factors_until_2));
        Sieve_SmallNumbers.push_back(std::make_pair(3, prime_factors_until_3));
        Sieve_SmallNumbers.push_back(std::make_pair(5, prime_factors_until_5));
        Sieve_SmallNumbers.push_back(std::make_pair(9, prime_factors_until_9));

        Sieve_LargeNumbers.push_back(std::make_pair(783, prime_factors_until_783));
        Sieve_LargeNumbers.push_back(std::make_pair(984, prime_factors_until_984));

    }

    virtual void TearDown()
    {
        GCD_ZeroInput.clear();
        GCD_PositiveCompositeNumber.clear();
        GCD_PositivePrimeNumber.clear();
        GCD_PositiveLargeNumber.clear();

        Sieve_SmallNumbers.clear();
        Sieve_LargeNumbers.clear();
    }

    std::vector<GCDNumber> GCD_ZeroInput;
    std::vector<GCDNumber> GCD_PositiveCompositeNumber;
    std::vector<GCDNumber> GCD_PositivePrimeNumber;
    std::vector<GCDNumber> GCD_PositiveLargeNumber;

    std::vector< std::pair<ULLI, std::vector<ULLI> > > Sieve_SmallNumbers;
    std::vector< std::pair<ULLI, std::vector<ULLI> > > Sieve_LargeNumbers;

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

class SieveOfEratosthenesTest : public FactorizationTest
{};

TEST_F(NaiveGCDTest, ZeroNumberTest)
{
    unsigned int numTests = GCD_ZeroInput.size();
    for(unsigned int index = 0; index < numTests; index++)
    {
        /*std::cout << "Running test case " << index << ": Math::NaiveGCD("
                  << GCD_ZeroInput[index].numOne << ", "
                  << GCD_ZeroInput[index].numTwo << ")\n";*/
        EXPECT_EQ(GCD_ZeroInput[index].answer,
                  Math::NaiveGCD(GCD_ZeroInput[index].numOne,
                                 GCD_ZeroInput[index].numTwo));
        //std::cout << "Success\n";
    }
    //std::cout << "\n";
}

TEST_F(NaiveGCDTest, PositiveCompositeNumberTest)
{
    unsigned int numTests = GCD_PositiveCompositeNumber.size();
    for(unsigned int index = 0; index < numTests; index++)
    {
        /*std::cout << "Running test case " << index << ": Math::NaiveGCD("
                  << GCD_PositiveCompositeNumber[index].numOne << ", "
                  << GCD_PositiveCompositeNumber[index].numTwo << ")\n";*/
        EXPECT_EQ(GCD_PositiveCompositeNumber[index].answer,
                  Math::NaiveGCD(GCD_PositiveCompositeNumber[index].numOne,
                                 GCD_PositiveCompositeNumber[index].numTwo));
        //std::cout << "Success\n";
    }
    //std::cout << "\n";
}

TEST_F(NaiveGCDTest, PositivePrimeNumberTest)
{
    unsigned int numTests = GCD_PositivePrimeNumber.size();
    for(unsigned int index = 0; index < numTests; index++)
    {
        /*std::cout << "Running test case " << index << ": Math::NaiveGCD("
                  << GCD_PositivePrimeNumber[index].numOne << ", "
                  << GCD_PositivePrimeNumber[index].numTwo << ")\n";*/
        EXPECT_EQ(GCD_PositivePrimeNumber[index].answer,
                  Math::NaiveGCD(GCD_PositivePrimeNumber[index].numOne,
                                 GCD_PositivePrimeNumber[index].numTwo));
        //std::cout << "Success\n";
    }
    //std::cout << "\n";
}

TEST_F(NaiveGCDTest, PositiveLargeNumberTest)
{
    unsigned int numTests = GCD_PositiveLargeNumber.size();
    TEST_TIMEOUT_BEGIN
    for(unsigned int index = 0; index < numTests-1; index++)
    {
        /*std::cout << "Running test case " << index << ": Math::NaiveGCD("
                  << GCD_PositiveLargeNumber[index].numOne << ", "
                  << GCD_PositiveLargeNumber[index].numTwo << ")\n";*/
        EXPECT_EQ(GCD_PositiveLargeNumber[index].answer,
                  Math::NaiveGCD(GCD_PositiveLargeNumber[index].numOne,
                                 GCD_PositiveLargeNumber[index].numTwo));
        //std::cout << "Success\n";
    }
    TEST_TIMEOUT_FAIL_END(1000);
    /*TEST_TIMEOUT_BEGIN
    std::cout << "Running test case " << numTests-1 << ": Math::NaiveGCD("
              << GCD_PositiveLargeNumber[numTests-1].numOne << ", "
              << GCD_PositiveLargeNumber[numTests-1].numTwo << ")\n";
    EXPECT_EQ(GCD_PositiveLargeNumber[numTests-1].answer,
              Math::NaiveGCD(GCD_PositiveLargeNumber[numTests-1].numOne,
                       GCD_PositiveLargeNumber[numTests-1].numTwo));
    //std::cout << "Success\n";
    TEST_TIMEOUT_FAIL_END(1000)*/
    //std::cout << "\n";
}

TEST_F(EuclideanGCDRecursiveTest, ZeroNumberTest)
{
    unsigned int numTests = GCD_ZeroInput.size();
    for(unsigned int index = 0; index < numTests; index++)
    {
        /*std::cout << "Running test case " << index << ": Math::EuclideanGCDRecursive("
                  << GCD_ZeroInput[index].numOne << ", "
                  << GCD_ZeroInput[index].numTwo << ")\n";*/
        EXPECT_EQ(GCD_ZeroInput[index].answer,
                  Math::EuclideanGCDRecursive(GCD_ZeroInput[index].numOne,
                                              GCD_ZeroInput[index].numTwo));
        //std::cout << "Success\n";
    }
    //std::cout << "\n";
}

TEST_F(EuclideanGCDRecursiveTest, PositiveCompositeNumberTest)
{
    unsigned int numTests = GCD_PositiveCompositeNumber.size();
    for(unsigned int index = 0; index < numTests; index++)
    {
        /*std::cout << "Running test case " << index << ": Math::EuclideanGCDRecursive("
                  << GCD_PositiveCompositeNumber[index].numOne << ", "
                  << GCD_PositiveCompositeNumber[index].numTwo << ")\n";*/
        EXPECT_EQ(GCD_PositiveCompositeNumber[index].answer,
                  Math::EuclideanGCDRecursive(GCD_PositiveCompositeNumber[index].numOne,
                                              GCD_PositiveCompositeNumber[index].numTwo));
        //std::cout << "Success\n";
    }
    //std::cout << "\n";
}

TEST_F(EuclideanGCDRecursiveTest, PositivePrimeNumberTest)
{
    unsigned int numTests = GCD_PositivePrimeNumber.size();
    for(unsigned int index = 0; index < numTests; index++)
    {
        /*std::cout << "Running test case " << index << ": Math::EuclideanGCDRecursive("
                  << GCD_PositivePrimeNumber[index].numOne << ", "
                  << GCD_PositivePrimeNumber[index].numTwo << ")\n";*/
        EXPECT_EQ(GCD_PositivePrimeNumber[index].answer,
                  Math::EuclideanGCDRecursive(GCD_PositivePrimeNumber[index].numOne,
                                              GCD_PositivePrimeNumber[index].numTwo));
        //std::cout << "Success\n";
    }
    //std::cout << "\n";
}

TEST_F(EuclideanGCDRecursiveTest, PositiveLargeNumberTest)
{
    unsigned int numTests = GCD_PositiveLargeNumber.size();
    for(unsigned int index = 0; index < numTests; index++)
    {
        /*std::cout << "Running test case " << index << ": Math::EuclideanGCDRecursive("
                  << GCD_PositiveLargeNumber[index].numOne << ", "
                  << GCD_PositiveLargeNumber[index].numTwo << ")\n";*/
        EXPECT_EQ(GCD_PositiveLargeNumber[index].answer,
                  Math::EuclideanGCDRecursive(GCD_PositiveLargeNumber[index].numOne,
                                              GCD_PositiveLargeNumber[index].numTwo));
        //std::cout << "Success\n";
    }
    //std::cout << "\n";
}

TEST_F(EuclideanGCDIterativeTest, ZeroNumberTest)
{
    unsigned int numTests = GCD_ZeroInput.size();
    for(unsigned int index = 0; index < numTests; index++)
    {
        /*std::cout << "Running test case " << index << ": Math::EuclideanGCDIterative("
                  << GCD_ZeroInput[index].numOne << ", "
                  << GCD_ZeroInput[index].numTwo << ")\n";*/
        EXPECT_EQ(GCD_ZeroInput[index].answer,
                  Math::EuclideanGCDIterative(GCD_ZeroInput[index].numOne,
                                              GCD_ZeroInput[index].numTwo));
        //std::cout << "Success\n";
    }
    //std::cout << "\n";
}

TEST_F(EuclideanGCDIterativeTest, PositiveCompositeNumberTest)
{
    unsigned int numTests = GCD_PositiveCompositeNumber.size();
    for(unsigned int index = 0; index < numTests; index++)
    {
        /*std::cout << "Running test case " << index << ": Math::EuclideanGCDIterative("
                  << GCD_PositiveCompositeNumber[index].numOne << ", "
                  << GCD_PositiveCompositeNumber[index].numTwo << ")\n";*/
        EXPECT_EQ(GCD_PositiveCompositeNumber[index].answer,
                  Math::EuclideanGCDIterative(GCD_PositiveCompositeNumber[index].numOne,
                                              GCD_PositiveCompositeNumber[index].numTwo));
        //std::cout << "Success\n";
    }
    //std::cout << "\n";
}

TEST_F(EuclideanGCDIterativeTest, PositivePrimeNumberTest)
{
    unsigned int numTests = GCD_PositivePrimeNumber.size();
    for(unsigned int index = 0; index < numTests; index++)
    {
        /*std::cout << "Running test case " << index << ": Math::EuclideanGCDIterative("
                  << GCD_PositivePrimeNumber[index].numOne << ", "
                  << GCD_PositivePrimeNumber[index].numTwo << ")\n";*/
        EXPECT_EQ(GCD_PositivePrimeNumber[index].answer,
                  Math::EuclideanGCDIterative(GCD_PositivePrimeNumber[index].numOne,
                                              GCD_PositivePrimeNumber[index].numTwo));
        //std::cout << "Success\n";
    }
    //std::cout << "\n";
}

TEST_F(EuclideanGCDIterativeTest, PositiveLargeNumberTest)
{
    unsigned int numTests = GCD_PositiveLargeNumber.size();
    for(unsigned int index = 0; index < numTests; index++)
    {
        /*std::cout << "Running test case " << index << ": Math::EuclideanGCDIterative("
                  << GCD_PositiveLargeNumber[index].numOne << ", "
                  << GCD_PositiveLargeNumber[index].numTwo << ")\n";*/
        EXPECT_EQ(GCD_PositiveLargeNumber[index].answer,
                  Math::EuclideanGCDIterative(GCD_PositiveLargeNumber[index].numOne,
                                              GCD_PositiveLargeNumber[index].numTwo));
        //std::cout << "Success\n";
    }
    //std::cout << "\n";
}

// https://stackoverflow.com/questions/12340470/compare-containers-with-googletest
TEST_F(PrimeFactorizationTest, SmallNumberCornerTest)
{
    std::vector< std::pair<ULLI, ULLI> > prime_factors_1;
    std::vector< std::pair<ULLI, ULLI> > prime_factors_0;
    EXPECT_THAT(prime_factors_0,
                ::testing::ContainerEq(Math::PrimeFactorization(0)));
    EXPECT_THAT(prime_factors_1,
                ::testing::ContainerEq(Math::PrimeFactorization(1)));
}

TEST_F(PrimeFactorizationTest, PrimeNumberTest)
{
    std::vector< std::pair<ULLI, ULLI> > prime_factors_2, prime_factors_3, prime_factors_5;
    prime_factors_2.emplace_back(2, 1);
    prime_factors_3.emplace_back(3, 1);
    prime_factors_5.emplace_back(5, 1);
    EXPECT_THAT(prime_factors_2,
                ::testing::ContainerEq(Math::PrimeFactorization(2)));
    EXPECT_THAT(prime_factors_3,
                ::testing::ContainerEq(Math::PrimeFactorization(3)));
    EXPECT_THAT(prime_factors_5,
                ::testing::ContainerEq(Math::PrimeFactorization(5)));
}

TEST_F(PrimeFactorizationTest, CompositeNumberTest)
{
    std::vector< std::pair<ULLI, ULLI> > prime_factors_100;
    prime_factors_100.emplace_back(2, 2);
    prime_factors_100.emplace_back(5, 2);
    EXPECT_THAT(prime_factors_100,
                ::testing::ContainerEq(Math::PrimeFactorization(100)));
}

TEST_F(SieveOfEratosthenesTest, SmallNumbersTest)
{
    unsigned int numTests = Sieve_SmallNumbers.size();
    for(unsigned int index = 0; index < numTests; index++)
    {
        /*std::cout << "Running test case " << index << ": Math::SieveOfEratosthenes("
                  << Sieve_SmallNumbers[index].first << ")\n";*/
        EXPECT_THAT(Sieve_SmallNumbers[index].second,
                    ::testing::ContainerEq(Math::SieveOfEratosthenes(Sieve_SmallNumbers[index].first)));
        //std::cout << "Success\n";
    }
    //std::cout << "\n";
}

TEST_F(SieveOfEratosthenesTest, LargeNumbersTest)
{
    unsigned int numTests = Sieve_LargeNumbers.size();
    for(unsigned int index = 0; index < numTests; index++)
    {
        /*std::cout << "Running test case " << index << ": Math::SieveOfEratosthenes("
                  << Sieve_LargeNumbers[index].first << ")\n";*/
        EXPECT_THAT(Sieve_LargeNumbers[index].second,
                    ::testing::ContainerEq(Math::SieveOfEratosthenes(Sieve_LargeNumbers[index].first)));
        //std::cout << "Success\n";
    }
    //std::cout << "\n";
}