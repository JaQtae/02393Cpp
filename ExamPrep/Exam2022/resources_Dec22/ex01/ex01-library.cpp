#include <iostream>
#include <random>
#include "ex01-library.h"

using namespace std;

// Task 1(a).  Implement this function
Tile **createCavern(unsigned int m, unsigned int n) {
    // Allocate memory for the tile array
    Tile **cav = (Tile **)malloc(m * sizeof(Tile *));
    
    if (!cav) {
        // Handle memory allocation failure
        return nullptr;
    }
    
    // Initialize each tile in the cavern
    for (unsigned int i = 0; i < m; ++i) {
        cav[i] = (Tile *)malloc(n * sizeof(Tile));
        
        if (!cav[i]) {
            // If any allocation fails, free previously allocated memory and return NULL
            for (unsigned int j = 0; j < i; ++j) {
                free(cav[j]);
            }
            free(cav);
            return nullptr;
        }
        
        for (unsigned int j = 0; j < n; ++j) {
            cav[i][j].content = nothing;
            cav[i][j].explored = false;
        }
    }
    
    return cav;
}

// Task 1(b).  Implement this function
void revealCavern(Tile **cav, unsigned int m, unsigned int n) {
    // Write your code here
}

// Task 1(c).  Implement this function
bool movePlayer(Tile **cav, int m, int n, int r, int c) {
    // Replace the following with your code
    return false;
}

// Task 1(d).  Implement this function
void drawCavern(Tile **cav, unsigned int m, unsigned int n) {
    // Write your code here
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
