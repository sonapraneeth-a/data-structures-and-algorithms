#!/bin/bash

set -x

echo "Running data structures test"
chmod +x ./Build/Test/DataStructuresTest
./Build/Test/DataStructuresTest | tee -a "Test-DataStructures.txt"

echo "Running algorithms test"
chmod +x ./Build/Test/AlgorithmsTest
./Build/Test/AlgorithmsTest | tee -a "Test-Algorithms.txt"

echo "Tests for 'Data structures'"
tail -n 1 "Test-DataStructures.txt"
echo "Tests for 'Algorithms'"
tail -n 1 "Test-Algorithms.txt"