/* * * * * * * * * * *
 * Austin J. Alexander
 * HW #7 "Templated Nodes"
 * File: List.h
 * Due: 05/07/2014
 * * * * * * * * * * */

#include "BaseNode.h"

#ifndef LIST_H
#define LIST_H
//=====================================
// List class definition
class List {
public:
  List();
  virtual ~List();
  BaseNode* getTopBaseNode();
  void addBaseNode(BaseNode*);
  void listBaseNodeDisplay(BaseNode*);
  void walkTheList();
  void deleteReverse();
private:
  BaseNode* top_node;
  BaseNode* reverseDeleteBaseNodes(BaseNode*);
};
#endif

