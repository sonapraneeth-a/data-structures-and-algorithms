/**
 *      Created on: 06 March 2018
 *   Last modified: 13 March 2018
 *          Author: Sona Praneeth Akula
 *         Details: Header for algorithms related to finding fibonacci numbers
 */

/**
 * Changelog
 *
 * Date (DD-MM-YYYY)            Author               Update
 * 06-03-2018             Sona Praneeth Akula   - Creation of the file
 * 13-03-2018             Sona Praneeth Akula   - Updation of the documentation
 */

#ifndef FIBONACCI_H
#define FIBONACCI_H

#include "DefaultHeaders.h"

namespace Math
{

    ULLI
    GetNthFibonacciRecursive(unsigned int index);

    ULLI
    GetNthFibonacciIterative(unsigned int index);

    std::vector<ULLI>
    FibonacciSeries(unsigned int length);

}

#endif //FIBONACCI_H
