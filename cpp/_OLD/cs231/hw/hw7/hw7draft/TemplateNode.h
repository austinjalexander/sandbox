/* * * * * * * * * * *
 * Austin J. Alexander
 * HW #7 "Templated Nodes"
 * File: TemplateNode.h
 * Due: 05/07/2014
 * * * * * * * * * * */

#include "BaseNode.h"

#ifndef TEMPLATE_NODE_H
#define TEMPLATE_NODE_H
//=====================================
// TemplateNode class definition
template <typename VALUE> 
class TemplateNode : public BaseNode {
public:
  TemplateNode() {
    value = NULL; 
    next_node = NULL;
    //std::cout << "TemplateNode default constructor " << " - " << this << std::endl;
  }
  TemplateNode(VALUE new_value) {
    value = new_value;
    //std::cout << "TemplateNode constructor with value" << " - " << this << std::endl;
  }
  ~TemplateNode() {
    //std::cout << "TemplateNode destructor " << " - " << this << std::endl;
  }
  void getValue() {
    std::cout << value << std::endl;
  }

private:
  VALUE value; 

};

#endif

