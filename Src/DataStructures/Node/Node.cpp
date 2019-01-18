/**
 * File description
 *
 *        Filename: Node.cpp
 *      Created on: 15 January 2019
 *   Last modified: 16 January 2019
 *          Author: sonapraneeth-a
 *         Details: Implementation for node
 */

/**
 * Changelog
 *
 * Date (DD-MM-YYYY)            Author               Update
 * 15-01-2019             sonapraneeth-a        - Creation of the file
 *                                              - Completed function signatures
 * 16-01-2019             sonapraneeth-a        - Added comments for the functions
 */

/**
 * @brief   Get the data present in the Node
 * @details
 *
 * @return  [T] data present in the node
 */
template <typename T>
T 
DS::Node<T>::Data() const
{
    return this->_Data;
}

/**
 * @brief   Sets the data value in the current node based on the given input
 *          value
 * @details
 *
 * @tparam  T Generic parameter
 * @param   [T] value - Value to be set for the data in current node
 */
template <typename T>
void
DS::Node<T>::Data(T value)
{
    this->_Data = value;
}

/**
 * @brief   Get the pointer to next node present in the Node
 * @details
 *
 * @return  [T] Pointer to next node for the current node
 */
template <typename T>
Node<T>*
DS::Node<T>::Next() const
{
    return this->_Next;
}

/**
 * @brief   Sets the next pointer to the current node based on the given input
 *          next link
 * @details
 *
 * @tparam  T Generic parameter
 * @param   [Node<T> *] NextLink - Pointer to the next node
 */
template <typename T>
void
DS::Node<T>::Next(Node<T> *nextLink)
{
    this->_Next = nextLink;
}

/**
 * @brief   Converts the Node object to std::string
 * @details
 *
 * @return  [std::string] Returns string format of the node object containing
 *                        the data and the address of the next pointer
 */
template <typename T>
std::string
DS::Node<T>::ToString()
{
    std::stringstream out;
    out << this->_Data << " -> " << this->_Next;
    return out.str();
}

/**
 * @brief   Prints the contents of the Node to the ostream operator
 * @details
 *
 * @tparam  T Generic parameter
 * @param   [std::ostream] os - Ostream operator to which contents of the node have
 *                        to be printed
 * @param   [Node<T>&] node - Node which has to be printed
 * @return  [std::ostream] os - Ostream operator with the noed contents
 */
template<typename T>
std::ostream &
operator<<(std::ostream &os, const Node<T> &node)
{
    if (node.Next())
    {
        os << node.Data() << " -> " << node.Next();
    }
    else
    {
        os << node.Data() << " -> NULL";
    }
    return os;
}

/**
 * @brief   Destructor for the class Node
 * @details Deletes the memory assigned for the Node and sets _Next back to null
 *
 */
template <typename T>
DS::Node<T>::~Node()
{
    this->_Next = nullptr;
}
