/**
 * File description
 *
 *        Filename: NotImplementedException.h
 *      Created on: 16 January 2019
 *   Last modified: 16 January 2019
 *         Authors: sonapraneeth-a
 *         Details: Header for NotImplementedException
 */

/**
 * Changelog
 *
 * Date (DD-MM-YYYY)            Author               Update
 * 16-10-2019               sonapraneeth-a      - Creation of the file
 *                                              - Added sample implementation for
 *                                                NotImplementedException
 */

#ifndef NOT_IMPLEMENTED_EXCEPTION_H
#define NOT_IMPLEMENTED_EXCEPTION_H

#include "IException.h"

namespace Exception
{
    class NotImplementedException: public IException
    {

    public:

        explicit NotImplementedException(const std::string& message = "")
        {
            this->_ExceptionName = "NotImplementedException";
            this->_DefaultMessage = "The function called is not implemented";
            this->_CustomMessage = message;
        }

    };

}

#endif // NOT_IMPLEMENTED_EXCEPTION_H
