#!/bin/bash

set -x

echo "Running data structures test"
./Build/test/DataStructuresTest.exe

echo "Running algorithms test"
./Build/test/AlgorithmsTest.exe
