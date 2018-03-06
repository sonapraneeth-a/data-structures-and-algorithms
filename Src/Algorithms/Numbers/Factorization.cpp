/*!
 * \addtogroup Numbers
 * \ingroup Numbers
 */

/**
 *      Created on: 06 March 2018
 *   Last modified: 06 March 2018
 *          Author: Sona Praneeth Akula
 *         Details: Code for algorithms related to factorization of numbers
 */

#include "Factorization.h"

unsigned int
NaiveGCD(int numOne, int numTwo)
{
    // Negativity of a number doesnot affect the final result
    // gcd(-a, -b) = gcd(-a, b) = gcd(a, -b) = gcd(a, b)
    if(numOne < 0) { numOne = -numOne; }
    if(numTwo < 0) { numTwo = -numTwo; }
    unsigned int greater = (numOne >= numTwo)?(unsigned int)numOne:(unsigned int)numTwo;
    unsigned int lesser  = (numOne < numTwo) ?(unsigned int)numOne:(unsigned int)numTwo;
    // gcd(a, a) = a;
    if(greater == lesser) { return lesser; }
    // gcd(a, 0) = gcd(0, a) = a;
    if(lesser == 0) { return greater; }
    unsigned int gcd = 1;
    for(unsigned int divisor = 2; divisor <= lesser; divisor++)
    {
        if (greater%divisor == 0 && lesser%divisor==0)
        {
            gcd = divisor;
        }
    }
    return gcd;
}

unsigned int
EuclideanGCD(int numOne, int numTwo)
{
    // Negativity of a number doesnot affect the final result
    // gcd(-a, -b) = gcd(-a, b) = gcd(a, -b) = gcd(a, b)
    if (numOne < 0) { numOne = -numOne; }
    if (numTwo < 0) { numTwo = -numTwo; }
    unsigned int greater = (numOne >= numTwo) ? (unsigned int) numOne : (unsigned int) numTwo;
    unsigned int lesser = (numOne < numTwo) ? (unsigned int) numOne : (unsigned int) numTwo;
    // gcd(a, a) = a;
    if(greater == lesser) { return lesser; }
    // gcd(a, 0) = gcd(0, a) = a;
    if(lesser == 0) { return greater; }
    return EuclideanGCD(greater%lesser, lesser);
}