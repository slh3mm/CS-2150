/*
Spencer Hernandez
2/7/2022
postfixCalculator.cpp
*/

#include <iostream>
#include "postfixCalculator.h"
#include <stack>
#include <string>
using namespace std;

postfixCalculator::postfixCalculator(){
  stack<int> theStack;
}

int postfixCalculator::calculate(string inputString){
  if (inputString[0] != '+' && inputString[0] != '-'){
      int numInt = stoi(inputString);
      theStack.push(numInt);
  }
  else{
    if (!theStack.empty()){
      int num1 = theStack.top();
      theStack.pop();
      
      int num2 = theStack.top();
      theStack.pop();
      
      if (inputString[0] == '+'){
	      theStack.push(num1 + num2);
      }
      else if (inputString[0] == '-'){
	      theStack.push(num2 - num1);
      }
    }
  }
  
  int answer = theStack.top();
  return answer;
}



