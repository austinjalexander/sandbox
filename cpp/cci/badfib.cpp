// % clang++ badfib.cpp -Weverything -o bin/badfib && ./bin/badfib 8
#include <iostream>
#include <string>

int fib(int);

int fib(int n) {
    if (n <= 0) return 0;
    else if (n == 1) return 1;
    return fib(n - 1) + fib(n - 2);
}

int main(int argc, char *argv[]) {
    if (argc > 1) {
        int n = std::atoi(argv[1]);
        for (int i = 0; i < n; i++) {
            std::cout << i << ": " << fib(i) << std::endl;
        }
    }
    return 0;
}

