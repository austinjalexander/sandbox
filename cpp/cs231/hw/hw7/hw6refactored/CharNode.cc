/* * * * * * * * * * *
 * Austin J. Alexander
 * HW #7 "Templated Nodes"
 * File: CharNode.h
 * Due: 05/07/2014
 * * * * * * * * * * */

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

