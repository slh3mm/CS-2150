/*
Spencer Hernandez
wordPuzzle.cpp
CS 2150

*/

#include <iostream>
#include <string>
#include <unordered_set>
#include <fstream>
#include "timer.h"
#include "hashTable.h"

using namespace std;

#define MAXROWS 500
#define MAXCOLS 500
char grid[MAXROWS][MAXCOLS];

// Forward declarations
bool readInGrid(string filename, int& rows, int& cols);
string getWordInGrid(int startRow, int startCol, int dir, int len, int numRows, int numCols);

int main(int argc, char **argv){
  //open dictionary
  string dict = argv[1];
  string line;
  ifstream myDict(dict);

  int numLines = 0;
  while(getline(myDict,line)){
    numLines++;
  }

  hashTable* theTable = new hashTable(numLines);
  myDict.close();
  
  //store words into hash table
  ifstream myDict2(dict);
  while(getline(myDict2,line)){
    if(line.length() >= 3){
      theTable->insert(line);
    }
  }myDict2.close();

  //load in grid of words
  string theGrid = argv[2];
  ifstream myGrid(theGrid);
  int rows;
  int columns;
  
  if(readInGrid(theGrid, rows, columns) == false){
    //cout << "File DNE" << endl;
    return 1;
  }

  int words = 0;

  timer runTime;
  runTime.start();
  //find what words are in grid
  for(int i = 0; i < rows; i++){
    for(int k = 0; k < columns; k++){
      for(int j = 0; j <= 7; j++){
	for(int l = 3; l <= 22; l++){
	  string way = "";
	  string currentWord = getWordInGrid(i, k, j, l, rows, columns);
	  int len = currentWord.length();
	  if(!theTable->contains(currentWord) && l <= len){
	    if(j == 0){
	      way = "N (";
	    }
	    if(j == 2){
	      way = "E (";
	    }
	    if(j == 4){
	      way = "S (";
	    }
	    if(j == 6){
	      way = "W (";
	    }
	    if(j == 1){
	      way = "NE (";
	    }
	    if(j == 3){
	      way = "SE (";
	    }
	    if(j == 5){
	      way = "SW (";
	    }
	    if(j == 7){
	      way = "NW (";
	    }
	    cout << way << i << ", " << k << "): " << currentWord << endl;
	    words++;
	  }
	}
      }
    }
  }
  runTime.stop();
  //int mili = runTime.getTime()*1000;
  int sec = runTime.getTime();
  cout << words << " words found" << endl;
  //cout << runTime.getTime() << endl;
  return 0;
}

bool readInGrid(string filename, int& rows, int& cols) {
  // try to open the file
  ifstream file(filename);
  // upon an error, return false
  if (!file.is_open()) {
    return false;
  }

  // first comes the number of rows
  file >> rows;
  //cout << "There are " << rows << " rows." << endl;

  // then the columns
  file >> cols;
  //cout << "There are " << cols << " cols." << endl;

  // and finally the grid itself
  string data;
  file >> data;

  // close the file
  file.close();

  // convert the string read in to the 2-D grid format into the
  // grid[][] array.
  // In the process, we'll print the grid to the screen as well.
  int pos = 0; // the current position in the input data
  for (int r = 0; r < rows; r++) {
    for (int c = 0; c < cols; c++) {
      grid[r][c] = data[pos++];
      //cout << grid[r][c];
    }
    //cout << endl;
  }
  return true;
}

string getWordInGrid (int startRow, int startCol, int dir, int len,
                      int numRows, int numCols) {
  // the static-ness of this variable prevents it from being
  // re-declared upon each function invocation.  It also prevents it
  // from being deallocated between invocations.  It's probably not
  // good programming practice, but it's an efficient means to return
  // a value.
  static string output;
  output.clear(); // Since it's static we need to clear it
  output.reserve(256); // Can't set capacity in the constructor so do it the first time here

  // the position in the output array, the current row, and the
  // current column
  int r = startRow, c = startCol;
  // iterate once for each character in the output
  for (int i = 0; i < len; i++) {
    // if the current row or column is out of bounds, then break
    if (c >= numCols || r >= numRows || r < 0 || c < 0) {
      break;
    }

    // set the next character in the output array to the next letter
    // in the grid
    output += grid[r][c];

    // move in the direction specified by the parameter
    switch (dir) { // assumes grid[0][0] is in the upper-left
    case 0:
      r--;
      break; // north
    case 1:
      r--;
      c++;
      break; // north-east
    case 2:
      c++;
      break; // east
    case 3:
      r++;
      c++;
      break; // south-east
    case 4:
      r++;
      break; // south
    case 5:
      r++;
      c--;
      break; // south-west
    case 6:
      c--;
      break; // west
    case 7:
      r--;
      c--;
      break; // north-west
    }
  }

  return output;
}
