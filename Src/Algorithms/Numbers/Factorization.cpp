/**
 *      Created on: 06 March 2018
 *   Last modified: 03 May 2018
 *          Author: Sona Praneeth Akula
 *         Details: Code for algorithms related to factorization of numbers
 */

/**
 * Changelog
 *
 * Date (DD-MM-YYYY)            Author               Update
 * 06-03-2018             Sona Praneeth Akula   - Creation of the file
 * 13-03-2018             Sona Praneeth Akula   - Updation of the documentation
 * 03-05-2018             Sona Praneeth Akula   - Updated time complexity of algorithms
 *                                              - Need to verify the time complexity of algorithms
 *                                                is correct or not
 */

#include "Factorization.h"


/*!
 * @todo Create test cases and check for the correctness of the algorithm
 * @todo Check what is N in the time complexity
 * @ingroup Factors
 * @brief   Calculates GCD of two numbers
 * @details Naive brute force algorithm for calculating GCD of two numbers
 *          <b>Time Complexity: </b> O(N), where N is the input number
 *
 * @param  [in] [long long int] numOne - First number
 * @param  [in] [long long int] numTwo - Second number
 * @return [out] [unsgined long long int] GCD of the two numbers
 */
ULLI
Math::NaiveGCD(LLI numOne, LLI numTwo)
{
    // Negativity of a number does not affect the final result
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
    // Loop through all the divisors until the smallest of the two numbers.
    // Smallest because any number greater than the smallest number does not divide
    // the smallest number
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
 * @todo Create test cases and check for the correctness of the algorithm
 * @todo Check what is N in the time complexity
 * @ingroup Factors
 * @brief   Calculates GCD of two numbers
 * @details Recursive Euclidean algorithm for calculating GCD of two numbers
 *          <b>Time Complexity: </b> O(log N), where N is the input number
 *
 * @param  [in] [long long int] numOne - First number
 * @param  [in] [long long int] numTwo - Second number
 * @return [out] [unsgined long long int] GCD of the two numbers
 */
ULLI
Math::EuclideanGCDRecursive(LLI numOne, LLI numTwo)
{
    // Negativity of a number does not affect the final result
    // gcd(-a, -b) = gcd(-a, b) = gcd(a, -b) = gcd(a, b)
    if (numOne < 0) { numOne = -numOne; }
    if (numTwo < 0) { numTwo = -numTwo; }
    ULLI greater = (numOne >= numTwo) ? (ULLI) numOne : (ULLI) numTwo;
    ULLI lesser = (numOne < numTwo) ? (ULLI) numOne : (ULLI) numTwo;
    // gcd(a, a) = a;
    if(greater == lesser) { return lesser; }
    // gcd(a, 0) = gcd(0, a) = a;
    if(lesser == 0) { return greater; }
    // gcd(a, b) = gcd(b, a%b) for a >= b
    return Math::EuclideanGCDRecursive(lesser, greater % lesser);
}

/*!
 * @todo Create test cases and check for the correctness of the algorithm
 * @todo Check what is N in the time complexity
 * @ingroup Factors
 * @brief   Calculates GCD of two numbers
 * @details Iterative algorithm for calculating GCD of two numbers
 *          <b>Time Complexity: </b> O(log N), where N is the input number
 *
 * @param  [in] [long long int] numOne - First number
 * @param  [in] [long long int] numTwo - Second number
 * @return [out] [unsgined long long int] GCD of the two numbers
 */
ULLI
Math::EuclideanGCDIterative(LLI numOne, LLI numTwo)
{
    // Negativity of a number does not affect the final result
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
        remainder = greater % lesser; // gcd(a, b) = gcd(b, a%b) for a >= b
        greater = lesser;
        lesser = remainder;
    }
    return greater;
}

/*!
 * @todo Check what is N in the time complexity
 * @ingroup Factors
 * @brief   Calculates GCD of two numbers
 * @details Best performance algorithm for calculating GCD of two numbers
 *          <b>Time Complexity: </b> O(log N), where N is the input number
 *
 * @param  [in] [long long int] numOne - First number
 * @param  [in] [long long int] numTwo - Second number
 * @return [out] [unsgined long long int] GCD of the two numbers
 */
ULLI
Math::GCD(LLI numOne, LLI numTwo)
{
    // Best algorithm in terms of CPU time and asymptotic time complexity
    return Math::EuclideanGCDIterative(numOne, numTwo);
}

/*!
 * @todo Create test cases and check for the correctness of the algorithm
 * @todo Check what is N in the time complexity
 * @ingroup Factors
 * @brief   Calculates LCM of two numbers
 * @details Best performance algorithm for calculating LCM of two numbers
 *          <b>Time Complexity: </b> O(log N), where N is the input number
 *
 * @param  [in] [long long int] numOne - First number
 * @param  [in] [long long int] numTwo - Second number
 * @return [out] [long long int] LCM of the two numbers
 */
LLI
Math::LCM(LLI numOne, LLI numTwo)
{
    // Use the best algorithm to calculate GCD
    ULLI gcd = Math::GCD(numOne, numTwo);
    ULLI greater = (numOne >= numTwo) ? (ULLI) numOne : (ULLI) numTwo;
    ULLI lesser = (numOne < numTwo) ? (ULLI) numOne : (ULLI) numTwo;
    // Lemma: GCD x LCM = numOne * numTwo
    LLI multiplier = (LLI)greater/gcd;
    LLI answer = lesser * multiplier;
    return answer;
}

/*!
 * @todo Find the link which detailed about this (emplace_back better than push_back for constructors)
 * @todo Create test cases and check for the correctness of the algorithm
 * @todo Verify the time complexity of the algorithm
 * @ingroup Prime
 * @brief   Calculates prime factorization of a number
 * @details Example: 100 = 2<sup>2</sup> x 5<sup>2</sup>
 *          <b>Time Complexity: <b> O(&radic; N)
 *
 * @param [in] [long long int] number - Number whose prime factorization is required
 * @return [out] [vector<pair<unsigned long long int, unsigned long long int>>] - List containing a pair of numbers where
 *          the first number in the pair is the prime factor and the second number in the pair is power of the prime
 *          factor. <br/> Example: 25 = 5<sup>2</sup>. Now the function will return [(5, 2)]
 */
std::vector< std::pair<ULLI, ULLI> >
Math::PrimeFactorization(LLI number)
{
    std::vector< std::pair<ULLI, ULLI> > PrimeFactors;
    ULLI factor = 2, count = 0;
    // Start with the first prime number ie., 2
    while(factor <= sqrt(number))
    {
        // Find to what power of the factor is the number divisible?
        // ie., number % ((factor)^(count)) == 0
        while(number%factor == 0)
        {
            number = number/factor;
            count++;
        }
        // emplace_back better than push_back for constructors
        // @todo Find the link which detailed about this
        if(count > 0) { PrimeFactors.emplace_back(factor, count); }
        if(factor == 2) {factor++;}
        else {factor += 2;} // Even numbers are not prime by default
        count = 0;
    }
    // If still number is greater than 1, then the number itself is a prime number
    // Hence push it with power 1
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
std::vector<ULLI>
Math::SieveOfEratosthenes(ULLI number)
{
    // Reference URL: https://drive.google.com/file/d/0B-W-TWxgtybGYWFWZHB5MDMyU3c/view
    std::vector<ULLI> primes;
    // isPrime vector starts from 2 in number series
    std::vector<bool> isPrime(number-1, true);
    isPrime[0] = false;
    isPrime[1] = false;
    for (ULLI index = 2; index <= number; ++index)
    {
        if(isPrime[index])
        {
            std::cout << index << "," << primes.size() << "\n";
            primes.push_back(index);
        }
        for (ULLI loop_index = index*index; loop_index <= number; loop_index+=index)
        {
            isPrime[loop_index] = false;
        }
    }
    return primes;
}

/*!
 * @todo Create test cases and check for the correctness of the algorithm
 * @ingroup Prime
 * @brief   Naive algorithm to determine if a number is prime
 * @details <b>Time Complexity</b>: O(N), where N is the input number
 *
 * @param  [in] [long long int] number - Number which should be tested for primality
 * @return [out] [bool] - <i>true</i> if number is prime else <i>false</i>
 */
bool
Math::IsPrimeNaive(ULLI number)
{
    if(number <= 1) { return false; }
    // Loop through all divisors until the number to check if the number
    // is divisible by any divisor. If divisible, it is not a prime number
    for(LLI divisor = 2; divisor < number; divisor++)
    {
        if(number%divisor == 0) { return false; }
    }
    return true;
}

/*!
 * @todo See if any link on this (Looping through \sqrt(number) is sufficient for prime number testing) can be obtained
 * @todo Create test cases and check for the correctness of the algorithm
 * @ingroup Prime
 * @brief   Best algorithm to determine if a number is prime
 * @details <b>Time Complexity</b>: O(&radic; N)
 *
 * @param  [in] [long long int] number - Number which should be tested for primality
 * @return [out] [bool] - <i>true</i> if number is prime else <i>false</i>
 */
bool
Math::IsPrime(ULLI number)
{
    if (number == 0 || number == 1)
    {
        return true;
    }
    else if (number == 2 || number == 3)
    {
        return true;
    }
    // Looping through \sqrt(number) is sufficient for prime number testing
    // @todo See if any link on this can be obtained
    for(LLI divisor = 2; divisor <= sqrt(number); divisor++)
    {
        if(number%divisor == 0)
        {
            return false;
        }
    }
    return true;
}

