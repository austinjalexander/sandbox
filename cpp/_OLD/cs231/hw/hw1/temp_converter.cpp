/* * * * * * * * * * *
 * Austin J. Alexander
 * HW #1 "TEMP CONVERTER"
 * File: temp_converter.cpp
 * Due: 01/22/2014
 * * * * * * * * * * */

#include <iostream>
#include <string>
#include <sstream>
using namespace std;

#include "temp_functions.h"

int main() {
	// temperature value
	string user_input_str = " ";
	double temp_value = 0, temp_value_converted = 0; // valid temperature values
	bool temp_valid = false; // for first do-while loop

	// current temperature scale
	char temp_scale = ' ', temp_scale_new = ' ';
	bool scale_valid = false; // for do-while loops

	// greeting
	cout << "\n\t\t\t****** TEMP CONVERTER ******\n\n";

	// get temperature; exit loop when temperature is valid
	do {
		cout << "\tEnter temperature: ";
		getline(cin, user_input_str);
		stringstream temp_str(user_input_str); // for cleaning/converting user_input_str to double

		// valid/true: 32, 32., 32.1, 32ef, etc.
		// invalid/false: ef, ef32, [carriage return], etc.
		if (temp_str >> temp_value) {
			temp_valid = true;
		}
		else {
			cout << "\t\t--- Invalid temperature! ---"
				 << "\n\t\t--- Please try again. ---\n\n";
			// clear any error flags
			cin.clear();
		}
	} while (!temp_valid);

	// get current scale; exit loop when scale is valid
	do
	{
		cout << "\tEnter current scale: ";
		cin.get(temp_scale);

		// valid: C, c, F, f, Fd, fd, Cd, cd, etc.
		// invalid: dC, dc, dF, df, 32, d, [carriage return], etc.
		switch (temp_scale) {
			case 'C':
			case 'c':
					temp_value_converted = ctof(temp_value);
					temp_scale_new = 'F';
					scale_valid = true;
					break;
			case 'F':
			case 'f':
					temp_value_converted = ftoc(temp_value);
					temp_scale_new = 'C';
					scale_valid = true;
					break;
			default: 
					cout << "\n\t\t--- Invalid scale! ---"
				 	     << "\n\t\t--- Please try again. ---\n\n";
				 	// clear any error flags and buffer
				 	cin.clear();
					cin.ignore(1000, '\n');
		}
	} while (!scale_valid);

	// output converted temperature with new scale indicated
	cout << "\n\tConverted temperature: " << temp_value_converted
		 << " \u00B0" << temp_scale_new << endl << endl;

	return 0;
}