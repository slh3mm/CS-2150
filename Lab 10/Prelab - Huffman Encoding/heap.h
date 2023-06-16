/*
Spencer Hernandez
4/17/2022
Heap.h
I utilized professor Bloomfield's code to implement the heap
*/
#ifndef HEAP_H
#define HEAP_H

#include <vector>
#include <iostream>
#include "Node.h"

using namespace std;

class heap{
 public:
  heap();
  heap(vector<Node*> vec);
  ~heap();
   
  void insert(Node* x);
  Node* findMin();
  Node* deleteMin();
  unsigned int size();
  void makeEmpty();
  bool isEmpty();
  void print();
  vector<Node*> getMyHeap();
  
 private:
  vector<Node*> myHeap;
  unsigned int heapSize;

  void percolateUp(int hole);
  void percolateDown(int hole);
};

#endif
