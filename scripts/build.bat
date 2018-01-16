echo "Compiling the code and generating binaries"
cmake -H.. -B../build -DCMAKE_BUILD_TYPE=Debug -G "MinGW Makefiles"