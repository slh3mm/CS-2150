/*
Spencer Hernandez
1/31/2021
Lab 2
*/
#include <iostream>
#include "List.h"

using namespace std;

List::List(){
  iterator = new ListItr();
  head = new ListNode();
  tail = new ListNode();
  head->next = tail;
  tail->previous = head;
  count = 0;
};

List::List(const List& source) {
  iterator = new ListItr();
    head=new ListNode();
    tail=new ListNode();
    head->next=tail;
    tail->previous=head;
    count=0;

    // Make a deep copy of the list
    ListItr iter(source.head->next);
    while (!iter.isPastEnd()) {
        insertAtTail(iter.retrieve());
        iter.moveForward();
    }
}

List::~List(){
  makeEmpty();
  delete head;
  delete tail;
  delete iterator;
}

List& List::operator=(const List& source) {
    if (this == &source) {
        // The two are the same list; no need to do anything
        return *this;
    } else {
        // Clear out anything this list contained
        // before copying over the items from the other list
        makeEmpty();

        // Make a deep copy of the list
        ListItr iter(source.head->next);
        while (!iter.isPastEnd()) {
            insertAtTail(iter.retrieve());
            iter.moveForward();
        }
    }
    return *this;
}

bool List::isEmpty() const{
  if (head->next == tail){
    return true;
  }
  return false;
}

void List::makeEmpty(){
  ListNode* currentNode = head->next;
  while(currentNode != tail){
    currentNode = currentNode->next;
    delete currentNode->previous;
  }
  /*
  iterator->current = head->next;
  while (iterator->current != tail){
    iterator->moveForward();
    head->next = head->next->next;
    delete head->next->previous;
  }*/
  count = 0;
  head->next = tail;
  tail->previous = head;
}

ListItr List::first(){
  iterator->current = head->next;
  return *iterator;
}

ListItr List::last(){
  iterator->current = tail->previous;
  return *iterator;
}

void List::insertAfter(int x, ListItr position){
  ListNode* afterNode = new ListNode();
  afterNode->value = x;
  afterNode->next = position.current->next;
  afterNode->previous = position.current;
  position.current->next->previous = afterNode;
  position.current->next = afterNode;
}

void List::insertBefore(int x, ListItr position){
  ListNode* beforeNode = new ListNode();
  beforeNode->value = x;
  beforeNode->next = position.current;
  beforeNode->previous = position.current->previous;
  position.current->previous->next = beforeNode;
  position.current->previous = beforeNode;
}

void List::insertAtTail(int x){
  iterator->current = tail->previous;
  this->insertAfter(x, iterator->current);
  /*
  ListNode* tailNode = new ListNode();
  tailNode->value = x;
  tail->previous->next = tailNode;
  tailNode->previous = tail->previous;
  tail->previous = tailNode;
  tailNode->next = tail;
  */
}

ListItr List::find(int x){
  ListNode* tempNode = head;
  while (tempNode->value != x){
     if (tempNode == tail){
       break;
     }
     tempNode = tempNode->next;
  }
  if (tempNode->value == x){
    iterator->current = tempNode;
    return *iterator;
  }
  else{
    iterator->current = tail;
    return *iterator;
  }
}

void List::remove(int x){
  ListNode* tempNode = head->next;
  while (tempNode->value != x){
    tempNode = tempNode->next;
  }
  tempNode->previous->next = tempNode->next;
  tempNode->next->previous = tempNode->previous;
  delete tempNode;
}
int List::size() const{
  int count = 0;
  ListNode* temp = head->next;
  while (temp != tail){
    count += 1;
    temp = temp->next;
  }
  
  return count;  
}

void printList(List& source, bool forward){
  if (forward){
    ListItr tempItr = source.first();
    while (!tempItr.isPastEnd()){
      cout << tempItr.retrieve() << " ";
      tempItr.moveForward();
    }
  }
  else{
    ListItr tempItr = source.last();
    while (!tempItr.isPastBeginning()){
      cout << tempItr.retrieve() << " ";
      tempItr.moveBackward();
    }
  }
  cout << endl;
}
