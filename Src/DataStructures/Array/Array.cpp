/**
 * File description
 *
 *        Filename: Array.cpp
 *      Created on: 13 December 2018
 *   Last modified: 13 December 2018
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
 * @brief   Destructor for the class Array
 * @details Deletes the memory assigned for the Array and sets it back to null
 *
 * @tparam  T Generic parameter
 */
template <typename T>
DS::Array<T>::~Array()
{
    this->_Capacity = 0;
    this->_Size = 0;
    delete [] this->_Container;
    this->_Container = nullptr;
}

