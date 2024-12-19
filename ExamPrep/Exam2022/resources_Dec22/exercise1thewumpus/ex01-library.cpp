#include <iostream>
#include <random>
#include <cmath>
#include "ex01-library.h"

using namespace std;

// Task 1(a).  Implement this function
Tile **createCavern(unsigned int m, unsigned int n) {
    // Replace the following with your code
    Tile **cav = new Tile*[m]; // Allocate memory
    // We are given n and m. So no need to calculate n.
    for (unsigned int row = 0; row < m; row++) {
        cav[row] = new Tile[n];
        for (unsigned int col = 0; col < n; col++) {
            cav[row][col] = {nothing, false}; // {content, explored} = {nothing, false}
        }
    }
    return cav; // Return the cavern map.
}

// Auxiliary function to check if Euclidean distance between two points is below a threshold
bool EuclideanDistanceBelowThreshold(int x1, int x2, int y1, int y2, int d) {
    // Euclidean distance formula: sqrt((x1-x2)^2 + (y1-y2)^2). 
    return (((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2))) < (d*d);
}

// Task 1(b).  Implement this function
void revealCavern(Tile **cav, unsigned int m, unsigned int n) {
    for (unsigned int row = 0; row < m; row++) {
        for (unsigned int col = 0; col < n; col++) {
            // Set parameter s.t. all is revealed!
            cav[row][col].explored = true;
            // Input content of tile as description...
            if (cav[row][col].content == nothing) {
                cout << " ";
            } else if (cav[row][col].content == player) {
                cout << "X";
            } else if (cav[row][col].content == rock) {
                cout << "#";
            } else if (cav[row][col].content == wumpus) {
                cout << "W";
            }
        }
    cout << endl;
    }
}

// Task 1(c).  Implement this function
bool movePlayer(Tile **cav, int m, int n, int r, int c) {
    // Returns a boolean. True if player moved, false if not.

    // Check if (r,c) target is NOT within boundaries of cav map
    if ((r < 0 || r >= m || c < 0 || c >= n)) { // Unvalid boundaries for map
        return false;
    }
    // Check (r,c) is NOT empty or is player coords (valid places to move)
    if ((cav[r][c].content != nothing && cav[r][c].content != player)) {
        return false;
    }

    for (unsigned int row = 0; row < m; row++) {
        for (unsigned int col = 0; col < n; col++) {
            if (cav[row][col].content == player) {
                bool accepted_distance = EuclideanDistanceBelowThreshold(row, r, col, c, 5);

                // Check if Euclidean distance NOT less than 5 between (r,c) and player coordinates
                if ( !accepted_distance ) {
                    return false;
                }
                // Moving player, old tile is now empty (nothing)
                cav[row][col].content = nothing;
                // Move player to new position (r,c)
                cav[r][c].content = player;
                return true;
            }
        }
    }
    return false;
}

// Task 1(d).  Implement this function
void drawCavern(Tile **cav, unsigned int m, unsigned int n) {
    // Find player
    int r, c;
    for (unsigned int row = 0; row < m; row++) {
        for (unsigned int col = 0; col < n; col++) {
            if (cav[row][col].content == player) {
                r = row;
                c = col;
            }
        }
    }

    // Loop to draw the cavern
    for (unsigned int row = 0; row < m; row++) {
        for (unsigned int col = 0; col < n; col++) {
            // if player position is within 4 of given tileset
            //  it is visible, else it is not visible.
            if (EuclideanDistanceBelowThreshold(row, r, col, c, 4)) {
                // Has now been explored at least once
                cav[row][col].explored = true;
                
                // Input content of tile as description...
                if (cav[row][col].content == nothing) {
                    cout << " ";
                } else if (cav[row][col].content == player) {
                    cout << "X";
                } else if (cav[row][col].content == rock) {
                    cout << "#";
                } else if (cav[row][col].content == wumpus) {
                    cout << "W";
                }
            } else {
                if (cav[row][col].explored) { // if explored before
                    if (cav[row][col].content == rock) { // if rock, print #
                        cout << "#";
                    } else { // if not rock, print -
                        cout << "-";
                    }
                } else {
                // If never explored, print ?
                cout << "?";
                }
            }
        }
    cout << endl; // per row
    }
}





// Do not modify the following function.
// This code (that you don't need to read) places the player
// at location (0,0) and pseudo-randomly places some rocks
// and a Wumpus. The pseudo-random placement depends on the
// value of 'seed'.
void setupCavern(Tile **cav, unsigned int m, unsigned int n,
                 unsigned int seed) {
    mt19937 e; // Pseudo-random number generator
    e.seed(seed);

    // 1/3rd of the tiles are rocks
    unsigned int rocks = (m * n) / 3;
    for (unsigned int i = 0; i < rocks; i++) {
        cav[e()%m][e()%n].content = rock;
    }

    // We never place the Wumpus on row 0 or column 0
    unsigned int row = (e() % (m-1)) + 1;
    unsigned int col = (e() % (n-1)) + 1;
    cav[row][col].content = wumpus;

    cav[0][0].content = player;
}

// Do not modify the following function.
void deleteCavern(Tile **c, unsigned int m) {
    for (unsigned int i = 0; i < m; i++) {
        delete[] c[i];
    }
    delete[] c;
}
