//
// Created by pranas on 3/1/2018.
//

#include "random_number.h"

int
random_number::gen_lcg(int a, int b, int m)
{
    int x_0 = 0;
    int x_1 = a*x_0 + b %m;
    return x_1;
}