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
  reverseList(getTopNode());
}
// ReversePrintingList private implementations
void ReversePrintingList::reverseList(Node* node) {
  if (node->getNextNode() == NULL) {
    List::listNodeDisplay(node);
  }
  else {
    reverseList(node->getNextNode()); 
    List::listNodeDisplay(node);  
  }
}