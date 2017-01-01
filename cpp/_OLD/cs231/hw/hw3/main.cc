/* * * * * * * * * * *
 * Austin J. Alexander
 * HW #3 "TEMPERATURE2_THERETURNOFCONVERSION"
 * File: main.cc
 * Due: 02/25/2014
 * * * * * * * * * * */

#include "main_functions.h"

 int main () {

 	// default constructor is used
 	Thermometer new_thermometer; 
 	int return_value = 0;

 	hi();

 	/****** all function calls with object arguments are pass-by-reference ******/

 	// "current temperature is"
 	// "reset thermometer?"
 	char user_decision = startThermometer(new_thermometer); 

 	if (user_decision == 'Y' || user_decision == 'y') {

 		// "temperature reset"
	 	resetThermometer(new_thermometer);
	 	// "current temperature is"
	 	useThermometer(new_thermometer);
	 	// "please set scale" 
	 	setThermometerScale(new_thermometer);
	 	// "current temperature is"
	 	useThermometer(new_thermometer);
	 	// "checking temperature"
	 	checkTemperatureWithThermometer(new_thermometer);
	 	// "current temperature is"
	 	useThermometer(new_thermometer);
	 	// instantiate second thermometer object
	 	// copy constructor is used
	 	Thermometer copy_thermometer(new_thermometer);
	 	// converting temperature to show the curious user
	 	convertTemperatureUsingNewThermometer(copy_thermometer);
	 	// sochi finale
	 	finale(new_thermometer, copy_thermometer);

	 	bye();
 	}
 	else if (user_decision == 'N' || user_decision == 'n') {
 		bye();
 	}
 	else {
 		// EPERM "Operation not permitted"
 		return_value = 1;
 	}

 	return return_value;
 }