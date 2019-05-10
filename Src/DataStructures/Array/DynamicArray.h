/**
 *      Created on: 22 March 2018
 *   Last modified: 09 May 2019
 *          Author: sonapraneeth-a
 *         Details: Header for Dynamic array
 */

/**
 * Changelog
 *
 * Date (DD-MM-YYYY)            Author               Update
 * 22-03-2018               sonapraneeth-a      - Creation of file
 *                                              - Added function signatures for dynamic
 *                                                arrays
 * 02-04-2018               sonapraneeth-a      - Added function signature for GetFront(), 
 *                                                GetBack(), IsEmpty(), Resize()
 * 09-05-2019               sonapraneeth-a      - Added Dynamic array code from master-cpp
 *                                                branch and made necessary changes
 */

#ifndef DYNAMIC_ARRAY_H
#define DYNAMIC_ARRAY_H

#include "DefaultHeaders.h"
#include "IArray.h"

namespace DS
{
    /*! @class Array
     *  @brief A Dynamic sized Array class.
     *
     *  @details This is a Static Array class. Static Array means that the size of
     *           the array cannot be changed once declared
     */
    template <typename T>
    class DynamicArray : public DS::IArray<T>
    {
    
    public:

        explicit DynamicArray();
        explicit DynamicArray(size_t capacity);
        explicit DynamicArray(size_t capacity, T defaultValue);

        void Insert(size_t index, T value);
        void Remove(size_t index);

        void PushFront(T value);
        void PushBack(T value);

        ~DynamicArray();
    
    private:

        const size_t MIN_ARRAY_CAPACITY = 10;
        void Resize();

    };
}

#include "DynamicArray.cpp"

#endif // DYNAMIC_ARRAY_H
