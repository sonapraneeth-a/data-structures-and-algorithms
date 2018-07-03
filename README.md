# Static library compilation

```bash
cd Build
make clean
# export LIBRARY_PATH=./Lib/
make
make install
cd ..
#export LD_LIBRARY_PATH=./Lib/
g++ -std=c++11 -I./Include/ -L./Lib/ Main.cpp -o Main -lDSA_Static_debug
```