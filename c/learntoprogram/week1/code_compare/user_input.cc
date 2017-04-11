#include <iostream>
#include <string> // this one is necessary for std::string

int main() {
  int integer_number = 0; 

  double decimal_number = 0.0; 

  std::string my_string = "Your Name Here";
  // in C++, while you can still use 
  // character strings like in C,
  // the string type can be easier to use 

  bool valid = true;
  // a Boolean; this type isn't in original C;
  // it's helpful for testing to see if something
  // is true or false

  std::cout << "\nhello, world - from: " << my_string 
            << std::endl;
  // what do you think std::endl does?

  // by the way, you can think of << as "get from"
  std::cout << "\nPlease enter a number, "
            << "then I'll double it: ";
            // notice how we can break these statements up
	
  std::cin >> integer_number;
  // std::cin can be much easier to use than scanf();
  // for example, you usually don't have to be explicit
  // about the type of input you're getting; however, 
  // that can really mess you up if you're not careful!
  // you can think of >> as "put to"

  std::cout << "You entered: " 
            << integer_number << std::endl;

  integer_number = integer_number * 2; // do some math

  std::cout << "Your number doubled: " 
            << integer_number << std::endl << std::endl; 

return 0;
}
