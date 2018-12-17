/**
 * File description
 *
 *        Filename: IArray.h
 *      Created on: 13 December 2018
 *   Last modified: 17 December 2018
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
 */

#ifndef IARRAY_H
#define IARRAY_H

#include <cstdlib>
#include <ostream>

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
//    virtual void Insert(size_t index, T value) = 0;
//    virtual void Remove(size_t index) = 0;

        T operator[] (size_t index) const;
        T& operator[] (size_t index);

    protected:

        T *_Container = nullptr;   /*!< Variable containing the array elements */
        size_t _Capacity = 0;      /*!< Maximum capacity of the array */
        size_t _Size = 0;          /*!< Current size of the array */

    };

    /**
     * @brief   Returns value present in the index^{th} block of the array
     * @details If the index given is invalid, then an "OutOfBoundsException"
     *          exception is thrown.
     *           **Time complexity:** O(1)
     *          **Space complexity:** O(1)
     *
     * @tparam  T Generic parameter
     * @param   [size_t] index - Index of the array for which user wants the contents
     * @return  [T] - Value in the Array at that location. If value is not set (or)
     *                index trying to access invalid location then an exception
     *                "OutOfBoundsException" is thrown
     */
    template<typename T>
    T
    IArray<T>::Get(
            size_t index
            ) const
    {
        T value;
        if (index < this->_Size)
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
     *           **Time complexity:** O(1)
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
        if (index >= this->_Capacity)
        {

        }
        this->_Container[index] = value;
        return;
    }

    /**
     * @brief   Returns the current size of the array
     * @details  **Time complexity:** O(1)
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
     * @details  **Time complexity:** O(1)
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
    }

    /**
     * @brief   Get the value present in the array at the location indexed by
     *          variable 'index'
     * @details  **Time complexity:** O(1)
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
        // Values inside the _Container can be accessed if the index requested
        // is less than the size of Array object
        if(index < this->_Size)
        {
            return this->_Container[index];
        }
    }

}

#endif // IARRAY_H