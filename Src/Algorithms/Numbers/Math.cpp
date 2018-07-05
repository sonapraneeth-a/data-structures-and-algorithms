/**
 *      Created on: 05 July 2018
 *   Last modified: 05 July 2018
 *          Author: Sona Praneeth Akula
 *         Details: Code for algorithms related to maths
 */

/**
 * Changelog
 *
 * Date (DD-MM-YYYY)            Author               Update
 * 05-07-2018             Sona Praneeth Akula   - Creation of the file
 */

#include "Math.h"

ULLI
Math::ExponentiationRecursive(ULLI number, ULLI exponent)
{
    if (number == 0 || number == 1)
        return number;
    if (exponent == 0)
        return 1;
    return number*Math::ExponentiationRecursive(number, exponent-1);
}