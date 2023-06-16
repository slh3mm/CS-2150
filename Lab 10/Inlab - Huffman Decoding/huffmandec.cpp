#include <iostream>
#include <fstream>
#include <sstream>
#include <cstdlib>
#include <string>
#include "heap.h"
#include "Node.h"
using namespace std;

void buildTree(char c, string prefix, Node*& root);
string decodeTree(string code, Node* root);
		
// main(): we want to use parameters
int main (int argc, char** argv) {
    // verify the correct number of parameters
    if (argc != 2) {
        cout << "Must supply the input file name as the only parameter" << endl;
        exit(1);
    }

    // attempt to open the supplied file
    // must be opened in binary mode as otherwise trailing whitespace is discarded
    ifstream file(argv[1], ifstream::binary);
    // report any problems opening the file and then exit
    if (!file.is_open()) {
        cout << "Unable to open file '" << argv[1] << "'." << endl;
        exit(2);
    }

    // read in the first section of the file: the prefix codes
    Node* rootNode = new Node();
    while (true) {
        string character, prefix;
        // read in the first token on the line
        file >> character;

        // did we hit the separator?
        if (character[0] == '-' && character.length() > 1) {
            break;
        }

        // check for space
        if (character == "space") {
            character = " ";
        }

        // read in the prefix code
        file >> prefix;
        // do something with the prefix code
	char let = character[0];
	buildTree(let, prefix, rootNode);
        //cout << "character '" << character << "' has prefix code '" << prefix << "'" << endl;
    }
    // read in the second section of the file: the encoded message
    stringstream sstm;
    while (true) {
        string bits;
        // read in the next set of 1's and 0's
        file >> bits;
        // check for the separator
        if (bits[0] == '-') {
            break;
        }
        // add it to the stringstream
        sstm << bits;
    }

    string allbits = sstm.str();
    // at this point, all the bits are in the 'allbits' string
    //cout << "All the bits: " << allbits << endl;
    // close the file before exiting
    file.close();
    // cout << decodeTree(allbits, rootNode, "") << endl;
    cout << decodeTree(allbits, rootNode) << endl;
    return 0;
}

void buildTree(char c, string prefix, Node*& root){
  if (root == NULL || prefix.length() == 0){
    root = new Node();
  }
  if (prefix.length() == 0){
    root->letter = c;
  }
  else{
    if (prefix[0] == '0'){
      buildTree(c, prefix.substr(1,prefix.length()), root->left);
    }
    if (prefix[0] == '1'){
      buildTree(c, prefix.substr(1,prefix.length()), root->right);
    }
  }
}
string decodeTree(string code, Node* root){
  if (root == NULL || code.length() == 0){
    return "";
  }
  Node* currNode = root;
  string message = "";
  for (int i = 0; i < code.length(); i++){
      if (code[i] == '0'){
	currNode = currNode->left;
      }
      if (code[i] == '1'){
	currNode = currNode->right;
      }
      if (currNode->letter != '!'){
	message += currNode->letter;
	currNode = root;
      }
  }
  return message;
}
