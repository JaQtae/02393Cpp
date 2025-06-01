#include <iostream>
#include <random>
#include "ex01-library.h"

using namespace std;

// Task 1(a).  Implement this function
Tile **createSea(unsigned int m) {
    Tile** sea = new Tile*[m]; // {unsigned int ship, bool hit} is assigned to sea with m
    // build the map that is [m x 2m], where ship = 0 and hit = 0 for all m
    for (unsigned int i = 0; i < m; i++){
        // Allocating memory for 2m columns for each row before insertion
        sea[i] = new Tile[2*m];
        for (unsigned int j = 0; j < 2*m; j++){
            sea[i][j].ship = 0;
            sea[i][j].hit = false;
        }
    }
    return sea;
}


// Task 1(b).  Implement this function
void displaySea(Tile **sea, unsigned int m, bool reveal) {
    // Needs to print screen. Remember to endl; after a given row!
    for (unsigned int i = 0; i < m; i++){
        for (unsigned int j = 0; j < 2*m; j++){
                if (reveal) {
                    if (sea[i][j].hit && sea[i][j].ship > 0){ 
                        cout << "X"; // Ship is valid AND has been hit
                    } else if (sea[i][j].ship > 0) {
                        cout << sea[i][j].ship; // Display the ship number
                    } else { // Not occupied by ship
                        cout << " ";
                    }
                } else { // No ship number displays
                    if (sea[i][j].hit && sea[i][j].ship > 0){ 
                        cout << "X"; // Ship is valid AND has been hit
                    } else if (sea[i][j].hit && sea[i][j].ship == 0){ 
                        cout << " "; // If you've hit, but there was nothing, replace "?" -> " "
                    } else {
                        cout << "?"; // Unknown/uninteracted square
                    }
                }
        } // Done with the column, so typewriter to next row
    cout << endl;
    }
}


// Task 1(c).  Implement this function
bool launchBigMissile(Tile **sea, unsigned int m, unsigned int r, unsigned int c) {
    if ((r >= m || c >= 2 * m) || sea[r][c].hit == true) {
        return false; // If its outside sea boundaries or is already hit
    } 

    // Update middle of hit
    sea[r][c].hit = true;
    // Check the surrounding and update if viable. Starting from left/top boundaries
    if (r > 0){ sea[r - 1][c].hit = true; } // If we're inside top, we can hit upward
    if (c > 0){ sea[r][c - 1].hit = true; } // we can hit left
    // Look from right/bottom boundaries
    if (r < m - 1){ sea[r + 1][c].hit = true; } // there's a row below we can hit
    if (c < 2*m - 1){ sea[r][c+1].hit = true; } // w can hit right

    return true;
}


// Task 1(d).  Implement this function
bool isGameOver(Tile **sea, unsigned int m){
    for (int i = 0; i < m; i++) { // Check all tiles
        for (int j = 0; j < 2 * m; j++) {
            if (sea[i][j].ship > 0 && !sea[i][j].hit) { // If we find a ship that is not hit
                return false; // Well then not all ships have been hit fully!
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
