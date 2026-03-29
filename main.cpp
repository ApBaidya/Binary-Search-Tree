/*
Aparajita Baidya
3.27.2026
To do:
-add to tree
-print out tree (show parent child relationship)
-remove from tree --> consider the 3 cases
-search if value in tree
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
void Display();//display tree --> left root right
void Search();//see if specific value in tree
void Remove();//remove specified value from tree
void Quit();//remove everything is tree

int main(){
  int running = 1;
  char input[2];//user input
  //Root!!!
  Node* root = nullptr;
  //stuff for the vector of number inputs
  string nums;
  vector<int>* numsV = new vector<int>();
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
    }
    else if(strcmp(input, "s")==0){
      
    }
    else if(strcmp(input, "d")==0){

    }
    else if(strcmp(input, "r")==0){

    }
    else if(strcmp(input, "q")==0){
      running = 0;
      //clear everything
    }
  }//end main loop
  return 0;
}

void mkVect(string nums, vector<int>* numsV){
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
  return;
}

void AddProc(vector<int>* numsV, Node* & root){
  for(vector<int>::iterator it = numsV->begin(); it != numsV->end(); ++it){
    Add(root, (*it));
  }
}

void Add(Node* & current, int data){
  if(!current){
    //mk current node w/ data
    current = new Node;
    current -> setD(data);
    return;
  }
  else{
    //consider which child
    if(current->getD() > data){//left
      Add(current->getL(), data);
    }
    else if(current->getD() <= data){//right
      Add(current->getR(), data);
    }
  }
}

void Search(Node* current, int value){
  if(!current){//empty/end of tree
  }
  else if(current->getD() == value){//found it
    
  }
}



