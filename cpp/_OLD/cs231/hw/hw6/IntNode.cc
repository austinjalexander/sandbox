#include <iostream>
#include <string>
#include "IntNode.h"
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