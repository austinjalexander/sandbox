#include "Node.h"

#ifndef LIST_H
#define LIST_H
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