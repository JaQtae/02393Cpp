#include <iostream>
#include <random>
#include "ex01-library.h"

using namespace std;

Tile **createSea(unsigned int m, unsigned int n) {
    Tile **sea = new Tile*[m]; // Allocate memory for the rows of the grid

    for (unsigned int i = 0; i < m; i++) {
        sea[i] = new Tile[n]; // Allocate memory for each column in the row
        for (unsigned int j = 0; j < n; j++) {
            sea[i][j].ship = 0;
            sea[i][j].hit = false;
        }
    }

    return sea;
}


// Task 1(b).  Implement this function
void displaySea(Tile **sea, unsigned int m, unsigned int n, bool reveal) {
    
}

// Task 1(c).  Implement this function
bool placeShip(Tile **sea, unsigned int m, unsigned int n, unsigned int r, unsigned int c, unsigned int number, unsigned int size, bool vertical) {
    return false; 
}

// Task 1(d).  Implement this function
bool launchMissile(Tile **sea, unsigned int m, unsigned int n, unsigned int r, unsigned int c)
{
    return false;
}

// Do not modify the following function.
void deleteSea(Tile **sea, unsigned int m) {
    for (unsigned int i = 0; i < m; i++) {
        delete[] sea[i];
    }
    delete[] sea;
}
