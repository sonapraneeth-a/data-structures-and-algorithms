/**
 *      Created on: 22 March 2018
 *   Last modified: 30 March 2018
 *          Author: Sona Praneeth Akula
 *         Details: Main testing file for dynamic array bug fixing
 */

/**
 * Changelog
 *
 * Date (DD-MM-YYYY)            Author               Update
 * 22-03-2018             Sona Praneeth Akula   - Creation of file
 * 30-03-2018             Sona Praneeth Akula   - Added code for testing dynamic array
 */

#include "DefaultHeaders.h"
#include "DynamicArray.h"

int main()
{
    DynamicArray<int> array(5);
    array[0] = 10;
    array.PushBack(3);
    for(ULLI index = 0; index < array.GetSize(); index++)
    {
        std::cout << array[index] << "\n";
    }
    return 0;
}