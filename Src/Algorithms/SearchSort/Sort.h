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

template <typename T>
void BubbleSort(T Array[], LLI start, LLI end)
{
    for (LLI loop = start; loop < end; ++loop)
    {
        bool sorted = true;
        for (LLI index = start; index < end-1; ++index)
        {
            if(Array[index] > Array[index+1])
            {
                /*T temp = Array[index+1];
                Array[index] = Array[index+1];
                Array[index+1] = temp;*/
                Swap(Array[index], Array[index+1]);
                sorted = false;
            }
        }
        if(sorted) {break;}
    }
}

template <typename T>
void InsertionSort(T Array[], LLI start, LLI end)
{
    for (LLI to_swap = start; to_swap < end; ++to_swap)
    {
        T minimum = Array[to_swap];
        T minimum_index = to_swap;
        for (LLI index = to_swap+1; index < end; ++index)
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
void QuickSort(T Array[], LLI start, LLI end)
{

}

template <typename T>
void MergeSort(T Array[], LLI start, LLI end)
{

}

#endif //SORT_H
