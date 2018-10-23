/**
 *      Created on: 20 March 2018
 *   Last modified: 14 October 2018
 *          Author: Sona Praneeth Akula
 *         Details: File for testing stack implementation
 */

/**
 * Changelog
 *
 * Date (DD-MM-YYYY)            Author               Update
 * 20-03-2018             Sona Praneeth Akula   - Creation of the file
 * 22-03-2018             Sona Praneeth Akula   - Testing stack exceptions
 * 14-10-2018             Sona Praneeth Akula   - Added catch block for empty exception
 */

#include "Stack.h"


int main(int argc, char **argv)
{
    Stack<int> stack;
    int array[3] = {30, 40, 50};
    for(unsigned int index = 0; index < 3; index++)
    {
        std::cout << "Pushing " << array[index] << "\n";
        stack.Push(array[index]);
        std::cout << "Pushed " << stack.Peek() << ".Stack size: " << stack.Size() << "\n";
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
    catch  (EmptyException &e)
    {
        std::cout << e.what() << "\n";
    }
    std::cout << "MainStack Complete\n";
    return 0;
}