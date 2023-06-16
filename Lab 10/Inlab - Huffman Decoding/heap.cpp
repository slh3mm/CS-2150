/*
Spencer Hernandez
4/17/2022
heap.cpp
I utilized professor Bloomfield's code to implement the heap
*/
#include <iostream>
#include <vector>
#include "heap.h"

using namespace std;

heap::heap(){
  heapSize = 0;
  vector<Node*> tempHeap = {0};
  myHeap = tempHeap;
}

heap::heap(vector<Node*> vec){
  heapSize = vec.size();
  myHeap = vec;
  myHeap.push_back(myHeap[0]);
  myHeap[0] = 0;
  for(int i = heapSize/2; i > 0; i--){
    percolateDown(i);
  }
}

heap::~heap(){
}

void heap::insert(Node* x){
  myHeap.push_back(x);
  heapSize = heapSize + 1;
  percolateUp(heapSize);
}

Node* heap::findMin(){
  if (heapSize == 0){
    cout << "Heap is empty!" << endl;
    return NULL;
  }
  return myHeap[1];
}

Node* heap::deleteMin(){
  if (heapSize == 0){
    throw "empty heap";
  }
  Node* ret = myHeap[1];
  myHeap[1] = myHeap[heapSize--];
  myHeap.pop_back();
  if(!isEmpty()){
    percolateDown(1);
  }

  return ret;
}

unsigned int heap::size(){
  return heapSize;
}

void heap::makeEmpty(){
  heapSize = 0;
  myHeap.resize(1);
}

bool heap::isEmpty(){
  return heapSize == 0;
}

void heap::print(){
  cout << "    (" << myHeap[0] << ") ";
  for(int i = 1; i <= heapSize; i++){
    cout << myHeap[i]->frequency << " ";
    bool isPow2 = (((i+1) & ~(i))==(i+1))? i+1 : 0;
    if(isPow2){
      cout << endl << "\t";
    }
  }
  cout << endl;
}

void heap::percolateUp(int hole){
  Node* x = myHeap[hole];
  for ( ; (hole > 1) && (x->frequency < myHeap[hole/2]->frequency); hole/= 2){
    myHeap[hole] = myHeap[hole/2];
  }

  myHeap[hole] = x;
}

void heap::percolateDown(int hole){
  Node* x = myHeap[hole];
  while (hole*2 <= heapSize){
    int child = hole*2;
    if ((child+1 <= heapSize) && (myHeap[child+1]->frequency < myHeap[child]->frequency)){
      child++;
    }
    if (x->frequency > myHeap[child]->frequency){
      myHeap[hole] = myHeap[child];
      hole = child;
    }
    else{
      break;
    }
  }
  myHeap[hole] = x;
}

vector<Node*> heap::getMyHeap(){
  return myHeap;
}
