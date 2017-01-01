/* * * * * * * * * * *
 * Austin J. Alexander
 * HW #6 "Reverse the Recurse"
 * File: List.h
 * Due: 04/16/2014
 * * * * * * * * * * */

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
