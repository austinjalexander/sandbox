/* * * * * * * * * * *
 * Austin J. Alexander
 * HW #4 "LIST O NODES"
 * File: List.cc
 * Due: 03/19/2014
 * * * * * * * * * * */

#include <iostream>
#include "List.h"
#include "Node.h"

/*** CONSTRUCTORS ***/
// default
List::List() {
	size = 10;
  first_node_ptr = NULL;
}
// list size as parameter
List::List(const int MAX_ENTRIES) {
	size = MAX_ENTRIES;
  first_node_ptr = NULL;
}

/*** DESTRUCTOR ***/
List::~List() {
  delete first_node_ptr;
}

/*** METHODS ***/
void List::displayListFirstNode() {
  std::cout << "\n\n\t <<<< LIST - First Node Location: "
            << first_node_ptr << " >>>>" << std::endl;
}
// Post: new_node_ptr should now be last node in list
void List::addNode(int entry_value) {

  // create a new node
  Node *new_node_ptr = new Node(entry_value);

  // if the list is empty
  if (first_node_ptr == NULL) {

    // set first_node_ptr to the new_node_ptr
    first_node_ptr = new_node_ptr;
    
    displayListFirstNode();
    // display current node information
    new_node_ptr->displayNode();
  }

  // if the list has only one node to start
  else if (first_node_ptr->getNextNode() == NULL) {

    displayListFirstNode();
    // set the first node's next_node_ptr to new_node_ptr
    first_node_ptr->setNextNode(new_node_ptr);

    // get first node as current_node_ptr
    Node *current_node_ptr = first_node_ptr;
    
    // while the current node does not have a next_node_ptr to NULL
    while (current_node_ptr->getNextNode() != NULL) {
        // display current node information
        current_node_ptr->displayNode();
        current_node_ptr = current_node_ptr->getNextNode();
    }
    // for the last one
    // display current node information
    current_node_ptr->displayNode();
  }

  // if the list has more than one node to start
  else {

    displayListFirstNode();
    // get first node as current_node_ptr
    Node *current_node_ptr = first_node_ptr;
      
    // while the current node does not have a next_node_ptr to NULL
    while (current_node_ptr->getNextNode() != NULL) {
      // display current node information
      current_node_ptr->displayNode();
      current_node_ptr = current_node_ptr->getNextNode();
    }

    // set the current node's next_node_ptr to new_node_ptr
    current_node_ptr->setNextNode(new_node_ptr);
    // for the last one,
    // display current node information
    current_node_ptr->displayNode();
    // display current node information
    new_node_ptr->displayNode();
  }
}
int List::findLargestValue() {
  // get first node as current_node_ptr
  Node *current_node_ptr = first_node_ptr;

  int largest_value = 0;
      
  // while the current node does not have a next_node_ptr to NULL
  while (current_node_ptr->getNextNode() != NULL) {
    if (current_node_ptr->getNodeValue() > largest_value) {
      largest_value = current_node_ptr->getNodeValue();
    }

    current_node_ptr = current_node_ptr->getNextNode();
  } 
    if (current_node_ptr->getNodeValue() > largest_value) {
      largest_value = current_node_ptr->getNodeValue();
    }

  return largest_value;
}
Node* List::getFirstNode() {
  return first_node_ptr; 
}
