#include <iostream>
#include <string>

int main() {

  // in C++, you can create the iterator in the for-loop header
  for (int i = 0; i < 5; i++) {
    int integer_number = 0;
    std::cout << "\nPlease enter a number, then I'll double it: ";
    std::cin >> integer_number;
    std::cout << "You entered: " << integer_number << std::endl;
    std::cout << "Your number doubled: " 
              << integer_number * 2 << std::endl << std::endl;
  }

  int counter = 0;
  while (counter < 5) {
    int integer_number = 0;
    std::cout << "\nPlease enter a number, then I'll double it: ";
    std::cin >> integer_number;
    std::cout << "You entered: " << integer_number << std::endl;
    std::cout << "Your number doubled: " 
              << integer_number * 2 << std::endl << std::endl;
    counter++;    
  }
  
  // while i'm using a string here, often Boolean values of 
  // true or false are used in while-loop conditions
  std::string action = "continue";
  while (action.compare("quit") != 0) {
    std::cout << "Type \"quit\" to exit the program: ";
    std::cin >> action;
  }

return 0;
}
