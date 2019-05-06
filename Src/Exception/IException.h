/**
 * File description
 *      Created on: 17 December 2018
 *   Last modified: 15 January 2019
 *         Authors: sonapraneeth-a
 *         Details: Header for exception interface
 */

/**
 * Changelog
 *
 * Date (DD-MM-YYYY)            Author               Update
 * 17-12-2018               sonapraneeth-a      - Creation of the file
 *                                              - Added sample implementation for
 *                                                exception interface
 * 15-01-2019               sonaprneeth-a       - Fixed a cppcheck error caused
 *                                                due to message.c_str() getting
 *                                                destroyed after function return
 */


#ifndef IEXCEPTION_H
#define IEXCEPTION_H

#include <exception>
#include <string>
#include <cstring>

namespace Exception
{

    class IException : public std::exception
    {

    public:

        const char* what() const noexcept(true);

    protected:

        std::string _ExceptionName;
        std::string _DefaultMessage;
        std::string _CustomMessage;

    };

    const char*
    IException::what() const noexcept(true)
    {
        std::string message = "";
        message += "   Type:: " + _ExceptionName + "\n";
        message += " Reason:: " + _DefaultMessage + "\n";
        message += "Message:: " + _CustomMessage + "\n";
        // Reference: https://stackoverflow.com/questions/22330250/how-to-return-a-stdstring-c-str
        // return strdup(message.c_str());
        char* message_char_string = new char[message.length() + 1];
        strcpy_s(message_char_string, message.length() + 1, message.c_str());
        return message_char_string;
        // return message.c_str();
    }

}

#endif // IEXCEPTION_H
