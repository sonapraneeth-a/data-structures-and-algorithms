/**
 *      Created on: 22 March 2018
 *   Last modified: 31 March 2018
 *          Author: Sona Praneeth Akula
 *         Details: Exceptions
 */

/**
 * Changelog
 *
 * Date (DD-MM-YYYY)            Author               Update
 * 22-03-2018             Sona Praneeth Akula   - Creation of file
 *                                              - Added definitions for exceptions
 * 31-03-2018             Sona Praneeth Akula   - Removed inheritance of public::exception
 *                                              - Modified message in OutOfBoundsException
 * 01-04-2018             Sona Praneeth Akula   - Added new MemoryAllocationException
 *                                              - Minor refactorings for the code
 *                                              - Moved from throw() to noexpect(true)
 */

#ifndef EXCEPTIONS_H
#define EXCEPTIONS_H

#include <string>

/**
 *
 */
class EmptyException
{
private:
    std::string PrefixMessage;
    std::string ExtraMessage;
    std::string StandardMessage;
public:
    /**
     *
     */
    explicit EmptyException()
    {
        PrefixMessage = "Exception::";
        ExtraMessage = "";
        StandardMessage = "Empty. ";
    }
    /**
     *
     * @param Message
     */
    explicit EmptyException(const std::string &Message)
    {
        PrefixMessage = "Exception::";
        StandardMessage = "";
        ExtraMessage = Message;
    }
    /**
     *
     * @return
     */
    std::string what() const noexcept(true)
    {
        std::string Message = PrefixMessage + StandardMessage + ExtraMessage;
        return Message;
    }
};

/**
 *
 */
class OverflowException
{
private:
    std::string PrefixMessage;
    std::string ExtraMessage;
    std::string StandardMessage;
public:
    /**
     *
     */
    explicit OverflowException()
    {
        PrefixMessage = "Exception::";
        ExtraMessage = "";
        StandardMessage = "Overflow. ";
    }
    /**
     *
     * @param Message
     */
    explicit OverflowException(const std::string &Message)
    {
        PrefixMessage = "Exception::";
        StandardMessage = "";
        ExtraMessage = Message;
    }
    /**
     *
     * @return
     */
    std::string what() const noexcept(true)
    {
        std::string Message = PrefixMessage + StandardMessage + ExtraMessage;
        return Message;
    }
};

/**
 *
 */
class OutOfBoundsException
{
private:
    std::string PrefixMessage;
    std::string ExtraMessage;
    std::string StandardMessage;
public:
    /**
     *
     */
    explicit OutOfBoundsException()
    {
        PrefixMessage = "Exception::";
        ExtraMessage = "";
        StandardMessage = "Index out of bounds for the data structure. ";
    }
    /**
     *
     * @param Message
     */
    explicit OutOfBoundsException(const std::string &Message)
    {
        PrefixMessage = "Exception::";
        ExtraMessage = Message;
        StandardMessage = "Index out of bounds for the data structure. ";
    }
    // Reference URL: http://en.cppreference.com/w/cpp/language/except_spec
    // Reference URL: http://en.cppreference.com/w/cpp/language/noexcept_spec
    /**
     *
     * @return
     */
    std::string what() const noexcept(true)
    {
        std::string Message = PrefixMessage + StandardMessage + ExtraMessage;
        return Message;
    }
};

/**
 *
 */
class MemoryAllocationException
{
private:
    std::string PrefixMessage;
    std::string ExtraMessage;
    std::string StandardMessage;
public:
    /**
     *
     */
    explicit MemoryAllocationException()
    {
        PrefixMessage = "Exception::";
        ExtraMessage = "";
        StandardMessage = "Memory allocation for the data structure failed. ";
    }
    /**
     *
     * @param Message
     */
    explicit MemoryAllocationException(const std::string &Message)
    {
        PrefixMessage = "Exception::";
        ExtraMessage = Message;
        StandardMessage = "Memory allocation for the data structure failed. ";
    }
    /**
     *
     * @return
     */
    std::string what() const noexcept(true)
    {
        std::string Message = PrefixMessage + StandardMessage + ExtraMessage;
        return Message;
    }
};


#endif //EXCEPTIONS_H
