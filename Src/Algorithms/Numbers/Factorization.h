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

#ifndef FACTORIZATION_H
#define FACTORIZATION_H

#include "DefaultHeaders.h"

ULLI
NaiveGCD(LLI numOne, LLI numTwo);

ULLI
EuclideanGCDRecursive(LLI numOne, LLI numTwo);

ULLI
EuclideanGCDIterative(LLI numOne, LLI numTwo);

ULLI
GCD(LLI numOne, LLI numTwo);

LLI
LCM(LLI numOne, LLI numTwo);

std::vector< std::pair<ULLI, ULLI> >
PrimeFactorization(LLI number);

std::vector< ULLI >
SieveOfEratosthenes(LLI number);

bool
IsPrimeNaive(LLI number);

bool
IsPrime(LLI number);

#endif //FACTORIZATION_H
