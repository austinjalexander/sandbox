/* * * * * * * * * * *
 * Austin J. Alexander
 * HW #7 "Templated Nodes"
 * File: IntNode.h
 * Due: 05/07/2014
 * * * * * * * * * * */

#include "Node.h"

#ifndef INTNODE_H
#define INTNODE_H
//=====================================
// IntNode class definition
class IntNode : public Node {
public: 
  IntNode();
  IntNode(int);
  ~IntNode();
  void getValue();
private:
  int integer;
};

#endif