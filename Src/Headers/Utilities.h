#ifndef UTILITIES_H
#define UTILITIES_H

#include <random>
#include <ctime>
#include "DefaultHeaders.h"

#define LLI long long int

inline int
GetRandomInt(int start=100, int end=100000, std::string mode="Fixed")
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

inline double
GetRandomDouble(int start=100, int end=100000, std::string mode="Fixed")
{
    std::random_device rd;
    std::mt19937 mt(rd());
    std::uniform_real_distribution<double> dist(start, end);
    return dist(mt);
}


template <typename T>
bool LessComparator(T first, T second)
{
    return first <= second;
}

template <typename T>
bool GreaterComparator(T first, T second)
{
    return first >= second;
}

template <typename T>
void Swap(T& first, T& second)
{
    T temp = second;
    second = first;
    first = temp;
}

template <typename T>
void PrintOneDArray(T Array[], LLI start, LLI end)
{
    for (LLI index = start; index < end; ++index)
    {
        std::cout << Array[index] << " ";
    }
    std::cout << "\n";
}

#endif