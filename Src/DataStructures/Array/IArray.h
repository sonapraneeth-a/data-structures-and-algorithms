/**
 * File description
 *
 *        Filename: IArray.h
 *      Created on: 13 December 2018
 *   Last modified: 07 May 2019
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
 * 17-12-2018               sonapraneeth-a      - Added time and space complexity
 *                                                to comments
 *                                              - Added base implementations for
 *                                                operators []
 * 07-05-2019               sonapraneeth-a      - Minor updates to comments
 *                                              - Added Reset() and ToString()
 */

#ifndef IARRAY_H
#define IARRAY_H

#include <cstdlib>
#include <ostream>
#include <sstream>
#include <cstddef>

#include "IndexOutOfBoundsException.h"
#include "MemoryAllocationException.h"

namespace DS
{
    /*! @interface IArray
     *  @brief An interface for Array class.
     *
     *  @details This is an interface for Array class
     */
    template<typename T>
    class IArray
    {

    public:

        bool IsEmpty() const;
        size_t Size() const;
        T Get(size_t index) const;
        void Set(size_t index, T value);
        void Reset();
        std::string ToString() const;
        T Front() const;
        T Back() const;

        // Operator code
        T operator[] (size_t index) const;
        T& operator[] (size_t index);


        virtual void Insert(size_t index, T value) = 0;
        virtual void Remove(size_t index) = 0;

    protected:

        T *_Container = nullptr;   /*!< Variable containing the array elements */
        size_t _Capacity = 0;      /*!< Maximum capacity of the array */
        size_t _Size = 0;          /*!< Current size of the array */

    };

    /**
     * @brief   Returns value present in the index^{th} block of the array
     * @details If the index given is invalid, then an "IndexOutOfBoundsException"
     *          exception is thrown.
     *          **Time complexity:** O(1)
     *          **Space complexity:** O(1)
     *
     * @tparam  T Generic parameter
     * @param   [size_t] index - Index of the array for which user wants the contents
     * @return  [T] - Value in the Array at that location. If value is not set (or)
     *                index trying to access invalid location then an exception
     *                "IndexOutOfBoundsException" is thrown
     */
    template<typename T>
    T
    IArray<T>::Get(
            size_t index
            ) const
    {
        T value;
        // Values inside the _Container can be accessed if the index requested
        // is less than the size of IArray object
        if (index < this->_Size)
        {
            value = this->_Container[index];
            return value;
        }
        std::string message = "index: " + std::to_string(index)
                                + " is greater than "
                                + "size of array: " + std::to_string(this->_Size);
        throw Exception::IndexOutOfBoundsException(message);
    }

    /**
     * @brief   Sets value present in the index^{th} block of the array to the one
     *          provided by the user
     * @details If index is greater than the size of the array an exception
     *          "IndexOutOfBoundsException" is thrown
     *          **Time complexity:** O(1)
     *          **Space complexity:** O(1)
     *
     * @tparam  T Generic parameter
     * @param   [size_t] index - Location in array whose value has to be modified
     * @param   [T] value - Value which should be put in the index^{th} location of
     *                      the array
     */
    template<typename T>
    void
    IArray<T>::Set(
            size_t index,
            T value
            )
    {
        if (index < this->_Capacity)
        {
            this->_Container[index] = value;
        }
        std::string message = "index: " + std::to_string(index)
                              + " is greater than "
                              + "size of array: " + std::to_string(this->_Size);
        throw Exception::IndexOutOfBoundsException(message);
    }

    /**
     * @brief   Returns the current size of the array
     * @details **Time complexity:** O(1)
     *          **Space complexity:** O(1)
     *
     * @tparam  T Generic parameter
     * @return  [size_t] Returns the current size of the array
     */
    template<typename T>
    size_t
    IArray<T>::Size() const
    {
        // Reference: https://stackoverflow.com/questions/3141087/what-is-meant-with-const-at-end-of-function-declaration
        return this->_Size;
    }

    /**
     * @brief   Returns true if array is empty else false
     * @details **Time complexity:** O(1)
     *          **Space complexity:** O(1)
     *
     * @tparam  T Generic parameter
     * @return  [bool] Returns true if array is empty else false
     */
    template<typename T>
    bool
    IArray<T>::IsEmpty() const
    {
        // Returns true if _Size is set to 0, else false
        return this->_Size == 0;
    }

    /**
     * @brief   Get a reference to the memory address of the array indexed by
     *          variable 'index'
     * @details  **Time complexity:** O(1)
     *          **Space complexity:** O(1)
     *
     * @tparam  T Generic parameter
     * @param   [size_t] index - Location in the array
     * @return  [T] Reference to the location index in the array
     */
    template <typename T>
    T& IArray<T>::operator[] (
            size_t index
            )
    {
        // Values inside the _Container can be accessed if the index requested
        // is less than the size of Array object
        if(index < this->_Size)
        {
            return this->_Container[index];
        }
        std::string message = "index: " + std::to_string(index)
                              + " is greater than "
                              + "size of array: " + std::to_string(this->_Size);
        throw Exception::IndexOutOfBoundsException(message);
    }

    /**
     * @brief   Get the value present in the array at the location indexed by
     *          variable 'index'
     * @details **Time complexity:** O(1)
     *          **Space complexity:** O(1)
     *
     * @tparam  T Generic parameter
     * @param   [size_t] index - Location in the array
     * @return  [T] Value present at the location index in the array
     */
    template <typename T>
    T IArray<T>::operator[] (
            size_t index
            ) const
    {
        this->Get(index);
    }

    /**
     * @brief   Prints the contents of the array to the ostream operator
     * @details
     *
     * @tparam  T Generic parameter
     * @param   [std::ostream] os - Ostream operator to which contents of the array have
     *                        to be printed
     * @param   [IArray<T>&] array - Array which has to be printed
     * @return  [std::ostream] os - Ostream operator with the array contents
     */
    template<typename T>
    std::ostream &operator<<(std::ostream &os, const IArray<T> &array)
    {
        os << "[";
        for (size_t __index = 0; __index < array.Size(); ++__index)
        {
            if (__index != array.Size() - 1)
            {
                os << array.Get(__index) << ", ";
            }
            else
            {
                os << array.Get(__index);// << "\n";
            }
        }
        os << "]";
        return os;
    }

    /**
     * @brief   Reset the contents of the array with default value
     * @details
     *
     * @tparam  T Generic parameter
     * @return  void
     */
    template<typename T>
    void IArray<T>::Reset()
    {
        for (size_t __index = 0; __index < this->_Size; ++__index)
        {
            this->_Container[__index] = T();
        }
    }

    /**
     * @brief   Return the contents of the array as string
     * @details
     *
     * @tparam  T Generic parameter
     * @return  [std::string] - String representation of the array
     */
    template<typename T>
    std::string IArray<T>::ToString() const
    {
        std::stringstream ss;
        ss << "[";
        for (size_t __index = 0; __index < this->_Size; ++__index)
        {
            if (__index != this->_Size - 1)
            {
                ss << this.Get(__index) << ", ";
            }
            else
            {
                ss << this.Get(__index);// << "\n";
            }
        }
        ss << "]";
        return ss.str();
    }

    /**
     * @brief   Returns the elements present in the first part of the array
     * @details If the array is empty, an exception "EmptyException" is thrown
     *
     * @tparam T Generic parameter
     * @return [T] - Value present in the first block of the array (First element of the array)
     */
    template <typename T>
    T IArray<T>::Front() const
    {
        if (this->_Size == 0)
        {
            std::string message = "index: " + std::to_string(0)
                + " is greater than "
                + "size of array: " + std::to_string(this->_Size);
            throw Exception::IndexOutOfBoundsException(message);
        }
        return this->_Container[0];
    }

    /**
     * @brief   Returns the elements present in the last part of the array
     * @details If the array is empty, an exception "EmptyException" is thrown
     *
     * @tparam T Generic parameter
     * @return [T] - Value present in the last block of the array (Last element of the array)
     */
    template <typename T>
    T IArray<T>::Back() const
    {
        if (this->_Size == 0)
        {
            std::string message = "index: " + std::to_string(0)
                + " is greater than "
                + "size of array: " + std::to_string(this->_Size);
            throw Exception::IndexOutOfBoundsException(message);
        }
        return this->_Container[this->_Size - 1];
    }



}

#endif // IARRAY_H
