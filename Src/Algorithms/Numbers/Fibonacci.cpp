/**
 *      Created on: 06 March 2018
 *   Last modified: 13 March 2018
 *          Author: Sona Praneeth Akula
 *         Details: Implementation Code for fibonacci numbers
 */

/**
 * Changelog
 *
 * Date (DD-MM-YYYY)            Author               Update
 * 06-03-2018             Sona Praneeth Akula   - Creation of the file
 * 13-03-2018             Sona Praneeth Akula   - Updation of the documentation
 */

#include "Fibonacci.h"

/*!
 * @todo Create test cases and check for the correctness of the algorithm
 * @ingroup Fibonacci
 * @brief   Get the nth fibonacci number
 * @details Recursive approach to get nth fibonacci number
 *
 * @param  [in] [unsigned int ] index - Index of fibonacci number
 * @return [out] [unsigned long long int] - Index<sup>th</sup> fibonacci number
 */
unsigned long long int
GetNthFibonacciRecursive(unsigned int index)
{
    // Series: 0 1 1 2 3 5 ...
    if (index == 0)
    {
        return 0; // return 0 as 0 is the 0th fibonacci number
    }
    else if(index == 1)
    {
        return 1; // return 1 as 1 is the 1st fibonacci number
    }
    else
    {
        // Recursive relation: F(n) = F(n-1) + F(n-2)
        return GetNthFibonacciRecursive(index - 1) + GetNthFibonacciRecursive(index - 2);
    }
}

/*!
 * @todo Create test cases and check for the correctness of the algorithm
 * @ingroup Fibonacci
 * @brief   Get the nth fibonacci number
 * @details Iterative approach to get nth fibonacci number
 *
 * @param  [in] [unsigned int ] index - Index of fibonacci number
 * @return [out] [unsigned long long int] - Index<sup>th</sup> fibonacci number
 */
unsigned long long int
GetNthFibonacciIterative(unsigned int index)
{
    // Series: 0 1 1 2 3 5 ...
    if (index == 0)
    {
        return 0;  // return 0 as 0 is the 0th fibonacci number
    }
    else if(index == 1)
    {
        return 1;  // return 1 as 1 is the 1st fibonacci number
    }
    else
    {
        unsigned long long int fn_2 = 0;   // F(n-2)
        unsigned long long int fn_1 = 1;   // F(n-1)
        unsigned long long int fn = 0;     // F(n)
        for(unsigned int i = 2; i <= index; i++)
        {
            fn = fn_1 + fn_2; // Recursive relation: F(n) = F(n-1) + F(n-2)
            fn_2 = fn_1;
            fn_1 = fn;
        }
        return fn;
    }
}

/*!
 * @ingroup Fibonacci
 * @brief   Gets the fibonacci series of specified length
 * @details
 *
 * @param  [in] [unsigned int] length - Length of fibonacci series required
 * @return [out] [vector<unsigned long long int>] - Fibonacci series of the required length
 */
std::vector<ULLI>
FibonacciSeries(unsigned int length)
{
    // Series: 0 1 1 2 3 5 ...
    std::vector<ULLI> series;
    if(length >= 1)
    {
        series.push_back(0);
    }
    if(length >= 2)
    {
        series.push_back(1);
    }
    // Recursive relation: F(n) = F(n-1) + F(n-2)
    for (unsigned int index = 2; index < length; index++)
    {
        // Using the last two elements of series vector for the current series
        series.push_back(series[index-1] + series[index-2]);
    }
    return series;
}
