/* * * * * * * * * * *
 * Austin J. Alexander
 * HW #4 "LIST O NODES"
 * File: main.cc
 * Due: 03/19/2014
 * * * * * * * * * * */

 #include <cctype>
 #include <iostream>
 #include <string>
 #include "List.h"

 int main() {

  /*** VARIABLES AND CONSTANTS ***/
 	const int MAX_ENTRIES = 10;
 	int num_of_entries = 0;
  List new_list(MAX_ENTRIES);
  
  /*** GREETINGS ***/
  std::cout << "\n\n\t\t|************ LIST O NODES ************|"
            << "\n\t\t|                                      |"
            << "\n\t\t|        [Type \"quit\" to exit.]        |"
            << "\n\t\t|______________________________________|"
            << std::endl;

 	/*** DRIVER ***/
 	// as long as we don't have 10 integer entries,
  // ask for new ones
 	while (num_of_entries < MAX_ENTRIES) {
 		std::cout << "\n\n\t\tPlease enter an integer: ";
    std::string temp_entry = " ";
 		std::getline(std::cin, temp_entry);

 		// but don't hold users against their will
 		if (temp_entry == "quit") {
 			num_of_entries = MAX_ENTRIES;
 			std::cout << "\n\t\t\tSee you later alligator."
 			          << std::endl<< std::endl;
 		}

 		// if it seems that users are in it for the long haul,
 		// and if at least the first input character is a valid integer: 
 		else if (isdigit(temp_entry[0])) {
 			// convert it to an int
 			int entry_value = std::atoi(temp_entry.c_str());
 			// display what was kept
 			std::cout << "\n\t\t\tYou entered: " 
                << entry_value << std::endl;
      // keep the value as a Node
      new_list.addNode(entry_value);
 			// increment the counter
 			num_of_entries++;
 		}

 		// if users don't enter integers
 		else { 
 			// tell them that they're really messing things up,
 			// but give 'em an out
 			std::cout << "\n\t\t\tYou're killing me Smalls. "
 			          << "\n\t\t\tTry again or type \"quit\" without the quotes."
 			          << std::endl;
 		} 
 	}

  // if the list is full:
  if (new_list.getFirstNode() != NULL) {
    std::cout << "\n\n\t\t\tLARGEST NODE VALUE = " 
              << new_list.findLargestValue()
              << std::endl;
  }

  /*** FAREWELL ***/
  std::cout << "\n\n\t\t|************ LIST O NODES ************|"
            << "\n\t\t|                                      |"
            << "\n\t\t|               GOODBYE!               |"
            << "\n\t\t|______________________________________|"
            << std::endl << std::endl;

 	return 0;
 }

