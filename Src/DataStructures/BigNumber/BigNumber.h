#ifndef BIG_NUMBER_H
#define BIG_NUMBER_H

#include <cstdlib>
#include <iostream>
#include <string>

class BigNumber
{
private:

    unsigned int *number;
    bool sign = true;
    unsigned int integer_size = 0;
    std::string integer;

public:

    BigNumber();
    BigNumber(std::string input);

    BigNumber operator + (BigNumber const &obj);
    std::string to_string();
    bool validate_string(std::string &input);

    ~BigNumber();

};


#endif
