/* * * * * * * * * * *
 * Austin J. Alexander
 * HW #7 "Templated Nodes"
 * File: List.cc
 * Due: 05/07/2014
 * * * * * * * * * * */

#include <iostream>
#include "List.h"

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

