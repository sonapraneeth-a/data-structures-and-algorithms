#ifndef UTILITIES_H
#define UTILITIES_H

#include <random>
#include <ctime>

#define LLI long long int

int
GetRandomInt(int start=100, int end=100000, std::string mode="Fixed");

double
GetRandomDouble(int start=100, int end=100000, std::string mode="Fixed");

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