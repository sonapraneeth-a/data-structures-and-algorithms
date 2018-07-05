#ifndef UTILITIES_H
#define UTILITIES_H

#include <random>
#include <ctime>
#include "DefaultHeaders.h"

#define MAJOR_VERSION 0
#define MINOR_VERSION 3
#define PATCH_VERSION 0

#define EXECUTE_FUNC(func) \
    {\
        std::chrono::high_resolution_clock::time_point t1 = std::chrono::high_resolution_clock::now();\
        func\
        std::chrono::high_resolution_clock::time_point t2 = std::chrono::high_resolution_clock::now();\
        auto duration = std::chrono::duration_cast<std::chrono::microseconds>(t2-t1).count();\
        std::cout << "Duration: " << duration << " us\n";\
    }

#define EXECUTE_FUNC_UNIT(unit, code_block) \
    {\
        std::chrono::high_resolution_clock::time_point t1 = std::chrono::high_resolution_clock::now();\
        code_block\
        std::chrono::high_resolution_clock::time_point t2 = std::chrono::high_resolution_clock::now();\
        auto duration = 0;\
        if (unit == "ns")\
            duration = std::chrono::duration_cast<std::chrono::nanoseconds>(t2-t1).count();\
        else if (unit == "s")\
            duration = std::chrono::duration_cast<std::chrono::seconds>(t2-t1).count();\
        else if (unit == "ms")\
            duration = std::chrono::duration_cast<std::chrono::milliseconds>(t2-t1).count();\
        else if (unit == "us")\
            duration = std::chrono::duration_cast<std::chrono::microseconds>(t2-t1).count();\
        else\
            duration = std::chrono::duration_cast<std::chrono::microseconds>(t2-t1).count();\
        if(!(unit == "ns" || unit == "ms" || unit == "us" || unit == "s"))\
            std::cout << "Duration: " << duration << " us\n";\
        else\
            std::cout << "Duration: " << duration << " " << unit << "\n";\
    }

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
bool StrictLessComparator(T first, T second)
{
    return first < second;
}

template <typename T>
bool StrictGreaterComparator(T first, T second)
{
    return first > second;
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

void
PrintVersion()
{
    std::cout << MAJOR_VERSION << "." << MINOR_VERSION << "." << PATCH_VERSION << "\n";
}

#endif