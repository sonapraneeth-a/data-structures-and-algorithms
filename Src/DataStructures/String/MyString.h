/**
 *      Created on: 01 March 2018
 *   Last modified: 17 August 2018
 *          Author: Sona Praneeth Akula
 *         Details: Header for strings
 */

/**
 * Changelog
 *
 * Date (DD-MM-YYYY)            Author               Update
 * 01-04-2018             Sona Praneeth Akula   - Creation of the file
 * 17-08-2018             Sona Praneeth Akula   - Renamed GetSize() to Size()
 *                                              - Added IsPalindrome() implementation
 */

#ifndef MY_STRING_H
#define MY_STRING_H

#include "DefaultHeaders.h"
#include "Exceptions.h"

class MyString
{
private:

    char *_String = nullptr;
    size_t _Size = 0;
    size_t _Capacity = 0;

public:

    static const int Npos = -1;

    explicit MyString();
    explicit MyString(const char* input);
    MyString(const MyString &input);
    MyString& operator = (const MyString &input);
    MyString& operator = (const char *input);

    size_t Size() const;
    char operator[] (size_t index) const;
    char& operator[] (size_t index);
    void Resize();
    void Clear();
    bool IsEmpty();
    void PushBack(char c);
    void PopBack();
    char GetFront();
    char GetBack();
    char Get(size_t index) const;
    MyString GetSubstring(ULLI start = 0, ULLI end = MyString::Npos);
    bool IsPalindrome();
    bool IsIsomorphic(const MyString &String);

    friend std::ostream & operator << (std::ostream &out, const MyString &c);

    ~MyString();
};


#endif // MY_STRING_H
