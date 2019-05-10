/**
 * File description
 *
 *        Filename: MemoryAllocationException.h
 *      Created on: 09 May 2019
 *   Last modified: 09 May 2019
 *         Authors: sonapraneeth-a
 *         Details: Header for MemoryAllocationException
 */

 /**
  * Changelog
  *
  * Date (DD-MM-YYYY)            Author               Update
  * 09-05-2019               sonapraneeth-a      - Creation of the file
  *                                              - Added sample implementation for
  *                                                MemoryAllocationException
  */

#ifndef MEMORY_ALLOCATION_EXCEPTION_H
#define MEMORY_ALLOCATION_EXCEPTION_H

#include "IException.h"

namespace Exception
{
    class MemoryAllocationException : public IException
    {

    public:

        explicit MemoryAllocationException(const std::string& message = "")
        {
            this->_ExceptionName = "MemoryAllocationException";
            this->_DefaultMessage = "Memory not available for the required operation";
            this->_CustomMessage = message;
        }

    };

}

#endif // MEMORY_ALLOCATION_EXCEPTION_H
