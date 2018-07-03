#!/bin/bash

set -x

rm -rf Include/ Lib/
rm Main
pushd Build
make clean
make
make install
popd
