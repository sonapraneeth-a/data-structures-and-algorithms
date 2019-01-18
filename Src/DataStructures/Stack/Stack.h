/**
 * File description
 *
 *        Filename: Stack.h
 *      Created on: 21 March 2018
 *   Last modified: 15 January 2019
 *          Author: sonapraneeth-a
 *         Details: Header for stack (Imported from master branch)
 */

/**
 * Changelog
 *
 * Date (DD-MM-YYYY)            Author               Update
 * 21-03-2018               sonapraneeth-a        - Creation of the file
 * 22-03-2018               sonapraneeth-a        - Added function signatures
 * 17-04-2018               sonapraneeth-a        - Added function signature to
 *                                                get size of the stack
 * 15-01-2019               sonapraneeth-a        - Moved from StackNode to Node
 *                                                - Moved from ULLI to size_t for
 *                                                  size type
 * 18-01-2019               sonapraneeth-a        - Moved the code to DS namespace
 *                                                - Renamed _MaxSize variable to _Capacity
 */

#ifndef STACK_H
#define STACK_H

#include "Node.h"
#include "AccessViolationException.h"


namespace DS {
    template<typename T>
    class Stack {
    private:

        DS::Node<T> *_Top;      /*!< Variable containing the pointer to top of Stack */
        size_t _Size = 0;       /*!< Variable containing the size of the Stack */
        size_t _Capacity = 0;   /*!< Variable containing the maximum capacity of Stack */

    public:

        explicit Stack();
        explicit Stack(T value);

        T Peek();
        T Pop();
        void Push(T value);

        size_t Size() const;
        bool IsEmpty();

        /**
         * @brief   Prints the contents of the Stack to the ostream operator
         * @details
         *
         * @tparam  T Generic parameter
         * @param   [std::ostream] os - Ostream operator to which contents of the stack have
         *                        to be printed
         * @param   [Node<T>&] node - Stack which has to be printed
         * @return  [std::ostream] os - Ostream operator with the stack contents
         */
        friend std::ostream &
        operator<<(std::ostream &os, const Stack<T> &stack)
        {
            // Reference: https://stackoverflow.com/questions/10787655/c-friend-declaration-declares-a-non-template-function/10787730#10787730
            DS::Node<T> *__TempNode = stack._Top;
            os << "Stack contents\n";
            while (__TempNode != nullptr)
            {
                os << __TempNode->Data() << "\n";
                __TempNode = __TempNode->Next();
            }
            return os;
        }

        ~Stack();

    };


#include "Stack.cpp"

}

#endif // STACK_H
