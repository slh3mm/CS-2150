/*
Spencer Hernandez
2/9/2022
postfixCalculator.h
*/
#ifndef POSTFIXCALCULATOR_H
#define POSTFIXCALCULATOR_H

#include <iostream>
#include "StackNode.h"
#include "Stack.h"
using namespace std;

class postfixCalculator{
public:
  postfixCalculator();
  int calculate(string inputString);
private:
  Stack theStack;
};

#endif
