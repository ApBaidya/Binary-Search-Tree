//Aparajita Baidya 3.16.2026
#include "Node.h"
Node::Node(){
  right = nullptr;
  left = nullptr;
}

Node::~Node(){
  right = nullptr;
  left = nullptr;//...for...predictability 
}

void Node::setR(Node* r){
  right = r;
}

void Node::setL(Node* l){
  left = l;
}

void Node::setD(int d){
  data = d;
}

Node* Node::getR(){
  return right;
}

Node* Node::getL(){
  return left;
}

int Node::getD(){
  return data;
}
