/*
Spencer Hernandez
Pre-lab 08
mathfun.cpp
*/
#include <iostream>
using namespace std;

extern "C" int product (int, int);
extern "C" int power (int, int);

int main(){
  int a = 0;
  int b = 0;

  cout << "Enter integer 1: ";
  cin >> a;
  cout << "Enter integer 2: ";
  cin >> b;

  cout << "Product: " << product(a,b) << endl;
  cout << "Power: " << power(a,b) << endl;
  
  return 0;
}
