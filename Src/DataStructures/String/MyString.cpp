/**
 *      Created on: 01 April 2018
 *   Last modified: 17 August 2018
 *          Author: Sona Praneeth Akula
 *         Details: Implementation for strings
 */

/**
 * Changelog
 *
 * Date (DD-MM-YYYY)            Author               Update
 * 01-04-2018             Sona Praneeth Akula   - Creation of file
 * 04-07-2018             Sona Praneeth Akula   - Added copy constructor and assignment operator
 * 17-08-2018             Sona Praneeth Akula   - Renamed GetSize() to Size()
 *                                              - Added IsPalindrome() implementation
 */

#include "MyString.h"

/**
 *
 */
MyString::MyString()
{
    this->_Size = 0;
    this->_Capacity = 10;
    // Allocating memory for the array
    this->_String = new (std::nothrow) char[this->_Capacity];
    if(!this->_String)
    {
        // Throw exception when memory allocation fails
        throw MemoryAllocationException();
    }
}

/**
 *
 * @param input
 */
MyString::MyString(const char* input)
{
    ULLI length = 0, index = 0;
    const char *temp_one = input;
    while(*temp_one)
    {
        length++; *temp_one++;
    }
    this->_Size = length;
    this->_Capacity = length;
    // Allocating memory for the array
    this->_String = new (std::nothrow) char[this->_Capacity+1];
    if(!this->_String)
    {
        // Throw exception when memory allocation fails
        throw MemoryAllocationException();
    }
    const char *temp_two = input;
    while(*temp_two)
    {
        this->_String[index] = *temp_two;
        index++; *temp_two++;
    }
    this->_String[index] = '\0';
}

/**
 *
 * @param input
 */
MyString::MyString(const MyString &input)
{

}

/**
 *
 * @param input
 * @return
 */
MyString&
MyString::operator = (const MyString &input)
{
    return *this;
}

/**
 *
 * @param input
 * @return
 */
MyString&
MyString::operator = (const char *input)
{
    return *this;
}

/**
 *
 * @return
 */
bool
MyString::IsEmpty()
{
    return this->_Size == 0;
}

/**
 *
 * @return
 */
size_t
MyString::Size() const
{
    return this->_Size;
}

/**
 *
 * @param out
 * @param string
 * @return
 */
std::ostream &
operator << (std::ostream &out, const MyString& string)
{
    out << string._String;
    return out;
}

/**
 *
 * @param c
 */
void
MyString::PushBack(char c)
{
    // If current size is greater than what the array can take in,
    // then we have to expand the memory of the MyString to take in
    // more elements
    if(this->_Size >= this->_Capacity)
    {
        this->Resize();
    }
    this->_String[this->_Size] = c;
    this->_Size++;
}

/**
 *
 */
void
MyString::PopBack()
{
    if(this->_Size <= 0)
    {
        throw;
    }
    this->_String[this->_Size - 1] = '\0';
    this->_Size--;
}

/**
 *
 */
void
MyString::Resize()
{
    // Reference: See MyString.cpp
    char *_TempString = new char[this->_Capacity * 2];
    // @todo - Linter hints that condition is always false. Find out what could be the problem?
    if(_TempString == nullptr)
    {
        // Throw exception when memory allocation fails
        throw MemoryAllocationException();
    }
    // Copy values from _Array to _TempArray as this will be used from now on
    for(ULLI index = 0; index < this->_Size; index++)
    {
        _TempString[index] = this->_String[index];
    }
    // Free the memory of old array
    delete [] this->_String;
    // Change the pointer of the array to the new array
    this->_String = _TempString;
    // Now the capacity of the array is doubled
    this->_Capacity = this->_Capacity * 2;
}

/**
 *
 * @return
 */
char
MyString::GetFront()
{
    if(this->_Size > 0)
    {
        return this->_String[0];
    }
    throw;
}

/**
 *
 * @return
 */
char
MyString::GetBack()
{
    if(this->_Size > 0)
    {
        return this->_String[this->_Size - 1];
    }
    throw ;
}

/**
 *
 */
void
MyString::Clear()
{
    for (ULLI index = 0; index < this->_Size; ++index)
    {
        this->_String[index] = '\0';
    }
    this->_Size = 0;
}

/**
 *
 * @param start
 * @param end
 * @return
 */
MyString
MyString::GetSubstring(ULLI start, ULLI end)
{
    MyString output;
    if(start < 0 || start >= this->_Size) { throw; }
    if(end != -1 && end > this->_Size) { throw; }
    if(end != -1 && end > start) { throw; }
    if(start == end && (start < 0 || start > this->_Size)) { throw; }
    if(end == -1) { end = (ULLI)this->_Size; }
    for (ULLI index = (ULLI)start; index < end; ++index)
    {
        output.PushBack(this->_String[index]);
    }
    return output;
}

/**
 * @brief
 * @details
 *
 * @param index
 * @return
 */
char&
MyString::operator[](size_t index)
{
    if(index < this->_Size)
    {
        return this->_String[index];
    }
    std::string ExceptionMessage = "Condition not satisfied: " + std::to_string(index)
                                   + " < " + std::to_string(this->_Size) + " and "
                                   + std::to_string(index) + " >= 0" ;
    throw OutOfBoundsException(ExceptionMessage);
}

/**
 * @brief
 * @details
 *
 * @param index
 * @return
 */
char
MyString::operator[](size_t index) const
{
    if(index < this->_Size)
    {
        return this->_String[index];
    }
    std::string ExceptionMessage = std::to_string(index) +
                                   " is greater than " +
                                   std::to_string(this->_Capacity);
    throw OutOfBoundsException(ExceptionMessage);
}

/**
 * @brief
 * @details
 *
 * @param index
 * @return
 */
char
MyString::Get(size_t index) const
{
    if(index < this->_Size)
    {
        return this->_String[index];
    }
    std::string ExceptionMessage = std::to_string(index) +
                                   " is greater than " +
                                   std::to_string(this->_Capacity);
    throw OutOfBoundsException(ExceptionMessage);
}

bool
MyString::IsPalindrome()
{
    bool __Result = true;
    if(_Size == 0) { return __Result; }
    size_t __MidIndex;
    __MidIndex = _Size % 2 ? _Size / 2 : (_Size / 2) - 1;
    for(size_t __Index = 0; __Index <= __MidIndex; __Index++)
    {
        if((*this)[__Index] != (*this)[this->_Size-__Index-1])
        {
            __Result = false;
            break;
        }
    }
    return __Result;
}

bool
MyString::IsIsomorphic(const MyString &String)
{
    bool __Result = true;
    if(this->_Size != String._Size)
    {
        __Result = false;
    }
    else
    {
        std::unordered_map<char, char> __Mapping;
        for (size_t index = 0; index < this->_Size; ++index)
        {
            // std::cout << "Index: " << index << "\n";
            // std::cout << this->Get(index) << ", " << String.Get(index) << "\n";
            // std::cout << __Mapping[this->Get(index)] << "\n";
            if(__Mapping.find(this->Get(index)) == __Mapping.end())
            {
                // std::cout << "Not found\n";
                __Mapping[this->Get(index)] = String.Get(index);
            }
            else
            {
                if(__Mapping[this->Get(index)] != String.Get(index))
                {
                    // std::cout << "Result is false\n";
                    __Result = false;
                    break;
                }
            }
        }
        __Mapping.clear();
    }
    return __Result;
}

/**
 *
 */
MyString::~MyString()
{
    this->_Size = 0;
    _String = nullptr;
}