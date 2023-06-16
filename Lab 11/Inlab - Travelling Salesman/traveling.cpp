#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <vector>

using namespace std;

#include "middleearth.h"

/** @details Returns a brute-force solution to the traveling salesperson problem
 *  @date 4/25/2022
 *  @emoji cry
 */

/**
 * @brief Computes distance between two cities
 *
 * @return float Distance
 * @param me Middle Earth Object
 * @param start Starting city
 * @param dests Cities in the itinerary
 */
float computeDistance(MiddleEarth& me, const string& start, vector<string> dests);

/**
 * @brief Prints route of itinerary
 *
 * @return string
 * @param start Starting city
 * @param dests Cities in the itinerary
 */
void printRoute(const string& start, const vector<string>& dests);

string saveRoute(const string& start, const vector<string>& dests);

int main(int argc, char** argv) {
    // check the number of parameters
    if (argc != 6) {
        cout << "Usage: " << argv[0] << " <world_height> <world_width> "
             << "<num_cities> <random_seed> <cities_to_visit>" << endl;
        exit(0);
    }

    // we'll assume the parameters are all well-formed
    int width = stoi(argv[1]);
    int height = stoi(argv[2]);
    int num_cities = stoi(argv[3]);
    int rand_seed = stoi(argv[4]);
    int cities_to_visit = stoi(argv[5]);

    // create the world, and select your itinerary
    MiddleEarth me(width, height, num_cities, rand_seed);
    vector<string> dests = me.getItinerary(cities_to_visit);
    // TODO: YOUR CODE HERE
    string start = dests.at(0);
    dests.erase(dests.begin());
    sort(dests.begin(), dests.end());
    
    float startDist = 10000000000000.0;
    float minDist = startDist;
    string path = "";
    
    do {
      if(computeDistance(me, start, dests) < minDist){
	minDist = computeDistance(me, start, dests);
	path = saveRoute(start,dests);
	//sort(dests.begin(), dests.end());
      }
    }
    while(next_permutation(dests.begin(), dests.end()));

    cout << "Minimum path has distance " << minDist << ": ";
    cout << path << endl;

    return 0;
}

// This method will compute the full distance of the cycle that starts
// at the 'start' parameter, goes to each of the cities in the dests
// vector IN ORDER, and ends back at the 'start' parameter.
float computeDistance(MiddleEarth& me, const string& start, vector<string> dests) {
    // TODO: YOUR CODE HERE
  float distance = me.getDistance(start,dests.at(0));
  
  for (int i = 0; i + 1 < dests.size(); i++){
    distance += me.getDistance(dests.at(i),dests.at(i+1));
  }
  distance += me.getDistance(start,dests.at(dests.size() - 1));

  return distance;
}

// This method will print the entire route, starting and ending at the
// 'start' parameter.
// The output should be similar to:
// Erebor -> Khazad-dum -> Michel Delving -> Bree -> Cirith Ungol -> Erebor
void printRoute(const string& start, const vector<string>& dests) {
    // TODO: YOUR CODE HERE
  cout << start << "->";
  for(string i : dests){
    cout << i << "->";
    }
  cout << start << endl;
}

string saveRoute(const string& start, const vector<string>& dests) {
    // TODO: YOUR CODE HERE
  string route = "";
  route += start;
  route += "->";
  //cout << start << "->";
  for(string i : dests){
      route += i;
      route += "->";
      //cout << i << "->";
  }
  route += start;
  //cout << start << endl;
  //cout << route << endl;
  return route;
}
