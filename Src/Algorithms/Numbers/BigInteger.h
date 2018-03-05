#ifndef UTIL_BIG_INTEGER_H
#define UTIL_BIG_INTEGER_H

#include <cstdlib>
#include <iostream>
#include <string>

class BigInteger
{
private:
    unsigned int *number;
    bool sign = true;
    unsigned int integer_size = 0;
public:
    std::string integer;

    BigInteger();
    BigInteger(std::string input);

    BigInteger operator + (BigInteger const &obj);
    std::string to_string();
    bool validate_string(std::string &input);

    ~BigInteger();

};


#endif
