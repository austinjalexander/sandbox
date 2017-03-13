// % clang++ sha1.cpp -Weverything -o bin/sha1 && ./bin/sha1
#include <iostream>
#include <string>

using namespace std;

int main() {
	string message = "The quick brown fox jumps over the lazy dog";
    cout << "message: " << message << endl;
    cout << "string length: " <<  message.length() << endl;

    /* 
     * Note 1: All variables are unsigned 32-bit quantities and wrap modulo 2^32 when calculating, excet for
     * m1, the message length, which is a 64-bit quantity, and 
     * hh, the message digest, which is a 160-bit quantity.
     * Note 2: All constants in this pseudo code are in big endian.
     * Within each word, the most significant byte is stored in the leftmost byte position.
     */

    /*
    int h0 = 0x67452301;
    int h1 = 0xEFCDAB89;
    int h2 = 0x98BADCFE;
    int h3 = 0x10325476;
    int h4 = 0xC3D2E1F0;
    */

    m1 
}
