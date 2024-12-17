#include <iostream>
#include <random>
#include "ex01-library.h"

using namespace std;

// Task 1(a).  Implement this function
Tile **createSea(unsigned int m) {
    Tile** sea = new Tile*[m]; // m [rows] (height)
      // Allocate memory of 2m columns for each row (at runtime)
    for (int i = 0; i < m; i++) {
        sea[i] = new Tile[2 * m]; // x 2m [columns] (width)
        // Initialize each tile in the sea to have no ship and not hit
        // Empty sea (no ships, no hits)
        for (unsigned int j = 0; j < 2 * m; j++) {
            sea[i][j].ship = 0;
            sea[i][j].hit = false;
        }
    }
    
    return sea;
}


// Task 1(b).  Implement this function
void displaySea(Tile **sea, unsigned int m, bool reveal) {

    for (int i = 0; i < m; i++) { // For each row
        for (int j = 0; j < 2 * m; j++) { // For each column
            if (reveal) {
                // If the tile has a ship and has been hit
                if (sea[i][j].ship > 0 && sea[i][j].hit) {
                    cout << "X"; // Hit ship
                } else if (sea[i][j].ship > 0) {
                    cout << sea[i][j].ship; // Ship number
                } else if (sea[i][j].hit) {
                    cout << " "; // Miss
                } else {
                    cout << " "; // Empty sea
                }
            } else {
                if (sea[i][j].ship > 0 && sea[i][j].hit) {
                    cout << "X"; // Hit ship
                } else if (sea[i][j].hit && sea[i][j].ship == 0) {
                    cout << " "; // Hit in empty sea area
                } else {
                    cout << "?"; // Unknown area (Not revealed by missile launch)
                }
            }
        }
        // New line for next row...
        cout << endl;
    }
}


// Task 1(c).  Implement this function
bool launchBigMissile(Tile **sea, unsigned int m, unsigned int r, unsigned int c) {

    // Launching missile at (r, c) in sea
    // If the tile has a ship, set hit to true

    // Check if (r,c) is a valid tile (within the sea) 
    // OR if the tile has been hit already
    if ((r >= m || c >= 2 * m) || sea[r][c].hit == true) {
        return false;
    } 

    // Otherwise, valid hit!
    sea[r][c].hit = true; 

    // Given we are +/- 1 from sea boundary, we can update .hit of surrounding tiles
    if (r > 0) { // if r is at least 1 inside map boundary, we can hit above 
        sea[r - 1][c].hit = true; // Up
    }
    if (r < m - 1) { // same, but bottom
        sea[r + 1][c].hit = true; // Down
    }
    if (c > 0) { // can hit left
        sea[r][c - 1].hit = true; // Left
    }
    if (c < 2 * m - 1) { // can hit right
        sea[r][c + 1].hit = true; // Right
    }
    return true;

}

// Task 1(d).  Implement this function
bool isGameOver(Tile **sea, unsigned int m){
    // Check if all ships have been hit 
    // (checking if a single ship is not hit)
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < 2 * m; j++) {
            if (sea[i][j].ship > 0 && !sea[i][j].hit) {
                return false;
            }
        }
    }
    // otherwise, true
    return true;
}

// Do not modify the following function.
void deleteSea(Tile **sea, unsigned int m) {
    for (unsigned int i = 0; i < m; i++) {
        delete[] sea[i];
    }
    delete[] sea;
}
