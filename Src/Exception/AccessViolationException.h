/**
 * File description
 *
 *        Filename: AccessViolationException.h
 *      Created on: 15 January 2019
 *   Last modified: 15 January 2019
 *         Authors: sonapraneeth-a
 *         Details: Header for AccessViolationException
 */

/**
 * Changelog
 *
 * Date (DD-MM-YYYY)            Author               Update
 * 15-01-2019               sonapraneeth-a      - Creation of the file
 *                                              - Added sample implementation for
 *                                                AccessViolationException
 */

#ifndef ACCESS_VIOLATION_EXCEPTION_H
#define ACCESS_VIOLATION_EXCEPTION_H

#include "IException.h"

namespace Exception
{
    class AccessViolationException: public IException
    {

    public:

        explicit AccessViolationException(const std::string& message = "")
        {
            this->_ExceptionName = "AccessViolationException";
            this->_DefaultMessage = "The memory requested cannot be accessed";
            this->_CustomMessage = message;
        }

    };

}

#endif // ACCESS_VIOLATION_EXCEPTION_H
