/**
 *      Created on: 05 March 2018
 *   Last modified: 17 August 2018
 *          Author: Sona Praneeth Akula
 *         Details: Implementation for SingleLinkedList
 */

/**
 * Changelog
 *
 * Date (DD-MM-YYYY)            Author               Update
 * 05-03-2018           Sona Praneeth Akula   - Creation of file
 *                                            - Added function implementations for singlelinkedlist -
 *                                              constructors, destructors, ToString(), GetSize(),
 *                                              Insert(), Clear(), Print(), Deletehead()
 * 17-08-2018           Sona Praneeth Akula   - Renamed GetSize() to Size()
 *                                            - Added function implementations for InsertAtHead()
 */

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
    _Head = nullptr;
    this->_Size = 0;
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
    _Head = new SingleLinkedListNode<T>(Value);
    this->_Size = 1;
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
SingleLinkedListNode<T>* SingleLinkedList<T>::Head()
{
    return _Head;
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
void SingleLinkedList<T>::Print()
{
    SingleLinkedListNode<T> *temp = this->_Head;
    while (temp)
    {
        std::cout << temp->Data() << " ";
        temp = temp->Next();
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
    SingleLinkedListNode<T> *temp = this->_Head;
    std::stringstream out;
    while (temp)
    {
        out << temp->Data() << " -> ";
        temp = temp->Next();
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
    SingleLinkedListNode<T> *temp = this->_Head;
    if(temp == nullptr)
    {
        this->_Head = new SingleLinkedListNode<T>(Value);
        this->_Size = 1;
        return;
    }
    while (temp->Next() != nullptr)
    {
        temp = temp->Next();
    }
    temp->Next(new SingleLinkedListNode<T>(Value));
    this->_Size++;
    return;
}

/*!
 * @brief  Insert a node at the start of list
 * @details
 *
 * @tparam T Generic parameter type. Currently supported types: int, double, char, std::string
 * @param [in] Value - The value to be inserted into the single linked list
 * @return
 */
template <typename T>
void SingleLinkedList<T>::InsertAtHead(T Value)
{
    SingleLinkedListNode<T> *__Temp = this->_Head;
    SingleLinkedListNode<T> *__NewNode = new SingleLinkedListNode<T>(Value);
    if(__Temp == nullptr)
    {
        this->_Head = __NewNode;
        this->_Size = 1;
        return;
    }
    __NewNode->Next(this->_Head);
    this->_Head = __NewNode;
    this->_Size++;
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
unsigned int SingleLinkedList<T>::Size()
{
    return this->_Size;
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
    SingleLinkedListNode<T> *temp = this->_Head;
    if(temp == nullptr)
    {
        exit(-1);
    }
    this->_Head = temp->Next();
    this->_Size--;
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
    SingleLinkedListNode<T> *temp = this->_Head;
    if(temp == nullptr)
    {
        return ;
    }
    while(this->_Head)
    {
        this->DeleteHead();
    }
    return ;
}

template class SingleLinkedList<int>;
template class SingleLinkedList<double>;
template class SingleLinkedList<char>;
template class SingleLinkedList<std::string>;
