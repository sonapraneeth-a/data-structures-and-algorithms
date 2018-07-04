#!/usr/bin/env bash

set -x

echo "Compiling CMakeLists.txt to generate Makefiles for the project"
# cmake -H. -B./Build/Linux_64/Debug -DCMAKE_BUILD_TYPE=Debug -G "Unix Makefiles"
cmake -B./Build/Linux_64/Debug -DCMAKE_BUILD_TYPE=Release \
        -DCMAKE_MAKE_PROGRAM=/usr/bin/make -DCMAKE_C_COMPILER=/usr/bin/gcc \
        -DCMAKE_CXX_COMPILER=/usr/bin/g++ -G "Unix Makefiles" .

