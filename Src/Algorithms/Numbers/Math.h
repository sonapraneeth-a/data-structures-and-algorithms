/**
 *      Created on: 05 July 2018
 *   Last modified: 05 July 2018
 *          Author: Sona Praneeth Akula
 *         Details: Code for algorithms related to math functions
 */

/**
 * Changelog
 *
 * Date (DD-MM-YYYY)            Author               Update
 * 05-07-2018             Sona Praneeth Akula   - Creation of the file
 */

#ifndef MATH_H
#define MATH_H

#include "DefaultHeaders.h"

#define MOD_ADD(a, b, c) ((a)%(c) + (b)%(c))%(c)
#define MOD_SUB(a, b, c) ((a)%(c) - (b)%(c) + (c))%(c)
#define MOD_MUL(a, b, c) ((a)%(c) * (b)%(c))%(c)

namespace Math
{
    // Reference: https://www.ideone.com/bMVAqI
    template <typename T>
    typename INTEGER_NUMBERS(T)
    ExponentiationRecursive(T number, T exponent);

    template <typename T>
    typename INTEGER_NUMBERS(T)
    ExponentiationIterative(T number, T exponent);

    template <typename T>
    typename INTEGER_NUMBERS(T)
    BinaryExponentiationRecursive(T number, T exponent);

    template <typename T>
    typename INTEGER_NUMBERS(T)
    BinaryExponentiationIterative(T number, T exponent);

    template <typename T>
    typename INTEGER_NUMBERS(T)
    ModularExponentiationRecursive(T number, T exponent, T mod);

    template <typename T>
    typename INTEGER_NUMBERS(T)
    ModularExponentiationIterative(T number, T exponent, T mod);

    /*template <typename T>
    typename INTEGER_NUMBERS
    typed_foo(const T& t)
    {
        std::cout << ">>> messing with unknown stuff! " << t << std::endl;
    }*/
}

/**
 *
 * @param number
 * @param exponent
 * @return
 */
template <typename T>
typename INTEGER_NUMBERS(T)
Math::ExponentiationRecursive(T number, T exponent)
{
    if (number == 0 || number == 1)
        return number;
    if (exponent == 0)
        return 1;
    return number*Math::ExponentiationRecursive(number, exponent-1);
}

/**
 *
 * @param number
 * @param exponent
 * @return
 */
template <typename T>
typename INTEGER_NUMBERS(T)
Math::ExponentiationIterative(T number, T exponent)
{
    if (number == 0 || number == 1)
        return number;
    if (exponent == 0)
        return 1;
    T answer = number;
    for (T index = 2; index <= exponent; ++index)
    {
        answer *= number;
    }
    return answer;
}

/**
 *
 * @param number
 * @param exponent
 * @return
 */
template <typename T>
typename INTEGER_NUMBERS(T)
Math::BinaryExponentiationRecursive(T number, T exponent)
{
    if (number == 0 || number == 1)
        return number;
    if (exponent == 0)
        return 1;
    if (exponent % 2 == 0)
    {
        T answer = Math::BinaryExponentiationRecursive(number, exponent/2);
        return answer*answer;
    }
    else
    {
        T answer = Math::BinaryExponentiationRecursive(number, exponent-1);
        return number*answer;
    }
}

/**
 *
 * @param number
 * @param exponent
 * @return
 */
template <typename T>
typename INTEGER_NUMBERS(T)
Math::BinaryExponentiationIterative(T number, T exponent)
{
    if (number == 0 || number == 1)
        return number;
    if (exponent == 0)
        return 1;
    T answer = 1;
    while (exponent > 0)
    {
        if (exponent % 2)
        {
            answer *= number;
        }
        number *= number;
        exponent /= 2;
    }
    return answer;
}

template <typename T>
typename INTEGER_NUMBERS(T)
Math::ModularExponentiationRecursive(T number, T exponent, T mod)
{
    if (number == 0 || number == 1)
        return number;
    if (exponent == 0)
        return 1;
    if (exponent % 2 == 0)
    {
        T answer = Math::ModularExponentiationRecursive(number, exponent/2, mod);
        return MOD_MUL(answer, answer, mod);
    }
    else
    {
        T answer = Math::ModularExponentiationRecursive(number, exponent-1, mod);
        return MOD_MUL(number, answer, mod);
    }
}

template <typename T>
typename INTEGER_NUMBERS(T)
Math::ModularExponentiationIterative(T number, T exponent, T mod)
{
    if (number == 0 || number == 1)
        return number;
    if (exponent == 0)
        return 1;
    T answer = 1;
    while (exponent > 0)
    {
        if (exponent % 2)
        {
            answer = MOD_MUL(answer, number, mod);
        }
        number = MOD_MUL(number, number, mod);
        exponent /= 2;
    }
    return answer;
}


#endif //MATH_H
