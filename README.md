## Features

### Data Strucutures

- Stack

### Algorithms

- Numbers
    - Factorization.h
        - GCD
        - LCM
    - Fibonacci.h
        - GetNthFibonacciRecursive
        - GetNthFibonacciIterative
        - FibonacciSeries

## Static library compilation

```bash
cd Build
make clean
export LIBRARY_PATH=./Lib/Linux64/
make
make install
cd ..
export LD_LIBRARY_PATH=./Lib/Linux64/
g++ -std=c++11 -I./Include/ -L./Lib/Linux64/ Main.cpp -o Main -lDSA_Static_debug
```

## Shared library compilation

```bash
cd Build
make clean
export LIBRARY_PATH=./Lib/Linux64/
make
make install
cd ..
export LD_LIBRARY_PATH=./Lib/Linux64/
g++ -std=c++11 -I./Include/ -L./Lib/Linux64/ Main.cpp -o Main -lDSA_Shared_debug
```