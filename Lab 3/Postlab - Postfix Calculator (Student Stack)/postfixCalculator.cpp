/*
Spencer Hernandez
2/9/2022
postfixCalculator.cpp
*/

#include <iostream>
#include "postfixCalculator.h"
#include <string>
#include "Stack.h"
#include "StackNode.h"
using namespace std;

postfixCalculator::postfixCalculator(){
  Stack theStack;
}

int postfixCalculator::calculate(string inputString){
  if (inputString[0] != '+' && inputString[0] != '/' && inputString[0] != '*' && inputString[0] != '~'){
    if (inputString[0] == '-' && inputString.length() != 1){
      int negInt = stoi(inputString);
      theStack.push(negInt);
    }
    else if (inputString[0] != '-'){
      int numInt = stoi(inputString);
      theStack.push(numInt);
    }
    else if (inputString[0] == '-'){
      int numA = theStack.top();
      theStack.pop();
      
      int numB = theStack.top();
      theStack.pop();
      theStack.push(numB - numA);
    }  
  }
  else{
    if (theStack.size() != 0){
      if (inputString[0] == '~'){
	int num0 = theStack.top();
	theStack.pop();
	theStack.push(num0 * -1);
      }
      else{
	int num1 = theStack.top();
	theStack.pop();
      
	int num2 = theStack.top();
	theStack.pop();
      
	if (inputString[0] == '+'){
	  theStack.push(num1 + num2);
	}
	else if (inputString[0] == '*'){
	  theStack.push(num2 * num1);
	}
	else if (inputString[0] == '/'){
	  theStack.push(num2 / num1);
	}
      }
    }
  }
  
  int answer = theStack.top();
  return answer;
}



