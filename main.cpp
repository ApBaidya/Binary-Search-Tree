/*
Aparajita Baidya
4.3.2026
To do:
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
void Quit(Node* & current);//remove everything is tree

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
    if(strcmp(input, "a")==0){//add
      cout<<"Please input your numbers"<<endl;
      getline(cin, nums);
      cout<<endl;
      cout<<nums<<endl;
      mkVect(nums, numsV);//store all the numbers in a vector
      AddProc(numsV, root);//which then is iterated through 
      numsV->clear();//clear the vector each time
    }
    else if(strcmp(input, "s")==0){//search
      cout<<"what value's existance do you wish to confirm?"<<endl;
      cin>>searchVal;
      cin.ignore(50, '\n');
      cin.clear();
      Search(root, searchVal);
    }
    else if(strcmp(input, "d")==0){//display
      if(root!=nullptr){
	Display(root, 0);
      }
    }
    else if(strcmp(input, "r")==0){//remove
      cout<<"what value's existance do you wish to delete?"<<endl;
      cin>>delVal;
      cin.ignore(50, '\n');
      cin.clear();
      Remove(root, delVal);

    }
    else if(strcmp(input, "q")==0){//quit
      running = 0;
      Quit(root);
      Display(root,0);//just to check
      //clear everything
    }
  }//end main loop
  numsV->clear();//clear vector for the last time
  delete numsV;//delete said vector 
  cout<<"Farewell. Fare. Thee. Well."<<endl;
  return 0;
}

void mkVect(string nums, vector<int>* numsV){//nums is the data, numsV is the vector
  cout<<"a"<<endl;
  string temp = "";
  for(int i = 0; i < nums.length(); i++){//add to vector every seperation
    if(nums[i] == ' '){
      numsV->push_back(stoi(temp));//https://www.codecademy.com/article/how-to-convert-a-string-to-an-integer-in-c
      temp = "";
    }
    else{
      temp += nums[i];//add to temp to get the full number
    }
  }
  numsV -> push_back(stoi(temp));//push back the last temp value
  cout<<"vector done"<<endl;
  return;
}

void AddProc(vector<int>* numsV, Node* & root){//numsV number vector, root is obvious
  for(vector<int>::iterator it = numsV->begin(); it != numsV->end(); ++it){
    cout<<"adding "<<(*it)<<endl;
    Add(root, (*it));//actual add code
  }
}

void Add(Node* & current, int data){
  if(!current){//where to add
    //cout<<"here";
    //mk current node w/ data
    current = new Node();//current will be nullptr, so make a new node
    current -> setD(data);
    current -> setL(nullptr);
    current -> setR(nullptr);
    return;
  }
  else{
    //consider which child
    if(current->getD() > data){//left
      //cout<<"less"<<endl;
      Node* next = current->getL();
      Add(next, data);
      current->setL(next);//reconnect
    }
    else if(current->getD() <= data){//right
      //cout<<"more"<<endl;
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
  else if(current->getD() > value){//to find which branch to go down
    //cout<<"left"<<endl;
    Search(current->getL(), value);
  }
  else{
    //cout<<"right"<<endl;
    Search(current->getR(), value);
  }
  return;
}

//heh. just infix.
void Display(Node* current, int depth){
  if(current == nullptr){//end of branch
    return;
  }
  if(current->getR() == nullptr && current->getL()==nullptr){//leaf hence nothing else to do except print the leaf
    for(int i = 0; i < depth; i++){
      cout<<"\t";
    }
    cout<<current->getD()<<endl;
    return;
  }
  else{//print right, center, left
    Display(current->getR(), (depth+1));//increase depth
    for(int i = 0; i<depth; i++){
      cout<<"\t";
    }
    cout<<current->getD()<<endl;
    Display(current->getL(), (depth+1));
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
      current = nullptr;//just to be assured of the value
      return;
    }
    //one child
    else if(current->getL() != nullptr && current->getR()==nullptr){
      c = current->getL();
      delete current;
      current = nullptr;
      current = c;//replace
      return;
    }
    else if(current->getL() == nullptr && current->getR()!=nullptr){
      c = current->getR();
      delete current;
      current = nullptr;
      current = c;//replace
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
      //cout<<"AAAA"<<endl;
      current->setD(successor->getD());//set current data to successor
      //handle whatever happens with successor
      if(successor->getR()!=nullptr){//is a right child
	//cout<<"Anime Richard I, save me."<<endl;
	c = successor->getR();//replace stuff in successor, and then delete right, essentially replacing succcessor with it's right 
	successor->setD(c->getD());
	successor->setL(c->getL());
	successor->setR(c->getR());
	c->setR(nullptr);
	c->setL(nullptr);
	delete c;
	return;
      }
      else{//no right child stuff to deal with
	//cout<<"By my chivalry's founder"<<endl;
	if(temp == current){
	  delete successor;
	  temp->setR(nullptr);
	  return;
	}
	else{//there is a successor
	  delete successor;
	  temp->setL(nullptr);
	  return;
	}
      }
    }
  }
  else{//recurse depending on the branch
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

//like postfix
void Quit(Node* & current){
  if(current == nullptr){ //branch g o n e
    return;
  }
  Node* L = nullptr;
  L = current->getL();
  Quit(L);
  Node* R = nullptr;
  R = current->getR();
  Quit(R);
  current->setL(L);
  current->setR(R);
  //current->setL(nullptr);
  //current->setR(nullptr);
  delete current;
  current = nullptr;
}
