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
#include "MyString.h"
#include <cstring>
#include <iomanip>

void Run()
{
//    MyString empty;
//    MyString full("First MyString");
//    std::cout << full.Size() << "\n";
//    std::cout << full << "\n";
//    full.PopBack();
//    std::cout << full << "\n";
//    full.PushBack('z');
//    std::cout << full << "\n";
//    std::cout << full.GetSubstring(5) << "\n";
//    full[5] = '=';
//    std::cout << full << "\n";
}

void RunIsPalindrome()
{
    MyString empty;
    std::cout << empty.IsPalindrome() << "\n";
}

void RunIsIsomorphic()
{
    MyString empty;
    MyString String_01("aab"), String_02("ccd");
    unsigned int RunNo = 1;
    // Reference: https://stackoverflow.com/questions/1714515/how-can-i-pad-an-int-with-leading-zeros-when-using-cout-operator
    std::cout << "Case " << std::setfill('0') << std::setw(2) << RunNo++
                << ": " << "'" << empty << "' - '" << empty << "'\n";
    std::cout << "Result: " << empty.IsIsomorphic(empty) << "\n";
    std::cout << "Case " << std::setfill('0') << std::setw(2) << RunNo++
                << ": " << "'" << String_01 << "' - '" << String_02 << "'\n";
    std::cout << "Result: " << String_01.IsIsomorphic(String_02);
    return;
}

void RunSubstring()
{
    MyString String_01("abcefghi");
    std::cout << "Result: '" << String_01.Substring(2, 6) << "'\n";
    std::cout << "Result: '" << String_01.Substring(2) << "'\n";
    std::cout << "Result: '" << String_01.Substring() << "'\n";
    String_01.PushBack('j');
    std::cout << "Result: '" << String_01.Substring() << "'\n";
    String_01.Insert('d', 3);
    std::cout << "Result: '" << String_01.Substring() << "'\n";
    String_01.Delete(3);
    std::cout << "Result: '" << String_01.Substring() << "'\n";
    MyString empty;
    std::cout << "Result: '" << empty.Substring() << "'\n";
    return;
}

int main()
{
    // RunIsIsomorphic();
    RunSubstring();
    return 0;
}