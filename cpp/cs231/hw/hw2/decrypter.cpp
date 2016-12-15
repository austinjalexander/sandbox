/* * * * * * * * * * *
 * Austin J. Alexander
 * HW #2 "DECRYPTER"
 * File: decrypter.cpp
 * Due: 02/05/2014
 * * * * * * * * * * */

#include "decrypt_functions.h"

int main() {

	cout << "\n\t\t<-- CUSTOM DECRYPTER -->" << endl;

	// VARIABLES ***************** //

	char character = ' '; // for characters in file
	int alpha_counter[26] = {0}; // to count characters in file
	double total = 0; // total number of alpha characters in file
	ifstream encrypted("encrypted.txt"); // create file object
	// for sorting purposes
	char alpha_letters[26] = {'a', 'b', 'c', 'd', 'e', 
							  'f', 'g', 'h', 'i', 'j', 
							  'k', 'l', 'm', 'n', 'o', 
							  'p', 'q', 'r', 's', 't', 
							  'u', 'v', 'w', 'x', 'y', 'z'};
	// the letter-frequency list used for the following array was adopted 
	// from http://en.wikipedia.org/wiki/Letter_frequency
	// however, as words in the decrypted text became more apparent, 
	// the list was modified (e.g., "n" has a higher frequency than "o"
	// in the decrypted text, although that frequency comparison 
	// differs from the one at the Wikipedia page listed above
	char alpha_by_freq[26] = {'e', 't', 'a', 'n', 'i', 
							  'o', 'h', 's', 'r', 'l', 
							  'm', 'd', 'p', 'f', 'w', 
							  'c', 'g', 'y', 'u', 'b', 
							  'v', 'k', 'x', 'z', 'q', 'j'};

	// PROCEDURES ***************** //

	// check if no file
	// if not, terminate program
	if (!encrypted) {
		cout << "\n\t\t*** File did not open correctly!*** \n"
			   << "\n\t\t\tPROGRAM TERMINATED \n" << endl;
		exit(2); // ENOENT: "No such file or directory"
	}
	else {

		readFile(character, alpha_counter, encrypted);

		countCharacters(total, alpha_counter);

		displayFrequencies(total, alpha_counter);

		sortCharacters(alpha_counter, alpha_letters);

		mapCharactersToFrequencies(alpha_counter, alpha_letters, alpha_by_freq);

		displayDecryptedText(character, alpha_letters, alpha_by_freq, encrypted);

		cout << "\n\n\n\t\t<-- END PROGRAM -->" << endl << endl;

		return 0;	
	}
}


