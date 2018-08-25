/**
 *      Created on: 01 March 2018
 *   Last modified: 25 August 2018
 *          Author: Sona Praneeth Akula
 *         Details: Header for my implementation of string
 */

/**
 * Changelog
 *
 * Date (DD-MM-YYYY)            Author               Update
 * 01-04-2018             Sona Praneeth Akula   - Creation of the file
 * 17-08-2018             Sona Praneeth Akula   - Renamed GetSize() to Size()
 *                                              - Added IsPalindrome() implementation
 * 24-08-2018             Sona Praneeth Akula   - Added IsIsomorphic() function signature
 *                                              - Added Get(index) function signature
 * 25-08-2018             Sona Praneeth Akula   - Added comments for class variables
 *                                              - Added function signatures for AllPatternMatch,
 *                                                FirstPatternMatch, Insert, Delete and a new
 *                                                constructor for MyString
 *                                              - Added const at the end of functions which are not
 *                                                supposed to change the main MyString object
 *                                              - Removed explicit from copy constructor
 */

#ifndef MY_STRING_H
#define MY_STRING_H

#include "DefaultHeaders.h"
#include "Exceptions.h"

/**
 * @brief   Class which represents a string object
 * @details
 */
class MyString
{
private:

    char *_String = nullptr; /*!< String represented as a character array */
    size_t _Size = 0;        /*!< Size of the String */
    size_t _Capacity = 0;    /*!< Maximum capacity (number of characters) of the String */

public:

    static const size_t Npos = (size_t)-1; /*!< Variable representing end of the string */

    explicit MyString();
    explicit MyString(const char* input);
    explicit MyString(char character, size_t length);
    MyString(const MyString &input, size_t startIndex = 0, size_t length = MyString::Npos);
    MyString& operator = (const MyString &input);
    MyString& operator = (const char *input);

    size_t Size() const;
    char operator[] (size_t index) const;
    char& operator[] (size_t index);
    void Resize();
    void Clear();
    bool IsEmpty() const;
    void PushBack(char c);
    void PopBack();
    char Front() const;
    char Back() const;
    void Insert(char character, size_t position);
    void Delete(size_t position);
    char Get(size_t index) const;
    MyString Substring(size_t start = 0, size_t end = MyString::Npos) const;
    bool IsPalindrome() const;
    bool IsIsomorphic(const MyString &String) const;
    std::vector<unsigned int> AllPatternMatch(MyString input, MyString pattern);
    unsigned int FirstPatternMatch(MyString pattern);

    friend std::ostream & operator << (std::ostream &out, const MyString &string);

    ~MyString();
};


#endif // MY_STRING_H
