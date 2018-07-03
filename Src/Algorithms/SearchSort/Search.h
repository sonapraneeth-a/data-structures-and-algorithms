/**
 *      Created on: 06 March 2018
 *   Last modified: 06 May 2018
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
 */

#ifndef SEARCH_H
#define SEARCH_H

#include "DefaultHeaders.h"

/**
 * @brief  Searches for an element in the array in linear fashion
 * @details <b>Time Complexity:</b> O(N), where N is the elements to be searched for
 *
 * @tparam T
 * @param [T] Array - Array in which the element has to be searched for
 * @param [T] element - Element to be searched in the array
 * @param [LLI - long long int] startIndex - From where to start searching in the array
 * @param [LLI- long long int] endIndex - Where to terminate the search
 * @return [LLI - long long int] index of the element in the array (0 indexing),
 *                                -1 if the element is not found in the array
 */
template <typename T>
LLI LinearSearch(T Array[], T element, LLI startIndex, LLI endIndex)
{
    // Loop through all elements in the array
    for (LLI index = startIndex; index < endIndex; ++index)
    {
        // Return the index if the element is found
        if(Array[index] == element)
        {
            return index;
        }
    }
    return -1;
}

/**
 * @brief  Searches for an element in the array in binary search iterative version
 * @details <b>Time Complexity:</b> O(log N), where N is the elements to be searched for
 *
 * @tparam T
 * @param [T] Array - Array in which the element has to be searched for
 * @param [T] element - Element to be searched in the array
 * @param [LLI - long long int] startIndex - From where to start searching in the array
 * @param [LLI- long long int] endIndex - Where to terminate the search
 * @return [LLI - long long int] index of the element in the array (0 indexing),
 *                                -1 if the element is not found in the array
 */
template <typename T>
LLI BinarySearchIterative(T Array[], T element, LLI startIndex, LLI endIndex)
{
    // Loop until we either find the element we are looking for (or) we are sure that the
    // element we are looking for is not there in the array
    while (true)
    {
        // Get the index of the element in the middle of the array
        LLI middleIndex = startIndex + (endIndex - startIndex)/2;
        // If the element required to be searched in the middle of the array
        // return the index
        if(Array[middleIndex] == element)
        {
            return middleIndex;
        }
        else if(startIndex > endIndex)
        {
            break;
        }
        // If the element we are looking for is greater than the middle element of the array, then
        // start searching in the right part of the array
        else if(Array[middleIndex] < element)
        {
            startIndex = middleIndex + 1;
        }
        // If the element we are looking for is lesser than the middle element of the array, then
        // start searching in the left part of the array
        else
        {
            endIndex = middleIndex - 1;
        }
    }
    // If the lower index and higher index of the array have crossed each other and element
    // is still not found, then return -1
    return -1;
}

/**
 * @brief  Searches for an element in the array in binary search recursive version
 * @details <b>Time Complexity:</b> O(log N), where N is the elements to be searched for
 *
 * @tparam T
 * @param [T] Array - Array in which the element has to be searched for
 * @param [T] element - Element to be searched in the array
 * @param [LLI - long long int] startIndex - From where to start searching in the array
 * @param [LLI- long long int] endIndex - Where to terminate the search
 * @return [LLI - long long int] index of the element in the array (0 indexing),
 *                                -1 if the element is not found in the array
 */
template <typename T>
LLI BinarySearchRecursive(T Array[], T element, LLI startIndex, LLI endIndex)
{
    // Get the index of the element in the middle of the array
    LLI middleIndex = startIndex + (endIndex - startIndex)/2;
    // If the element required to be searched in the middle of the array
    // return the index
    if(Array[middleIndex] == element)
    {
        return middleIndex;
    }
    // If the lower index and higher index of the array have crossed each other and element
    // is still not found, then return -1
    else if(startIndex > endIndex)
    {
        return -1;
    }
    // If the element we are looking for is greater than the middle element of the array, then
    // start searching in the right part of the array
    else if(Array[middleIndex] < element)
    {
        BinarySearchRecursive(Array, middleIndex + 1, endIndex, element);
    }
    // If the element we are looking for is lesser than the middle element of the array, then
    // start searching in the left part of the array
    else
    {
        BinarySearchRecursive(Array, startIndex, middleIndex - 1, element);
    }
}



#endif //SEARCH_H
