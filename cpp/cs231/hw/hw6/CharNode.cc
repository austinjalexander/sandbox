#include <iostream>
#include <string>
#include "CharNode.h"
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