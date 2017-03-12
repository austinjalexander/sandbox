// % clang++ powerstwo.cpp -Weverything -o bin/powerstwo && ./bin/powerstwo
#include <iostream>

int powersOf2(long  n);

int main(int argc, char *argv[]) {
    if (argc > 1) {
        long n = std::strtol(argv[1], nullptr, 10);
        powersOf2(n);   
    }
    return 0;
}

int powersOf2(long n) {
    if (n < 1) {
        return 0;
    } else if (n == 1) {
        std::cout << 1 << std::endl;
        return 1;
    } else {
        int prev = powersOf2(n / 2);
        int curr = prev * 2;
        std::cout << curr << std::endl;
        return curr;
    }
}

