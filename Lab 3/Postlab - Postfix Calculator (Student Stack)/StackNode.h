/*
Spencer Hernandez
2/9/2022
StackNode.cpp
*/
#ifndef STACKNODE_H
#define STACKNODE_H

#include <iostream>

using namespace std;

class StackNode {
public:
    StackNode();

private:
  int value;      
  StackNode* next;    
  StackNode* previous;

  friend class Stack;
};

#endif
