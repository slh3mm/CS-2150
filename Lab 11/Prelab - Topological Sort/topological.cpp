#include <iostream>
#include <fstream>
#include <cstdlib>
#include <unordered_map>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

/**
 * @brief Performs a topological sort on strings and prints it out.
 * @emoji smile
 * @date 4/25/2022
 */

// we want to use parameters
int main(int argc, char** argv) {
    // verify the correct number of parameters
    if (argc != 2) {
        cout << "Must supply the input file name as the one and only parameter" << endl;
        exit(1);
    }

    // attempt to open the supplied file
    ifstream file(argv[1], ifstream::binary);
    // report any problems opening the file and then exit
    if (!file.is_open()) {
        cout << "Unable to open file '" << argv[1] << "'." << endl;
        exit(2);
    }

    // read in two strings
    string s1, s2;
    file >> s1;
    file >> s2;

    unordered_map<string, vector<string>> outgoingEdges;
    unordered_map<string, int> numIncoming;
    int numNodes = 0;
    vector<string> classes;
    while(s1 != "0" && s2 != "0"){
      outgoingEdges[s1].push_back(s2);
      numIncoming[s2]++;
      if (find(classes.begin(), classes.end(), s1) == classes.end()){
	      classes.push_back(s1);
      }
      if (find(classes.begin(), classes.end(), s2) == classes.end()){
	      classes.push_back(s2);
      }
      file >> s1;
      file >> s2;
      numNodes++;
    }

    file.close();
    numNodes--;
    queue<string> q;
    vector<string> list;
    int counter = 0;
    for (int i = 0; i < classes.size(); i++){
      if (numIncoming[classes.at(i)] == 0){
	      q.push(classes.at(i));
	      list.push_back(classes.at(i));
      }
    }

    while (!q.empty()){
      string vertex = q.front();
      q.pop();
      counter++;
      for (string i : outgoingEdges[vertex]){
        if (--numIncoming[i] == 0){
          q.push(i);
        }
        if (find(list.begin(), list.end(), i) == list.end()){
          list.push_back(i);
        }
      }
    }
    // close the file before exiting
    for (int i = 0; i < list.size(); i++){
      cout << list.at(i) << " ";
    }
    cout << endl;

    return 0;
}
