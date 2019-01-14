/**
 * File description
 *      Created on: 17 December 2018
 *   Last modified: 17 December 2018
 *         Authors: sonapraneeth-a
 *         Details: Header for IndexOutOfBoundsException
 */

/**
 * Changelog
 *
 * Date (DD-MM-YYYY)            Author               Update
 * 17-12-2018               sonapraneeth-a      - Creation of the file
 *                                              - Added sample implementation for
 *                                                IndexOutOfBoundsException
 */

#ifndef INDEX_OUT_OF_BOUNDS_EXCEPTION_H
#define INDEX_OUT_OF_BOUNDS_EXCEPTION_H

#include "IException.h"

namespace Exception
{
    class IndexOutOfBoundsException: public IException
    {

    public:

        explicit IndexOutOfBoundsException(const std::string& message = "")
        {
            this->_ExceptionName = "IndexOutOfBoundsException";
            this->_DefaultMessage = "IndexOutOfBoundsException received";
            this->_CustomMessage = message;
        }

    };

}

#endif // INDEX_OUT_OF_BOUNDS_EXCEPTION_H
