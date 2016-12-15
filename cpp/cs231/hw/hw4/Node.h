/* * * * * * * * * * *
 * Austin J. Alexander
 * HW #4 "LIST O NODES"
 * File: Node.cc
 * Due: 03/19/2014
 * * * * * * * * * * */

#ifndef NODE_H
#define NODE_H

#include <cstdlib>

class Node {

public:
  /*** CONSTRUCTORS ***/
  // default
  Node();
  // value as parameter
  Node(int entry_value);

  /*** DESTRUCTOR ***/
  ~Node();

  /*** METHODS ***/
  Node *getNextNode();
  void setNextNode(Node *next_node);
  int getNodeValue();
  void displayNode();

private:
	int value;
 	Node *next_node_ptr;
};

#endif

