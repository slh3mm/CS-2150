/*
Spencer Hernandez
3/13
hashTable.cpp
*/

#include <iostream>
#include "hashTable.h"
#include <string>
#include <list>
#include <algorithm>
#include <vector>
#include <math.h>

using namespace std;

hashTable::hashTable(int someSize){
  table = new vector<list<string>>;
  /* for(int i = 0; i < size; i++) {
    table->push_back(list<string>());
    }*/
  table->resize(someSize);
}

hashTable::~hashTable(){
  delete table; 
}

void hashTable::insert(string word){
  int val = hash(word);
  list<string> & theBucket = table->at(val);
  theBucket.push_back(word);
}

bool hashTable::contains(string word){
  int val = hash(word);
  list<string> &bucket = table->at(val);
  return (find(bucket.begin(), bucket.end(),word) == bucket.end());
}

int hashTable::hash(string key){
  int val = 0;
  for(int i = 0; i < key.length(); i++){
    val = (int)(key[i]) + (val *3);
  }

  return val % table->size();
}

bool hashTable::checkprime(unsigned int p) {
   if ( p <= 1 ) // 0 and 1 are not primes; the are both special cases
    return false;
  if ( p == 2 ) // 2 is prime
    return true;
  if ( p % 2 == 0 ) // even numbers other than 2 are not prime
    return false;
  for ( int i = 3; i*i <= p; i += 2 ) // only go up to the sqrt of p
    if ( p % i == 0 )
      return false;
  return true;
}

int hashTable::getNextPrime(unsigned int n) {
  while ( !checkprime(++n) );
  return n; // all your primes are belong to us
}
