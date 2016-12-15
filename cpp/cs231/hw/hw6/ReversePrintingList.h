/* * * * * * * * * * *
 * Austin J. Alexander
 * HW #6 "Reverse the Recurse"
 * File: ReversePrintingList.h
 * Due: 04/16/2014
 * * * * * * * * * * */
#include "List.h"
#include "Node.h"

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
  void reverseList(Node*);
};
#endif