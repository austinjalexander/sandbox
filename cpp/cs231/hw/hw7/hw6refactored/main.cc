/* * * * * * * * * * *
 * Austin J. Alexander
 * HW #7 "Templated Nodes"
 * File: main.cc
 * Due: 05/07/2014
 * * * * * * * * * * */

#include <string>
#include "IntNode.h"
#include "CharNode.h"
#include "ReversePrintingList.h"

//=====================================
// Main driver
int main() {
  std::cout << "\n\t\t<-- POLYMORPHIC AND TEMPLATED LINKED LIST -->"
            << "\n\t\t\t[type \\q to exit]\n" << std::endl;
  List* list = new ReversePrintingList();
  
  std::string user_input = " ";
  while (user_input != "\\q") {
    std::cout << "\tWould you like to enter a char or an int? ";
    std::cin >> user_input;
    if (user_input == "char") {
      std::cout << "\tEnter char value: ";
      char char_user_input = ' ';
      std::cin >> char_user_input;
      list->addNode(new CharNode(char_user_input));
      std::cout << std::endl;
    }
    if (user_input == "int") {
      std::cout << "\tEnter int value: ";
      int int_user_input = 0;
      std::cin >> int_user_input;
      list->addNode(new IntNode(int_user_input));
      std::cout << std::endl;
    }
  }

  std::cout << std::endl;
  std::cout << "\tYOUR LIST:" << std::endl;
  list->walkTheList();
  std::cout << "\n\tYOUR LIST REVERSED:" << std::endl;
  list->printReverse();

  std::cout << "\n\t\t\t<-- END -->\n" << std::endl;

  delete list;
  return 0;
}