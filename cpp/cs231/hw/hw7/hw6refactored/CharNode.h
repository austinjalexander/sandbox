/* * * * * * * * * * *
 * Austin J. Alexander
 * HW #7 "Templated Nodes"
 * File: CharNode.h
 * Due: 05/07/2014
 * * * * * * * * * * */

#include "Node.h"

#ifndef CHARNODE_H
#define CHARNODE_H
//=====================================
// CharNode class definition
class CharNode : public Node {
public: 
  CharNode();
  CharNode(char);
  ~CharNode();
  void getValue();
private:
  char character;
};

#endif

