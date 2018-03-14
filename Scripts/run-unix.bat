#!/bin/bash

set -x

echo "Running data structures test"
chmod +x ./Build/Test/DataStructuresTest
./Build/Test/DataStructuresTest

echo "Running algorithms test"
chmod +x ./Build/Test/AlgorithmsTest
./Build/Test/AlgorithmsTest
