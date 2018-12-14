/**
 * File description
 *
 *        Filename: MainArray.cpp
 *      Created on: 13 December 2018
 *   Last modified: 13 December 2018
 *         Authors: sonapraneeth-a
 *         Details: File for main executable of the project - array
 */

/**
 * Changelog
 *
 * Date (DD-MM-YYYY)            Author               Update
 * 13-12-2018               sonapraneeth-a      - Creation of the file
 * 14-12-2018               sonapraneeth-a      - Added code for RunArray_Constructors()
 */


#include "DefaultHeaders.h"

#include "Array.h"

void RunArray_Constructors()
{
    std::cout << "Running code for Array Constructor\n";
    std::cout << "----------------------------------\n";

    std::cout << "Constructor(1) --> Array()\n";
    Array<int> Array_001;
    std::cout << "          Array_001: " << Array_001 << "\n";
    std::cout << "   Array_001.Size(): " << Array_001.Size() << "\n";
    std::cout << "Array_001.IsEmpty(): " << Array_001.IsEmpty() << "\n";

    std::cout << "Constructor(2) --> Array(size_t Capacity)\n";
    Array<char> Array_101(5);
    std::cout << "          Array_101: " << Array_101 << "\n";
    std::cout << "   Array_101.Size(): " << Array_101.Size() << "\n";
    std::cout << "Array_101.IsEmpty(): " << Array_101.IsEmpty() << "\n";

    std::cout << "Constructor(3) --> Array(size_t Capacity, T DefaultValue)\n";
    Array<int> Array_201(5, 5);
    std::cout << "          Array_201: " << Array_201 << "\n";
    std::cout << "   Array_201.Size(): " << Array_201.Size() << "\n";
    std::cout << "Array_201.IsEmpty(): " << Array_201.IsEmpty() << "\n";
    std::cout << "Constructor(3) --> Array(size_t Capacity, T DefaultValue)\n";
    Array<char> Array_202(5, 'c');
    std::cout << "          Array_202: " << Array_202 << "\n";
    std::cout << "   Array_202.Size(): " << Array_202.Size() << "\n";
    std::cout << "Array_202.IsEmpty(): " << Array_202.IsEmpty() << "\n";
    Array<std::string> Array_203(5, "Ramu");
    std::cout << "          Array_203: " << Array_203 << "\n";
    std::cout << "   Array_203.Size(): " << Array_203.Size() << "\n";
    std::cout << "Array_203.IsEmpty(): " << Array_203.IsEmpty() << "\n";

    return ;
}

int main()
{
    PrintProjectInfo();
    std::cout << "\n";
    std::cout << "Sample code for Array module\n";
    std::cout << "============================\n\n";
    RunArray_Constructors();
    return 0;
}
