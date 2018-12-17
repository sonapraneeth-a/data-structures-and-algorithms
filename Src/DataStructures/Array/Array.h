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

    /**
     * @brief   Prints the contents of the array to the ostream operator
     * @details
     *
     * @tparam  T Generic parameter
     * @param   [std::ostream] os - Ostream operator to which contents of the array have
     *                        to be printed
     * @param   [Array<T>&] array - Array which has to be printed
     * @return  [std::ostream] os - Ostream operator with the array contents
     */
    template<typename T>
    std::ostream &operator<<(std::ostream &os, const Array<T> &array)
    {
        for (size_t __index = 0; __index < array.Size(); ++__index)
        {
            if (__index != array.Size() - 1)
            {
                os << array.Get(__index) << ", ";
            }
            else
            {
                os << array.Get(__index);// << "\n";
            }
        }
        return os;
    }

}

#include "Array.cpp"

#endif // ARRAY_H
