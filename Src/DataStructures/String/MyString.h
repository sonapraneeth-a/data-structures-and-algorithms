/**
 *      Created on: 01 March 2018
 *   Last modified: 01 April 2018
 *          Author: Sona Praneeth Akula
 *         Details: Header for strings
 */

/**
 * Changelog
 *
 * Date (DD-MM-YYYY)            Author               Update
 * 01-04-2018             Sona Praneeth Akula   - Creation of the file
 */

#ifndef STRING_H
#define STRING_H

#include "DefaultHeaders.h"
#include "Exceptions.h"

class MyString
{
private:

    char *_String = nullptr;
    ULLI _Size = 0;
    ULLI _Capacity = 0;

public:

    static const int Npos = -1;

    explicit MyString();
    explicit MyString(const char* input);
    MyString(const MyString &input);
    MyString& operator = (const MyString &input);
    MyString& operator = (const char *input);

    ULLI GetSize() const;
    char operator[] (ULLI index) const;
    char& operator[] (ULLI index);
    void Resize();
    void Clear();
    bool IsEmpty();
    void PushBack(char c);
    void PopBack();
    char GetFront();
    char GetBack();
    MyString GetSubstring(ULLI start = 0, ULLI end = MyString::Npos);

    friend std::ostream & operator << (std::ostream &out, const MyString &c);

    ~MyString();
};


#endif // STRING_H
