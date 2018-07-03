#!/bin/bash

set -x


g++ -std=c++11 -I./Include -L./Lib/ Main.cpp -o Main -lDSA_Static_debug