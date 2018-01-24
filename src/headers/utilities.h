#ifndef UTILITIES_H
#define UTILITIES_H

#include "default_headers.h"

int get_random_int(int start=100, int end=100000, std::string mode="fixed")
{
    int number;
    if (mode == "random")
    {
        srand((int) time(0));
        number = (rand() % end) + start;
    }
    else
    {
        std::random_device rd;
        std::mt19937 mt(rd());
        std::uniform_int_distribution<int> dist(start, end);
        number = dist(mt);
    }
    return number;
}

double get_random_double(int start=100, int end=100000, std::string mode="fixed")
{
    std::random_device rd;
    std::mt19937 mt(rd());
    std::uniform_real_distribution<double> dist(start, end);
    return dist(mt);
}

#endif