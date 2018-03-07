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

/*!
 * @brief   Calculates GCD of two numbers
 * @details Naive brute force algorithm for calculating GCD of two numbers
 *          <b>Time Complexity: </b> O(N)
 *
 * @param  [in] [long long int] numOne - First number
 * @param  [in] [long long int] numTwo - Second number
 * @return [out] [unsgined long long int] GCD of the two numbers
 */
ULLI
NaiveGCD(LLI numOne, LLI numTwo)
{
    // Negativity of a number doesnot affect the final result
    // gcd(-a, -b) = gcd(-a, b) = gcd(a, -b) = gcd(a, b)
    if(numOne < 0) { numOne = -numOne; }
    if(numTwo < 0) { numTwo = -numTwo; }
    ULLI greater = (numOne >= numTwo)?(ULLI)numOne:(ULLI)numTwo;
    ULLI lesser  = (numOne < numTwo) ?(ULLI)numOne:(ULLI)numTwo;
    // gcd(a, a) = a;
    if(greater == lesser) { return lesser; }
    // gcd(a, 0) = gcd(0, a) = a;
    if(lesser == 0) { return greater; }
    ULLI gcd = 1;
    for(ULLI divisor = 2; divisor <= lesser; divisor++)
    {
        if (greater%divisor == 0 && lesser%divisor==0)
        {
            gcd = divisor;
        }
    }
    return gcd;
}

/*!
 * @brief   Calculates GCD of two numbers
 * @details Recursive Euclidean algorithm for calculating GCD of two numbers
 *          <b>Time Complexity: </b> O(log N)
 *
 * @param  [in] [long long int] numOne - First number
 * @param  [in] [long long int] numTwo - Second number
 * @return [out] [unsgined long long int] GCD of the two numbers
 */
ULLI
EuclideanGCDRecursive(LLI numOne, LLI numTwo)
{
    // Negativity of a number doesnot affect the final result
    // gcd(-a, -b) = gcd(-a, b) = gcd(a, -b) = gcd(a, b)
    if (numOne < 0) { numOne = -numOne; }
    if (numTwo < 0) { numTwo = -numTwo; }
    ULLI greater = (numOne >= numTwo) ? (ULLI) numOne : (ULLI) numTwo;
    ULLI lesser = (numOne < numTwo) ? (ULLI) numOne : (ULLI) numTwo;
    // gcd(a, a) = a;
    if(greater == lesser) { return lesser; }
    // gcd(a, 0) = gcd(0, a) = a;
    if(lesser == 0) { return greater; }
    return EuclideanGCDRecursive(lesser, greater % lesser);
}

/*!
 * @brief   Calculates GCD of two numbers
 * @details Iterative algorithm for calculating GCD of two numbers
 *          <b>Time Complexity: </b> O(log N)
 *
 * @param  [in] [long long int] numOne - First number
 * @param  [in] [long long int] numTwo - Second number
 * @return [out] [unsgined long long int] GCD of the two numbers
 */
ULLI
EuclideanGCDIterative(LLI numOne, LLI numTwo)
{
    // Negativity of a number doesnot affect the final result
    // gcd(-a, -b) = gcd(-a, b) = gcd(a, -b) = gcd(a, b)
    if (numOne < 0) { numOne = -numOne; }
    if (numTwo < 0) { numTwo = -numTwo; }
    ULLI greater = (numOne >= numTwo) ? (ULLI) numOne : (ULLI) numTwo;
    ULLI lesser = (numOne < numTwo) ? (ULLI) numOne : (ULLI) numTwo;
    // gcd(a, a) = a;
    if(greater == lesser) { return lesser; }
    // gcd(a, 0) = gcd(0, a) = a;
    if(lesser == 0) { return greater; }
    ULLI remainder = 0;
    while(lesser != 0)
    {
        remainder = greater % lesser;
        greater = lesser;
        lesser = remainder;
    }
    return greater;
}

/*!
 * @brief   Calculates GCD of two numbers
 * @details Best performance algorithm for calculating GCD of two numbers
 *          <b>Time Complexity: </b> O(log N)
 *
 * @param  [in] [long long int] numOne - First number
 * @param  [in] [long long int] numTwo - Second number
 * @return [out] [unsgined long long int] GCD of the two numbers
 */
ULLI
GCD(LLI numOne, LLI numTwo)
{
    return EuclideanGCDIterative(numOne, numTwo);
}

/*!
 * @brief   Calculates LCM of two numbers
 * @details Best performance algorithm for calculating LCM of two numbers
 *          <b>Time Complexity: </b> O(log N)
 *
 * @param  [in] [long long int] numOne - First number
 * @param  [in] [long long int] numTwo - Second number
 * @return [out] [long long int] LCM of the two numbers
 */
LLI
LCM(LLI numOne, LLI numTwo)
{
    ULLI gcd = GCD(numOne, numTwo);
    ULLI greater = (numOne >= numTwo) ? (ULLI) numOne : (ULLI) numTwo;
    ULLI lesser = (numOne < numTwo) ? (ULLI) numOne : (ULLI) numTwo;
    LLI multiplier = (LLI)greater/gcd;
    LLI answer = lesser * multiplier;
    return answer;
}

std::vector< std::pair<ULLI, ULLI> >
PrimeFactorization(LLI number)
{
    std::vector< std::pair<ULLI, ULLI> > PrimeFactors;
    ULLI factor = 2, count = 0;
    while(factor <= sqrt(number))
    {
        while(number%factor == 0)
        {
            number = number/factor;
            count++;
        }
        if(count > 0) { PrimeFactors.emplace_back(factor, count); }
        if(factor == 2) {factor++;}
        else {factor+=2;}
        count = 0;
    }
    if(number > 1) {PrimeFactors.emplace_back(number, 1);}
    return PrimeFactors;
}