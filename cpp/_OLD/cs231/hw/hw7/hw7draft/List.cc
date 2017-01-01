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
BaseNode* List::getTopBaseNode() {
  return top_node;
}
void List::addBaseNode(BaseNode* new_node) {
  if (top_node == NULL) {
    top_node = new_node;
  }
  else {
    BaseNode* temp_node = top_node;
    while (temp_node->getNextBaseNode() != NULL) {
      temp_node = temp_node->getNextBaseNode(); 
    }
  temp_node->setNextBaseNode(new_node);
  }
}
void List::walkTheList() {
  if (top_node == NULL) {
    std::cout << "\t\tList is empty." << std::endl;
  }
  else {
    BaseNode* temp_node = top_node;
    while (temp_node->getNextBaseNode() != NULL) {
      listBaseNodeDisplay(temp_node);
      temp_node = temp_node->getNextBaseNode();
    }
    if (temp_node->getNextBaseNode() == NULL) {
      listBaseNodeDisplay(temp_node);
    }  
  }
}
void List::listBaseNodeDisplay(BaseNode* node) {
  std::cout << "\t\tNode: " << node << " | Value: ";
  node->getValue();
  std::cout << " | NextNode: " << node->getNextBaseNode() << std::endl;  
}

