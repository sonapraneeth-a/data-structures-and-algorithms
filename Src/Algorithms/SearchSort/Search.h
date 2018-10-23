/**
 *      Created on: 06 March 2018
 *   Last modified: 24 August 2018
 *          Author: Sona Praneeth Akula
 *         Details: Header for algorithms related to searching array
 */

/**
 * Changelog
 *
 * Date (DD-MM-YYYY)            Author               Update
 * 06-03-2018             Sona Praneeth Akula   - Creation of the file
 * 06-05-2018             Sona Praneeth Akula   - Added function signatures for search algorithms
 *                                                linear and binary(iterative and recursive both)
 * 08-07-2018             Sona Praneeth Akula   - Moved implementations from .cpp file to .h file
 * 23-08-2018             Sona Praneeth Akula   - Updated some comments
 * 24-08-2018             Sona Praneeth Akula   - Updated some comments according to coding guidelines
 *                                                document
 */

#ifndef SEARCH_H
#define SEARCH_H

#include "DefaultHeaders.h"

/**
 * @brief  Searches for an element in the array in a linear fashion
 * @details <b>Time Complexity:</b> O(N), where N is the length of the array
 *          to be searched for<br/>
 *          <b>Space Complexity:</b> O(1)
 *
 * @tparam T
 * @param [T] array - array in which the element has to be searched for
 * @param [T] element - Element to be searched in the array
 * @param [LLI - long long int] startIndex - From where to start searching in the array
 * @param [LLI- long long int] endIndex - Where to terminate the search
 * @return [LLI - long long int] index of the element in the array (0 indexing),
 *                                -1 if the element is not found in the array
 */
template <typename T, ULLI N>
LLI LinearSearch(T (&array)[N], T element, LLI startIndex = 0, LLI endIndex = -1)
{
    ULLI __LengthOfArray = SizeOfArray(array);
    if (__LengthOfArray == 0)
    {
        throw OutOfBoundsException();
    }
    if (endIndex == -1)
    {
        endIndex = (LLI)__LengthOfArray;
    }
    if (!(startIndex >= 0 && startIndex <= __LengthOfArray))
    {
        throw OutOfBoundsException();
    }
    if (!(endIndex >= 0 && endIndex <= __LengthOfArray))
    {
        throw OutOfBoundsException();
    }
    if (startIndex > endIndex)
    {
        throw OutOfBoundsException();
    }
    // Loop through all elements in the array
    for (LLI index = startIndex; index < endIndex; ++index)
    {
        // Return the index if the element is found
        if(array[index] == element)
        {
            return index;
        }
    }
    return -1;
}

/**
 * @brief  Searches for an element in the array in binary search iterative version
 * @details <b>Time Complexity:</b> O(log N), where N is the length of the array
 *          to be searched for<br/>
 *          <b>Space Complexity:</b> O(1)
 *
 * @tparam T
 * @param [T] array - array in which the element has to be searched for
 * @param [T] element - Element to be searched in the array
 * @param [LLI - long long int] startIndex - From where to start searching in the array
 * @param [LLI- long long int] endIndex - Where to terminate the search
 * @return [LLI - long long int] index of the element in the array (0 indexing),
 *                                -1 if the element is not found in the array
 */
template <typename T, ULLI N>
LLI BinarySearchIterative(T (&array)[N], T element, LLI startIndex = 0, LLI endIndex = -1)
{
    ULLI __LengthOfArray = SizeOfArray(array);
    if (endIndex == -1)
    {
        endIndex = (LLI)__LengthOfArray;
    }
    if (!(startIndex >= 0 && startIndex <= __LengthOfArray))
    {
        throw OutOfBoundsException();
    }
    if (!(endIndex >= 0 && endIndex <= __LengthOfArray))
    {
        throw OutOfBoundsException();
    }
    if (startIndex > endIndex)
    {
        throw OutOfBoundsException();
    }
    // Loop until we either find the element we are looking for (or) we are sure that the
    // element we are looking for is not there in the array
    while (true)
    {
        // Get the index of the element in the middle of the array
        LLI __MiddleIndex = startIndex + (endIndex - startIndex)/2;
        // If the element required to be searched in the middle of the array
        // return the index
        if(array[__MiddleIndex] == element)
        {
            return __MiddleIndex;
        }
        else if(startIndex > endIndex)
        {
            break;
        }
            // If the element we are looking for is greater than the middle element of the array, then
            // start searching in the right part of the array
        else if(array[__MiddleIndex] < element)
        {
            startIndex = __MiddleIndex + 1;
        }
            // If the element we are looking for is lesser than the middle element of the array, then
            // start searching in the left part of the array
        else
        {
            endIndex = __MiddleIndex - 1;
        }
    }
    // If the lower index and higher index of the array have crossed each other and element
    // is still not found, then return -1
    return -1;
}

/**
 * @brief  Searches for an element in the array in binary search recursive version
 * @details <b>Time Complexity:</b> O(log N), where N is the length of the array
 *          to be searched for<br/>
 *          <b>Space Complexity:</b> O(1)
 *
 * @tparam T
 * @param [T] array - array in which the element has to be searched for
 * @param [T] element - Element to be searched in the array
 * @param [LLI - long long int] startIndex - From where to start searching in the array
 * @param [LLI- long long int] endIndex - Where to terminate the search
 * @return [LLI - long long int] index of the element in the array (0 indexing),
 *                                -1 if the element is not found in the array
 */
template <typename T, ULLI N>
LLI BinarySearchRecursive(T (&array)[N], T element, LLI startIndex = 0, LLI endIndex = -1)
{
    ULLI __LengthOfArray = SizeOfArray(array);
    // std::cout << "Length of array: " << __LengthOfArray << "\n";
    if (endIndex == -1)
    {
        endIndex = (LLI)__LengthOfArray;
    }
    if (!(startIndex >= 0 && startIndex <= __LengthOfArray))
    {
        throw OutOfBoundsException();
    }
    if (!(endIndex >= 0 && endIndex <= __LengthOfArray))
    {
        throw OutOfBoundsException();
    }
    if (startIndex > endIndex)
    {
        throw OutOfBoundsException();
    }
    // Get the index of the element in the middle of the array
    LLI __MiddleIndex = startIndex + (endIndex - startIndex)/2;
    // If the element required to be searched in the middle of the array
    // return the index
    if(array[__MiddleIndex] == element)
    {
        return __MiddleIndex;
    }
        // If the lower index and higher index of the array have crossed each other and element
        // is still not found, then return -1
    else if(startIndex > endIndex)
    {
        return -1;
    }
        // If the element we are looking for is greater than the middle element of the array, then
        // start searching in the right part of the array
    else if(array[__MiddleIndex] < element)
    {
        BinarySearchRecursive(array, element, __MiddleIndex + 1, endIndex);
    }
        // If the element we are looking for is lesser than the middle element of the array, then
        // start searching in the left part of the array
    else
    {
        BinarySearchRecursive(array, element, startIndex, __MiddleIndex - 1);
    }
}

#endif //SEARCH_H
