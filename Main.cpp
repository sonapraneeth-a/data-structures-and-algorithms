//
// Created by pranas on 7/3/2018.
//

#include "DefaultHeaders.h"
#include "Factorization.h"
#include "Stack.h"

int main()
{
    std::cout << EuclideanGCDIterative(6, 12) << "\n";
    Stack<std::string> TestStack;
    TestStack.Push("Rama");
    std::cout << TestStack.Peek() << "\n";
    return 0;
}
