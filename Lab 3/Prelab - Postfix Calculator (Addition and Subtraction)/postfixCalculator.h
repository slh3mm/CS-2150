/*
Spencer Hernandez
2/7/2022
postfixCalculator.h
*/
#ifndef POSTFIXCALCULATOR_H
#define POSTFIXCALCULATOR_H

#include <iostream>
#include <stack>
using namespace std;

class postfixCalculator{
 public:
  postfixCalculator();
  int calculate(string inputString);
private:
  stack<int> theStack;
};
#endif
