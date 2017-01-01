/* * * * * * * * * * *
 * Austin J. Alexander
 * HW #3 "TEMPERATURE2_THERETURNOFCONVERSION"
 * File: thermometer.cc
 * Due: 02/25/2014
 * * * * * * * * * * */

#include "thermometer.h"

// CONSTRUCTORS
Thermometer::Thermometer() {
	// initial current_temperature is a random number 
	// between 0 and 32; this goes against one of the specs, 
	// but i hope that's OK
	current_temperature = randomCelsiusTemperature();
	// initial current temperature scale is Celsius 
	current_temperature_scale = " \u00B0C";
}
Thermometer::Thermometer(Thermometer &copy) {
	current_temperature = copy.current_temperature;
	current_temperature_scale = copy.current_temperature_scale;
}
/* to meet one of the specs, the following constructor is provided;
 * however, i didn't end up using it; again, i hope that's OK 
Thermometer::Thermometer(double new_temperature, std::string new_temperature_scale) {
	current_temperature = new_temperature;
	current_temperature_scale = new_temperature_scale;	
}
*/

// GETTERS
double Thermometer::getCurrentTemperature() {
	return current_temperature;
}
std::string Thermometer::getCurrentTemperatureScale() {
	return current_temperature_scale;
}

// SETTERS
void Thermometer::setCurrentTemperature() {
	current_temperature = Thermometer::randomCelsiusTemperature();
}
void Thermometer::setCurrentTemperature(double new_temperature) {
	current_temperature = new_temperature;
}
// since setting the scale resets temperature, be sure to run this first!
void Thermometer::setCurrentTemperatureScale(std::string new_temperature_scale) {
	current_temperature_scale = " \u00B0" + new_temperature_scale;
	Thermometer::resetCurrentTemperature();
}

// FUNCTIONS
// since we're not really taking the temperature...at first anyway...
double Thermometer::randomCelsiusTemperature() {
	srand(time(NULL));
	return rand() % 111; 		
}
void Thermometer::resetCurrentTemperature() {
	if (current_temperature_scale == " \u00B0C") {
		current_temperature = 0;
	}
	else if (current_temperature_scale == " \u00B0F") {
		current_temperature = 32;
	}		
}


