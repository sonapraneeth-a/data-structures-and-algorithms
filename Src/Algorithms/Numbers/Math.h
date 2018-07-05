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

#define MOD_ADD(a, b, c) (a%c + b%c)%c
#define MOD_SUB(a, b, c) (a%c - b%c + c)%c
#define MOD_MUL(a, b, c) (a%c * b%c)%c

namespace Math
{
    ULLI
    ExponentiationRecursive(ULLI a, ULLI b);

    ULLI
    ExponentiationIterative(ULLI a, ULLI b);

    ULLI
    BinaryExponentiationRecursive(ULLI a, ULLI b);

    ULLI
    BinaryExponentiationIterative(ULLI a, ULLI b);
}

#endif //MATH_H
