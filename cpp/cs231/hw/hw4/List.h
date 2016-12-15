/* * * * * * * * * * *
 * Austin J. Alexander
 * HW #4 "LIST O NODES"
 * File: List.h
 * Due: 03/19/2014
 * * * * * * * * * * */

#ifndef LIST_H
#define LIST_H

#include "Node.h"

class List {
public:
	/*** CONSTRUCTORS ***/
	// default
	List();
	// list size as parameter
	List(const int MAX_ENTRIES);

  /*** DESTRUCTOR ***/
  ~List();

  /***  METHODS ***/
  void displayListFirstNode();
  void addNode(int entry_value);
  int findLargestValue();
  Node* getFirstNode();

private: 
  int size;
	Node *first_node_ptr;
};

#endif

