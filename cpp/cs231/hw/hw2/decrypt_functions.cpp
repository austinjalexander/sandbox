/* * * * * * * * * * *
 * Austin J. Alexander
 * HW #2 "DECRYPTER"
 * File: decrypt_functions.cpp
 * Due: 02/05/2014
 * * * * * * * * * * */

#include "decrypt_functions.h"

// FUNCTION DEFINITIONS ***************** //

// read
void readFile(char &character, int alpha_counter[], ifstream &encrypted) {
	cout << "\n\tReading encrypted file...";
	// while there are characters in the text file,
	// convert each character into its ascii equivalent,
	// and increment the corresponding (0-25) array element as a counter
	while (encrypted >> character) {
		// if an alpha character
		if (character != ' ' && character != '-' && character != '.' && character != '\'' && character != ',' && character != ';' && character != ':' && character != '\n') {
			alpha_counter[(static_cast<int>(character)) - 97]++;
		}
	}
	// clear the stream
	encrypted.clear();
	encrypted.seekg(0, ios::beg);
	cout << "\n\tDone. Press [Enter] to continue." << endl;
	cin.ignore();
}

// count
void countCharacters(double &total, int alpha_counter[]) {
	cout << "\n\tCounting total number of alpha characters...";
	
	// count the total number of characters for percentages 
	for (int i = 0; i < 26; i++) {
			total += alpha_counter[i];
	}
	cout << "\n\tDone. Press [Enter] to continue.";
	cin.ignore();
}

// display
void displayFrequencies(double &total, int alpha_counter[]) {
	cout << "\n\tAlpha-Character (Non-Zero) Frequencies"
	     << "\n\t======================================" << endl;
	// display list of alpha non-zero counted characters
	//cout << "\n\t\t"
	for (int i = 0; i < 26; i++) {
		// if the character count > 0
		if (alpha_counter[i] != 0) {
			// display character
			cout << "\t"
					 << static_cast<char>(i + 97) 
			     << ": " 
			     << setw(3)
			     << setfill('0')
			     // character count
			     << alpha_counter[i] 
			     << " ("
			     << setw(5)
			     << setprecision(3)
			     << setfill('0')
			     // percentage
			     << alpha_counter[i] / total
			     << ")" << endl;
		}
	}
	cout << "\n\tDone. Press [Enter] to continue.";
	cin.ignore();
}

// sort
void sortCharacters(int alpha_counter[], char alpha_letters[]) {
	cout << "\n\tSorting alpha-characters by frequency...";
	
	bool ordered = false;
	while (!ordered) {
		int swap_counter = 0;
		for (int i = 0; i < 25; i++) {
			if (alpha_counter[i] < alpha_counter[i + 1]) {
				swap_counter++;

				int temp_int = alpha_counter[i];
				char temp_char = alpha_letters[i];

				alpha_counter[i] = alpha_counter[i + 1];
				alpha_letters[i] = alpha_letters[i + 1];

				alpha_counter[i + 1] = temp_int;
				alpha_letters[i + 1] = temp_char;

			}
		}

		if (swap_counter == 0) {
			ordered = true;
		}
	}
	cout << "\n\tDone. Press [Enter] to continue.";
	cin.ignore();
}

// map
void mapCharactersToFrequencies(int alpha_counter[], char alpha_letters[], char alpha_by_freq[]) {
	cout << "\n\tMapped Crypted Characters Based on Frequencies"
	     << "\n\t==============================================" << endl;

	for (int i = 0; i < 26; i++) {
		cout << "\tcharacter: " << alpha_letters[i] 
		     << ", frequency: " << setw(3) << setfill('0') << alpha_counter[i] 
		     << " ==> possible value: " << alpha_by_freq[i]
		     << endl;
	}
	cout << "\n\tDone. Press [Enter] to continue.";
	cin.ignore();
}

// display
void displayDecryptedText(char &character, char alpha_letters[], char alpha_by_freq[], ifstream &encrypted) {
	cout << "\n\tDecrypted Text Based on Mapping"
	     << "\n\t===============================" << endl;
	// display decrypted text based on character mapping
	while (encrypted >> noskipws >> character) {
		// if an alpha character
		if (character != ' ' && character != '-' && character != '.' && character != '\'' && character != ',' && character != ';' && character != ':' && character != '\n') {
			int index = 0;
			for (int i = 0; i < 26; i++) {
				if (alpha_letters[i] == character) {
					index = i;
					i = 26;
				}
			}
			cout << alpha_by_freq[index];			
		}
		else {
			cout << character;
		}
	}
	encrypted.close();
}


