/**
 * File description
 *
 *        Filename: Node.h
 *      Created on: 15 January 2019
 *   Last modified: 15 January 2019
 *          Author: sonapraneeth-a
 *         Details: Header for node
 */

/**
 * Changelog
 *
 * Date (DD-MM-YYYY)            Author               Update
 * 15-01-2019             sonapraneeth-a        - Creation of the file
 *                                              - Added function signatures
 *                                              - Added comments for the constructor
 *                                                and protected variables
 */

#ifndef NODE_H
#define NODE_H

#include <cstdlib>
#include <sstream>

namespace DS
{
    /*! @class Node
     *  @brief An interface for Node class.
     *
     *  @details This is an interface for Node class
     */
    template<typename T>
    class Node
    {

    protected:

        T _Data;            /*!< Variable containing the value to be contained in Node */
        Node<T> *_Next;     /*!< Variable containing the pointer to next Node */

    public:

        /**
         * @brief   Default empty constructor for node
         * @details
         *
         * @tparam T Generic Parameter
         */
        explicit Node(): _Data(T()), _Next(nullptr) {};

        /**
         * @brief   Constructor which initializes data element in the Node
         * @details
         *
         * @tparam T Generic Parameter
         * @param  [T] value - Value to be contained in the node
         */
        explicit Node(T value): _Data(value), _Next(nullptr) {};

        T Data() const;
        void Data(T value);

        Node<T> *Next() const;
        void Next(Node<T> *nextLink);

        std::string ToString();

        ~Node();

    };

    #include "Node.cpp"
}

#endif // NODE_H
