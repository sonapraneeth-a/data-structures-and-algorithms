/**
 *      Created on: 01 April 2018
 *   Last modified: 29 August 2018
 *          Author: sonapraneeth-a
 *         Details: Implementation for strings
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
 * 04-07-2018               sonapraneeth-a      - Added copy constructor and assignment operator
 * 17-08-2018               sonapraneeth-a      - Renamed GetSize() to Size()
 * 12-08-2018               sonapraneeth-a      - Renamed String to MyString as it was causing issues
 *                                                with clang on Mac OS X
 *                                              - Added IsPalindrome() implementation
 * 24-08-2018               sonapraneeth-a      - Added IsIsomorphic() implementation
 *                                              - Added Get(index) implementation
 * 25-08-2018               sonapraneeth-a      - Added function implementations for Insert, Delete
 *                                                and a new constructor for MyString
 *                                              - Added const at the end of functions which are not
 *                                                supposed to change the main MyString object
 *                                              - Added detailed comments for all functions and their
 *                                                implementation details
 * 26-08-2018               sonapraneeth-a      - Added function implementations for PopFront,
 *                                                PushFront
 *                                              - Added function implementations for operator ==
 * 28-08-2018               sonapraneeth-a      - Added function implementations for Append (all
 *                                                versions)
 *                                              - Added function implementations for operators +, +=
 * 29-08-2018               sonapraneeth-a      - Fixed errors in Insert() function implementation
 */

#include "MyString.h"

/**
 * @brief   Default constructor. A constructor with no arguments
 * @details Initializes an empty string and allocates memory on heap
 */
MyString::MyString()
{
    // Empty string. So, size of the string is 0
    this->_Size = 0;
    // Allocating memory to store 10 characters
    this->_Capacity = 10;
    // Allocating memory for the array on the heap
    this->_String = new (std::nothrow) char[this->_Capacity];
    // Checking if memory has been allocated
    if(!this->_String)
    {
        // Throw exception when memory allocation fails
        throw MemoryAllocationException();
    }
    // Null termination for the string
    (this->_String)[0] = '\0';
}

/**
 * @brief   Constructor for string object using C style strings
 * @details
 *
 * @param [const char*] input - Input string given as pointer to char
 */
MyString::MyString(const char* input)
{
    // length variable captures the size of the string pointed by character pointer
    size_t length = 0, index = 0;
    const char *__TempOne = input;
    // Determine the length of the string by moving the character pointer
    while(*__TempOne)
    {
        length++; *__TempOne++;
    }
    // Set the size and capacity of the string object
    this->_Size = length;
    this->_Capacity = length+10;
    // Allocating memory for the array on the heap
    this->_String = new (std::nothrow) char[this->_Capacity];
    // Checking if memory has been allocated
    if(!this->_String)
    {
        // Throw exception when memory allocation fails
        throw MemoryAllocationException();
    }
    // Copy the contents from the character pointer
    // to the character array in the string object
    const char *__TempTwo = input;
    // Looping over the input
    while(*__TempTwo)
    {
        this->_String[index] = *__TempTwo;
        index++; *__TempTwo++;
    }
    // Null terminate the string
    this->_String[index] = '\0';
}

/**
 * @brief   Created a string which contains a single character of certain length
 * @details
 *
 * @param [char] character - Character which should populate the string object
 * @param [size_t] length - Length of the string object which should be created
 */
MyString::MyString(char character, size_t length)
{
    // Setting the size and capacity of the string object
    this->_Size = length;
    this->_Capacity = length+10;
    // Allocating memory for the array
    this->_String = new (std::nothrow) char[this->_Capacity];
    // Checking if memory has been allocated
    if(!this->_String)
    {
        // Throw exception when memory allocation fails
        throw MemoryAllocationException();
    }
    // Copy the character to character array
    for (size_t index = 0; index < length; ++index)
    {
        this->_String[index] = character;
    }
    // Null terminate the string
    this->_String[length] = '\0';
}

/**
 * @brief   Copy constructor which copies a part/full string as specified by the
 *          indices
 * @details
 *
 * @param [MyString] input - Input MyString object whose copy has to be made
 * @param [size_t] startIndex - Index in the <pre>input</pre> from where the copying
 *                              of the string has to start
 * @param [size_t] length - Length of the string from <pre>startIndex</pre> where the
 *                          copy has to start
 */
MyString::MyString(const MyString &input, size_t startIndex, size_t length)
{
    // If startIndex+length crosses the size of the input string object
    // then we would be accessing memory which is not created
    // Hence, throw OutOfBoundsException
    if(input.Size() > startIndex+length)
    {
        throw OutOfBoundsException();
    }
    // Set the length and capacity of the string object to be created
    this->_Size = length;
    this->_Capacity = length+10;
    // Free up the memory which the current object and reallocate it
    delete[](this->_String);
    // Allocating memory for the array
    this->_String = new (std::nothrow) char[this->_Capacity];
    // Checking if memory has been allocated
    if(!this->_String)
    {
        // Throw exception when memory allocation fails
        throw MemoryAllocationException();
    }
    // Copy the contents from the input string object to the
    // current object's character array
    for (size_t index = startIndex; index < startIndex+length; ++index)
    {
        this->_String[index] = input[index];
    }
    // Null terminate the string
    this->_String[length] = '\0';
}

/**
 * @brief   Equals operator, kind of assignment operator from one MyString object
 *          to current object
 * @details
 *
 * @param  [MyString] input - Input object to the assignment operator
 * @return [MyString] Copies the contents from <pre>input</pre> object to the current object
 */
MyString&
MyString::operator = (const MyString &input)
{
    // Copy the size and capacity of the input object to current object
    this->_Size = input._Size;
    this->_Capacity = input._Capacity;
    // Free up the memory which the current object and reallocate it
    delete[](this->_String);
    // Allocating memory for the array
    this->_String = new (std::nothrow) char[this->_Capacity];
    // Checking if memory has been allocated
    if(!this->_String)
    {
        // Throw exception when memory allocation fails
        throw MemoryAllocationException();
    }
    // Copy the contents from the input string object to the
    // current object's character array
    for (size_t index = 0; index < input._Size; ++index)
    {
        this->_String[index] = input[index];
    }
    // Null terminate the string
    this->_String[input._Size] = '\0';
    // Return a pointer to the current object for copying
    return *this;
}

/**
 * @brief   Equals operator, Returns if the current string (character pointer) content is
 *          the same as input string (character pointer) content
 * @details
 *
 * @param  [MyString] input - Input MyString object which is to be compared
 * @return [bool] true if the MyString content and the current Mytring content are same
 *                else false
 */
bool
MyString::operator == (const MyString &input)
{
    bool __Result = true;
    if(this->_Size != input._Size)
    {
        __Result = false;
    }
    else
    {
        // Copy the contents from the input string object to the
        // current object's character array
        for (size_t index = 0; index < input._Size; ++index)
        {
            if (this->_String[index] != input[index])
            {
                __Result = false;
            }
        }
    }
    // Return a pointer to the current object for copying
    return __Result;
}

/**
 * @brief   Equals operator, kind of assignment operator from one string represented
 *          as character pointer to current object
 * @details
 *
 * @param  [MyString] input - Pointer to character array to the assignment operator
 * @return [MyString] Copies the contents from <pre>input</pre> object to the current object
 */
MyString&
MyString::operator = (const char *input)
{
    // length variable captures the size of the string pointed by character pointer
    size_t length = 0, index = 0;
    const char *__TempOne = input;
    // Determine the length of the string by moving the character pointer
    while(*__TempOne)
    {
        length++; *__TempOne++;
    }
    // Set the size and capacity of the string object
    this->_Size = length;
    this->_Capacity = length+10;
    // Allocating memory for the array on the heap
    this->_String = new (std::nothrow) char[this->_Capacity];
    // Checking if memory has been allocated
    if(!this->_String)
    {
        // Throw exception when memory allocation fails
        throw MemoryAllocationException();
    }
    // Copy the contents from the character pointer
    // to the character array in the string object
    const char *__TempTwo = input;
    // Looping over the input
    while(*__TempTwo)
    {
        this->_String[index] = *__TempTwo;
        index++; *__TempTwo++;
    }
    // Null terminate the string
    this->_String[index] = '\0';
    // Return a pointer to the current object for copying
    return *this;
}

/**
 * @brief   Equals operator, Returns if the current string (character pointer) content is
 *          the same as input string (character pointer) content
 * @details
 *
 * @param  [char*] input - Pointer to character array to the equals operator
 * @return [bool] true if the character pointer content and the current string content are same
 *                else false
 */
bool
MyString::operator == (const char *input)
{
    bool __Result = false;
    // length variable captures the size of the string pointed by character pointer
    size_t length = 0, index = 0;
    const char *__TempOne = input;
    // Determine the length of the string by moving the character pointer
    while(*__TempOne)
    {
        length++; *__TempOne++;
    }
    if(length != this->_Size)
    {
        __Result = false;
    }
    else
    {
        // Copy the contents from the character pointer
        // to the character array in the string object
        const char *__TempTwo = input;
        // Looping over the input
        while (*__TempTwo)
        {
            if(this->_String[index] == *__TempTwo)
            {
                index++;
                *__TempTwo++;
            }
            else
            {
                __Result = false;
                break;
            }
        }
    }
    // Return a pointer to the current object for copying
    return __Result;
}

/**
 * @brief   Checks whether the string object is empty or does it contain any characters
 * @details
 *
 * @return [bool] true if there are no characters in the string object else false
 */
bool
MyString::IsEmpty() const
{
    // Check if the size of the string object is 0 or not
    return this->_Size == 0;
}

/**
 * @brief
 * @details
 *
 * @param input
 * @return
 */
MyString&
MyString::operator + (const MyString &input)
{
    MyString Answer(*this);
    return Answer.Append(input);
}

/**
 * @brief
 * @details
 *
 * @param input
 * @return
 */
MyString&
MyString::operator + (const char *input)
{
    MyString Answer(*this);
    return Answer.Append(input);
}

/**
 * @brief
 * @details
 *
 * @param character
 * @return
 */
MyString&
MyString::operator + (char character)
{
    MyString Answer(*this);
    Answer.PushBack(character);
    return Answer;
}

/**
 * @brief
 * @details
 *
 * @param input
 * @return
 */
MyString&
MyString::operator += (const MyString &input)
{
    return this->Append(input);
}

/**
 * @brief
 * @details
 *
 * @param input
 * @return
 */
MyString&
MyString::operator += (const char *input)
{
    return this->Append(input);
}

/**
 * @brief
 * @details
 *
 * @param character
 * @return
 */
MyString&
MyString::operator += (char character)
{
    return this->Append(character);
}

/**
 * @brief
 * @details
 *
 * @param input
 * @return
 */
MyString&
MyString::Append(const MyString &input)
{
    for (size_t index = 0; index < input._Size; ++index)
    {
        this->PushBack(input[index]);
    }
    return *this;
}

/**
 * @brief
 * @details
 *
 * @param input
 * @return
 */
MyString&
MyString::Append(const char *input)
{
    size_t index = 0;
    // Copy the contents from the character pointer
    // to the character array in the string object
    const char *__TempOne = input;
    // Looping over the input
    while(*__TempOne)
    {
        this->PushBack(*__TempOne);
        index++; *__TempOne++;
    }
    // Return a pointer to the current object for copying
    return *this;
}

/**
 * @brief
 * @details
 *
 * @param character
 * @return
 */
MyString&
MyString::Append(char character)
{
    this->PushBack(character);
    return *this;
}

/**
 * @brief   Returns the size of the string
 * @details
 *
 * @return [size_t] Size of the string
 */
size_t
MyString::Size() const
{
    return this->_Size;
}

/**
 * @brief   Output the string object to << operator
 * @details
 *
 * @param  [ostream] out - Ostream operator
 * @param  [MyString] string - String object which should be printed
 * @return [ostream] Ostream populated withe String object which is to be printed
 */
std::ostream &
operator << (std::ostream &out, const MyString& string)
{
    // Print the character array to the ostream operator
    out << string._String;
    return out;
}

/**
 * @brief   Inserts a character to the string at the front
 * @details
 *
 * @param [char] c - Character which has to be pushed to the start of the string
 */
void
MyString::PushFront(char character)
{
    // If current size is greater than what the array can take in,
    // then we have to expand the memory of the MyString to take in
    // more elements
    if(this->_Size >= this->_Capacity-1)
    {
        // Call to the resize function
        this->Resize();
    }
    // Insert the character at the beginning of the string
    this->Insert(character, 0);
}

/**
 * @brief   Inserts a character to the string at the end
 * @details
 *
 * @param [char] c - Character which has to be pushed to the end of the string
 */
void
MyString::PushBack(char character)
{
    // If current size is greater than what the array can take in,
    // then we have to expand the memory of the MyString to take in
    // more elements
    if(this->_Size >= this->_Capacity-1)
    {
        // Call to the resize function
        this->Resize();
    }
    // Insert the character at the beginning of the string
    this->Insert(character, this->_Size);
}

/**
 * @brief   Deletes a character from the start of the string
 * @details
 */
void
MyString::PopFront()
{
    // If the size of the string is 0, then we cannot pop from the string
    if(this->_Size <= 0)
    {
        throw EmptyException();
    }
    // Delete the character from the first position
    this->Delete(0);
    return;
}

/**
 * @brief   Deletes a character from the end of the string
 * @details
 */
void
MyString::PopBack()
{
    // If the size of the string is 0, then we cannot pop from the string
    if(this->_Size <= 0)
    {
        throw EmptyException();
    }
    this->Delete(this->_Size-1);
    return;
}

/**
 * @brief   Resizes the size of the character array and copies the content
 *          from the old character array to the new character array
 * @details Deletes unecessary memory. Throws MemoryAllocationException if the
 *          increasing the size of the character array fails
 */
void
MyString::Resize()
{
    // Reference: See MyString.cpp. Default constructor
    char *_TempString = new char[this->_Capacity * 2];
    // @todo - Linter hints that condition is always false. Find out what could be the problem?
    if(!_TempString)
    {
        // Throw exception when memory allocation fails
        throw MemoryAllocationException();
    }
    // Copy values from _Array to _TempArray as this will be used from now on
    for(size_t index = 0; index < this->_Size; index++)
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
 * @brief   Retrieves the element at the front of the string
 * @details Throws OutOfBoundsExceptions if the size of the string is 0 or negative
 *
 * @return [char] Character at the front of the string
 */
char
MyString::Front() const
{
    if(this->_Size > 0)
    {
        return this->_String[0];
    }
    throw OutOfBoundsException();
}

/**
 * @brief   Retrieves the element at the end of the string
 * @details Throws OutOfBoundsExceptions if the size of the string is 0 or negative
 *
 * @return [char] Character at the end of the string
 */
char
MyString::Back() const
{
    if(this->_Size > 0)
    {
        return this->_String[this->_Size - 1];
    }
    throw OutOfBoundsException();
}

/**
 * @brief   Sets all the characters of the string to empty/null character
 * @details
 */
void
MyString::Clear()
{
    // Loop through all elements of the character array and set them to empty
    for (size_t index = 0; index < this->_Size; ++index)
    {
        // Clear the characters in the character array using null character
        // operator
        this->_String[index] = '\0';
    }
    // Now the size of the string is 0
    this->_Size = 0;
}

/**
 * @brief   Returns a substring as specified the indices
 * @details
 *
 * @param  [size_t] start - Start index from where the substring has to be extracted
 * @param  [size_t] end - End index upto where the substring has to be extracted
 * @return [MyString] MyString object which contains the substring
 */
MyString
MyString::Substring(size_t start, size_t end) const
{
    // MyString object which contains the substring
    MyString output;
    // Checking if the current string is empty and its correponding indices
    // to decide if an exception is to be thrown
    if(this->_Size == 0 && (start != 0 && (end != (size_t)-1 || end != 0)))
    { throw OutOfBoundsException(); }
    // If the current string is empty and the indices are correct, then an empty
    // string should be returned. So, do nothing
    else if(this->_Size == 0 && (start == 0 && (end == (size_t)-1 || end == 0)))
    {
        // Do nothing
    }
    // Check for other conditions
    else
    {
        // If start is out of the bounds of the size of the character array
        if (start < 0 || start >= this->_Size)
        {
            throw OutOfBoundsException();
        }
        // If end does not point to end of string but it is out of scope of the
        // character array, then throw OutOfboundsException
        if (end != (size_t)-1 && end >= this->_Size)
        {
            throw OutOfBoundsException();
        }
        // If end is lesser than start, then substring cannot be formed
        if (end != (size_t)-1 && end < start)
        {
            throw OutOfBoundsException();
        }
        // If either start or end are out of bounds of character array
        if (start == end && (start < 0 || start >= this->_Size))
        {
            throw OutOfBoundsException();
        }
        // If end is -1, it means the substring is still the end of the string
        if (end == (size_t) -1) { end = this->_Size - 1; }
        // Loop over the string from start position upto end position as
        // specified by the indices in the function
        for (size_t index = start; index <= end; ++index)
        {
            // Push the character to the end of the string
            output.PushBack(this->_String[index]);
        }
    }
    // Null terminate the string
    output.PushBack('\0');
    return output;
}

/**
 * @brief   Access the character at the index position in the character array
 * @details Throws OutOfBoundsException if index is crossing the limits of the
 *          character array
 *
 * @param  [size_t] index - Index in the character array which is to be retrieved
 * @return [char] Character present at the index^th position in the character array
 */
char&
MyString::operator[](size_t index)
{
    if(index < this->_Size)
    {
        return this->_String[index];
    }
    // Exception message
    std::string __ExceptionMessage = "Condition not satisfied: "
                                     + std::to_string(index)
                                     + " < " + std::to_string(this->_Size) + " and "
                                     + std::to_string(index) + " >= 0" ;
    throw OutOfBoundsException(__ExceptionMessage);
}

/**
 * @brief   Access the character at the index position in the character array
 * @details Throws OutOfBoundsException if index is crossing the limits of the
 *          character array
 *
 * @param  [size_t] index - Index in the character array which is to be retrieved
 * @return [char] Character present at the index^th position in the character array
 */
char
MyString::operator[](size_t index) const
{
    if(index < this->_Size)
    {
        return this->_String[index];
    }
    // Exception message
    std::string __ExceptionMessage = std::to_string(index) +
                                     " is greater than " +
                                     std::to_string(this->_Capacity);
    throw OutOfBoundsException(__ExceptionMessage);
}

/**
 * @brief   Access the character at the index position in the character array
 * @details Throws OutOfBoundsException if index is crossing the limits of the
 *          character array
 *
 * @param  [size_t] index - Index in the character array which is to be retrieved
 * @return [char] Character present at the index^th position in the character array
 */
char
MyString::Get(size_t index) const
{
    if(index < this->_Size)
    {
        return this->_String[index];
    }
    // Exception Message
    std::string __ExceptionMessage = std::to_string(index) +
                                     " is greater than " +
                                     std::to_string(this->_Capacity);
    throw OutOfBoundsException(__ExceptionMessage);
}

/**
 * @brief   Checks if the given string is a palindrome or not
 * @details Palindrome strings are the strings which reads the same way
 *          both in forward direction and backward direction
 *
 * @return [bool] true if the input string is palindrome else false
 */
bool
MyString::IsPalindrome() const
{
    bool __Result = true;
    // If string is empty, then the string is a palindrome
    if(_Size == 0) { return __Result; }
    // Get the pointer to middle of the string
    size_t __MidIndex;
    __MidIndex = _Size % 2 ? _Size / 2 : (_Size / 2) - 1;
    // Compare the character from both ends to see if they are same
    // Do this until we reach the middle of the string (or) until
    // we have realised that string is not a palindrome
    for(size_t __Index = 0; __Index <= __MidIndex; __Index++)
    {
        // Compare the character from both ends to see if they are same
        // If not the string is not a palindrome
        if((*this)[__Index] != (*this)[this->_Size-__Index-1])
        {
            __Result = false;
            break;
        }
    }
    // Return the result of the algorithm
    return __Result;
}

/**
 * @brief   Checks if the given input string is isomorphic or not wrt current string
 * @details Isomorphic strings are the strings which have the same structure ie.,
 *          there exists a one-to-one mapping for each character among the strings
 *
 * @param  [MyString] string- Input string which needs to be verified if the string is
 *                            isomorphic or not with the current string
 * @return [bool] true if the input string is isomorphic to the current string else false
 */
bool
MyString::IsIsomorphic(const MyString &string) const
{
    bool __Result = true;
    // If the sizes of the strings are not same, then we are sure that the strings
    // cannot be isomorphic
    if(this->_Size != string._Size)
    {
        __Result = false;
    }
    else
    {
        // Hashmap to map characters from current string to input string
        std::unordered_map<char, char> __Mapping = {};
        // Hashmap to check if the characters in the input string are visited
        // any time. This is necessary for this case
        // To prevent cases like abc -> ccd
        std::unordered_map<char, bool> __Visit = {};
        // Loop through all characters in the current string
        for (size_t index = 0; index < this->_Size; ++index)
        {
            // If a new character is found in the current string, then
            // add it to the hashmap
            if(__Mapping.find(this->Get(index)) == __Mapping.end())
            {
                __Mapping[this->Get(index)] = string.Get(index);
                // To prevent cases like abc -> ccd
                // If the character in the input string is not yet visited,
                // then mark it as visited
                if(__Visit.find(string.Get(index)) == __Visit.end())
                {
                    __Visit[string.Get(index)] = true;
                }
                else
                {
                    // If the character in the input string is visited, then it would
                    // mean that two different characters in the current string are
                    // mapping to same character in the input string, which violates
                    // the definition of isomorphic strings
                    // Example: abc -> ccd
                    // a -> c in the first iteration, then in the next iteration b -> c
                    // which means {a, b} -> c
                    if(__Visit[string.Get(index)] == true)
                    {
                        __Result = false;
                        break;
                    }
                }
            }
            else
            {
                // If the character present in the current string is visited,
                // then there should be a mapping of it to a character in the
                // input string. If they do not match, then the strings are not
                // isomorphic
                if(__Mapping[this->Get(index)] != string.Get(index))
                {
                    __Result = false;
                    break;
                }
            }
        }
        // Clear the hashmaps
        __Mapping.clear();
        __Visit.clear();
    }
    // Return the result
    return __Result;
}

/**
 * @brief   Delete a character from the specified position from the string object
 * @details
 *
 * @param [char] character - Character which has to be inserted into the string object
 * @param [size_t] position - Character position (0-indexed) from the string which
 *                            should be deleted
 */
void
MyString::Insert(char character, size_t position)
{
    // If the position of the character to be inserted is not within
    // the limits of the character array, then throw OutOfBoundsException
    if(!(position >= 0 && position <= this->_Size))
    {
        throw OutOfBoundsException();
    }
    // If current size is greater than what the array can take in,
    // then we have to expand the memory of the MyString to take in
    // more elements
    if(this->_Size >= this->_Capacity-1)
    {
        // Create more space in the character array by resizing
        this->Resize();
    }
    // Movement of characters is necessary only if the size of the string is
    // greater than 0
    if(this->_Size > 0)
    {
        // Push the elements from position by one to the right to create space for the
        // character to be inserted
        for (size_t index = this->_Size-1; index >= position; --index)
        {
            this->_String[index+1] = this->_String[index];
        }
    }
    // Replace the character at the position with the input character
    this->_String[position] = character;
    // Increase the size of the string by 1
    this->_Size++;
    // Null terminate the string
    this->_String[this->_Size] = '\0';
}

/**
 * @brief   Delete a character from the specified position from the string object
 * @details Throws OtuOfBoundsException if the size of string is non-negative (or)
 *          <pre>position</pre> is not within the limits of the size of the string
 *
 * @param [size_t] position - Character position (0-indexed) from the string which
 *                            should be deleted
 */
void
MyString::Delete(size_t position)
{
    // If the size of the string is 0 or less, then we cannot delete anything
    // from it. So, we need to throw OutOfBoundsException
    if(this->_Size <= 0)
    {
        throw OutOfBoundsException();
    }
    // If the character to be deleted from the string is outside the scope of
    // the character array, then we cannot delete it. So, we need to throw
    // OutOfBoundsException
    if(position < 0 || position >= this->_Size)
    {
        throw OutOfBoundsException();
    }
    // Shift the characters from position index by one before, which would mean we have
    // deleted the character from the position
    for (size_t index = position; index < this->_Size-1; ++index)
    {
        this->_String[index] = this->_String[index+1];
    }
    // Reduce the size of the string
    this->_Size--;
    // Null terminate the string
    this->_String[this->_Size] = '\0';
}

/**
 *
 * @param compareString
 * @return
 */
short int
MyString::Compare(const MyString &compareString)
{
    short int __Result = 0;
    size_t __MinStringLength = (this->_Size >= compareString._Size) ?
                                compareString._Size : this->_Size;
    for (size_t index = 0; index < __MinStringLength; ++index)
    {
        if(this->Get(index) > compareString.Get(index))
        {
            __Result = 1; break;
        }
        else if(this->Get(index) < compareString.Get(index))
        {
            __Result = -1; break;
        }
    }
    if(__Result == 0)
    {
        if(this->_Size > compareString._Size)
        {
            __Result = 1;
        }
        else if(this->_Size < compareString._Size)
        {
            __Result = -1;
        }
    }
    return __Result;
}

/**
 *
 * @param compareString
 * @return
 */
short int
MyString::Compare(const char* compareString)
{

}

/**
 * @brief
 * @details
 *
 * @param pattern
 * @return
 */
std::vector<unsigned int>
MyString::AllPatternMatch(const MyString &pattern)
{
    throw NotImplementedException();
}

/**
 * @brief
 * @details
 *
 * @param pattern
 * @return
 */
unsigned int
MyString::FirstPatternMatch(const MyString &pattern)
{
    throw NotImplementedException();
}

/**
 * @brief
 * @details
 *
 * @param pattern
 * @return
 */
unsigned int
MyString::LastPatternMatch(const MyString &pattern)
{
    throw NotImplementedException();
}

/**
 * @brief   Destructor for the MyString object
 * @details
 */
MyString::~MyString()
{
    // Free the memory assigned to the character array by new using delete
    delete[] _String;
    _String = nullptr;
    // Set the size and capacity of the string to 0
    this->_Size = 0;
    this->_Capacity = 0;
}