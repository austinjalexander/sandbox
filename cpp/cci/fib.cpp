#include <iostream>
#include <string>

int fib(int n) {
    if (n <= 0) return 0;
    else if (n == 1) return 1;
    return fib(n - 1) + fib(n - 2);
}

void allFib(int n) {
    for (int i = 0; i < n; i++) {
        std::cout << std::to_string(i) + ": " + std::to_string(fib(i));
    }
}

int main(int argc, char *argv[]) {
    int n = *argv[0];
    fib(n);
    return 0;
}

