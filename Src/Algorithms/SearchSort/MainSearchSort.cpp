//
// Created by pranas on 5/6/2018.
//

#include "DefaultHeaders.h"
#include "Search.h"
#include "Sort.h"

void RunLinearSearch()
{
    int array[] = {5, 4, 3, 2, 1};
    std::cout << LinearSearch(array, 0, 5, 4) << "\n";
}

void RunBinarySearch()
{
    int array[] = {1, 2, 3, 4, 5};
    std::cout << BinarySearchIterative(array, 0, 5, 4) << "\n";
    std::cout << BinarySearchRecursive(array, 0, 5, 4) << "\n";
}

void RunBubbleSort()
{
    int array_one[5] = {5, 4, 3, 2, 1};
    int array_two[5] = {1, 2, 3, 4, 5};
    /*std::cout << "Before sorting(1): "; PrintOneDArray(array_one);
    BubbleSort(array_one);
    std::cout << " After sorting(1): "; PrintOneDArray(array_one);*/
    std::cout << "Before sorting(2): "; PrintOneDArray(array_two);
    BubbleSort(array_two, 2, -1, &GreaterComparator);
    std::cout << " After sorting(2): "; PrintOneDArray(array_two);
}

void RunInsertionSort()
{
    int array_one[5] = {5, 4, 3, 2, 1};
    int array_two[5] = {5, 4, 3, 2, 1};
    std::cout << "Before sorting(1): "; PrintOneDArray(array_one);
    InsertionSort(array_one);
    std::cout << " After sorting(1): "; PrintOneDArray(array_one);
}

void RunSort()
{
    RunBubbleSort();
    //RunInsertionSort();
}

int main()
{
    //RunLinearSearch();
    //RunBinarySearch();
    RunSort();
    return 0;
}