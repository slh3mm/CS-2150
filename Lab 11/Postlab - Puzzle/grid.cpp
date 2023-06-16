#include <vector>
#include <string>
#include <iostream>
#include "grid.h"

using namespace std;
/**
 * @brief Constructs a grid object
 *
 * @return void
 * @param none
*/
grid::grid(){
  count = 0;
}
/**
 * @brief Constructs a grid object and sets the board
 *
 * @return void
 * @param newBoard is a board
*/
grid::grid(vector<int> newBoard){
  board = newBoard;
  count = 0;
}
/**
 * @brief Destructs a grid object 
 *
 * @return void
*/
grid::~grid(){

}
/**
 * @brief Returns the board of a grid object
 *
 * @return vector<int>
*/
vector<int> grid::getBoard(){
  return board;
}
/**
 * @brief Returns the index of where the hole is
 *
 * @return int
*/
int grid::findHole(){
  int index = 0;
  for (int i = 0; i < board.size(); i++){
    if (board.at(i) == 0){
      index = i;
      break;
    }
  }
  return index;
}
/**
 * @brief Moves hole up if possible
 *
 * @return void
*/
void grid::moveUp(){
  if (this->checkMove("up") == true){
    int holeIndex = this->findHole();
    if (holeIndex == 3){
      int temp = this->board.at(0);
      this->board.at(0) = 0;
      this->board.at(3) = temp;
    }
    else if (holeIndex == 4){
      int temp = this->board.at(1);
      this->board.at(1) = 0;
      this->board.at(4) = temp;
    }
    else if (holeIndex == 5){
      int temp = this->board.at(2);
      this->board.at(2) = 0;
      this->board.at(5) = temp;
    }
    else if (holeIndex == 6){
      int temp = this->board.at(3);
      this->board.at(3) = 0;
      this->board.at(6) = temp;
    }
    else if (holeIndex == 7){
      int temp = this->board.at(4);
      this->board.at(4) = 0;
      this->board.at(7) = temp;
    }
    else if (holeIndex == 8){
      int temp = this->board.at(5);
      this->board.at(5) = 0;
      this->board.at(8) = temp;
    }
  }
}
/**
 * @brief Moves hole down if possible
 *
 * @return void
*/
void grid::moveDown(){
  if (this->checkMove("down") == true){
    int holeIndex = this->findHole();
    if (holeIndex == 0){
      int temp = this->board.at(3);
      this->board.at(3) = 0;
      this->board.at(0) = temp;
    }
    else if (holeIndex == 1){
      int temp = this->board.at(4);
      this->board.at(4) = 0;
      this->board.at(1) = temp;  
    }
    else if (holeIndex == 2){
      int temp = this->board.at(5);
      this->board.at(5) = 0;
      this->board.at(2) = temp;  
    }
    else if (holeIndex == 3){
      int temp = this->board.at(6);
      this->board.at(6) = 0;
      this->board.at(3) = temp;  
    }
    else if (holeIndex == 4){
      int temp = this->board.at(7);
      this->board.at(7) = 0;
      this->board.at(4) = temp;  
    }
    else if (holeIndex == 5){
      int temp = this->board.at(8);
      this->board.at(8) = 0;
      this->board.at(5) = temp;  
    }
  }
}
/**
 * @brief Moves hole left if possible
 *
 * @return void
*/
void grid::moveLeft(){
  if (this->checkMove("left") == true){
    int holeIndex = this->findHole();
    if (holeIndex == 1){
      int temp = this->board.at(0);
      this->board.at(0) = 0;
      this->board.at(1) = temp;
    }
    else if (holeIndex == 2){
      int temp = this->board.at(1);
      this->board.at(1) = 0;
      this->board.at(2) = temp;
    }
    else if (holeIndex == 4){
      int temp = this->board.at(3);
      this->board.at(3) = 0;
      this->board.at(4) = temp;
    }
    else if (holeIndex == 5){
      int temp = this->board.at(4);
      this->board.at(4) = 0;
      this->board.at(5) = temp;
    }
    else if (holeIndex == 7){
      int temp = this->board.at(6);
      this->board.at(6) = 0;
      this->board.at(7) = temp;
    }
    else if (holeIndex == 8){
      int temp = this->board.at(7);
      this->board.at(7) = 0;
      this->board.at(8) = temp;
    }
  }
}
/**
 * @brief Moves hole right if possible
 *
 * @return void
*/
void grid::moveRight(){
  if (this->checkMove("right") == true){
    int holeIndex = this->findHole();
    if (holeIndex == 0){
      int temp = this->board.at(1);
      this->board.at(1) = 0;
      this->board.at(0) = temp;
    }
    else if (holeIndex == 1){
      int temp = this->board.at(2);
      this->board.at(2) = 0;
      this->board.at(1) = temp;
    }
    else if (holeIndex == 3){
      int temp = this->board.at(4);
      this->board.at(4) = 0;
      this->board.at(3) = temp;
    }
    else if (holeIndex == 4){
      int temp = this->board.at(5);
      this->board.at(5) = 0;
      this->board.at(4) = temp;
    }
    else if (holeIndex == 6){
      int temp = this->board.at(7);
      this->board.at(7) = 0;
      this->board.at(6) = temp;
    }
    else if (holeIndex == 7){
      int temp = this->board.at(8);
      this->board.at(8) = 0;
      this->board.at(7) = temp;
    }
  }
}
/**
 * @brief Checks whether or not a move is valid
 *
 * @return bool Whether or not the move is valid
 * @param direction the move 
*/
bool grid::checkMove(string direction){
  if (this->findHole() == 0 && (direction == "up" || direction == "left")){
    return false;
  }
  if (this->findHole() == 1 && direction == "up"){
    return false;
  }
  if (this->findHole() == 2 && (direction == "up" || direction == "right")){
    return false;
  }
  if (this->findHole() == 3 && direction == "left"){
    return false;
  }
  if (this->findHole() == 5 && direction == "right"){
    return false;
  }
  if (this->findHole() == 6 && (direction == "down" || direction == "left")){
    return false;
  }
  if (this->findHole() == 7 && direction == "down"){
    return false;
  }
  if (this->findHole() == 8 && (direction == "down" || direction == "right")){
    return false;
  }
  return true;
}
/**
 * @brief Prints the board of an object
 *
 * @return void
 * @param none
*/
void grid::printBoard(){
  cout << board.at(0) << " " << board.at(1) << " " << board.at(2) << endl;
  cout << board.at(3) << " " << board.at(4) << " " << board.at(5) << endl;
  cout << board.at(6) << " " << board.at(7) << " " << board.at(8) << endl;
  cout << endl;
}
/**
 * @brief Returns count of the object
 *
 * @return int
 * @param none
*/
int grid::getCount(){
  return this->count;
}
/**
 * @brief Sets count of the object to c
 *
 * @return void
 * @param c
*/
void grid::setCount(int c){
  count = c;
}
/**
 * @brief Returns the string interpretation of the grid
 *
 * @return string
 * @param none
*/
string grid::theString(){
  string s = "";
  for (int i = 0; i < this->board.size(); i++){
    s += to_string(this->board[i]);
    //cout << this->board.at(i) << endl;
  }
  return s;
}
/**
 * @brief Finds which grids are valid moves of the current board
 *
 * @return vector of grids 
 * @param none
*/
vector<grid> grid::getEdges(){
  vector<grid> neighbors;
  if (this->checkMove("up") == true){
    this->moveUp();
    grid upEdge(this->getBoard());
    upEdge.setCount(this->getCount() + 1);
    neighbors.push_back(upEdge);
    this->moveDown();
  }
  if (this->checkMove("down") == true){
    this->moveDown();
    grid downEdge(this->getBoard());
    downEdge.setCount(this->getCount() + 1);
    neighbors.push_back(downEdge);
    this->moveUp();
  }
  if (this->checkMove("left") == true){
    this->moveLeft();
    grid leftEdge(this->getBoard());
    leftEdge.setCount(this->getCount() + 1);
    neighbors.push_back(leftEdge);
    this->moveRight();
  }
  if (this->checkMove("right") == true){
    this->moveRight();
    grid rightEdge(this->getBoard());
    rightEdge.setCount(this->getCount() + 1);
    neighbors.push_back(rightEdge);
    this->moveLeft();
  }
  return neighbors;
}
