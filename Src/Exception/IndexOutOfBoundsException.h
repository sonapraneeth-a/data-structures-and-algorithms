/**
 * File description
 *      Created on: 17 December 2018
 *   Last modified: 15 January 2019
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
 * 15-01-2019               sonapraneeth-a      - Added comments for the class
 */

#ifndef INDEX_OUT_OF_BOUNDS_EXCEPTION_H
#define INDEX_OUT_OF_BOUNDS_EXCEPTION_H

#include "IException.h"

namespace Exception
{
    /*! @class IndexOutOfBoundsException
     *  @brief An exception class for IndexOutOfBoundsException
     *
     *  @details This is an implementation for IndexOutOfBoundsException
     *           exception. A custom message can be accompanied by the default
     *           message provided by the exception
     */
    class IndexOutOfBoundsException: public IException
    {

    public:

        explicit IndexOutOfBoundsException(const std::string& message = "")
        {
            this->_ExceptionName = "IndexOutOfBoundsException";
            // Reference: https://stackoverflow.com/questions/23936246/error-invalid-operands-of-types-const-char-35-and-const-char-2-to-binar
            this->_DefaultMessage = std::string("The index being accessed is out")
                                    + " of the boundary of the container";
            this->_CustomMessage = message;
        }

    };

}

#endif // INDEX_OUT_OF_BOUNDS_EXCEPTION_H
