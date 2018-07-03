#include "DoubleLinkedList.h"
#include <iostream>

/*!
 * @brief   DoubleLinkedList Constructor with no value for head
 * @details Create a pointer to the head of the Double linked list. But head of the list will not contain any value.
 *
 * @tparam T Generic parameter type. Currently supported types: int, double, char, std::string
 */
template <typename T>
DoubleLinkedList<T>::DoubleLinkedList()
{
    Head = nullptr;
    this->Size = 0;
}

/*!
 * @brief   DoubleLinkedList Constructor with input value for head
 * @details Create a pointer to the head of the linked list. But head of the list will contain the value
 *          provided the program
 *
 * @tparam T Generic parameter type. Currently supported types: int, double, char, std::string
 * @param [in] Value - value to be put in the Double linked list node
 * @return
 */
template <typename T>
DoubleLinkedList<T>::DoubleLinkedList(T Value)
{
    Head = new DoubleLinkedListNode<T>(Value);
    this->Size = 1;
}

/*!
 * @brief   Get pointer to head of Double linked list
 * @details
 *
 * @tparam T Generic parameter type. Currently supported types: int, double, char, std::string
 * @param
 * @return [out] DoubleLinkedListNode * - Pointer to the head of the Double linked list node
 */
template <typename T>
DoubleLinkedListNode<T>* DoubleLinkedList<T>::GetHead()
{
    return Head;
}

/*!
 * @brief   Print the contents of the Double linked list on console
 * @details
 *
 * @tparam T Generic parameter type. Currently supported types: int, double, char, std::string
 * @param
 * @return
 */
template <typename T>
void DoubleLinkedList<T>::PrintList()
{
    DoubleLinkedListNode<T> *temp = this->Head;
    while (temp)
    {
        std::cout << temp->GetData() << " ";
        temp = temp->GetNext();
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
 * @return [out] std::string - String representation of the Double linked list
 */
template <typename T>
std::string DoubleLinkedList<T>::ToString()
{
    DoubleLinkedListNode<T> *temp = this->Head;
    std::stringstream out;
    while (temp)
    {
        out << temp->GetData() << " -> ";
        temp = temp->GetNext();
    }
    out << temp;
    return out.str();
}

/*!
 * @brief  Insert a node at the end of list
 * @details
 *
 * @tparam T Generic parameter type. Currently supported types: int, double, char, std::string
 * @param [in] Value - The value to be inserted into the Double linked list
 * @return
 */
template <typename T>
void DoubleLinkedList<T>::Insert(T Value)
{
    DoubleLinkedListNode<T> *temp = this->Head;
    if(temp == nullptr)
    {
        this->Head = new DoubleLinkedListNode<T>(Value);
        this->Size = 1;
        return;
    }
    while (temp->GetNext() != nullptr)
    {
        temp = temp->GetNext();
    }
    temp->SetNext(new DoubleLinkedListNode<T>(Value));
    this->Size++;
    return;
}

/*!
 * @brief  Get the length of the Double linked list
 * @details
 *
 * @tparam T Generic parameter type. Currently supported types: int, double, char, std::string
 * @param
 * @return [out] unsigned int - Size of the Double linked list
 */
template <typename T>
unsigned int DoubleLinkedList<T>::GetSize()
{
    return this->Size;
}

/*!
 * @brief   Delete the head of the list
 * @details Removes the first element from the start of the Double linked list
 *
 * @tparam T Generic parameter type. Currently supported types: int, double, char, std::string
 * @param
 * @return
 */
template <typename T>
void DoubleLinkedList<T>::DeleteHead()
{
    DoubleLinkedListNode<T> *temp = this->Head;
    if(temp == nullptr)
    {
        exit(-1);
    }
    this->Head = temp->GetNext();
    this->Size--;
    delete temp;
}

/*!
 * @brief   Clear the Double linked list
 * @details Removes all the nods from the Double linked list
 *
 * @tparam T Generic parameter type. Currently supported types: int, double, char, std::string
 * @param
 * @return void
 */
template <typename T>
void DoubleLinkedList<T>::Clear()
{
    DoubleLinkedListNode<T> *temp = this->Head;
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

template class DoubleLinkedList<int>;
template class DoubleLinkedList<double>;
template class DoubleLinkedList<char>;
template class DoubleLinkedList<std::string>;
