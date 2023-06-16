/*
Spencer Hernandez
4/17/2022
Node.cpp
I utilized professor Bloomfield's code to implement the heap
*/
#include <iostream>
#include "Node.h"

using namespace std;

Node::Node(){
  left = NULL;
  right = NULL;
  frequency = 0;
  letter = '!';
  bits = 0;
}

Node::Node(int frequency, char letter){
  left = NULL;
  right = NULL;
  this->letter = letter;
  this->frequency = frequency;
  prefix = "";
  bits = 0;
}

Node::~Node(){
}
