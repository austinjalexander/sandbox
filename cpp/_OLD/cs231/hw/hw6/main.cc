/* * * * * * * * * * *
 * Austin J. Alexander
 * HW #6 "Reverse the Recurse"
 * File: main.cc
 * Due: 04/16/2014
 * * * * * * * * * * */

#include <iostream>
#include <string>
#include "Node.h"
#include "IntNode.h"
#include "CharNode.h"
#include "List.h"
#include "ReversePrintingList.h"

/*
//=====================================
// Node class definition
class Node {
public:
  Node();
  virtual ~Node();
  Node* getNextNode();
  virtual void getValue() = 0;
  void setNextNode(Node*);
private:
  Node* next_node;
};
// Node implementations
Node::Node() {
  next_node = NULL;
  //std::cout << "Node default constructor " << " - " << this << std::endl;
}
Node::~Node() {
  delete next_node;
  next_node = NULL;
  //std::cout << "Node destructor " << " - " << this << std::endl;
}
Node* Node::getNextNode(){
  return next_node;
}
void Node::setNextNode(Node* new_node){
  next_node = new_node;
}
//=====================================
// IntNode class definition
class IntNode : public Node {
public: 
  IntNode();
  IntNode(int);
  ~IntNode();
  void getValue();
private:
  int integer;
};
// IntNode implementation
IntNode::IntNode() {
  integer = 0;
  //std::cout << "IntNode default constructor" << " - " << this << std::endl;
}
IntNode::IntNode(int value) {
  integer = value;
  //std::cout << "IntNode constructor " << integer << " - " << this << std::endl;
}
IntNode::~IntNode() {
  //std::cout << "IntNode destructor " << integer << " - " << this << std::endl;
  integer = 0;
}
void IntNode::getValue() {
  std::cout << integer << " (int)";
}
//=====================================
// CharNode class definition
class CharNode : public Node {
public: 
  CharNode();
  CharNode(char);
  ~CharNode();
  void getValue();
private:
  char character;
};
// CharNode implementation
CharNode::CharNode() {
  character = ' ';
  //std::cout << "CharNode default constructor" << " - " << this << std::endl;
}
CharNode::CharNode(char value) {
  character = value;
  //std::cout << "CharNode constructor " << character << " - " << this << std::endl;
}
CharNode::~CharNode() {
  //std::cout << "CharNode destructor " << character << " - " << this << std::endl;
  character = ' ';
}
void CharNode::getValue() {
  std::cout << character << " (char)";
}
//=====================================
// List class definition
class List {
public:
  List();
  virtual ~List();
  Node* getTopNode();
  void addNode(Node*);
  void listNodeDisplay(Node*);
  void walkTheList();
  virtual void printReverse() = 0;
private:
  Node* top_node;
};
// List implementations
List::List() {
  top_node = NULL;
}
List::~List() {
  delete top_node;
  top_node = NULL;
}
Node* List::getTopNode() {
  return top_node;
}
void List::addNode(Node* new_node) {
  if (top_node == NULL) {
    top_node = new_node;
  }
  else {
    Node* temp_node = top_node;
    while (temp_node->getNextNode() != NULL) {
      temp_node = temp_node->getNextNode(); 
    }
  temp_node->setNextNode(new_node);
  }
}
void List::walkTheList() {
  if (top_node == NULL) {
    std::cout << "\t\tList is empty." << std::endl;
  }
  else {
    Node* temp_node = top_node;
    while (temp_node->getNextNode() != NULL) {
      listNodeDisplay(temp_node);
      temp_node = temp_node->getNextNode();
    }
    if (temp_node->getNextNode() == NULL) {
      listNodeDisplay(temp_node);
    }  
  }
}
void List::listNodeDisplay(Node* node) {
  std::cout << "\t\tNode: " << node << " | Value: ";
  node->getValue();
  std::cout << " | NextNode: " << node->getNextNode() << std::endl;  
}
//=====================================
// ReversePrintingList class definition
class ReversePrintingList : public List {
public:
  ReversePrintingList();
  ~ReversePrintingList( );
  void printReverse();
private:
  void reverseList(Node*);
};
// ReversePrintingList public implementations
ReversePrintingList::ReversePrintingList() {
  // nothing needed
}
ReversePrintingList::~ReversePrintingList() {
  // nothing needed
}
void ReversePrintingList::printReverse() {
  reverseList(getTopNode());
}
// ReversePrintingList private implementations
void ReversePrintingList::reverseList(Node* node) {
  if (node->getNextNode() == NULL) {
    List::listNodeDisplay(node);
  }
  else {
    reverseList(node->getNextNode()); 
    List::listNodeDisplay(node);  
  }
}
*/
//=====================================
// Main driver
int main() {
  std::cout << "\n\t\t<-- POLYMORPHIC LINKED LIST -->"
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