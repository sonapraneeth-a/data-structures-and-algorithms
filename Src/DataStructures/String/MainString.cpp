/**
 *      Created on: 01 April 2018
 *   Last modified: 29 August 2018
 *          Author: Sona Praneeth Akula
 *         Details: Main testing file for strings bug fixing
 */

/**
 * Author Details
 *
 * sonapraneeth-a --- Sona Praneeth Akula <sonapraneeth.akula@gmail.com>
 */

/**
 * Changelog
 *
 * Date (DD-MM-YYYY)            Author               Update
 * 01-04-2018               sonapraneeth-a      - Creation of file
 * 17-04-2018               sonapraneeth-a      - Added code for testing string constructor
 * 29-08-2018               sonapraneeth-a      - Added RunSize() function
 *                                              - Added RunInsert() function
 */

#include "DefaultHeaders.h"
#include "MyString.h"
#include <cstring>
#include <iomanip>

#define START_RUN(func) std::cout << "Running " << func << "\n";
#define END_RUN std::cout << "\n"; return;
#define TAB std::cout << "\t";
/**
 * @brief   Generic Run function
 * @details
 */
void Run()
{
    START_RUN("")
    MyString empty;
    MyString full("First MyString");
    std::cout << full.Size() << "\n";
    std::cout << full << "\n";
    full.PopBack();
    std::cout << full << "\n";
    full.PushBack('z');
    std::cout << full << "\n";
    std::cout << full.Substring(5) << "\n";
    full[5] = '=';
    std::cout << full << "\n";
    END_RUN
}

/**
 * @brief   Running Size() function
 * @details
 */
void Run_Size()
{
    START_RUN("MyString::Size()")
    MyString String_00, String_01("T"), String_02("Ta");
    MyString String_03("Tar"), String_04("Tara");
    MyString String_05("Tarak");
    TAB std::cout << "00 String: '" << String_00 << "', " << String_00.Size() << "\n";
    TAB std::cout << "01 String: '" << String_01 << "', " << String_01.Size() << "\n";
    TAB std::cout << "02 String: '" << String_02 << "', " << String_02.Size() << "\n";
    TAB std::cout << "03 String: '" << String_03 << "', " << String_03.Size() << "\n";
    TAB std::cout << "04 String: '" << String_04 << "', " << String_04.Size() << "\n";
    TAB std::cout << "05 String: '" << String_05 << "', " << String_05.Size() << "\n";
    END_RUN
}

/**
 * @brief   Running Insert() function
 * @details
 */
void Run_Insert()
{
    START_RUN("MyString::Insert()")
    MyString String_00, String_01("T"), String_02("Tr");
    TAB std::cout << "String_00 :: Inserting 'T' at position 0\n";
    TAB TAB std::cout << "Before: '" << String_00 << "'\n";
    String_00.Insert('T', 0);
    TAB TAB std::cout << " After: '" << String_00 << "'\n";
    TAB std::cout << "String_01 :: Inserting 'a' at position 1\n";
    TAB TAB std::cout << "Before: '" << String_01 << "'\n";
    String_01.Insert('a', 1);
    TAB TAB std::cout << " After: '" << String_01 << "'\n";
    TAB std::cout << "String_02 :: Inserting 'a' at position 1\n";
    TAB TAB std::cout << "Before: '" << String_02 << "'\n";
    String_02.Insert('a', 1);
    TAB TAB std::cout << " After: '" << String_02 << "'\n";
    END_RUN
}

/**
 * @brief   Running IsPalindrome() function
 * @details
 */
void Run_IsPalindrome()
{
    START_RUN("MyString::IsPalindrome()")
    MyString empty;
    TAB std::cout << empty.IsPalindrome() << "\n";
    END_RUN
}

/**
 * @brief   Running IsIsomorphic() function
 * @details
 */
void Run_IsIsomorphic()
{
    START_RUN("MyString::IsIsomorphic()")
    MyString empty;
    MyString String_01("aab"), String_02("ccd");
    unsigned int RunNo = 1;
    // Reference: https://stackoverflow.com/questions/1714515/how-can-i-pad-an-int-with-leading-zeros-when-using-cout-operator
    TAB std::cout << "Case " << std::setfill('0') << std::setw(2) << RunNo++
                << ": " << "'" << empty << "' - '" << empty << "'\n";
    TAB TAB std::cout << "Result: " << empty.IsIsomorphic(empty) << "\n";
    TAB std::cout << "Case " << std::setfill('0') << std::setw(2) << RunNo++
                << ": " << "'" << String_01 << "' - '" << String_02 << "'\n";
    TAB TAB std::cout << "Result: " << String_01.IsIsomorphic(String_02) << "\n";
    END_RUN
}

void Run_Substring()
{
    START_RUN("MyString::Substring()")
    MyString String_01("abcefghi");
    TAB std::cout << "Result: '" << String_01.Substring(2, 6) << "'\n";
    TAB std::cout << "Result: '" << String_01.Substring(2) << "'\n";
    TAB std::cout << "Result: '" << String_01.Substring() << "'\n";
    String_01.PushBack('j');
    TAB std::cout << "Result: '" << String_01.Substring() << "'\n";
    String_01.Insert('d', 3);
    TAB std::cout << "Result: '" << String_01.Substring() << "'\n";
    String_01.Delete(3);
    TAB std::cout << "Result: '" << String_01.Substring() << "'\n";
    MyString empty;
    TAB std::cout << "Result: '" << empty.Substring() << "'\n";
    END_RUN
}

int main()
{
    START_RUN("Main Run")
    Run_Size();
    Run_Insert();
    Run_IsPalindrome();
    Run_IsIsomorphic();
    Run_Substring();
    return EXIT_SUCCESS;
}