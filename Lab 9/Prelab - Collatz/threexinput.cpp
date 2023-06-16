#include <iostream>
#include "timer.h"

using namespace std;

extern "C" int threexplusone(int x);

int main(){
  int x = 0;
  cout << "Enter a number: ";
  cin >> x;

  float iterations = 0;
  cout << "Enter iterations of subroutine: ";
  cin >> iterations;

  timer StopWatch;
  StopWatch.start();
  for(int i = 0; i < iterations; i++){
    threexplusone(x);
  }
  StopWatch.stop();
  
  int step = threexplusone(x);
  cout << "Steps: " << step  << endl;
  return 0;
}
