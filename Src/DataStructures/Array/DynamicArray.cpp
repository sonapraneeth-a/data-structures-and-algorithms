/**
 *      Created on: 22 March 2018
 *   Last modified: 01 April 2018
 *          Author: Sona Praneeth Akula
 *         Details: Implementation for Dynamic array
 */

/**
 * Changelog
 *
 * Date (DD-MM-YYYY)            Author               Update
 * 22-03-2018             Sona Praneeth Akula   - Creation of file
 * 22-03-2018             Sona Praneeth Akula   - Added function signatures for dynamic arrays
 * 31-03-2018             Sona Praneeth Akula   - Made some changes to operator[] function
 * 01-04-2018             Sona Praneeth Akula   - Made some changes to PushBack() and Remove()
 *                                                functions to fix size value
 * 02-04-2018             Sona Praneeth Akula   - Updated the code to replicate function of std::vector
 *                                                which is a dynamic array.
 *                                              - Added new function definitions for GetFront, GetBack,
 *                                                IsEmpty, Resize
 *                                              - Adding comments for all the functions
 */

#include "DynamicArray.h"

/**
 * @todo Find a way to initialize the 10 values in the dynamic array wth default values for their type
 * @brief   Empty constructor for DynamicArray
 * @details Allocates memory for an array of size 10. All the 10 values are garbage in nature
 *
 * @tparam T Generic parameter
 */
template <typename T>
DynamicArray<T>::DynamicArray()
{
    this->Capacity = 10;
    this->Size = 0;
    // Allocating memory for the array
    this->_Array = new (std::nothrow) T[this->Capacity];
    if(!this->_Array)
    {
        // Throw exception when memory allocation fails
        throw MemoryAllocationException();
    }
}

/**
 * @todo Find a way to initialize the 10 values in the dynamic array wth default values for their type
 * @brief   Constructor for DynamicArray which determines the initial capacity of the dynamic array
 * @details Allocates memory for an array of size given the user. All values are garbage in nature
 *
 * @tparam T Generic parameter
 * @param Capacity - Capacity of the DynamicArray
 */
template <typename T>
DynamicArray<T>::DynamicArray(ULLI Capacity)
{
    this->Capacity = Capacity;
    this->Size = Capacity;
    // Allocating memory for the array
    this->_Array = new (std::nothrow) T[this->Capacity];
    if(!this->_Array)
    {
        // Throw exception when memory allocation fails
        throw MemoryAllocationException();
    }
}

/**
 * @brief   Returns value present in the index^{th} block of the array
 * @details If the index given is invalid, then an "OutOfBoundsException" exception is thrown
 *
 * @tparam T Generic parameter
 * @param index - Index of the array for which user wants the contents
 * @return [T] - Value in the DynamicArray at that location. If value is not set (or) index
 *               trying to access invalid location then an exception "OutOfBoundsException" is
 *               thrown
 */
template <typename T>
T DynamicArray<T>::Get(ULLI index) const
{
    if(index < this->Size)
    {
        return this->_Array[index];
    }
    throw OutOfBoundsException(index + " is greater than " + this->Capacity);
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
T& DynamicArray<T>::operator[](ULLI index)
{
    if(index < this->Size)
    {
        return this->_Array[index];
    }
    std::string ExceptionMessage = "Condition not satisfied: " + std::to_string(index)
                                    + " < " + std::to_string(this->Size) + " and "
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
T DynamicArray<T>::operator[](ULLI index) const
{
    if(index < this->Size)
    {
        return this->_Array[index];
    }
    throw OutOfBoundsException(index + " is greater than " + this->Capacity);
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
void DynamicArray<T>::Set(ULLI index, T Value)
{
    if(index >= this->Capacity)
    {
        throw OutOfBoundsException(index + " does not exist in the array.");
    }
    this->_Array[index] = Value;
}

/**
 * @brief   Resizes the dynamic array to twice its capacity
 * @details If the resizing of the DynamicArray fails, then "MemoryAllocationException" is thrown
 *
 * @tparam T Generic parameter
 */
template <typename T>
void DynamicArray<T>::Resize()
{
    // Reference URL: https://stackoverflow.com/questions/18556590/c-11-initialization-with-auto
    T *_TempArray = new T[this->Capacity * 2];
    // @todo - Linter hints that condition is always false. Find out what could be the problem?
    if(_TempArray == nullptr)
    {
        // Throw exception when memory allocation fails
        throw MemoryAllocationException();
    }
    // Copy values from _Array to _TempArray as this will be used from now on
    for(ULLI index = 0; index < this->Size; index++)
    {
        _TempArray[index] = this->_Array[index];
    }
    // Free the memory of old array
    delete [] this->_Array;
    // Change the pointer of the array to the new array
    this->_Array = _TempArray;
    // Now the capacity of the array is doubled
    this->Capacity = this->Capacity * 2;
}

/**
 * @brief   Appends element to the end of the DynamicArray
 * @details
 *
 * @tparam T Generic parameter
 * @param [T] Value - Value to appended to the end of the array
 */
template <typename T>
void DynamicArray<T>::PushBack(T Value)
{
    // If current size is greater than what the array can take in,
    // then we have to expand the memory of the DynamicArray to take in
    // more elements
    if(this->Size >= this->Capacity)
    {
        this->Resize();
    }
    this->_Array[this->Size] = Value;
    this->Size++;
}

/**
 * @brief   Removes the elements present at index^{th} location in the DynamicArray
 * @details If index^{th} element does not exist, then "OutOfBoundsException" is thrown
 *
 * @tparam T Generic parameter
 * @param [unsigned long long int] index - The element index which has to be removed from the
 *                                         DynamicArray
 */
template <typename T>
void DynamicArray<T>::Remove(ULLI index)
{
    if(index < this->Size)
    {
        // Shift all the elements by the index
        for(ULLI array_index = index+1; array_index < this->Size; array_index++)
        {
            this->_Array[array_index-1] = this->_Array[array_index];
        }
        // Reduce the size
        this->Size--;
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
ULLI DynamicArray<T>::GetSize() const
{
    // https://stackoverflow.com/questions/3141087/what-is-meant-with-const-at-end-of-function-declaration
    return this->Size;
}

/**
 * @brief   Returns true if array is empty else false
 * @details
 *
 * @tparam T Generic parameter
 * @return [bool] Returns true if array is empty else false
 */
template <typename T>
bool DynamicArray<T>::IsEmpty() const
{
    return this->Size == 0;
}

/**
 * @brief   Returns the elements present in the first part of the array
 * @details If the array is empty, an exception "EmptyException" is thrown
 *
 * @tparam T Generic parameter
 * @return [T] - Value present in the first block of the array (First element of the array)
 */
template <typename T>
T DynamicArray<T>::GetFront() const
{
    if (this->Size == 0)
    {
        throw EmptyException();
    }
    return this->_Array[0];
}

/**
 * @brief   Returns the elements present in the last part of the array
 * @details If the array is empty, an exception "EmptyException" is thrown
 *
 * @tparam T Generic parameter
 * @return [T] - Value present in the last block of the array (Last element of the array)
 */
template <typename T>
T DynamicArray<T>::GetBack() const
{
    if (this->Size == 0)
    {
        throw EmptyException();
    }
    return this->_Array[this->Size-1];
}

/**
 * @brief   Destructor for the class DynamicArray
 * @details Deletes the memory assigned for the DynamicArray and sets it back to null
 *
 * @tparam T Generic parameter
 */
template <typename T>
DynamicArray<T>::~DynamicArray()
{
    this->Capacity = 0;
    this->Size = 0;
    delete [] this->_Array;
    this->_Array = nullptr;
}


template class DynamicArray<int>;
template class DynamicArray<double>;
template class DynamicArray<std::string>;