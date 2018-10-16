/**
 *      Created on: 02 August 2018
 *   Last modified: 16 October 2018
 *          Author: sonapraneeth-a <Sona Praneeth Akula>
 *         Details: Header for Normal array
 */

/**
 * Changelog
 *
 * Date (DD-MM-YYYY)    Author              Update
 * 02-08-2018           sonapraneeth-a      - Creation of file
 *                                          - Added function signatures for
 *                                            arrays
 * 15-10-2018           sonapraneeth-a      - Updated comments in the header
 * 16-10-2018           sonapraneeth-a      - Fixed the Changelog comment format
 */


#ifndef ARRAY_H
#define ARRAY_H

#include "DefaultHeaders.h"

template <typename T>
class Array
{
private:
    T *_Array = nullptr;   /*!< Variable containing the array elements */
    ULLI _Capacity = 0;    /*!< Maximum capacity of the dynamic array */
    ULLI _Size = 0;        /*!< Current size of the array */

public:

    explicit Array(ULLI Capacity);
    Array(ULLI Capacity, T DefaultValue);

    T Get(ULLI index) const;
    T operator[] (ULLI index) const;
    T& operator[] (ULLI index);
    void Set(ULLI index, T Value);
    ULLI Size() const;
    bool IsEmpty() const;
    void Insert(ULLI index, T value);
    void Remove(ULLI index);

    ~Array();
};


#endif //ARRAY_H
