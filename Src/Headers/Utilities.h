#ifndef UTILITIES_H
#define UTILITIES_H

#include <random>
#include <ctime>

int GetRandomInt(int start=100, int end=100000, std::string mode="Fixed")
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

double GetRandomDouble(int start=100, int end=100000, std::string mode="Fixed")
{
    std::random_device rd;
    std::mt19937 mt(rd());
    std::uniform_real_distribution<double> dist(start, end);
    return dist(mt);
}

#endif