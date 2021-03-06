/**
 * File description
 *
 *        Filename: MainArray.cpp
 *      Created on: 13 December 2018
 *   Last modified: 15 January 2019
 *         Authors: sonapraneeth-a
 *         Details: File for main executable of the project - array
 */

/**
 * Changelog
 *
 * Date (DD-MM-YYYY)            Author               Update
 * 13-12-2018               sonapraneeth-a      - Creation of the file
 * 14-12-2018               sonapraneeth-a      - Added code for RunArray_Constructors()
 * 15-12-2018               sonapraneeth-a      - Updated code to use DS namespace
 * 15-01-2019               sonapraneeth-a      - Added empty comments for functions
 */


#include "DefaultHeaders.h"

#include "Array.h"

/**
 * @brief   Code for manual testing of Array constructors
 * @details
 *
 * @return
 */
void
RunArray_Constructors()
{
    PrintHeading("Running code for Array Constructors()", 2);

    std::cout << "Constructor(1) --> Array()\n";
    DS::Array<int> Array_001;
    std::cout << "          Array_001: " << Array_001 << "\n";
    std::cout << "   Array_001.Size(): " << Array_001.Size() << "\n";
    std::cout << "Array_001.IsEmpty(): " << Array_001.IsEmpty() << "\n";

    std::cout << "Constructor(2) --> Array(size_t Capacity)\n";
    DS::Array<char> Array_101(5);
    std::cout << "          Array_101: " << Array_101 << "\n";
    std::cout << "   Array_101.Size(): " << Array_101.Size() << "\n";
    std::cout << "Array_101.IsEmpty(): " << Array_101.IsEmpty() << "\n";
    std::cout << "Constructor(2) --> Array(size_t Capacity)\n";
    DS::Array<int> Array_102(5);
    std::cout << "          Array_102: " << Array_102 << "\n";
    std::cout << "   Array_102.Size(): " << Array_102.Size() << "\n";
    std::cout << "Array_102.IsEmpty(): " << Array_102.IsEmpty() << "\n";

    std::cout << "Constructor(3) --> Array(size_t Capacity, T DefaultValue)\n";
    DS::Array<int> Array_201(5, 5);
    std::cout << "          Array_201: " << Array_201 << "\n";
    std::cout << "   Array_201.Size(): " << Array_201.Size() << "\n";
    std::cout << "Array_201.IsEmpty(): " << Array_201.IsEmpty() << "\n";
    std::cout << "Constructor(3) --> Array(size_t Capacity, T DefaultValue)\n";
    DS::Array<char> Array_202(5, 'c');
    std::cout << "          Array_202: " << Array_202 << "\n";
    std::cout << "   Array_202.Size(): " << Array_202.Size() << "\n";
    std::cout << "Array_202.IsEmpty(): " << Array_202.IsEmpty() << "\n";
    DS::Array<std::string> Array_203(5, "Ramu");
    std::cout << "          Array_203: " << Array_203 << "\n";
    std::cout << "   Array_203.Size(): " << Array_203.Size() << "\n";
    std::cout << "Array_203.IsEmpty(): " << Array_203.IsEmpty() << "\n";

}

/**
 * @brief   Code for manual testing of Array Get()
 * @details
 *
 * @return
 */
void
RunArray_Get()
{
    PrintHeading("Running code for Array Get()", 2);

    std::cout << "Get() --> Array()\n";
    try
    {
        DS::Array<int> Array_001;
        std::cout << "          Array_001: " << Array_001 << "\n";
        std::cout << Array_001.Get(8) << "\n";
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << "\n";
    }
}

/**
 * @brief   Code for manual testing of Array module
 * @details
 *
 * @return
 */
int
main()
{
    PrintProjectInfo();
    std::cout << "\n";

    PrintHeading("Sample code for Array module", 1);

    RunArray_Constructors();
    RunArray_Get();

    return 0;
}
