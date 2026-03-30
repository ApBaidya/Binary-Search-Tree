/*
Aparajita Baidya
3.29.2026
To do:
-add to tree --> fix
-remove from tree --> consider the 3 cases
-Add comments in order to not shame myself. And my family. And my ancestors. 
*/

#include "Node.h"
#include <iostream>
#include <cstring>
#include <string>
#include <vector>

//define f u n c t i o n s :D
void mkVect(string nums, vector<int>*);
void AddProc(vector<int>* numsV, Node* & root);//does all the cin, vector making, and iterate to add
void Add(Node* & current, int data);//find proper location for new data -> l e a f -> set null to new node w/ this data 
void Display(Node* current, int depth);//display tree --> left root right
void Search(Node* current, int value);//see if specific value in tree
void Remove(Node* & current, int data);//remove specified value from tree
void Quit();//remove everything is tree

int main(){
  int running = 1;
  char input[2];//user input
  //Root!!!
  Node* root = nullptr;
  //stuff for the vector of number inputs
  string nums;
  vector<int>* numsV = new vector<int>();
  //search value
  int searchVal;
  //value to delete
  int delVal;
  //enter main loop
  cout<<"welcome!!! (^w^)/"<<endl;
  while(running == 1){
    cout<<endl;
    cout<<"[a] add \n"<<"[s] search \n"<<"[d] display \n"<<"[r] remove \n"<<"[q] quit"<<endl;//all commands
    cin>>input;//get command
    cin.ignore(10, '\n');
    cin.clear();
    if(strcmp(input, "a")==0){
      cout<<"Please input your numbers"<<endl;
      getline(cin, nums);
      cout<<endl;
      cout<<nums<<endl;
      mkVect(nums, numsV);
      AddProc(numsV, root);
      numsV->clear();
    }
    else if(strcmp(input, "s")==0){
      cout<<"what value's existance do you wish to confirm?"<<endl;
      cin>>searchVal;
      cin.ignore(50, '\n');
      cin.clear();
      Search(root, searchVal);
    }
    else if(strcmp(input, "d")==0){
      if(root!=nullptr){
	Display(root, 0);
      }
    }
    else if(strcmp(input, "r")==0){
      cout<<"what value's existance do you wish to delete?"<<endl;
      cin>>delVal;
      cin.ignore(50, '\n');
      cin.clear();
      Remove(root, delVal);

    }
    else if(strcmp(input, "q")==0){
      running = 0;
      //clear everything
    }
  }//end main loop
  return 0;
}

void mkVect(string nums, vector<int>* numsV){
  cout<<"a"<<endl;
  string temp = "";
  for(int i = 0; i < nums.length(); i++){
    if(nums[i] == ' '){
      numsV->push_back(stoi(temp));//https://www.codecademy.com/article/how-to-convert-a-string-to-an-integer-in-c
      temp = "";
    }
    else{
      temp += nums[i];
    }
  }
  numsV -> push_back(stoi(temp));
  cout<<"vector done"<<endl;
  return;
}

void AddProc(vector<int>* numsV, Node* & root){
  for(vector<int>::iterator it = numsV->begin(); it != numsV->end(); ++it){
    cout<<"adding "<<(*it)<<endl;
    Add(root, (*it));
  }
}

void Add(Node* & current, int data){
  if(!current){
    cout<<"here";
    //mk current node w/ data
    current = new Node;
    current -> setD(data);
    current -> setL(nullptr);
    current -> setR(nullptr);
    return;
  }
  else{
    //consider which child
    if(current->getD() > data){//left
      cout<<"less"<<endl;
      Node* next = current->getL();
      Add(next, data);
      current->setL(next);
    }
    else if(current->getD() <= data){//right
      cout<<"more"<<endl;
      Node* next = current->getR();
      Add(next, data);
      current->setR(next);
    }
  }
}

void Search(Node* current, int value){
  if(current == nullptr){//empty/end of tree
    cout<<"not here"<<endl;
    return;
  }
  if(current->getD() == value){//found it
    cout << "found "<<current->getD()<<endl;
    return;
  }
  else if(current->getD() > value){
    cout<<"left"<<endl;
    Search(current->getL(), value);
  }
  else{
    cout<<"right"<<endl;
    Search(current->getR(), value);
  }
  return;
}

//heh. just infix.
void Display(Node* current, int depth){
  if(current == nullptr){
    return;
  }
  if(current->getR() == nullptr && current->getL()==nullptr){//leaf
    for(int i = 0; i < depth; i++){
      cout<<"\t";
    }
    cout<<current->getD()<<endl;
    return;
  }
  else{
    Display(current->getL(), (depth+1));
    for(int i = 0; i<depth; i++){
      cout<<"\t";
    }
    cout<<current->getD()<<endl;
    Display(current->getR(), (depth+1));
  }
  return;
}

void Remove(Node* & current, int data){
  Node* c = nullptr;
  if(!current){//empty
    return;
  }
  //delete time
  if(current->getD() == data){//found value to delete
    //leaf
    if(current->getL() == nullptr && current->getR()==nullptr){
      delete current;
      current = nullptr;
      return;
    }
    //one child
    else if(current->getL() != nullptr && current->getR()==nullptr){
      c = current->getL();
      delete current;
      current = nullptr;
      current = c;
      return;
    }
    else if(current->getL() == nullptr && current->getR()!=nullptr){
      c = current->getR();
      delete current;
      current = nullptr;
      current = c;
      return;
    }
    //2 children
    if(current->getL() != nullptr && current->getR()!=nullptr){
      //find that successor->right child, leftmost
      Node* temp = current;
      Node* successor = current->getR();
      while(successor->getL()!=nullptr){
	temp = successor;
	successor = successor->getL();
      }
      cout<<"AAAA"<<endl;
      current->setD(successor->getD());//set current data to successor
      //handle whatever happens with successor
      if(successor->getR()!=nullptr){
	cout<<"Richard I save me."<<endl;
	c = successor->getR();
	successor->setD(c->getD());
	successor->setL(c->getL());
	successor->setR(c->getR());
	c->setR(nullptr);
	c->setL(nullptr);
	delete c;
	return;
      }
      else{
	cout<<"By my chivalry's founder"<<endl;
	if(temp == current){
	  delete successor;
	  temp->setR(nullptr);
	  return;
	}
	else{
	  delete successor;
	  temp->setL(nullptr);
	  return;
	}
      }
    }
  }
  else{//recurse
    if(current->getD() > data){
      Node* L = current->getL();
      Remove(L, data);
      current->setL(L);
    }
    else{
      Node* R = current->getR();
      Remove(R, data);
      current->setR(R);
    }
  }
}
