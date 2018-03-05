#include "BigInteger.h"

BigInteger::BigInteger()
{
    integer = "0";
}

BigInteger::BigInteger(std::string inputNumber)
{
    std::string input = inputNumber;
    if(validate_string(input)) {
        this->integer = input;
        this->integer_size = (unsigned int) input.size() + 2;
        number = (unsigned int *) malloc(this->integer_size * sizeof(unsigned int));
        unsigned int num_index = this->integer_size - 1;
        for (int index = 0; index < num_index; index++) {
            number[index] = 0;
        }
        for (int index = (int) input.size() - 1; index >= 0; index--) {
            number[num_index--] = input[index] - '0';
        }
    }
    else
    {
        std::cout << "Input string: " << input << " is invalid. Hence setting the value to 0";
        BigInteger();
    }
}

BigInteger BigInteger::operator + (BigInteger const &obj)
{
    integer = "0";
    number = (unsigned int*)malloc(1 * sizeof(unsigned int));
    number[0] = 0;
}

std::string BigInteger::to_string()
{
    std::string answer = "";
    for(unsigned int index = 0; index < this->integer_size; index++)
    {
        answer += number[index] + '0';
    }
    return answer;
}

bool BigInteger::validate_string(std::string &input)
{
    bool result = true;
    bool number_start = false;
    bool symbol_start = false;
    std::string formatted_int = "";
    int index = 0;
    while(input[index] == ' ')
    {
        index++;
    }
    for(int inp_index = index; inp_index < input.size(); inp_index++)
    {
        if (input[inp_index] >= '0' && input[inp_index] <= '9')
        {
            number_start = true; symbol_start = true;
            formatted_int += input[inp_index];
        }
        else if(!(input[inp_index] >= '0' && input[inp_index] <= '9') && number_start)
        {
            result = false; break;
        }
        else if ((input[inp_index] == '+' || input[inp_index] == '-') && !number_start && !symbol_start)
        {
            symbol_start = true;
            formatted_int += input[inp_index];
        }
        else if ((input[inp_index] == '+' || input[inp_index] == '-') && !number_start && symbol_start)
        {
            result = false; break;
        }
        else if(!(input[inp_index] >= '0' && input[inp_index] <= '9') ||
                !((input[inp_index] == '+' || input[inp_index] == '-')))
        {
            result = false; break;
        }
        else
        {}
    }
    if (result)
    {
        input = formatted_int;
    }
    return result;
}

BigInteger::~BigInteger()
{
    free(number);
}