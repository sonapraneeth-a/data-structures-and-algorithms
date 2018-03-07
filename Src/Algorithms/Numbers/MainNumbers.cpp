#include "DefaultHeaders.h"
#include "BigInteger.h"
#include "Factorization.h"

void RunBigInteger()
{
    BigInteger number;
    std::string positive_signInteger = "+123";
    std::cout << number.validate_string(positive_signInteger) << "\n";
    return;
}

void RunGCD()
{
    // int numOne = 624129, numTwo = 2061517;
    LLI numOne = 1406700, numTwo = 164115;
    EXECUTE_FUNC_UNIT("ns",
                      std::cout << "GCD of " << numOne << " and " << numTwo << " is: "
                                << NaiveGCD(numOne, numTwo) << "\n";)
    EXECUTE_FUNC_UNIT("us",
                      std::cout << "GCD of " << numOne << " and " << numTwo << " is: "
                                << EuclideanGCDRecursive(numOne, numTwo) << "\n";)
    return;
}

void RunPrimeFactorization()
{
    std::vector< std::pair<ULLI, ULLI> > factors = PrimeFactorization(100);
    for(unsigned int index = 0; index < factors.size(); index++)
    {
        std::cout << "(" << factors[index].first << ", " << factors[index].second << ");";
    }
    std::cout << "\n";
}

int main()
{
    RunPrimeFactorization();
    return 0;
}