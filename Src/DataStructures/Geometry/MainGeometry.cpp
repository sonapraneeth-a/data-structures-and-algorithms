//
// Created by pranas on 7/6/2018.
//

#include "Vector2d.h"

void
RunVector2d()
{
    Geometry::Vector2d<int> v(10);
    Geometry::Vector2d<int> v1;
    Geometry::Vector2d<int> v2 = v + v1;
    std::cout << "Vector v(0): " << v.GetX() << "\n";
    std::cout << "Vector v1(0): " << v1.GetX() << "\n";
    std::cout << "Vector v: " << v << "\n";
    std::cout << "Vector v1: " << v1 << "\n";
    std::cout << "Vector v2: " << v2 << "\n";
    std::cout << "Vector v2: " << v2.GetX() << ", " << v2.GetY() << "\n";
    return ;
}

int main()
{
    RunVector2d();
    return 0;
}