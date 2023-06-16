/*
Spencer Hernandez
slh3mm
1/25
bankAccount.cpp
*/


#include "bankAccount.h"
#include <iostream>
using namespace std;

bankAccount::bankAccount(){
  balance = 0.0;
}

bankAccount::bankAccount(double amount){
  balance = amount;
}

bankAccount::~bankAccount(){}

double bankAccount::withdraw(double amount){
  if (amount > getBalance()){
    return getBalance();
  }
  balance = balance - amount;
  return balance;
}

double bankAccount::deposit(double amount){
  balance += amount;
  return balance;
}

double bankAccount::getBalance(){
  return balance;
}





