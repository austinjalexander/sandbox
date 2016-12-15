
#ifndef LIST_H
#define LIST_H
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

