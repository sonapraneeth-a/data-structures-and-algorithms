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
#include "plog/Appenders/ConsoleAppender.h"

int main()
{
    static plog::ConsoleAppender<plog::TxtFormatter> consoleAppender;
    plog::init(plog::debug, &consoleAppender);
    LOGD << "Log for dynamic array";
    DynamicArray<int> array(5);
    array[0] = 10;
    array[1] = 20;
    array[2] = 30;
    array[3] = 40;
    array[4] = 50;
    array.PushBack(60);
    for(ULLI index = 0; index < array.GetSize(); index++)
    {
        std::cout << array[index] << " ";
    }
    std::cout << "\n";
    std::cout << "Press Enter to continue: ";
    char ch; std::cin >> ch;
    return 0;
}