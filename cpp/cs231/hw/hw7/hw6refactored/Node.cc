/* * * * * * * * * * *
 * Austin J. Alexander
 * HW #7 "Templated Nodes"
 * File: Node.cc
 * Due: 05/07/2014
 * * * * * * * * * * */

#include "Node.h"
 
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