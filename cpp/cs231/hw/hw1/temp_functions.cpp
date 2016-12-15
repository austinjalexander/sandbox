/* * * * * * * * * * *
 * Austin J. Alexander
 * HW #1 "TEMP CONVERTER"
 * File: temp_functions.cpp
 * Due: 01/22/2014
 * * * * * * * * * * */

#include "temp_functions.h"

// function definitions
double ctof(double temp_input) {
	return ((temp_input * 9) / 5) + 32;
}
double ftoc(double temp_input) {
	return ((temp_input - 32) * 5) / 9;
}