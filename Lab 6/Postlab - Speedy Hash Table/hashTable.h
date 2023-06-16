/*
Spencer Hernandez
3/13
hashTable.h
*/

#ifndef HASHTABLE_H
#define HASHTABLE_H

#include <iostream>
#include <string>
#include <fstream>
#include <list>
#include <vector>

using namespace std;

class hashTable{
 public:
  hashTable(int someSize);
  ~hashTable();
  void insert(string word);
  bool contains(string word);
  bool checkprime(unsigned int p);
  int getNextPrime(unsigned int n);
 private:
  vector<list<string>> *table;
  int hash(string key);
};

#endif
