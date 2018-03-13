/**
 *      Created on: 06 March 2018
 *   Last modified: 13 March 2018
 *          Author: Sona Praneeth Akula
 *         Details: Code for algorithms related to factorization of numbers
 */

#include "Factorization.h"

/*!
 * @ingroup Factors
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
 * @ingroup Factors
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
 * @ingroup Factors
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
 * @ingroup Factors
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
 * @ingroup Factors
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

/*!
 * @ingroup Prime
 * @brief   Calculates prime factorization of a number
 * @details Example: 100 = 2<sup>2</sup> x 5<sup>2</sup>
 *
 * @param [in] [long long int] number - Number whose prime factorization is required
 * @return [out] [vector<pair<unsigned long long int, unsigned long long int>>] - List containing a pair of numbers where
 *          the first number in the pair is the prime factor and the second number in the pair is power of the prime
 *          factor. <br/> Example: 25 = 5<sup>2</sup>. Now the function will return [(5, 2)]
 */
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

/*!
 * @todo Complete the implementation of the function SieveOfErastosthenes
 * @ingroup Prime
 * @brief   Gets all the prime numbers lesser than or equal to the specified number
 * @details
 *
 * @param  [in] [long long int] number
 * @return [out] [vector<unsinged long long int>] - Vector of primes less than or equal to the given number
 */
std::vector< ULLI >
SieveOfEratosthenes(LLI number)
{

}

/*!
 * @ingroup Prime
 * @brief   Naive algorithm to determine if a number is prime
 * @details <b>Time Complexity</b>: O(N)
 *
 * @param  [in] [long long int] number - Number which should be tested for primality
 * @return [out] [bool] - <i>true</i> if number is prime else <i>false</i>
 */
bool
IsPrimeNaive(LLI number)
{
    if(number <= 1) { return false; }
    for(LLI divisor = 2; divisor < number; divisor++)
    {
        if(number%divisor == 0) { return false; }
    }
    return true;
}

/*!
 * @ingroup Prime
 * @brief   Best algorithm to determine if a number is prime
 * @details <b>Time Complexity</b>: O(\sqrt(N))
 *
 * @param  [in] [long long int] number - Number which should be tested for primality
 * @return [out] [bool] - <i>true</i> if number is prime else <i>false</i>
 */
bool
IsPrime(LLI number)
{
    if (number == 0 || number == 1)
    {
        return true;
    }
    else if (number == 2 || number == 3)
    {
        return true;
    }
    for(LLI divisor = 2; divisor <= sqrt(number); divisor++)
    {
        if(number%divisor == 0)
        {
            return false;
        }
    }
    return true;
}

