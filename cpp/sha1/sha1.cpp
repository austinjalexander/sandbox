// % clang++ sha1.cpp -Weverything -o bin/sha1 && ./bin/sha1
#include <iostream>

int main() {
    "The quick brown fox jumps over the lazy dog";

    /* 
     * Note 1: All variables are unsigned 32-bit quantities and wrap modulo 2^32 when calculating, excet for
     * m1, the message length, which is a 64-bit quantity, and 
     * hh, the message digest, which is a 160-bit quantity.
     * Note 2: All constants in this pseudo code are in big endian.
     * Within each word, the most significant byte is stored in the leftmost byte position.
     */

    int h0; 

}
