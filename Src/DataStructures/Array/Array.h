/**
 * File description
 *
 *        Filename: Array.h
 *      Created on: 13 December 2018
 *   Last modified: 14 December 2018
 *         Authors: sonapraneeth-a
 *         Details: File for function signatures of static array class
 */

/**
 * Changelog
 *
 * Date (DD-MM-YYYY)            Author               Update
 * 13-12-2018               sonapraneeth-a      - Creation of the file
 *                                              - Added function signatures for
 *                                                Static Array constructors and
 *                                                destructors
 * 14-12-2018               sonapraneeth-a      - Added implementation for << operator
 *                                              - Fixed code to follow Coding guidelines
 *                                              - Added variable MIN_ARRAY_CAPACITY
 */

#ifndef ARRAY_H
#define ARRAY_H

#include "IArray.h"

namespace DS
{
    /*! @class Array
     *  @brief A Static Array class.
     *
     *  @details This is a Static Array class. Static Array means that the size of
     *           the array cannot be changed once declared
     */
    template<typename T>
    class Array : public DS::IArray<T>
    {

    public:

        // Reference: https://www.geeksforgeeks.org/g-fact-93/
        explicit Array();
        explicit Array(size_t capacity);
        explicit Array(size_t capacity, T defaultValue);

        void Insert(size_t index, T value);
        void Remove(size_t index);

        ~Array();

    private:

        const size_t MIN_ARRAY_CAPACITY = 10;

    };

}

#include "Array.cpp"

#endif // ARRAY_H
