#include "big_integer.h"

int main()
{
    BigInteger number;
    std::string positive_sign_integer = "+123";
    std::cout << number.validate_string(positive_sign_integer) << "\n";
    return 0;
}