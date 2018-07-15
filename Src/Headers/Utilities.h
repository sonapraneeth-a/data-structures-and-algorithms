#ifndef UTILITIES_H
#define UTILITIES_H

#include <random>
#include <ctime>
#include <array>

#define MAJOR_VERSION 0
#define MINOR_VERSION 3
#define PATCH_VERSION 0

#define ULLI unsigned long long int
#define LLI long long int

// Reference: https://stackoverflow.com/questions/8061456/c-function-template-partial-specialization
#define INTEGER_NUMBERS(return_type) std::enable_if<(std::is_same<T, int>::value) \
                                       or (std::is_same<T, unsigned long long int>::value) \
                                       or (std::is_same<T, unsigned short int>::value) \
                                       or (std::is_same<T, long long int>::value), return_type>::type

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
    // std::cout << "Length of array: " << lengthOfArray << "\n";
    // std::cout << "StartIndex: " << startIndex << ", EndIndex: " << endIndex << "\n";
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

inline const std::string
GetCurrentTime()
{
    std::array<char, 64> buffer;
    buffer.fill(0);
    time_t rawtime;
    time(&rawtime);
    const auto timeinfo = localtime(&rawtime);
    strftime(buffer.data(), sizeof(buffer), "%H:%M:%S", timeinfo);
    std::string TimeStr(buffer.data());
    return TimeStr;
}


#endif