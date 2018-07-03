#!/usr/bin/env bash

set -x

echo "Compiling CMakeLists.txt to generate Makefiles for the project"
cmake -H. -B./Build-Unix -DCMAKE_BUILD_TYPE=Debug -G "Unix Makefiles"

