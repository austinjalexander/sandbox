#include <iostream>

using namespace std;

int main()
{
	int i = 57;
	int j = 31;
	int* p = 0;
//	int* q = (int*) 1004; // 1004 is the hypothetical address of j; this is unknown, so:
	int* q = &j;

	cout << endl << "POINTERS" << endl;

	cout << " i: " << i << endl;  // 57
	cout << " j: " << j << endl;  // 31
	cout << " p: " << p << endl;  // 0
//	cout << "*p: " << *p << endl;  // dereferences pointer, so will seg fault, since p == 0
	cout << " q: " << q << endl;  // e.g., 0x7fff67b0f8c0 (init. address decided at compile time)
	cout << "*q: " << *q << endl;  // 31

	cout << endl;

	i = j; // the r-value of j (31) is assigned to i
	p = q; // the r-value of value of q (0x7fff67b0f8c0) is now stored at the l-value of p

	cout << " i: " << i << endl;  // 31
	cout << " j: " << j << endl;  // 31
	cout << " p: " << p << endl;  // e.g., 0x7fff67b0f8c0
	cout << "*p: "  << *p << endl;  // 31
	cout << " q: " << q << endl;  // e.g., 0x7fff67b0f8c0
	cout << "*q: " << *q << endl;  // 31

	cout << endl;


	i = *q; // the r-value of j (31) is assigned to i
	*q = 32; // the l-value of j (0x7fff67b0f8c0) now stores the value 32

	// thus, the the l-value of *q is identical to the r-value of q

	cout << " i: " << i << endl;  // 31
	cout << " j: " << j << endl;  // 32
	cout << " p: " << p << endl;  // e.g., 0x7fff67b0f8c0
	cout << "*p: "  << *p << endl;  // 32
	cout << " q: " << q << endl;  // e.g., 0x7fff67b0f8c0
	cout << "*q: " << *q << endl;  // 32

	cout << endl << "REFERENCES" << endl;
	i = 57;
	int& r = i;

	cout << " i: " << i << endl;  // 57
	cout << "&i: " << &i << endl;  // e.g., 0x7fff67b0f8c4
	cout << " r: " << r << endl;  // 57
	cout << "&r: " << &r << endl;  // e.g., 0x7fff67b0f8c4

	cout << endl;

	cout << " p: " << p << endl;  // e.g., 0x7fff67b0f8c0
	cout << "&p: "  << &p << endl;  // e.g., 0x7fff67b0f8b8, the actual address of p
	cout << " q: " << q << endl;  // e.g., 0x7fff67b0f8c0
	cout << "&q: " << &q << endl;  // e.g., 0x7fff67b0f8b0, the actual address of q


	cout << endl;
	return 0;
}