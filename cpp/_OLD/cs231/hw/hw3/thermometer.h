/* * * * * * * * * * *
 * Austin J. Alexander
 * HW #3 "TEMPERATURE2_THERETURNOFCONVERSION"
 * File: thermometer.h
 * Due: 02/25/2014
 * * * * * * * * * * */

#include <cstdlib>
#include <ctime>
#include <iostream>
#include <string>

#ifndef THERMOMETER_H
#define THERMOMETER_H

class Thermometer {

private:
	double current_temperature;
	std::string current_temperature_scale;

public:
	// CONSTRUCTORS
 	Thermometer();
 	Thermometer(Thermometer &);
 	// again, the following constructor was for meeting one of the specs,
 	// but it wasn't used
 	//Thermometer::Thermometer(double new_temperature, std::string new_temperature_scale)

 	// GETTERS
 	double getCurrentTemperature();
 	std::string getCurrentTemperatureScale();

 	// SETTERS
 	void setCurrentTemperature();
 	void setCurrentTemperature(double new_temperature);
	// since setting the scale resets temperature, be sure to run this first!
 	void setCurrentTemperatureScale(std::string new_temperature_scale);

 	// FUNCTIONS
 	// since we're not really measuring temperature...
 	double randomCelsiusTemperature();
 	void resetCurrentTemperature();
};

#endif // THERMOMETER_H

