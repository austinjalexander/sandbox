/* * * * * * * * * * *
 * Austin J. Alexander
 * HW #7 "Templated Nodes"
 * File: main.cc
 * Due: 05/07/2014
 * * * * * * * * * * */

#include "TemplateNode.h"
#include "List.h"

//=====================================
// Main driver
int main() {
  std::cout << "\n\t\t<-- POLYMORPHIC AND TEMPLATED LINKED LIST -->"
            << std::endl;

  List* list = new List();
  
  //list->addBaseNode(new TemplateNode<int>(2));
  //list->addBaseNode(new TemplateNode<char>('A'));
  //list->addBaseNode(new TemplateNode<std::string>("hello, world"));
  
  std::cout << "\n\tYOUR LIST:" << std::endl;
  list->walkTheList();

  std::cout << "\n\n\tDELETE NODES RECURSIVELY" << std::endl;
  delete list;
  std::cout << "\n\t\t\t\t<-- END -->\n" << std::endl;

  return 0;
}

