/* * * * * * * * * * *
 * Austin J. Alexander
 * HW #7 "Templated Nodes"
 * File: List.h
 * Due: 05/07/2014
 * * * * * * * * * * */

 #include "Node.h"

#ifndef LIST_H
#define LIST_H
//=====================================
// List class definition
class List {
public:
  List();
  virtual ~List();
  Node* getTopNode();
  void addNode(Node*);
  void listNodeDisplay(Node*);
  void walkTheList();
  virtual void printReverse() = 0;
private:
  Node* top_node;
};
#endif
