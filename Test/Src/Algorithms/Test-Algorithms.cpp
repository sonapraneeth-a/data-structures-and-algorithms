#include "gtest/gtest.h"
#include <iostream>

int main(int argc, char* argv[])
{
    ::testing::InitGoogleTest(&argc, argv);
    int failedTests = RUN_ALL_TESTS();
    std::cout << "Number of failed tests: " << failedTests << "\n";
    return failedTests;
}