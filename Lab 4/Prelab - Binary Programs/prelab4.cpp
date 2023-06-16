#include <iostream>
#include <cmath>
using namespace std;

void sizeOfTest();
void overflow();
void outputBinary(unsigned int x);

int main(){
  unsigned int a;
  sizeOfTest();
  overflow();
  cin >> a;
  outputBinary(a);
  return 0;
}

void sizeOfTest(){
  int a;
  unsigned int b;
  float c;
  double d;
  char e;
  bool f;
  int* g;
  char* h;
  double* i;

  cout << "Size of int: " << sizeof(a) << endl;
  cout << "Size of unsigned int: " << sizeof(b) << endl;
  cout << "Size of float: " << sizeof(c) << endl;
  cout << "Size of double: " << sizeof(d) << endl;
  cout << "Size of char: " << sizeof(e) << endl;
  cout << "Size of bool: " << sizeof(f) << endl;
  cout << "Size of int*: " << sizeof(g) << endl;
  cout << "Size of char*: " << sizeof(h) << endl;
  cout << "Size of double*: " << sizeof(i) << endl;
}

void overflow(){
  unsigned int a = 4294967295;
  unsigned int b = a + 1;

  cout << a << " + 1 = " << b << endl;
}

void outputBinary(unsigned int x){
  int n = 31;
  
  while(n >= 0){
    if (n == 27 || n == 23 || n == 19 || n == 15 || n == 11 || n == 07 || n == 3){
      cout << " ";
    }
    if (x >= pow(2,n)){
      cout << "1";
      x -= pow(2,n);
    }
    
    else{
      cout << "0";
    }

    n--;
  }
  
  cout << endl;
}
