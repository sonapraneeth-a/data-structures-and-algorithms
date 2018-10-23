/**
 *      Created on: 05 March 2018
 *   Last modified: 17 August 2018
 *          Author: Sona Praneeth Akula
 *         Details: Header for SingleLinkedList
 */

/**
 * Changelog
 *
 * Date (DD-MM-YYYY)            Author               Update
 * 05-03-2018           Sona Praneeth Akula   - Creation of file
 *                                            - Added function signature for singlelinkedlist -
 *                                              constructors, destructors, ToString(), GetSize(),
 *                                              Insert(), Clear(), Print(), Deletehead()
 * 17-08-2018           Sona Praneeth Akula   - Renamed GetSize() to Size()
 *                                            - Added function signature for InsertAtHead()
 */

#ifndef DS_LIST_SLL_H
#define DS_LIST_SLL_H

#include "SingleLinkedListNode.h"

template <typename T>
class SingleLinkedList
{
private:

    SingleLinkedListNode<T> *_Head;
    unsigned int _Size;


public:

    SingleLinkedList();
    SingleLinkedList(T Value);

    SingleLinkedListNode<T>* Head();
    void Print();
    std::string ToString();
    unsigned int Size();
    void InsertAtHead(T Value);
    void DeleteHead();
    void Clear();
    void Insert(T Value);

};


#endif //DS_LIST_SLL_H
