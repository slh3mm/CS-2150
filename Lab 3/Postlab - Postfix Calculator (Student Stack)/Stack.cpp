/*
Spencer Hernandez
2/9/2022
Stack.cpp
*/
#include <iostream>
#include "Stack.h"

using namespace std;

Stack::Stack(){
  head = new StackNode;
  tail = new StackNode;
  head->next = tail;
  tail->previous = head;
}

void Stack::push(int e){
  StackNode* newNode = new StackNode();
  newNode->value = e;
  newNode->next = head->next;
  newNode->previous = head;
  head->next->previous = newNode;
  head->next = newNode;
}

void Stack::pop(){
  if (head->next == tail){
    cout << "Error! Empty Stack!" << endl;
  }
  else{
    head->next = head->next->next;
    delete head->next->previous;
    head->next->previous = head;
  }
}

int Stack::top(){
   if (head->next == NULL){
    cout << "Error! Empty Stack!" << endl;
    return -1;
  }
  else{
    return head->next->value;
  } 
}

bool Stack::empty(){
   StackNode* currentNode = head->next;
   if(currentNode == tail){
     return true;
   }
  while(currentNode != tail){
    currentNode = currentNode->next;
    delete currentNode->previous;
  }

  head->next = tail;
  tail->previous = head;
  return true;
}

int Stack::size(){
  int count = 0;
  StackNode* temp = head->next;
  while (temp != tail){
    count += 1;
    temp = temp->next;
  }
  
  return count;  
}
