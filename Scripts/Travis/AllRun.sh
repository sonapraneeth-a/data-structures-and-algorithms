#!/bin/bash

set -x

echo "Running all tests"
chmod +x ./Build/Test/MainTest
./Build/Test/MainTest
