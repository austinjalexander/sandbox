/* * * * * * * * * * *
 * Austin J. Alexander
 * HW #7 "Templated Nodes"
 * File: BaseNode.h
 * Due: 05/07/2014
 * * * * * * * * * * */

#include <iostream>
#include <typeinfo>

#ifndef BASE_NODE_H
#define BASE_NODE_H
//=====================================
// BaseNode class definition
class BaseNode {
public:
  BaseNode() {
    next_node = NULL;
    //std::cout << "BaseNode default constructor " << " - " << this << std::endl;
  }
  virtual ~BaseNode() {
    delete next_node;
    next_node = NULL;
    std::cout << "\t\tBaseNode destructor " << " - " << this << std::endl;
  }
  virtual void getValue() = 0;
  BaseNode* getNextBaseNode(){
    return next_node;
  }
  void setNextBaseNode(BaseNode* new_node){
    next_node = new_node;
  }
private:
  BaseNode* next_node;
};
#endif

