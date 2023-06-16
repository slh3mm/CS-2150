#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <unordered_set>
#include "grid.h"

using namespace std;
/** @details My code for an 8-puzzle solver
 *  @date 4/27/2022
 *  @emoji smile
 */

 

int main(){
  cout << "Enter puzzle" << endl;
  string num1 = "";
  cin >> num1;

  string num2 = "";
  cin >> num2;

  string num3 = "";
  cin >> num3;

  string num4 = "";
  cin >> num4;

  string num5 = "";
  cin >> num5;
  
  string num6 = "";
  cin >> num6;

  string num7 = "";
  cin >> num7;

  string num8 = "";
  cin >> num8;
  
  string num9 = "";
  cin >> num9;

  vector<int> input;
  input.push_back(stoi(num1));
  input.push_back(stoi(num2));
  input.push_back(stoi(num3));
  input.push_back(stoi(num4));
  input.push_back(stoi(num5));
  input.push_back(stoi(num6));
  input.push_back(stoi(num7));
  input.push_back(stoi(num8));
  input.push_back(stoi(num9));

  grid puzzle(input);
  vector<int> goal = {1, 2, 3, 4, 5, 6, 7, 8, 0};
  
  queue<grid> q;
  puzzle.setCount(0);
  q.push(puzzle);

  unordered_set<string> dict;
  int k = 0;
  
  cout << "Solving Puzzle" << endl;
  
  while (!q.empty()){
    grid state = q.front();
    q.pop();
    dict.insert(state.theString());
    if (state.getBoard() == goal){
      k = state.getCount();
      break;
    }
    
    vector<grid> edges = state.getEdges();
    for (int i = 0; i < edges.size(); i++){
      if (dict.find(edges.at(i).theString()) == dict.end()){
        int newCount = edges.at(i).getCount();
        grid newState(edges.at(i).getBoard());
        newState.setCount(newCount);
        q.push(newState);
      }
    }
  }

  if (k == 0){
    cout << "IMPOSSIBLE" << endl;
  }
  else{
    cout << k << endl;
  }
  return 0;
}
