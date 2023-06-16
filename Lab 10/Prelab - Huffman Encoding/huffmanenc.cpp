/*
Spencer Hernandez
4/17/2022
huffmanenc.cpp
I utilized professor Bloomfield's code to implement the heap
*/
#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>
#include <vector>
#include <unordered_set>
#include <unordered_map>
#include "heap.h"
#include "Node.h"

using namespace std;
bool setPrefix(Node *root, string thePrefix);

int main(int argc, char *argv[]){
  //Open file
  ifstream file(argv[1]);
  if (!file.is_open()) {
    cout << "Unable to open '" << argv[1] << "' for reading" << endl;
    exit(2);
  }

  //Read in characters, store frequencies in array
  char letter;
  int frequencies[95] = {0};
  int numLetters = 0;
  string String = "";
  while(file.get(letter)){
    if ((int) letter >= 32 && (int) letter <= 127){
      int letterInt = (int) letter - 32;
      frequencies[letterInt]++;
      numLetters++;
      String += letter;
    }
  }

  //Construct min-heap with characters and frequencies
  heap theHeap;
  int diffLetters = 0;
  for(int i = 0; i <= 94; i++){
    if(frequencies[i] > 0){
      char nodeLetter = (char) i;
      Node* newNode = new Node(frequencies[i], nodeLetter);
      theHeap.insert(newNode);
      diffLetters++;
    }
  }

  //Construct forest out of min-heap
  heap forest;
  for (int i = 1; i <= diffLetters; i++){
    Node* min = theHeap.deleteMin();
    forest.insert(min);
  }

  //Construct huffman Tree out of forest
  heap huffHeap = forest;
  while(huffHeap.size() != 1){
    Node* tempNode = new Node();
    tempNode->left = huffHeap.deleteMin();
    tempNode->right = huffHeap.deleteMin();
    tempNode->frequency = tempNode->left->frequency + tempNode->right->frequency;
    huffHeap.insert(tempNode);
  }

  //Set and print prefixes
  Node* top = huffHeap.getMyHeap()[1];
  bool val = setPrefix(top, "");

  if (val == false){
    cout << "Prefixes not set" << endl;
  }

  for (int i = 1; i <= diffLetters; i++){
    char let = (char) forest.getMyHeap()[i]->letter + 32;
    if (let == ' '){
      cout << "space" << " " << forest.getMyHeap()[i]->prefix << endl;
    }
    else{
      cout << let << " " << forest.getMyHeap()[i]->prefix << endl;
    }
  }
  
  cout << "----------------------------------------" << endl;

  //Store characters and their frequencies in a hash map
  unordered_map<char, string> theHash;
  for (int i = 1; i <= diffLetters; i++){
    char theLet = (char) forest.getMyHeap()[i]->letter + 32;
    theHash[theLet] = forest.getMyHeap()[i]->prefix;
  }
  
  //Print out the encoded message and count the total number of bits
  double numBits = 0;
  
  for(int i = 0; i < String.length(); i++){
    cout << theHash.find(String[i])->second << " ";
    numBits += theHash.find(String[i])->second.length();
  }
  cout << endl;

  cout << "----------------------------------------" << endl;

  //Print out other statistics
  double totalLetters = numLetters - 1;
  cout << "There are a total of " << numLetters<< " symbols that are encoded." << endl;
  cout << "There are " << diffLetters << " distinct symbols used." << endl;

  cout << "There were " << numLetters * 8 << " bits in the original file." << endl;

  cout << "There were " << numBits << " bits in the compressed file." << endl;

  cout << "This gives a compression ratio of " << numLetters * 8 / numBits << endl;

  cout << "The cost of the Huffman tree is " << numBits / numLetters << endl;
  return 0;
}

bool setPrefix(Node *node, string thePrefix){
  if (node != NULL){
    Node* Left = node->left;
    Node* Right = node->right;
    if (Left == NULL && Right == NULL){
      node->prefix = thePrefix;
    }
    if (Left != NULL){
      setPrefix(Left, thePrefix + "0");
    }
    if (Right != NULL) {
      setPrefix(Right, thePrefix + "1");
    }
    return true;
  }
  else{
    return false;
  }
}
