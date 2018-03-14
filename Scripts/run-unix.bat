#!/bin/bash

set -x

echo "Running data structures test"
chmod +x ./Build/test/DataStructuresTest
./Build/Test/DataStructuresTest

echo "Running algorithms test"
chmod +x ./Build/test/AlgorithmsTest
./Build/Test/AlgorithmsTest
