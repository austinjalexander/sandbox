/* * * * * * * * * * *
 * Austin J. Alexander
 * HW #5 "Inherited and Dynamically Binded Nodes"
 * File: main.cc
 * Due: 04/09/2014
 * * * * * * * * * * */
#include <iostream>
#include <string>
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
  ~List();
  void addNode(Node*);
  void walkTheList();
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
      std::cout << "\t\tNode: " << temp_node << " | Value: ";
      temp_node->getValue();
      std::cout << " | NextNode: " << temp_node->getNextNode() << std::endl;
      temp_node = temp_node->getNextNode();
    }
    if (temp_node->getNextNode() == NULL) {
      std::cout << "\t\tNode: " << temp_node << " | Value: ";
      temp_node->getValue();
      std::cout << " | NextNode: " << temp_node->getNextNode() << std::endl;      
    }  
  }

}
//=====================================
// Main driver
int main() {
  std::cout << "\n\t\t<-- POLYMORPHIC LINKED LIST -->"
            << "\n\t\t\t[type \\q to exit]\n" << std::endl;
  List* list = new List();
  
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

  std::cout << "\n\t\t\t<-- END -->\n" << std::endl;

  delete list;
  return 0;
}