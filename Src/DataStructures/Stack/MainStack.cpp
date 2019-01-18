/**
 * File description
 *
 *        Filename: MainStack.cpp
 *      Created on: 20 March 2018
 *   Last modified: 18 January 2019
 *          Author: sonapraneeth-a
 *         Details: File for testing stack implementation
 */

/**
 * Changelog
 *
 * Date (DD-MM-YYYY)            Author               Update
 * 20-03-2018               sonapraneeth-a        - Creation of the file
 * 22-03-2018               sonapraneeth-a        - Testing stack exceptions
 * 14-10-2018               sonapraneeth-a        - Added catch block for empty
 *                                                exception
 * 18-01-2019               sonapaneeth-a         - Moved code to Run_Push()
 *                                                - Added code for Run_Pop()
 *                                                - Added code for Run_Peek()
 */

#include "Stack.h"
#include "DefaultHeaders.h"

#include <iostream>

/**
 * @brief   Code for testing Stack Push()
 * @details
 *
 * @return
 */
void 
Run_Push()
{
    PrintHeading("Running code for Stack Push()", 2);

    DS::Stack<int> stack;
    int array[3] = {30, 40, 50};
    for (auto element: array)
    {
        std::cout << "Pushing " << element << "\n";
        stack.Push(element);
        std::cout << "Pushed " << stack.Peek() << ". Stack size: " << stack.Size() << "\n";
    }
    std::cout << stack << "\n";
}

/**
 * @brief   Code for testing Stack Pop()
 * @details
 *
 * @return
 */
void 
Run_Pop()
{
    PrintHeading("Running code for Stack Pop()", 2);

    DS::Stack<int> stack;
    int array[3] = {30, 40, 50};
    for (auto element: array)
    {
        std::cout << "Pushing " << element << "\n";
        stack.Push(element);
    }
    try
    {
        std::cout << "Popping " << stack.Peek() << "\n";
        stack.Pop();
        std::cout << "Popping " << stack.Peek() << "\n";
        stack.Pop();
        std::cout << "Popping " << stack.Peek() << "\n";
        stack.Pop();
        std::cout << "Popping " << stack.Peek() << "\n";
        stack.Pop();
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << "\n";
    }
}

/**
 * @brief   Code for testing Stack Peek()
 * @details
 *
 * @return
 */
void 
Run_Peek()
{
    PrintHeading("Running code for Stack Peek()", 2);

    DS::Stack<int> stack;
    int array[3] = {30, 40, 50};
    for (auto element: array)
    {
        std::cout << "Pushing " << element << "\n";
        stack.Push(element);
        std::cout << "Peeking top of stack: " << stack.Peek() << "\n";
    }
}

/**
 * @brief   Code for manual testing of Stack module
 * @details
 *
 * @return
 */
int
main(int argc, char **argv)
{
    PrintProjectInfo();
    std::cout << "\n";

    PrintHeading("Sample code for Stack module", 1);

    Run_Push();
    Run_Pop();
    Run_Peek();

    return 0;
}
