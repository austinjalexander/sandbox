// % clang++ hello.cpp -Weverything -o bin/hello && ./bin/hello Austin
#include <iostream>

int main(int argc, char *argv[]) {
    if (argc > 1) 
        std::cout << "Hello, " << argv[1] << std::endl;
    return 0;
}

