/**
 * File description
 *
 *        Filename: IArray.h
 *      Created on: 13 December 2018
 *   Last modified: 14 December 2018
 *         Authors: sonapraneeth-a
 *         Details: File for interface of array
 */

/**
 * Changelog
 *
 * Date (DD-MM-YYYY)            Author               Update
 * 13-12-2018               sonapraneeth-a      - Creation of the file
 *                                              - Creation of IArray interface
 * 14-12-2018               sonapraneeth-a      - Added base implementations
 *                                                for Get(), Set(), Size(), IsEmpty()
 */

#ifndef IARRAY_H
#define IARRAY_H

#include <cstdlib>
#include <ostream>

template <typename T>
class IArray
{

public:

    bool IsEmpty() const;
    size_t Size() const;

    T Get(size_t index) const;
    void Set(size_t index, T value);
//    virtual void Insert(size_t index, T value) = 0;
//    virtual void Remove(size_t index) = 0;
//
//    T operator[] (size_t index) const = 0;
//    T& operator[] (size_t index) = 0;

protected:

    T *_Container    = nullptr;   /*!< Variable containing the array elements */
    size_t _Capacity = 0;         /*!< Maximum capacity of the array */
    size_t _Size     = 0;         /*!< Current size of the array */

};

/**
 * @brief   Returns value present in the index^{th} block of the array
 * @details If the index given is invalid, then an "OutOfBoundsException"
 *          exception is thrown
 *
 * @tparam  T Generic parameter
 * @param   [size_t] index - Index of the array for which user wants the contents
 * @return  [T] - Value in the Array at that location. If value is not set (or)
 *                index trying to access invalid location then an exception
 *                "OutOfBoundsException" is thrown
 */
template <typename T>
T
IArray<T>::Get(
        size_t index
) const
{
    T value;
    if(index < this->_Size)
    {
        value = this->_Container[index];
    }
    return value;
}

/**
 * @brief   Sets value present in the index^{th} block of the array to the one
 *          provided by the user
 * @details If index is greater than the size of the array an exception
 *          "OutOfBoundsException" is thrown
 *
 * @tparam  T Generic parameter
 * @param   [size_t] index - Location in array whose value has to be modified
 * @param   [T] value - Value which should be put in the index^{th} location of
 *                      the array
 */
template <typename T>
void
IArray<T>::Set(
        size_t index,
        T value
)
{
    if(index >= this->_Capacity)
    {

    }
    this->_Container[index] = value;
    return ;
}

/**
 * @brief   Returns the current size of the array
 * @details
 *
 * @tparam  T Generic parameter
 * @return  [size_t] Returns the current size of the array
 */
template <typename T>
size_t
IArray<T>::Size() const
{
    // Reference:
    // https://stackoverflow.com/questions/3141087/what-is-meant-with-const-at-end-of-function-declaration
    return this->_Size;
}

/**
 * @brief   Returns true if array is empty else false
 * @details
 *
 * @tparam  T Generic parameter
 * @return  [bool] Returns true if array is empty else false
 */
template <typename T>
bool
IArray<T>::IsEmpty() const
{
    // returns true if _Size is set to 0, else false
    return this->_Size == 0;
}


#endif // IARRAY_H
