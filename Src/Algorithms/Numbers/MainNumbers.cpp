#include "BigInteger.h"

int main()
{
    BigInteger number;
    std::string positive_signInteger = "+123";
    std::cout << number.validate_string(positive_signInteger) << "\n";
    return 0;
}