#include <iostream>
#include <random>
#include "ex01-library.h"

using namespace std;

// Task 1(a).  Implement this function
Tile **createSea(unsigned int m, unsigned int n) {
    Tile** sea = new Tile*[m];
    for (unsigned int i = 0; i < m; i++){
        sea[i] = new Tile[n];
        for (unsigned int j = 0; j < n; j++){
            sea[i][j].hit = false;
            sea[i][j].ship = 0;
        }
    }
    return sea;
}


// Task 1(b).  Implement this function
void displaySea(Tile **sea, unsigned int m, unsigned int n, bool reveal) {
    for (unsigned int i = 0; i < m; i++){
        for (unsigned int j = 0; j < n; j++){
            if (reveal) {
                if (sea[i][j].hit && sea[i][j].ship > 0) {
                    cout << "X";
                } else if (sea[i][j].ship > 0){
                    cout << sea[i][j].ship;
                } else {
                    cout << " ";
                }
            } else {
                if (sea[i][j].hit && sea[i][j].ship > 0) {
                    cout << "X";
                } else if (sea[i][j].hit && sea[i][j].ship == 0){
                    cout << " ";
                } else {
                    cout << "?";
                }
            }
        }
    cout << endl;
    }
}

// Task 1(c).  Implement this function
bool placeShip(Tile **sea, unsigned int m, unsigned int n, unsigned int r, unsigned int c, unsigned int number, unsigned int size, bool vertical) {
    // Checks that make it unvalid
    for (unsigned int i = 0; i < m; i++){
        for (unsigned int j = 0; j < n; j++){
            if (sea[i][j].ship == number) { // Another ship has this number already
                return false;
            }
        }
    }

    if (size < 1 || size > 4) {
        return false; // Size invalid
    }
    if ((r < 0) ||( r >= m) || (c < 0) || (c >= n)) {
        return false; // Outside boundaries of m x n grid
    }
    if (vertical) {
        if (r+size > m) {
            return false; // (r+size,c) is within sea boundaries
        }
        for (unsigned int i = 0; i < size; i++){
            if (sea[r+i][c].ship > 0) {
                return false; // Occupied by another ship
            }   // Go through entirety of size to check before we can put down all numbers along the line
        }
        for (unsigned int i = 0; i < size; i++){
            sea[r+i][c].ship = number; // Update sea!
        }

    } else { // horizontal
        if (c+size > n) {
            return false; // (r,c+size) is within sea boundaries
        }
        for (unsigned int i = 0; i < size; i++){
            if (sea[r][c+i].ship > 0) {
                return false; // Occupied by another ship
            }   // Go through entirety of size to check before we can put down all numbers along the line
        }
        for (unsigned int i = 0; i < size; i++){
            sea[r][c+i].ship = number; // Update sea!
        }
    }


    
    return true; // Made it past all false checks
}

// Task 1(d).  Implement this function
bool launchMissile(Tile **sea, unsigned int m, unsigned int n, unsigned int r, unsigned int c){
    if ((r < 0) ||( r >= m) || (c < 0) || (c >= n)) {
        return false; // Outside boundaries of m x n grid
    }
    if (sea[r][c].hit){return false;} // already hit

    // Update
    sea[r][c].hit = true;

    return true;
}

// Do not modify the following function.
void deleteSea(Tile **sea, unsigned int m) {
    for (unsigned int i = 0; i < m; i++) {
        delete[] sea[i];
    }
    delete[] sea;
}
