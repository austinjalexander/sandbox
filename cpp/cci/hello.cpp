#include <iostream>

int main(int argc, char *argv[]) {
    if (argc > 1) 
        std::cout << "Hello, " + std::to_string(*argv[1]);
    return 0;
}

