/*
Spencer Hernandez
2/9/2022
Stack.h
*/
#ifndef STACK_H
#define STACK_H

#include <iostream>
#include "StackNode.h"
using namespace std;

class Stack {
public:
  Stack();
  void push(int e);
  void pop();
  int top();
  bool empty();
  int size();

private:
  StackNode* head;
  StackNode* tail;
};

#endif
