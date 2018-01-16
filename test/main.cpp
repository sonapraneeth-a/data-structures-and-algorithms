#include "gtest/gtest.h"
#include <iostream>

int main(int argc, char* argv[])
{
    ::testing::InitGoogleTest(&argc, argv);
    int failed_tests = RUN_ALL_TESTS();
    std::cout << "Number of failed tests: " << failed_tests << "\n";
    return failed_tests;
}