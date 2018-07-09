#ifndef UTILITIES_H
#define UTILITIES_H

#include <random>
#include <ctime>
#include "DefaultHeaders.h"

#define MAJOR_VERSION 0
#define MINOR_VERSION 3
#define PATCH_VERSION 0

#define ULLI unsigned long long int
#define LLI long long int

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

/**
 *
 * @param start
 * @param end
 * @param mode
 * @return
 */
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

/**
 *
 * @param start
 * @param end
 * @param mode
 * @return
 */
inline double
GetRandomDouble(int start=100, int end=100000, std::string mode="Fixed")
{
    std::random_device rd;
    std::mt19937 mt(rd());
    std::uniform_real_distribution<double> dist(start, end);
    return dist(mt);
}

/**
 *
 * @tparam T
 * @param first
 * @param second
 * @return
 */
template <typename T>
bool LesserComparator(T &first, T &second)
{
    return first <= second;
}

/**
 *
 * @tparam T
 * @param first
 * @param second
 * @return
 */
template <typename T>
bool GreaterComparator(T first, T second)
{
    return first >= second;
}

/**
 *
 * @tparam T
 * @param first
 * @param second
 * @return
 */
template <typename T>
bool StrictLesserComparator(T first, T second)
{
    return first < second;
}

/**
 *
 * @tparam T
 * @param first
 * @param second
 * @return
 */
template <typename T>
bool StrictGreaterComparator(T first, T second)
{
    return first > second;
}

/**
 *
 * @tparam T
 * @param first
 * @param second
 */
template <typename T>
void Swap(T& first, T& second)
{
    T temp = second;
    second = first;
    first = temp;
}

/**
 *
 * @tparam T
 * @tparam N
 * @param Array
 * @return
 */
template <typename T, size_t N>
ULLI SizeOfArray(T (&Array)[N])
{
    // Reference: https://stackoverflow.com/questions/5724171/passing-an-array-by-reference
    // Reference: https://www.geeksforgeeks.org/how-to-find-size-of-array-in-cc-without-using-sizeof-operator/
    // Reference: https://stackoverflow.com/questions/26269777/passing-unknown-array-to-function-by-reference-c
    ULLI lengthOfArray = *(&Array + 1) - Array;
    return lengthOfArray;
}

/**
 *
 * @tparam T
 * @tparam N
 * @param Array
 * @param startIndex
 * @param endIndex
 */
template <typename T, size_t N>
void PrintOneDArray(T (&Array)[N], LLI startIndex = 0, LLI endIndex = -1)
{
    ULLI lengthOfArray = SizeOfArray(Array);
    if (endIndex == -1)
    {
        endIndex = (LLI)lengthOfArray;
    }
    for (LLI index = startIndex; index < endIndex; ++index)
    {
        std::cout << Array[index] << " ";
    }
    std::cout << "\n";
}

/**
 *
 */
inline void
PrintVersion()
{
    std::cout << MAJOR_VERSION << "." << MINOR_VERSION << "." << PATCH_VERSION << "\n";
}

#endif