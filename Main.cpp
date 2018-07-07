//
// Created by pranas on 7/3/2018.
//

#include "DefaultHeaders.h"
#include "Factorization.h"
#include "Stack.h"
#include "Vector2d.h"
#include <string>

void
GCD()
{
    std::cout << EuclideanGCDIterative(6, 12) << "\n";
    return;
}

void
RunStack()
{
    Stack<std::string> TestStack;
    TestStack.Push("Rama");
    std::cout << TestStack.Peek() << "\n";
}

void
RunVector2d()
{
    Geometry::Vector2d<double> vec(10);
    std::cout << vec.GetX() << "\n";
    return;
}

int main()
{
    RunVector2d();
    return 0;
}
