#include <iostream>
#include <random>
#include "ex01-library.h"

using namespace std;

// Task 1(a).  Implement this function
Tile **createCavern(unsigned int m, unsigned int n) {
    Tile **c = new Tile*[m];
    for (unsigned int row = 0; row < m; row++) {
        c[row] = new Tile[n];
        for (unsigned int col = 0; col < n; col++) {
            c[row][col] = {nothing, false};
        }
    }
    return c;
}

// Auxiliary function to print the content of a tile
void printTile(Content c) {
    switch (c) {
        case nothing:
            cout << " "; break;
        case player:
            cout << "X"; break;
        case rock:
            cout << "#"; break;
        case wumpus:
            cout << "W"; break;
        default:
            cout << "?"; // This case should never occur
    }
}

// Auxiliary function to check whether the distance between a tile at coordinate
// (r1,c1) and another at (r2,c2) is less than d.
bool isDistanceBelow(int r1, int c1, int r2, int c2, int d) {
    return (((r1-r2) * (r1-r2)) + ((c1-c2) * (c1-c2))) < (d*d);
}

// Task 1(b).  Implement this function
void revealCavern(Tile **cav, unsigned int m, unsigned int n) {
    for (unsigned int row = 0; row < m; row++) {
        for (unsigned int col = 0; col < n; col++) {
            printTile(cav[row][col].content);
        }
        cout << endl;
    }
}

// Task 1(c).  Implement this function
bool movePlayer(Tile **cav, int m, int n, int r, int c) {
    if ((r < 0) || (r >= m) || (c < 0) || (c >= n)) {
        return false; // The destination is outside the cavern boundaries
    }
    if ((cav[r][c].content != nothing) && (cav[r][c].content != player)) {
        return false; // We cannot move to the requested tile
    }

    // Loop to find the player and move it
    for (int row = 0; row < m; row++) {
        for (int col = 0; col < n; col++) {
            if (cav[row][col].content == player) {
                if (!isDistanceBelow(row, col, r, c, 5)) {
                    return false; // The destination is too far
                }
                cav[row][col].content = nothing;
                cav[r][c].content = player;
                return true;
            }
        }
    }

    return false; // Only executed if there is no player in the cavern
}

// Task 1(d).  Implement this function
void drawCavern(Tile **cav, unsigned int m, unsigned int n) {
    int r, c;
    // Loop to find the player
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
            if (isDistanceBelow(row, col, r, c, 4)) {
                printTile(cav[row][col].content);
                cav[row][col].explored = true;
            } else {
                if (cav[row][col].explored) {
                    if (cav[row][col].content == rock) {
                        printTile(cav[row][col].content);
                    } else {
                        cout << "-";
                    }
                } else {
                    cout << "?";
                }
            }
        }
        cout << endl;
    }
}

// Do not modify the following function.
// This code (that you don't need to read) places the player at location (0,0)
// and pseudo-randomly places some rocks and a Wumpus. The pseudo-random
// placement depends on the value of 'seed'.
void setupCavern(Tile **cav, unsigned int m, unsigned int n,
                 unsigned int seed) {
    mt19937 e; // Pseudo-random number generator (Mersenne Twister)
    e.seed(seed);
    
    unsigned int rocks = (m * n) / 3; // 1/3rd of the tiles are rocks
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
