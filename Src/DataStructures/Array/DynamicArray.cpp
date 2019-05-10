/**
 *      Created on: 22 March 2018
 *   Last modified: 09 May 2019
 *          Author: sonapraneeth-a
 *         Details: Implementation for Dynamic array
 */

/**
 * Changelog
 *
 * Date (DD-MM-YYYY)            Author               Update
 * 22-03-2018               sonapraneeth-a      - Creation of file
 * 22-03-2018               sonapraneeth-a      - Added function signatures for dynamic 
 *                                                arrays
 * 31-03-2018               sonapraneeth-a      - Made some changes to operator[] function
 * 01-04-2018               sonapraneeth-a      - Made some changes to PushBack() and 
 *                                                Remove()
 *                                                functions to fix size value
 * 02-04-2018               sonapraneeth-a      - Updated the code to replicate function of
 *                                                std::vector
 *                                                which is a dynamic array.
 *                                              - Added new function definitions for
 *                                                GetFront, GetBack, IsEmpty, Resize
 *                                              - Adding comments for all the functions
 * 09-05-2019               sonapraneeth-a      - Added Dynamic array code from master-cpp
 *                                                branch and made necessary changes
 */

#include "IndexOutOfBoundsException.h"
#include "MemoryAllocationException.h"

/**
 * @brief   Empty constructor for DynamicArray
 * @details Allocates memory for an array of size 10. All the 10 values are garbage in nature
 *
 * @tparam T Generic parameter
 */
template <typename T>
DS::DynamicArray<T>::DynamicArray()
{
    this->_Capacity = this->MIN_ARRAY_CAPACITY;
    this->_Size = 0;
    // Allocating memory for the array
    this->_Container = new (std::nothrow) T[this->_Capacity];
    if(!this->_Container)
    {
        // Throw exception when memory allocation fails
        throw Exception::MemoryAllocationException();
    }
}

/**
 * @brief   Constructor for DynamicArray which determines the initial capacity of the dynamic array
 * @details Allocates memory for an array of size given the user. All values are garbage in nature
 *
 * @tparam T Generic parameter
 * @param Capacity - Capacity of the DynamicArray
 */
template <typename T>
DS::DynamicArray<T>::DynamicArray(size_t capacity)
{
#if DEBUG_LOGS
    LOGD << "DynamicArray::Constructor (2)";
#endif
    this->_Capacity = capacity;
    this->_Size = capacity;
    // Allocating memory for the array
    this->_Container = new (std::nothrow) T[this->_Capacity];
    if(!this->_Container)
    {
        // Throw exception when memory allocation fails
        throw Exception::MemoryAllocationException();
    }
}

/**
 * @brief   Constructor for DynamicArray which determines the initial capacity of the dynamic array
 *          and assigns each element of the Array with DefaultValue
 * @details Allocates memory for an array of size given the user. All values are garbage in nature
 *
 * @tparam T Generic parameter
 * @param [size_t] Capacity - Capacity of the DynamicArray
 * @param [T] DefaultValue - Value which should be used to fill the DynamicArray
 */
template <typename T>
DS::DynamicArray<T>::DynamicArray(size_t capacity, T defaultValue)
{
    this->_Capacity = capacity;
    this->_Size = capacity;
    // Allocating memory for the array
    this->_Container = new (std::nothrow) T[this->_Capacity];
    if(!this->_Container)
    {
        // Throw exception when memory allocation fails
        throw Exception::MemoryAllocationException();
    }
    for (size_t __index = 0; __index < this->_Size; ++__index)
    {
        this->_Container[__index] = defaultValue;
    }
}

/**
 * @brief   Resizes the dynamic array to twice its capacity
 * @details If the resizing of the DynamicArray fails, then "MemoryAllocationException" is thrown
 *
 * @tparam T Generic parameter
 */
template <typename T>
void
DS::DynamicArray<T>::Resize()
{
    // Reference URL: https://stackoverflow.com/questions/18556590/c-11-initialization-with-auto
    T *__TempArray = new T[this->_Capacity * 2];
    // @todo - Linter hints that condition is always false. Find out what could be the problem?
    if(__TempArray == nullptr)
    {
        // Throw exception when memory allocation fails
        throw Exception::MemoryAllocationException();
    }
    // Copy values from _Array to _TempArray as this will be used from now on
    for(size_t index = 0; index < this->_Size; index++)
    {
        __TempArray[index] = this->_Container[index];
    }
    // Free the memory of old array
    delete [] this->_Container;
    // Change the pointer of the array to the new array
    this->_Container = __TempArray;
    // Now the capacity of the array is doubled
    this->_Capacity = this->_Capacity * 2;
}

/**
 * @brief   Appends element to the start of the DynamicArray
 * @details 
 *
 * @tparam  T Generic parameter
 * @param   [T] value - Value to added to the start of the array
 */
template <typename T>
void
DS::DynamicArray<T>::PushFront(T value)
{
    this->Insert(0, value);
}

/**
 * @brief   Appends element to the end of the DynamicArray
 * @details 
 *
 * @tparam  T Generic parameter
 * @param   [T] Value - Value to appended to the end of the array
 */
template <typename T>
void
DS::DynamicArray<T>::PushBack(T value)
{
    this->Insert(this->_Size, value);
}

/**
 * @brief   Insert the elements present at index^{th} location in the DynamicArray
 * @details If index^{th} element does not exist, then "IndexOutOfBoundsException" is thrown
 *
 * @tparam T Generic parameter
 * @param [size_t] index - The element index which has to be removed from the
 *                                         DynamicArray
 */
template <typename T>
void
DS::DynamicArray<T>::Insert(size_t index, T value)
{
    // If current size is greater than what the array can take in,
    // then we have to expand the memory of the DynamicArray to take in
    // more elements
    if (this->_Size >= this->_Capacity)
    {
        this->Resize();
    }
    if (index >= 0 && index <= this->_Size)
    {   
        // Shift all the elements by the index
        for (size_t array_index = this->_Size-1; array_index >= index; array_index--)
        {
            this->_Container[array_index + 1] = this->_Container[array_index];
        }
        this->_Container[index] = value;
        // Increase the size
        this->_Size++;
        return;
    }
    
}

/**
 * @brief   Removes the elements present at index^{th} location in the DynamicArray
 * @details If index^{th} element does not exist, then "IndexOutOfBoundsException" is thrown
 *
 * @tparam T Generic parameter
 * @param [size_t] index - The element index which has to be removed from the
 *                                         DynamicArray
 */
template <typename T>
void
DS::DynamicArray<T>::Remove(size_t index)
{
    if(index < this->_Size)
    {
        // Shift all the elements by the index
        for(size_t array_index = index+1; array_index < this->_Size; array_index++)
        {
            this->_Container[array_index-1] = this->_Container[array_index];
        }
        // Reduce the size
        this->_Size--;
        return;
    }
    // Throw exception if index is not within proper limits
    throw Exception::IndexOutOfBoundsException(
            std::to_string(index) + " does not exist in the array."
            );
}

/**
 * @brief   Destructor for the class DynamicArray
 * @details Deletes the memory assigned for the DynamicArray and sets it back to null
 *
 * @tparam T Generic parameter
 */
template <typename T>
DS::DynamicArray<T>::~DynamicArray()
{
    this->_Capacity = 0;
    this->_Size = 0;
    delete [] this->_Container;
    this->_Container = nullptr;
}
