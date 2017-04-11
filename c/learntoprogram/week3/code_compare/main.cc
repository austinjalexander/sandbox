#include <iostream>

// comments 
/* 
 * work the same here
 */

int main() {
	std::cout << "hello, world\n";
}

Initializing const members and other special cases (such a parent classes) can be accomplished in the initializer list

class Foo {
private:
   const int data;
public:
   Foo(int x) : data(x) {}
};

// aggregation: classes in classes

// arrays of objects

// structs in c cant have functions; thus, and for other reasons, classes