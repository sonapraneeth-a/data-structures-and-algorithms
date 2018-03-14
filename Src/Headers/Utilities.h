#ifndef UTILITIES_H
#define UTILITIES_H

#include <random>
#include <ctime>

int
GetRandomInt(int start=100, int end=100000, std::string mode="Fixed");

double
GetRandomDouble(int start=100, int end=100000, std::string mode="Fixed");

#endif