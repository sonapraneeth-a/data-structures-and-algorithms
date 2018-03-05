#ifndef DEFAULT_HEADERS
#define DEFAULT_HEADERS

#include <iostream>
#include <Random>
#include <ctime>
#include <chrono>


#define EXECUTE_FUNC(func) \
    {\
        std::chrono::high_resolution_clock::time_point t1 = std::chrono::high_resolution_clock::now();\
        func\
        std::chrono::high_resolution_clock::time_point t2 = std::chrono::high_resolution_clock::now();\
        auto duration = std::chrono::duration_cast<std::chrono::microseconds>(t2-t1).count();\
        std::cout << "Duration: " << duration << " ms\n";\
    }

#define EXECUTE_FUNC_UNIT(unit, func) \
    {\
        std::chrono::high_resolution_clock::time_point t1 = std::chrono::high_resolution_clock::now();\
        func\
        std::chrono::high_resolution_clock::time_point t2 = std::chrono::high_resolution_clock::now();\
        auto duration = 0;\
        if (unit == "ns")\
            duration = std::chrono::duration_cast<std::chrono::nanoseconds>(t2-t1).count();\
        else if (unit == "s")\
            duration = std::chrono::duration_cast<std::chrono::seconds>(t2-t1).count();\
        else\
            duration = std::chrono::duration_cast<std::chrono::microseconds>(t2-t1).count();\
        std::cout << "Duration: " << duration << " " << unit << "\n";\
    }

#endif