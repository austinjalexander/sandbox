#include <iostream>
// class definitions
class Node {
public:
  Node();
  Node(int);
  ~Node();
  Node* getNextNode();
  void setNextNode(Node*);
private:
  int integer;
  Node* next_node;
};
// implementations
Node::Node() {
  integer = 0;
  next_node = NULL;
}
Node::Node(int value) {
  integer = value;
  next_node = NULL;
}
Node::~Node() {
  delete next_node;
  next_node = NULL;
}
Node* Node::getNextNode(){
  return next_node;
}
void Node::setNextNode(Node* new_node){
  next_node = new_node;
}
// class definition
class List {
public:
  List();
  ~List();
  void addNode(Node*);
private:
  Node* top_node;
};
// implementations
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
// driver
int main() {
  List* list = new List();

  int value = 0;
  std::cin >> value;

  list->addNode(new Node(value));
  list->addNode(new Node(value));

  // get rid of the list manually;
  // if list had only one node,
  // it would free it automagically,
  // without the need of an explicit
  // node destructor
  delete list;
  return 0;
}