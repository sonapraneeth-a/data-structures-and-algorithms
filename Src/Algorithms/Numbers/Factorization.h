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


unsigned int
NaiveGCD(int numOne, int numTwo);

unsigned int
EuclideanGCD(int numOne, int numTwo);

int
LCM(int numOne, int numTwo);

bool
IsPrime(int number);

#endif //FACTORIZATION_H
