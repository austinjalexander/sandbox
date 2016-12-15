/* * * * * * * * * * *
 * Austin J. Alexander
 * HW #3 "TEMPERATURE2_THERETURNOFCONVERSION"
 * File: main_functions.cc
 * Due: 02/25/2014
 * * * * * * * * * * */

#include "main_functions.h"
// this is just for a little hacked-out monster at the end
#include <curl/curl.h>
#include <fstream>

void hi() {
	std::cout << "\n\t\t\t<<<--- Hi! --->>\n" << std::endl;
}

// start the thermometer
// and ask user if he/she wants to reset it
char startThermometer(Thermometer &new_thermometer) {
 	useThermometer(new_thermometer);

 	std::cout << "\n\t\tWould you like to reset the "
 	          << "thermometer? (Y/N): ";
 	char user_decision = ' ';
 	while (user_decision != 'Y' && user_decision != 'y' && user_decision != 'N' && user_decision != 'n') {
 		if (user_decision != ' ') {
 			std::cout << "You have entered an invalid option; "
 			          << "please try again (Y/N): ";
 		}
 		std::cin >> user_decision;
 	}
 	return user_decision;
}

// reset the thermometer to 0 or 32 depending on scale
void resetThermometer(Thermometer &new_thermometer) {
 	new_thermometer.resetCurrentTemperature();
 	std::cout << "\n\t\t\tTemperature has been reset."
 	          << std::endl;
}

// displays current temperature and scale
void useThermometer(Thermometer &new_thermometer) {
 	std::cout << "\n\tThe current temperature is: "
 			  << new_thermometer.getCurrentTemperature()
 			  << new_thermometer.getCurrentTemperatureScale()
 			  << std::endl;
}

// the name says it all
void setThermometerScale(Thermometer &new_thermometer) {
  	std::cout << "\n\t\tPlease set the thermometer scale (C/F): ";
 	std::string user_decision = " ";
 	while (user_decision != "C" && user_decision != "c" && user_decision != "F" && user_decision != "f") {
 		if (user_decision != " ") {
 			std::cout << "You have entered an invalid option; "
 			          << "please try again (C/F): ";
 		}
 		std::cin >> user_decision;
 	}

 	if (user_decision == "c") {
 		user_decision = "C";
 	}
 	else if (user_decision == "f") {
 		user_decision = "F";
 	}
  	new_thermometer.setCurrentTemperatureScale(user_decision);	
}

// does a little random dance to give a value
// displays a count down/up to fake like it's a working thermometer
void checkTemperatureWithThermometer(Thermometer &new_thermometer) {

	std::cout << "\n\t\tChecking for new temperature...\n" 
	          << std::endl;

	new_thermometer.setCurrentTemperature();
	double thermometer_temperature = new_thermometer.getCurrentTemperature();
	std::string thermometer_scale = new_thermometer.getCurrentTemperatureScale();

	if (thermometer_scale == " \u00B0C") {
 		if (thermometer_temperature <= 55) {
 			for (int i = 110; i >= thermometer_temperature; i -= 5) {
 				std::cout << i << "...";
 			}
 		}
 		else if (thermometer_temperature > 55) {
 			for (int i = 0; i <= thermometer_temperature; i += 5) {
 				std::cout << i << "...";
 			}
 		}
 	}
 	else if (thermometer_scale == " \u00B0F") {
 		if (thermometer_temperature <= 131) {
 			for (int i = 230; i >= thermometer_temperature; i -= 5) {
 				std::cout << i << "...";
 			}
 		}
 		else if (thermometer_temperature > 131) {
 			for (int i = 32; i <= thermometer_temperature; i += 5) {
 				std::cout << i << "...";
 			}
 		}
	}
	std::cout << std::endl;	
}

// makes a copy of the thermometer 
// in order to do a scale conversion
void convertTemperatureUsingNewThermometer(Thermometer &copy_thermometer) {

	double thermometer_temperature = copy_thermometer.getCurrentTemperature();
	std::string thermometer_scale = copy_thermometer.getCurrentTemperatureScale();

	if (thermometer_scale == " \u00B0C") {
		thermometer_temperature = ((thermometer_temperature * 9) / 5) + 32;
		std::cout << "\t\t\t[That's "
			      << thermometer_temperature
			      << " \u00B0F in case you're curious.]" 
	          	  << std::endl;	
 	}
 	else if (thermometer_scale == " \u00B0F") {
 		thermometer_temperature = ((thermometer_temperature - 32) * 5) / 9;
		std::cout << "\t\t\t[That's "
			      << thermometer_temperature
			      << " \u00B0C in case you're curious.]" 
	          	  << std::endl;	
	}

	std::cout << "\n\t\t[[[Done. Press [Enter] to continue.]]]";
	std::cin.ignore();
	std::cin.ignore();
}

void finale(Thermometer &new_thermometer, Thermometer &copy_thermometer) {
	// now modify the copied thermometer object
	// and display both at the end
	double sochi_temperature = checkSochiTemperature();

	std::cout << "\n\t~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n"
	          << "\n\tSpeaking of curiosity, perhaps you're wondering\n"
	          << "\twhat the current temperature in Sochi, Russia is right now..."
	          << std::endl;

	copy_thermometer.setCurrentTemperatureScale("F");
	copy_thermometer.setCurrentTemperature(sochi_temperature);

	std::cout << "\n\t\tWell, while the temperature you took was " 
	          << new_thermometer.getCurrentTemperature() 
	          << new_thermometer.getCurrentTemperatureScale()
	          << ",\n"
	          << "\t\tthe temperature in Sochi is " 
	          << copy_thermometer.getCurrentTemperature() 
	          << copy_thermometer.getCurrentTemperatureScale()
	          << ".\n"
	          << std::endl;
}

// this is where the real (hack-y) magic happens
double checkSochiTemperature() {
	// made use of the official example here: 
	// http://curl.haxx.se/libcurl/c/simple.html
	// and a SO example here: 
	// http://stackoverflow.com/questions/3471122/saving-a-file-using-libcurl-in-c
	// have to compile with -lcurl flag
	/*********** BEGIN COPIED & MODIFIED STUFF ***********/
  	CURL *curl;
  	CURLcode res;

  	curl = curl_easy_init();
  	if(curl) {
    	curl_easy_setopt(curl, CURLOPT_URL, "https://api.forecast.io/forecast/bd93a5fce6c5d3e1ee369ba451cc63e7/43.5853,39.7203");

    	FILE* file = fopen("json.txt", "w");

    	curl_easy_setopt(curl, CURLOPT_WRITEDATA, file);

    	res = curl_easy_perform(curl);

    	fclose(file);

    	if(res != CURLE_OK) {
      	fprintf(stderr, "curl_easy_perform() failed: %s\n", curl_easy_strerror(res));
    }

    curl_easy_cleanup(curl);
  }	
  /*********** END COPIED & MODIFIED STUFF ***********/

  // get ready for Hack-Fest 2014 right here
  std::ifstream json("json.txt");
  int counter = 0, tracker = 0;
  char character = ' ';
  char json_array[500] = {' '}, temperature_section[20] = {' '};
  char actual_temperature_array[5] = {' '};

  // place characters in file into a char array
	while (json >> character && counter != 500) {
		json_array[counter] = character;
		counter++;
	}

	// get temperature's start index
	for (int i = 0; i < 500; i++) {
		if (json_array[i] == '"' && json_array[i + 1] == 't' && json_array[i + 2] == 'e' && json_array[i + 3] == 'm') {
			tracker = i;
			i = 500;
		}
	}

	// get temperature section from json_array
	for (int i = 0; i < 21; i++) {
		temperature_section[i] = json_array[tracker];
		tracker++;
	}

	// get actual temperature numbers
	for (int i = 14; i < 19; i++) {
		actual_temperature_array[i - 14] = temperature_section[i];
	}

	return atof(actual_temperature_array);
}

void bye() {
	std::cout << "\n\t\t\t<<<--- See ya! --->>\n" << std::endl;
}

