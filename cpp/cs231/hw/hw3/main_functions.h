/* * * * * * * * * * *
 * Austin J. Alexander
 * HW #3 "TEMPERATURE2_THERETURNOFCONVERSION"
 * File: main_functions.h
 * Due: 02/25/2014
 * * * * * * * * * * */

#include "thermometer.h"

#ifndef MAIN_FUNCTIONS_H
#define MAIN_FUNCTIONS_H

void hi();
char startThermometer(Thermometer &new_thermometer);
void resetThermometer(Thermometer &new_thermometer);
void useThermometer(Thermometer &new_thermometer);
void setThermometerScale(Thermometer &new_thermometer);
void checkTemperatureWithThermometer(Thermometer &new_thermometer);
void convertTemperatureUsingNewThermometer(Thermometer &copy_thermometer);
void finale(Thermometer &new_thermometer, Thermometer &copy_thermometer);
double checkSochiTemperature();
void bye();

#endif // MAIN_FUNCTIONS_H

