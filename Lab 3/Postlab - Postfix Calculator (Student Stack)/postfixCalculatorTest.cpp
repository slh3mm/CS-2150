/*
Spencer Hernandez
2/7/2022
postfixCalculatorTest.cpp
*/
#include <iostream>
using namespace std;

#include "postfixCalculator.h"

int main(){
  postfixCalculator calc;
  string token;
  int result = 0;
  
  while (cin >> token) {
    result = calc.calculate(token);
}
  
   cout << result << endl;
  return 0;
}
