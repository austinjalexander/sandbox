/* * * * * * * * * * *
 * Austin J. Alexander
 * HW #4 "LIST O NODES"
 * File: Node.cc
 * Due: 03/19/2014
 * * * * * * * * * * */

#include <iostream>
#include "Node.h"

/*** CONSTRUCTORS ***/
// default
Node::Node() {
  value = 0;
  next_node_ptr = NULL;
}
// value as parameter
Node::Node(int entry_value) {
  value = entry_value;
  next_node_ptr = NULL;
}

/*** DESTRUCTOR ***/
Node::~Node() {
  delete next_node_ptr;
}

/*** METHODS ***/
Node *Node::getNextNode() {
  return next_node_ptr;
}
void Node::setNextNode(Node *next_node) {
  next_node_ptr = next_node;
}
int Node::getNodeValue() {
  return value;
}
void Node::displayNode() {
  std::cout << "\t\t\t--------NODE--------" << std::endl
            << "\t\t\tLocation: " << this << std::endl
            << "\t\t\tValue: " << value << std::endl
            << "\t\t\tNext Node: " << next_node_ptr << std::endl
            << "\t\t\t--------------------" << std::endl;
}

