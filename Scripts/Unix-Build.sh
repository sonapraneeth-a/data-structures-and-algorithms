#!/bin/bash

set -x

echo "Removing Include and Lib directories"
rm -rf Include/ Lib/ Bin/
echo "Removing any compiled executable if present"
rm Main*.out
echo "Entering the Build directory"
pushd Build
echo "Cleaning the executables/libraries and compiling them from start"
make clean
make
echo "Installing libraries and header files"
make install
popd
