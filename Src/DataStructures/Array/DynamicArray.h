/**
 *      Created on: 22 March 2018
 *   Last modified: 02 April 2018
 *          Author: Sona Praneeth Akula
 *         Details: Header for Dynamic array
 */

/**
 * Changelog
 *
 * Date (DD-MM-YYYY)            Author               Update
 * 22-03-2018             Sona Praneeth Akula   - Creation of file
 *                                              - Added function signatures for dynamic arrays
 * 02-04-2018             Sona Praneeth Akula   - Added  function signature for GetFront, GetBack, IsEmpty
 *                                                Resize
 */

#ifndef DYNAMIC_ARRAY_H
#define DYNAMIC_ARRAY_H

#include "DefaultHeaders.h"

/**
 * @brief Generic template implementation for dynamic arrays
 * @details
 * @todo Generate test cases for this class
 * @tparam T Generic type. Currently restricted to int, double, string
 */
template <typename T>
class DynamicArray
{
private:

    T *_Array = nullptr;  /*!< Variable containing the array elements */
    ULLI Capacity = 0;    /*!< Maximum capacity of the dynamic array */
    ULLI Size = 0;        /*!< Current size of the array */

public:

    DynamicArray();
    DynamicArray(ULLI Capacity);

    T Get(ULLI index) const;
    T operator[] (ULLI index) const;
    T& operator[] (ULLI index);
    void Set(ULLI index, T Value);
    ULLI GetSize() const;
    void Resize();
    bool IsEmpty() const;
    T GetFront() const;
    T GetBack() const;
    void PushBack(T value);
    void Remove(ULLI index);

    ~DynamicArray();
};


#endif // DYNAMIC_ARRAY_H
