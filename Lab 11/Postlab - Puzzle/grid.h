#ifndef GRID_H
#define GRID_H

#include <string>
#include <vector>
#include <iostream>

using namespace std;

class grid{
 public:
  grid();
  grid(vector<int> newBoard);
  ~grid();
  vector<int> getBoard();
  int findHole();
  void moveUp();
  void moveDown();
  void moveLeft();
  void moveRight();
  bool checkMove(string direction);
  void printBoard();
  void setCount(int c);
  int getCount();
  vector<grid> getEdges();
  string theString();
  
 private:
  vector<int> board;
  int count;
};


#endif
