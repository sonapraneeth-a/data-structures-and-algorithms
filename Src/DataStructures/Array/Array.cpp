/**
 * File description
 *
 *        Filename: Array.cpp
 *      Created on: 13 December 2018
 *   Last modified: 04 March 2018
 *         Authors: sonapraneeth-a
 *         Details: File for implementation of static array class functions
 */

/**
 * Changelog
 *
 * Date (DD-MM-YYYY)            Author               Update
 * 13-12-2018               sonapraneeth-a      - Creation of the file
 *                                              - Creation of Static Array class
 *                                                definitions
 * 14-12-2018               sonapraneeth-a      - Fixed code to follow Coding guidelines
 * 04-03-2018               sonapraneeth-a      - Added time complexity for remove
 *                                                and insert functions
 */


/**
 * @brief   Default empty constructor for the Array class
 * @details Allocates memory for an array of MIN_ARRAY_CAPACITY. Values in the
 *          array are not initialized.
 *
 * @tparam  T Generic parameter
 */
template<typename T>
DS::Array<T>::Array()
{
    this->_Capacity = this->MIN_ARRAY_CAPACITY;
    this->_Size = 0;
    // Allocating memory for the array
    this->_Container = new (std::nothrow) T[this->_Capacity];
    if(!this->_Container)
    {
        // Throw exception when memory allocation fails
        // throw MemoryAllocationException();
    }
}

/**
 * @brief   Constructor for Array which determines the initial capacity of the
 *          dynamic array and assigns each element of the Array with DefaultValue
 * @details Allocates memory for an array of size given the user. All values are
 *          in the array are determined by the default value of the T type. 
 *          Example: 0 for int, '' for char etc.,
 *
 * @tparam  T Generic parameter
 * @param   [size_t] capacity - Capacity of the Array
 */
template <typename T>
DS::Array<T>::Array (
        size_t capacity
)
{
    this->_Capacity = capacity;
    this->_Size = capacity;
    // Allocating memory for the array
    this->_Container = new (std::nothrow) T[this->_Capacity];
    if(!this->_Container)
    {
        // Throw exception when memory allocation fails
        // throw MemoryAllocationException();
    }
    for (size_t __index = 0; __index < this->_Size; ++__index)
    {
        // Reference: https://stackoverflow.com/questions/12615549/how-to-get-the-default-value-of-any-type
        this->_Container[__index] = T();
    }
}

/**
 * @brief   Constructor for Array which determines the initial capacity of the
 *          dynamic array and assigns each element of the Array with defaultValue
 * @details Allocates memory for an array of size given the user. All values are
 *          in the array are determined by the second parameter to the
 *          constructor
 *
 * @tparam  T Generic parameter
 * @param   [size_t] capacity - Capacity of the Array
 * @param   [T] defaultValue - Value which should be used to fill the Array
 */
template <typename T>
DS::Array<T>::Array (
        size_t capacity,
        T defaultValue
)
{
    this->_Capacity = capacity;
    this->_Size = capacity;
    // Allocating memory for the array
    this->_Container = new (std::nothrow) T[this->_Capacity];
    if(!this->_Container)
    {
        // Throw exception when memory allocation fails
        // throw MemoryAllocationException();
    }
    for (size_t __index = 0; __index < this->_Size; ++__index)
    {
        this->_Container[__index] = defaultValue;
    }
}

/**
 * @brief   Inserts an element at the specified location in the Array
 * @details **Time Complexity:** O(n)
 * @todo    Add tests for this function
 *
 * @tparam  T Generic parameter
 * @param   [size_t] index - Location in array where the value has to be inserted
 * @param   [T] value - Value to appended to the end of the array
 */
template<typename T>
void
DS::Array<T>::Insert(
        size_t index,
        T value
        )
{
    // If current size is greater than what the array can take in,
    // then we have to expand the memory of the Array to take in
    // more elements
    if(this->_Size < this->_Capacity)
    {
        // Shift all the elements by the index to right
        for(size_t __index = index; __index < this->_Size; __index++)
        {
            this->_Container[__index+1] = this->_Container[__index];
        }
        this->_Container[index] = value;
        this->_Size++;
    }
}


/**
 * @brief   Removes the elements present at index^{th} location in the Array
 * @details If index^{th} element does not exist, then "OutOfBoundsException" is
 *          thrown
 *          **Time Complexity:** O(n)
 * @todo    Add tests for this function
 *
 * @tparam  T Generic parameter
 * @param   [size_t] index - The element index which has to be removed from the Array
 */
template<typename T>
void
DS::Array<T>::Remove(
        size_t index
        )
{
    if(index < this->_Size)
    {
        // Shift all the elements by the index to left
        for(size_t __index = index+1; __index < this->_Size; __index++)
        {
            this->_Container[__index-1] = this->_Container[__index];
        }
        // Reduce the size
        this->_Size--;
    }
}

/**
 * @brief   Destructor for the class Array
 * @details Deletes the memory assigned for the Array and sets it back to null
 *
 */
template <typename T>
DS::Array<T>::~Array()
{
    this->_Capacity = 0;
    this->_Size = 0;
    delete [] this->_Container;
    this->_Container = nullptr;
}

