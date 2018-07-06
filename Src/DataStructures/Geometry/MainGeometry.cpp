//
// Created by pranas on 7/6/2018.
//

#include "Vector2d.h"

void
RunVector2d()
{
    Geometry::Vector2d<int> v(10);
    std::cout << v.GetX() << "\n";
    Geometry::Vector2d<int> v1;
    std::cout << v1.GetX() << "\n";
    return ;
}

int main()
{
    RunVector2d();
    return 0;
}