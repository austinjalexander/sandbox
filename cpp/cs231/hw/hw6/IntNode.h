#include "Node.h"

#ifndef LIST_H
#define LIST_H
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