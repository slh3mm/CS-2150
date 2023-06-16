#include <iostream>
#include <cmath>
#include <string>
using namespace std;

int bitCounter(int x);
string baseConverter(int bitCountNum, string convert, int start, int end);

int main(int argc, char *argv[]){
  if (argc == 1){
    cout << "No arguments found!" << endl;
    return 0;
  }
  cout << argv[1] << " has " << bitCounter(stoi(argv[1])) << " bit(s)" << endl;
  cout << argv[2] << " (base " << argv[3] << ") = " << baseConverter(stoi(argv[1]), argv[2], stoi(argv[3]), stoi(argv[4])) << " (base " << argv[4] << ")"  << endl;
  
  return 0;
}


int bitCounter(int x){
  if (x == 1){
    return 1;
  }
  if (x % 2 == 0){
    return bitCounter(x/2);
  }
  else{
    return bitCounter(x/2) + 1;
  }
  return 0;
}

string baseConverter(int bitCountNum, string convert, int start, int end){
  int length = convert.length();
  int temp = length - 1;
  int tempInt = 0;
  string tempString = "";
  string finalString = "";
  
  
  //convert to base 10
  for (int i = 0; i < length; i++){
    int digit = convert[i] - '0';
    if (digit > 9){
      digit -= 7;
    }
      digit *= pow(start,temp);
      tempInt += digit;
      temp--;
  }
  tempString = to_string(tempInt);
  
  //convert to base END
  while (tempInt != 0){
    int mod = tempInt % end;
    tempInt = tempInt / end;
    if (mod > 9){
      char num = mod + '7';
      string dumbString = "";
      dumbString += num;
      finalString.insert(0, dumbString);
    }
    else{
      finalString.insert(0, to_string(mod));
    }
  }
  
  return finalString;
}
