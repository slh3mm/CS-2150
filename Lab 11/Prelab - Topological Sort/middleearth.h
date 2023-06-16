#ifndef MIDDLEEARTH_H
#define MIDDLEEARTH_H

#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <random>

using namespace std;

// see the comments in the lab11 write-up, or in middleearth.cpp

/**
 * @brief Class used to construct the world for TSP Problem
 * @details Not my original code, I only commented it!
 * @emoji cry
 * @date 4/24/2022
 */
 
class MiddleEarth {
public:
/** @brief Constructs objects of type MiddleEarth
 * 
 * @param xsize Width of world
 * @param ysize Hieght of world
 * @param num_cities Number of cities in the  world
 * @param seed Random seed to generate cities by
 */
    MiddleEarth(int xsize, int ysize, int num_cities, int seed);
    
/** @brief Prints out info on created world
 * 
 * @return void
 * 
 */
    void print();
    
/** @brief Prints a tab-separated table of the distances
 * 
 * @return void
 * 
 */
    void printTable();
    
/** @brief Calculates the distance between 2 cities
 * 
 * @return Distance between two cities (float)
 * @param city1 First city
 * @param city2 Second city 
 * 
 */
    float getDistance(const string& city1, const string& city2);
    
/** @brief Returns the list of cities to travel to
 * 
 * @return Cities in itinerary (vector<string>)
 * @param length of path (unsigned int)
 * 
 */
    vector<string> getItinerary(unsigned int length);

private:
/**@brief Stores number of cities (num_city_names), width (xsize), and height (ysize) of world
*/
    int num_city_names, xsize, ysize;
/**@brief Stores x and y coordinates of current position 
*/
    unordered_map<string, float> xpos, ypos;
/**@brief Stores cities
*/
    vector<string> cities;
/**@brief Stores distances between cities
*/ 
    unordered_map<string, unordered_map<string, float>> distances;

/**@brief Mersenne-Twister random number engine
*/
    mt19937 gen;
};

#endif
