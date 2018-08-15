/**
 *      Created on: 02 August 2018
 *   Last modified: 02 August 2018
 *          Author: Sona Praneeth Akula
 *         Details: Implementation for Normal array
 */

/**
 * Changelog
 *
 * Date (DD-MM-YYYY)            Author               Update
 * 02-08-2018             Sona Praneeth Akula   - Creation of file
 *                                              - Added function implementations for arrays -
 *                                                constructors, destructors, get, set, size,
 */

#include "Array.h"

/**
 * @todo Find a way to initialize the values in the dynamic array with default values for their type
 * @brief   Constructor for Array which determines the initial capacity of the dynamic array
 * @details Allocates memory for an array of size given the user. All values are garbage in nature
 *
 * @tparam T Generic parameter
 * @param Capacity - Capacity of the Array
 */
template <typename T>
Array<T>::Array(ULLI Capacity)
{
#if DEBUG_PRINT
    LOGD << "Array::Constructor (2)";
#endif
    this->_Capacity = Capacity;
    this->_Size = 0;
    // Allocating memory for the array
    this->_Array = new (std::nothrow) T[this->_Capacity];
    if(!this->_Array)
    {
        // Throw exception when memory allocation fails
        throw MemoryAllocationException();
    }
}

/**
 * @todo Find a way to initialize the values in the dynamic array wth default values for their type
 * @brief   Constructor for Array which determines the initial capacity of the dynamic array
 *          and assigns each element of the Array with DefaultValue
 * @details Allocates memory for an array of size given the user. All values are garbage in nature
 *
 * @tparam T Generic parameter
 * @param [unsigned long long int] _Capacity - _Capacity of the Array
 * @param [T] DefaultValue - Value which should be used to fill the Array
 */
template <typename T>
Array<T>::Array(ULLI Capacity, T DefaultValue)
{
    this->_Capacity = Capacity;
    this->_Size = Capacity;
    // Allocating memory for the array
    this->_Array = new (std::nothrow) T[this->_Capacity];
    if(!this->_Array)
    {
        // Throw exception when memory allocation fails
        throw MemoryAllocationException();
    }
    for (ULLI index = 0; index < this->_Size; ++index)
    {
        this->_Array[index] = DefaultValue;
    }
}

/**
 * @brief   Returns value present in the index^{th} block of the array
 * @details If the index given is invalid, then an "OutOfBoundsException" exception is thrown
 *
 * @tparam T Generic parameter
 * @param index - Index of the array for which user wants the contents
 * @return [T] - Value in the Array at that location. If value is not set (or) index
 *               trying to access invalid location then an exception "OutOfBoundsException" is
 *               thrown
 */
template <typename T>
T Array<T>::Get(ULLI index) const
{
    if(index < this->_Size)
    {
        return this->_Array[index];
    }
    throw OutOfBoundsException(index + " is greater than " + this->_Capacity);
}


/**
 * @brief
 * @details
 *
 * @tparam T Generic parameter
 * @param index
 * @return
 */
template <typename T>
T& Array<T>::operator[](ULLI index)
{
    if(index < this->_Size)
    {
        return this->_Array[index];
    }
    std::string ExceptionMessage = "Condition not satisfied: " + std::to_string(index)
                                   + " < " + std::to_string(this->_Size) + " and "
                                   + std::to_string(index) + " >= 0" ;
    throw OutOfBoundsException(ExceptionMessage);
}

/**
 * @brief
 * @details
 *
 * @tparam T Generic parameter
 * @param index
 * @return
 */
template <typename T>
T Array<T>::operator[](ULLI index) const
{
    if(index < this->_Size)
    {
        return this->_Array[index];
    }
    throw OutOfBoundsException(index + " is greater than " + this->_Capacity);
}

/**
 * @brief   Sets value present in the index^{th} block of the array to the one provided
 *          by the user
 * @details If index is greater than the size of the array an exception "OutOfBoundsException" is thrown
 *
 * @tparam T Generic parameter
 * @param [unsigned long long int] index - Location in array whose value has to be modified
 * @param [T] Value - Value which should be put in the index^{th} location of the array
 */
template <typename T>
void Array<T>::Set(ULLI index, T Value)
{
    if(index >= this->_Capacity)
    {
        throw OutOfBoundsException(index + " does not exist in the array.");
    }
    this->_Array[index] = Value;
}

/**
 * @brief   Appends element to the end of the Array
 * @details
 *
 * @tparam T Generic parameter
 * @param [T] Value - Value to appended to the end of the array
 */
template <typename T>
void Array<T>::Insert(ULLI index, T Value)
{
    // If current size is greater than what the array can take in,
    // then we have to expand the memory of the Array to take in
    // more elements
    if(this->_Size < this->_Capacity)
    {
        // Shift all the elements by the index to right
        for(ULLI array_index = index; array_index < this->_Size; array_index++)
        {
            this->_Array[array_index+1] = this->_Array[array_index];
        }
        this->_Array[index] = Value;
        this->_Size++;
        return;
    }
    // Throw exception if index is not within proper limits
    throw OverflowException(std::to_string(index) + " does not exist in the array.");
}

/**
 * @brief   Removes the elements present at index^{th} location in the Array
 * @details If index^{th} element does not exist, then "OutOfBoundsException" is thrown
 *
 * @tparam T Generic parameter
 * @param [unsigned long long int] index - The element index which has to be removed from the
 *                                         Array
 */
template <typename T>
void Array<T>::Remove(ULLI index)
{
    if(index < this->_Size)
    {
        // Shift all the elements by the index to left
        for(ULLI array_index = index+1; array_index < this->_Size; array_index++)
        {
            this->_Array[array_index-1] = this->_Array[array_index];
        }
        // Reduce the size
        this->_Size--;
        return;
    }
    // Throw exception if index is not within proper limits
    throw OutOfBoundsException(std::to_string(index) + " does not exist in the array.");
}

/**
 * @brief   Returns the current size of the array
 * @details
 *
 * @tparam T Generic parameter
 * @return [unsigned long long int] Returns the current size of the array
 */
template <typename T>
ULLI Array<T>::Size() const
{
    // https://stackoverflow.com/questions/3141087/what-is-meant-with-const-at-end-of-function-declaration
    return this->_Size;
}

/**
 * @brief   Returns true if array is empty else false
 * @details
 *
 * @tparam T Generic parameter
 * @return [bool] Returns true if array is empty else false
 */
template <typename T>
bool Array<T>::IsEmpty() const
{
    return this->_Size == 0;
}

/**
 * @brief   Destructor for the class Array
 * @details Deletes the memory assigned for the Array and sets it back to null
 *
 * @tparam T Generic parameter
 */
template <typename T>
Array<T>::~Array()
{
    this->_Capacity = 0;
    this->_Size = 0;
    delete [] this->_Array;
    this->_Array = nullptr;
}


template class Array<int>;
template class Array<double>;
template class Array<std::string>;