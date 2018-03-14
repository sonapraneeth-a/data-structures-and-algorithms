#include "SingleLinkedList.h"
#include <iostream>

/*!
 * @brief   SingleLinkedList Constructor with no value for head
 * @details Create a pointer to the head of the single linked list. But head of the list will not contain any value.
 *
 * @tparam T Generic parameter type. Currently supported types: int, double, char, std::string
 */
template <typename T>
SingleLinkedList<T>::SingleLinkedList()
{
    Head = nullptr;
    this->Size = 0;
}

/*!
 * @brief   SingleLinkedList Constructor with input value for head
 * @details Create a pointer to the head of the linked list. But head of the list will contain the value
 *          provided the program
 *
 * @tparam T Generic parameter type. Currently supported types: int, double, char, std::string
 * @param [in] Value - value to be put in the single linked list node
 * @return
 */
template <typename T>
SingleLinkedList<T>::SingleLinkedList(T Value)
{
    Head = new SingleLinkedListNode<T>(Value);
    this->Size = 1;
}

/*!
 * @brief   Get pointer to head of single linked list
 * @details
 *
 * @tparam T Generic parameter type. Currently supported types: int, double, char, std::string
 * @param
 * @return [out] SingleLinkedListNode * - Pointer to the head of the single linked list node
 */
template <typename T>
SingleLinkedListNode<T>* SingleLinkedList<T>::GetHead()
{
    return Head;
}

/*!
 * @brief   Print the contents of the single linked list on console
 * @details
 *
 * @tparam T Generic parameter type. Currently supported types: int, double, char, std::string
 * @param
 * @return
 */
template <typename T>
void SingleLinkedList<T>::PrintList()
{
    SingleLinkedListNode<T> *temp = this->Head;
    while (temp)
    {
        std::cout << temp->get_data() << " ";
        temp = temp->get_next();
    }
    std::cout << "\n";
    return;
}

/*!
 * @brief   Return the list as string
 * @details
 *
 * @tparam T Generic parameter type. Currently supported types: int, double, char, std::string
 * @param
 * @return [out] std::string - String representation of the single linked list
 */
template <typename T>
std::string SingleLinkedList<T>::ToString()
{
    SingleLinkedListNode<T> *temp = this->Head;
    std::stringstream out;
    while (temp)
    {
        out << temp->get_data() << " -> ";
        temp = temp->get_next();
    }
    out << temp;
    return out.str();
}

/*!
 * @brief  Insert a node at the end of list
 * @details
 *
 * @tparam T Generic parameter type. Currently supported types: int, double, char, std::string
 * @param [in] Value - The value to be inserted into the single linked list
 * @return
 */
template <typename T>
void SingleLinkedList<T>::Insert(T Value)
{
    SingleLinkedListNode<T> *temp = this->Head;
    if(temp == nullptr)
    {
        this->Head = new SingleLinkedListNode<T>(Value);
        this->Size = 1;
        return;
    }
    while (temp->get_next() != nullptr)
    {
        temp = temp->get_next();
    }
    temp->set_next(new SingleLinkedListNode<T>(Value));
    this->Size++;
    return;
}

/*!
 * @brief  Get the length of the single linked list
 * @details
 *
 * @tparam T Generic parameter type. Currently supported types: int, double, char, std::string
 * @param
 * @return [out] unsigned int - Size of the single linked list
 */
template <typename T>
unsigned int SingleLinkedList<T>::GetSize()
{
    return this->Size;
}

/*!
 * @brief   Delete the head of the list
 * @details Removes the first element from the start of the single linked list
 *
 * @tparam T Generic parameter type. Currently supported types: int, double, char, std::string
 * @param
 * @return
 */
template <typename T>
void SingleLinkedList<T>::DeleteHead()
{
    SingleLinkedListNode<T> *temp = this->Head;
    if(temp == nullptr)
    {
        exit(-1);
    }
    this->Head = temp->get_next();
    this->Size--;
    delete temp;
}

/*!
 * @brief   Clear the single linked list
 * @details Removes all the nods from the single linked list
 *
 * @tparam T Generic parameter type. Currently supported types: int, double, char, std::string
 * @param
 * @return void
 */
template <typename T>
void SingleLinkedList<T>::Clear()
{
    SingleLinkedListNode<T> *temp = this->Head;
    if(temp == nullptr)
    {
        return ;
    }
    while(this->Head)
    {
        this->DeleteHead();
    }
    return ;
}

template class SingleLinkedList<int>;
template class SingleLinkedList<double>;
template class SingleLinkedList<char>;
template class SingleLinkedList<std::string>;
