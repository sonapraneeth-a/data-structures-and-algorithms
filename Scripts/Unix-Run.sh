#!/bin/bash

set -x

echo "Creating Bin directory"
mkdir -p Bin
echo "Compiling the code by linking static libraries"
g++ -std=c++11 -I./Include -L./Lib/ Main.cpp -o ./Bin/MainStatic.out -lDSA_Static_debug
echo "Compiling the code by linking shared libraries"
export LB_LIBRARY_PATH=./Lib/
g++ -std=c++11 -I./Include -L./Lib/ Main.cpp -o ./Bin/MainShared.out -lDSA_Shared_debug