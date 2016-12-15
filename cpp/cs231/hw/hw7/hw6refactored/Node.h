/* * * * * * * * * * *
 * Austin J. Alexander
 * HW #7 "Templated Nodes"
 * File: Node.h
 * Due: 05/07/2014
 * * * * * * * * * * */

#include <iostream>

#ifndef NODE_H
#define NODE_H
//=====================================
// Node class definition
class Node {
public:
  Node();
  virtual ~Node();
  Node* getNextNode();
  virtual void getValue() = 0;
  void setNextNode(Node*);
private:
  Node* next_node;
};

#endif

