/* * * * * * * * * * *
 * Austin J. Alexander
 * HW #7 "Templated Nodes"
 * File: ReversePrintingList.h
 * Due: 05/07/2014
 * * * * * * * * * * */

#include "List.h"

#ifndef REVERSE_PRINTING_LIST_H
#define REVERSE_PRINTING_LIST_H
//=====================================
// ReversePrintingList class definition
class ReversePrintingList : public List {
public:
  ReversePrintingList();
  ~ReversePrintingList( );
  void printReverse();
private:
  void reverseList(BaseNode*);
};
#endif