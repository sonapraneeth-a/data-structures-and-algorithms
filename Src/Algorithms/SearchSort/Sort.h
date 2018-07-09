/**
 *      Created on: 06 March 2018
 *   Last modified: 06 May 2018
 *          Author: Sona Praneeth Akula
 *         Details: Header for algorithms related to sorting array
 */

/**
 * Changelog
 *
 * Date (DD-MM-YYYY)            Author               Update
 * 06-03-2018             Sona Praneeth Akula   - Creation of the file
 * 06-05-2018             Sona Praneeth Akula   - Added function signatures/implementations for
 *                                                sorting algorithms
 */

#ifndef SORT_H
#define SORT_H

#include "DefaultHeaders.h"

// https://www.youtube.com/watch?v=67vTjgbT56Q
template <typename T, size_t N>
void BubbleSort(T (&Array)[N], LLI startIndex = 0, LLI endIndex = -1,
                bool (*CompFunction)(T&, T&) = &LesserComparator)
{
    ULLI lengthOfArray = SizeOfArray(Array);
    // std::cout << "Length of array: " << lengthOfArray << "\n";
    if (endIndex == -1)
    {
        endIndex = (LLI)lengthOfArray;
    }
    if (!(startIndex >= 0 && startIndex <= lengthOfArray))
    {
        throw OutOfBoundsException();
    }
    if (!(endIndex >= 0 && endIndex <= lengthOfArray))
    {
        throw OutOfBoundsException();
    }
    if (startIndex > endIndex)
    {
        throw OutOfBoundsException();
    }
    // std::cout << "StartIndex: " << startIndex << "\n";
    // std::cout << "EndIndex: " << endIndex << "\n";
    for (LLI loop = startIndex; loop < endIndex; ++loop)
    {
        // std::cout << "Loop index: " << loop << "\n";
        // std::cout << "Array before: "; PrintOneDArray(Array);
        bool sorted = true;
        for (LLI index = startIndex; index < endIndex-loop-1; ++index)
        {
            // std::cout << "Index: " << index << "\n";
            // std::cout << "Elements: " << Array[index] << ", " << Array[index+1] << "\n";
            // std::cout << "Comparison: " << CompFunction(Array[index] , Array[index+1]) << "\n";
            if(!CompFunction(Array[index] , Array[index+1]))
            {
                /*T temp = Array[index+1];
                Array[index] = Array[index+1];
                Array[index+1] = temp;*/
                Swap(Array[index], Array[index+1]);
                sorted = false;
            }
            // std::cout << "Array: "; PrintOneDArray(Array);
        }
        // std::cout << "Array after: "; PrintOneDArray(Array);
        if(sorted) {break;}
    }
}

template <typename T, size_t N>
void InsertionSort(T (&Array)[N], bool (*CompFunction)(T&, T&) = &LesserComparator,
                    LLI startIndex = 0, LLI endIndex = -1)
{
    ULLI lengthOfArray = SizeOfArray(Array);
    // std::cout << "Length of array: " << lengthOfArray << "\n";
    if (endIndex == -1)
    {
        endIndex = lengthOfArray;
    }
    if (!(startIndex >= 0 && startIndex <= lengthOfArray))
    {
        throw OutOfBoundsException();
    }
    if (!(endIndex >= 0 && endIndex <= lengthOfArray))
    {
        throw OutOfBoundsException();
    }
    if (startIndex > endIndex)
    {
        throw OutOfBoundsException();
    }
    for (LLI to_swap = startIndex; to_swap < endIndex; ++to_swap)
    {
        T minimum = Array[to_swap];
        T minimum_index = to_swap;
        for (LLI index = to_swap+1; index < endIndex; ++index)
        {
            if(Array[index] < minimum)
            {
                minimum = Array[index];
                minimum_index = index;
            }
        }
        Swap(Array[to_swap], Array[minimum_index]);
    }
}

template <typename T>
void QuickSort(T Array[], LLI startIndex, LLI endIndex)
{

}

template <typename T>
void MergeSort(T Array[], LLI start, LLI end)
{

}

#endif //SORT_H
