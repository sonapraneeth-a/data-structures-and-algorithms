//
// Created by pranas on 3/1/2018.
//

#ifndef RANDOM_NUMBER_H
#define RANDOM_NUMBER_H

#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>

class random_number
{
    std::string generator = "LCG"; // Linear congruential Generators
    int number;

    std::vector<int> gen_list();
    int gen_num(std::string = "LCG");
    int gen_lcg(int a = 1, int b = 1, int m = 1);
};


#endif //DATA_STRUCTURES_AND_ALGORITHMS_RANDOM_NUMBER_H
