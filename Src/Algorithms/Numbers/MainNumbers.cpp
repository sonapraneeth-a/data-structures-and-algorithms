#include "BigInteger.h"
#include "Factorization.h"

void RunBigInteger()
{
    BigInteger number;
    std::string positive_signInteger = "+123";
    std::cout << number.validate_string(positive_signInteger) << "\n";
    return;
}

void RunFactorization()
{
    std::cout << "GCD of 357 and 234 is: " << EuclideanGCD(357, 234) << "\n";
    return;
}

int main()
{
    RunFactorization();
    return 0;
}