//
// Created by pranas on 7/15/2018.
//

#include "PointNd.h"

int main()
{
    Geometry::PointNd<4, int> point_4d(10);
    std::cout << point_4d << "\n";
    return 0;
}