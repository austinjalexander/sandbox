/* * * * * * * * * * *
 * Austin J. Alexander
 * HW #7 "Templated Nodes"
 * File: ReversePrintingList.cc
 * Due: 05/07/2014
 * * * * * * * * * * */

#include "ReversePrintingList.h"
 
// ReversePrintingList public implementations
ReversePrintingList::ReversePrintingList() {
  // nothing needed
}
ReversePrintingList::~ReversePrintingList() {
  // nothing needed
}
void ReversePrintingList::printReverse() {
  reverseList(getTopBaseNode());
}
// ReversePrintingList private implementations
void ReversePrintingList::reverseList(BaseNode* node) {
  if (node->getNextBaseNode() == NULL) {
    List::listBaseNodeDisplay(node);
  }
  else {
    reverseList(node->getNextBaseNode()); 
    List::listBaseNodeDisplay(node);  
  }
}