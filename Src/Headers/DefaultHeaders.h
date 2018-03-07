#ifndef DEFAULT_HEADERS
#define DEFAULT_HEADERS

#include <iostream>
#include <Random>
#include <ctime>
#include <chrono>

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

#endif