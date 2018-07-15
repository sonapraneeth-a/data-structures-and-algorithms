//
// Created by pranas on 3/23/2018.
//


/**
 *
 * @tparam T
 * @param Value
 */
template <typename T>
QueueNode<T>::QueueNode(T Value)
{
    _Data = Value;
    _Next = nullptr;
}

/**
 *
 * @tparam T
 * @return
 */
template <typename T>
T QueueNode<T>::Data() const
{
    return this->_Data;
}

/**
 *
 * @tparam T
 * @return
 */
template <typename T>
QueueNode<T>* QueueNode<T>::Next() const
{
    return this->_Next;
}

/**
 *
 * @tparam T
 * @param Value
 */
template <typename T>
void QueueNode<T>::Data(T Value)
{
    this->_Data = Value;
}

/**
 *
 * @tparam T
 * @param NextLink
 */
template <typename T>
void QueueNode<T>::SetNext(QueueNode<T> *NextLink)
{
    this->_Next = NextLink;
}

/**
 *
 * @tparam T
 * @return
 */
template <typename T>
std::string QueueNode<T>::ToString()
{
    std::stringstream out;
    out << this->_Data << " -> " << this->_Next;
    return out.str();
}

/**
 *
 * @tparam T
 */
template <typename T>
QueueNode<T>::~QueueNode()
{
    this->_Next = nullptr;
}

//template class QueueNode<int>;
//template class QueueNode<BinaryTreeNode<int>*>;