/*!
 * \defgroup Numbers
 * \addtogroup Numbers
 * \ingroup Numbers
 */

/**
 *      Created on: 06 March 2018
 *   Last modified: 06 March 2018
 *          Author: Sona Praneeth Akula
 *         Details: Code for fibonacci numbers
 */

#include "Fibonacci.h"

/*!
 * @brief   Get the nth fibonacci number
 * @details Recursive approach to get nth fibonacci number
 *
 * @param  [in] index - index of fibonacci number
 * @return [out] [int] - index th fibonacci number
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
 * @brief   Get the nth fibonacci number
 * @details Iterative approach to get nth fibonacci number
 *
 * @param  [in] index - index of fibonacci number
 * @return [out] [int] - index th fibonacci number
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
        unsigned long long int fn = 0;     // F(n)
        unsigned long long int fn_2 = 0;   // F(n-2)
        unsigned long long int fn_1 = 1;   // F(n-1)
        for(unsigned int i = index; i <= index; i++)
        {
            fn = fn_1 + fn_2; // Recursive relation: F(n) = F(n-1) + F(n-2)
            fn_2 = fn_1;
            fn_1 = fn;
        }
        return fn;
    }
}