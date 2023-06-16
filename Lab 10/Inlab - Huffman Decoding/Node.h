/*
Spencer Hernandez
4/17/2022
Node.h
I utilized professor Bloomfield's code to implement the heap
*/
#ifndef NODE_H
#define NODE_H
#include <iostream>
using namespace std;

class Node {
 public:
  Node();
  Node(int frequency, char letter);
  ~Node();

  Node *left;
  Node *right;
  char letter;
  int frequency;
  string prefix;
  int bits;
};

#endif
