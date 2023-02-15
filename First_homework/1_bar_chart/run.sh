#GNU c++17 7.3
g++ -lm -O2 -fno-stack-limit -std=c++1z -x c++ bar_char.cpp -lm -o a.out
./a.out
rm a.out