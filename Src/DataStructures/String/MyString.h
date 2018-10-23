/**
 *      Created on: 01 March 2018
 *   Last modified: 28 August 2018
 *          Author: Sona Praneeth Akula
 *         Details: Header for my implementation of string
 */

/**
 * Author Details
 *
 * Sona Praneeth Akula --- sonapraneeth-a <sonapraneeth.akula@gmail.com>
 */

/**
 * Changelog
 *
 * Date (DD-MM-YYYY)            Author               Update
 * 01-04-2018               sonapraneeth-a      - Creation of the file
 * 05-07-2018               sonapraneeth-a      - Added function signatures for operators([], <<),
 *                                                constructors(default, with const char*), GetSize,
 *                                                Resize, Clear, IsEmpty, PushBack, PopBack,
 *                                                GetFront, GetBack, GetSubstring
 * 10-07-2018               sonapraneeth-a      - Added function signatures for constructor(copy),
 *                                                operator =
 *                                              - Changed second argument of GetSubstring from -1
 *                                                to String::Npos
 * 12-08-2018               sonapraneeth-a      - Renamed String to MyString as it was causing issues
 *                                                with clang on Mac OS X
 * 17-08-2018               sonapraneeth-a      - Renamed GetSize() to Size()
 *                                              - Change the data type of _Size and _Capacity from
 *                                                ULLI to size_t
 *                                              - Added IsPalindrome() implementation
 * 24-08-2018               sonapraneeth-a      - Added IsIsomorphic() function signature
 *                                              - Added Get(index) function signature
 * 25-08-2018               sonapraneeth-a      - Added comments for class variables
 *                                              - Added function signatures for AllPatternMatch, FirstPatternMatch,
 *                                                Insert, Delete and a new constructor for MyString
 *                                              - Added const at the end of functions which are not
 *                                                supposed to change the main MyString object
 *                                              - Removed explicit from copy constructor
 *                                              - Made the following changes to function names
 *                                                  - GetFront -> Front
 *                                                  - GetBack -> Back,
 *                                                  - GetSubstring -> Substring
 * 26-08-2018               sonapraneeth-a      - Added function signatures for +, +=, == operators
 *                                              - Added function signatures for Append, PushFront,
 *                                                PopFront
 * 28-08-2018               sonapraneeth-a      - Added function signatures for Compare, LastPatternMatch
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
    MyString& operator + (const MyString &input);
    MyString& operator + (const char *input);
    MyString& operator + (char character);
    MyString& operator += (const MyString &input);
    MyString& operator += (const char *input);
    MyString& operator += (char character);
    bool operator == (const MyString &input);
    bool operator == (const char *input);

    size_t Size() const;
    char operator[] (size_t index) const;
    char& operator[] (size_t index);
    void Resize();
    void Clear();
    bool IsEmpty() const;
    MyString& Append(const MyString &input);
    MyString& Append(const char *input);
    MyString& Append(char character);
    void PushFront(char c);
    void PopFront();
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
    short int Compare(const MyString &compareObject);
    short int Compare(const char* compareObject);
    std::vector<unsigned int> AllPatternMatch(const MyString &pattern);
    unsigned int FirstPatternMatch(const MyString &pattern);
    unsigned int LastPatternMatch(const MyString &pattern);

    friend std::ostream & operator << (std::ostream &out, const MyString &string);

    ~MyString();
};


#endif // MY_STRING_H
