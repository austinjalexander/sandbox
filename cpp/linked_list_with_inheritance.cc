#include <iostream>
// Node class definitions
class Node {
public:
  Node();
  virtual ~Node();
  Node* getNextNode();
  void setNextNode(Node*);
private:
  Node* next_node;
};
// Node implementations
Node::Node() {
  next_node = NULL;
  std::cout << "Node default constructor " << " - " << this << std::endl;
}
Node::~Node() {
  delete next_node;
  next_node = NULL;
  std::cout << "Node destructor " << " - " << this << std::endl;
}
Node* Node::getNextNode(){
  return next_node;
}
void Node::setNextNode(Node* new_node){
  next_node = new_node;
}
//=====================================
// IntNode class definition
class IntNode : public Node {
public: 
  IntNode();
  IntNode(int);
  ~IntNode();
private:
  int integer;
};
// IntNode implementation
IntNode::IntNode() {
  integer = 0;
  std::cout << "IntNode default constructor" << " - " << this << std::endl;
}
IntNode::IntNode(int value) {
  integer = value;
  std::cout << "IntNode constructor " << integer << " - " << this << std::endl;
}
IntNode::~IntNode() {
  std::cout << "IntNode destructor " << integer << " - " << this << std::endl;
  integer = 0;
}
//=====================================
// List class definition
class List {
public:
  List();
  ~List();
  void addNode(Node*);
private:
  Node* top_node;
};
// List implementations
List::List() {
  top_node = NULL;
}
List::~List() {
  delete top_node;
  top_node = NULL;
}
void List::addNode(Node* new_node) {
  if (top_node == NULL) {
    top_node = new_node;
  }
  else {
    Node* temp_node = top_node;
    while (temp_node->getNextNode() != NULL) {
      temp_node = temp_node->getNextNode(); 
    }
  temp_node->setNextNode(new_node);
  }
}
//=====================================
// Main driver
int main() {
  List* list = new List();

  list->addNode(new IntNode(1));
  list->addNode(new IntNode(2));
  std::cout << std::endl;

  // get rid of the list manually
  delete list;
  return 0;
}