/**
 * File description
 *      Created on: 17 December 2018
 *   Last modified: 17 December 2018
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
 */


#ifndef IEXCEPTION_H
#define IEXCEPTION_H

#include <exception>
#include <string>

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
        return message.c_str();
    }

}

#endif // IEXCEPTION_H
