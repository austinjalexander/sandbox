#include <stdio.h>

int main() {

	// collection of numbers
	int number_array[10] = {0};

	char string[] = {0,1,2,3};
	char string[4] = {0,1,2,3};

	int* number_array_ptr = NULL;

	return 0;
}

// http://artery.wbur.org/2013/11/07/city-hall-call-music

// copy one array to another


// char* p = &v[3];
// char x = *p;

// "reference to"

// scope; can you access?
// extern and const s globals in header files?

// give a problem with globals example?

// lets say you want to make a person

// first a struct in C with char array
// after that, the next week starts C++, with strings and vectors in structs and then classes 

// typical to put structs in a header file

// dot operator

// functions that will writeout all values or modify them by using the struct variable as a parameter/argument

struct Employee {
	int id;
	string name;
	string title;
};

// struct in a struct

// pass by reference or pointer

// string

// vector

// static

// \a alert/bell character

// strlen(s), excludes '\0'

// char actually an int, ascii;;; 'x' is not "x"

// always initialize; garbaage values

// int function(const arr[]); can't change values

// auto type conversion

// short circuit for logical operators

// if(!valid)

// tolower(c)

// isdigit(c)

// type cast: (int) 3.14

// sqrt(n), or sqrt((double) n)

// rand ans srand

// strcat(s,t)

//; as statement terminator
// { } make a block

// else if

// strtol()

// strstr()

// initial function definition:
// dummy() {}
// int is assumed as return type
// but that's bad practice

// atoi and atof

// when no function prototype, a function is declared by its first appearance and is assumed to retrn an int

// cant define functions inside of functions

// char pattern[] = "sun";
// char pattern[] = { 's', 'u', 'n', '\0' }

// qsort()

// C++ while(!myFile.eof()) {myFile >> inputChar;}

// java: static methods vs instance methods
// java: static methods are functions
// method signature vs function header