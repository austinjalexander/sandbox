/* * * * * * * * * * *
 * Austin J. Alexander
 * HW #2 "DECRYPTER"
 * File: decrypt_functions.h
 * Due: 02/05/2014
 * * * * * * * * * * */

#include <cstdlib>
#include <fstream>
#include <iomanip>
#include <iostream>

using namespace std;

#ifndef DECRYPT_FUNCTIONS_H_
#define DECRYPT_FUNCTIONS_H_

// FUNCTION PROTOTYPE DECLARATIONS ***************** //
void readFile(char&, int[], ifstream&);
void countCharacters(double&, int[]);
void displayFrequencies(double&, int[]);
void sortCharacters(int[], char[]);
void mapCharactersToFrequencies(int[], char[], char[]);
void displayDecryptedText(char&, char[], char[], ifstream&);

#endif // DECRYPT_FUNCTIONS_H_

