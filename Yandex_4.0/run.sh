#GNU c++20
g++ -O2 -lm -fno-stack-limit -std=c++20 -x c++ test.cpp -o a.out
./a.out
rm a.out