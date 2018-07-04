/**
 *      Created on: 01 April 2018
 *   Last modified: 17 April 2018
 *          Author: Sona Praneeth Akula
 *         Details: Main testing file for strings bug fixing
 */

/**
 * Changelog
 *
 * Date (DD-MM-YYYY)            Author               Update
 * 01-04-2018             Sona Praneeth Akula   - Creation of file
 * 17-04-2018             Sona Praneeth Akula   - Added code for testing string constructor
 */

#include "DefaultHeaders.h"
#include "String.h"
#include <cstring>

int main()
{
    String empty;
    String full("First String");
    std::cout << full.GetSize() << "\n";
    std::cout << full << "\n";
    full.PopBack();
    std::cout << full << "\n";
    full.PushBack('z');
    std::cout << full << "\n";
    std::cout << full.GetSubstring(5) << "\n";
    full[5] = '=';
    std::cout << full << "\n";
    return 0;
}