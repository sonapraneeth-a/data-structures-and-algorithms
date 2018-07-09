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
    int array_01[5] = {5, 4, 3, 2, 1};
    int array_02[5] = {1, 2, 3, 4, 5};
    int array_03[2] = {2, 1};
    int array_05[5] = {2, 1, 4, 3, 5};
    std::cout << "Before sorting(1): "; PrintOneDArray(array_01);
    BubbleSort(array_01);
    std::cout << " After sorting(1): "; PrintOneDArray(array_01);
    std::cout << "Before sorting(2): "; PrintOneDArray(array_02);
    BubbleSort(array_02, 2, -1, &GreaterComparator);
    std::cout << " After sorting(2): "; PrintOneDArray(array_02);
    std::cout << "Before sorting(3): "; PrintOneDArray(array_03);
    BubbleSort(array_03);
    std::cout << " After sorting(3): "; PrintOneDArray(array_03);
    std::cout << "Before sorting(3): "; PrintOneDArray(array_05);
    BubbleSort(array_05);
    std::cout << " After sorting(3): "; PrintOneDArray(array_05);
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