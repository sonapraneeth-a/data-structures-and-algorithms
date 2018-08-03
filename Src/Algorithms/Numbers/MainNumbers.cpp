#include "DefaultHeaders.h"
#include "Factorization.h"
#include "Math.h"
#include "Utilities.h"

void RunGCD()
{
    // int numOne = 624129, numTwo = 2061517;
    LLI numOne = 1406700, numTwo = 164115;
    EXECUTE_FUNC_UNIT("ns",
                      std::cout << "GCD of " << numOne << " and " << numTwo << " is: "
                                << Math::NaiveGCD(numOne, numTwo) << "\n";)
    EXECUTE_FUNC_UNIT("us",
                      std::cout << "GCD of " << numOne << " and " << numTwo << " is: "
                                << Math::EuclideanGCDRecursive(numOne, numTwo) << "\n";)
    return;
}

void RunPrimeFactorization()
{
    std::vector< std::pair<ULLI, ULLI> > factors = Math::PrimeFactorization(100);
    for(unsigned int index = 0; index < factors.size(); index++)
    {
        std::cout << "(" << factors[index].first << ", " << factors[index].second << ");";
    }
    std::cout << "\n";
}

void RunSieveOfEratosthenes()
{
    // std::vector< ULLI > test_cases{0, 1, 2, 3, 4, 5, 10, 1000, 1000000};
    std::vector< ULLI > test_cases({1000000});
    for(unsigned int test_case_index = 0; test_case_index < test_cases.size(); test_case_index++)
    {
        std::vector< ULLI > primes = Math::SieveOfEratosthenes(test_cases[test_case_index]);
        std::cout << test_cases[test_case_index] << ": { ";
        for(unsigned int factor_index = 0; factor_index < primes.size(); factor_index++)
        {
            std::cout << primes[factor_index] << ", ";
        }
        std::cout << "}\n";
        primes.clear();
    }
    std::cout << "\n";
}

void RunExponentiation()
{
    std::cout << Math::ExponentiationRecursive(2, 3);
}

int main()
{
    // RunSieveOfEratosthenes();
    RunExponentiation();
    /*int a = 5;
    unsigned short int b = 5;
    ULLI c = 78;
    Math::typed_foo(a);
    Math::typed_foo(b);
    Math::typed_foo(c);*/
    return 0;
}