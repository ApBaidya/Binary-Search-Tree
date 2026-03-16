/*
Aparajita Baidya 3.16.2026
Binary tree node file
*/
#ifndef NODE
#define NODE

using namespace std;

class Node{
 private:
  Node* right;
  Node* left;
  int data;
 public:
  Node();//Perfect life
  ~Node();//Painful death
  //sets
  void setR(Node* r);//set right child
  void setL(Node* l);//set left child
  void setD(int d);//set data
  //gets
  Node* getR();//returns right child
  Node* getL();//returns left child
  int getD();//returns data
};

#endif //NODE
