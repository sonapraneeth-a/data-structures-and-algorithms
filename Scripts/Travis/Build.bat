#!/bin/bash

set -x

echo "Compiling the code and generating binaries"
cmake -H. -B./Build -DCMAKE_BUILD_TYPE=Debug -G "Unix Makefiles"
