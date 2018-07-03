//
// Created by pranas on 3/15/2018.
//

#include "Utilities.h"

int GetRandomInt(int start, int end, std::string mode)
{
    int number;
    if (mode == "Random")
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

double GetRandomDouble(int start, int end, std::string mode)
{
    std::random_device rd;
    std::mt19937 mt(rd());
    std::uniform_real_distribution<double> dist(start, end);
    return dist(mt);
}
