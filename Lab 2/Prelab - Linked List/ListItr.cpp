/*
Spencer Hernandez
1/31/2021
Lab 2
*/
#include <iostream>
#include "ListItr.h"

using namespace std;

ListItr::ListItr(){
  current = NULL;
};

ListItr::ListItr(ListNode* theNode){
  current = theNode;
};

bool ListItr::isPastEnd() const{
  if (current->next == NULL){
    return true;
  }
  return false;
}

bool ListItr::isPastBeginning() const{
   if (current->previous == NULL){
    return true;
  }
  return false;
}

void ListItr::moveForward(){
  if (isPastEnd() == false){
    current = current-> next;
  }
}

void ListItr::moveBackward(){
  if (isPastBeginning() == false){
    ListNode temp = *current;
    current = temp.previous;
  }
}

int ListItr::retrieve() const{
  ListNode temp = *current;
  int val = temp.value;
  return val;
}
