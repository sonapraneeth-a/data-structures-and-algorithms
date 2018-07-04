/**
 *      Created on: 21 March 2018
 *   Last modified: 22 March 2018
 *          Author: Sona Praneeth Akula
 *         Details: Implementation for stack node
 */

/**
 * Changelog
 *
 * Date (DD-MM-YYYY)            Author               Update
 * 21-03-2018             Sona Praneeth Akula   - Creation of the file
 * 22-03-2018             Sona Praneeth Akula   - Completed function signatures
 */


/**
 *
 * @tparam T
 * @param Value
 */
template <typename T>
StackNode<T>::StackNode(T Value)
{
    Data = Value;
    Next = nullptr;
}

/**
 *
 * @tparam T
 * @return
 */
template <typename T>
T StackNode<T>::GetData()
{
    return this->Data;
}

/**
 *
 * @tparam T
 * @return
 */
template <typename T>
StackNode<T>* StackNode<T>::GetNext()
{
    return this->Next;
}

/**
 *
 * @tparam T
 * @param Value
 */
template <typename T>
void StackNode<T>::SetData(T Value)
{
    Data = Value;
}

/**
 *
 * @tparam T
 * @param NextLink
 */
template <typename T>
void StackNode<T>::SetNext(StackNode<T> *NextLink)
{
    Next = NextLink;
}

/**
 *
 * @tparam T
 * @return
 */
template <typename T>
std::string StackNode<T>::ToString()
{
    std::stringstream out;
    out << this->Data << " -> " << this->Next;
    return out.str();
}

/**
 *
 * @tparam T
 */
template <typename T>
StackNode<T>::~StackNode()
{
    Next = nullptr;
}
