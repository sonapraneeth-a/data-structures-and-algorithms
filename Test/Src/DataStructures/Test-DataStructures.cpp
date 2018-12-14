/**
 * File description
 *
 *        Filename: Test-DataStructures.cpp
 *      Created on: 14 December 2018
 *   Last modified: 14 December 2018
 *         Authors: sonapraneeth-a
 *         Details: File for testing DataStructures module
 */

/**
 * Changelog
 *
 * Date (DD-MM-YYYY)            Author               Update
 * 14-12-2018               sonapraneeth-a      - Creation of file
 *                                              - Added code for running tests for
 *                                                DataStructures
 */

#include "gtest/gtest.h"
#include <iostream>

int main(int argc, char* argv[])
{
    ::testing::InitGoogleTest(&argc, argv);
    int failedTests = RUN_ALL_TESTS();
    std::cout << "Number of failed tests: " << failedTests << "\n";
    return failedTests;
}