#include <iostream>
#include <random>
#include "ex01-library.h"

using namespace std;

// Task 1(a).  Implement this function
Tile **createMinefield(unsigned int m, unsigned int n) {

    Tile** map = new Tile*[m]; // Allocate memory
    for (unsigned int row = 0; row < m; row++) {
        map[row] = new Tile[n];
        for (unsigned int col = 0; col < n; col++) {
            map[row][col] = {0, false};
        }
    }
    return map;

}

// Task 1(b).  Implement this function
bool placeMine(Tile **field, unsigned int m, unsigned int n, unsigned int r, unsigned int c) {
    // cout << "Placing mine at (r,c): (" << r << "," << c <<")"<< endl;
    // cout << "Size of field: " << m << "x" << n << endl;


    unsigned int total_tiles = m * n;
    unsigned int maxMines = total_tiles / 4; // Truncate
    unsigned int num_mines = 0;

    if ((r < 0) || (r >= m) || (c < 0) || (c >= n)) {
        // cout << "Out of bounds" << endl;
        return false; // (r,c) is outside the boundaries of map
    }

    // Contains mine already?
    if (field[r][c].mine) {
        return false;
    }
    
    // Calculate the number of mines already present
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            if (field[i][j].mine) {
                ++num_mines;
            }
        }
    }
    if (num_mines >= maxMines) {
        // cout << "Max mines reached" << endl;
        return false; // Can't place mine if max mines reached
    }
    
    // Place mine
    field[r][c].mine = true;
    return true;

}

static unsigned int countAdjacentMines(Tile **field, unsigned int m, unsigned int n, unsigned int r, unsigned int c) {
    // Helper function to count mines around (r,c)
    unsigned int count = 0;
    // (r,c) is the center of a 3x3 grid
    // Loop through the 3x3 grid around (r,c)
    for (int i = -1; i <= 1; ++i) { // row
        for (int j = -1; j <= 1; ++j) { // Column
            if (i == 0 && j == 0) continue; // Skip the current tile
            int newRow = r + i; // Go down
            int newCol = c + j; //Go right
            // Check if the new row and column are within bounds of field
            if (newRow >= 0 && newRow < m && newCol >= 0 && newCol < n) {
                if (field[newRow][newCol].mine) {
                    count++;
                }
            }
        }
    }
    return count;
}


// Task 1(c).  Implement this function
void displayMinefield(Tile **field, unsigned int m, unsigned int n) {
    for (unsigned int r = 0; r < m; ++r) {
        for (unsigned int c = 0; c < n; ++c) {
            const Tile &t = field[r][c]; // Get the tile at (r,c)
            if (!t.hit) { // If it's NOT hit, display ?
                cout << '?';
            } else if (t.mine) { // If it's a mine, display X
                cout << 'X';
            } else { // Not a mine, and not hit
                // Count adjacent mines and colour the tile with that number
                unsigned int adj = countAdjacentMines(field, m, n, r, c);
                // Has to be between 0 and 8
                cout << adj;
            }
        }
        cout << endl; // Change line after each row
    }
}

// Task 1(d).  Implement this function
bool isGameOver(Tile **field, unsigned int m, unsigned int n)
{
    unsigned int total_tiles = m * n;
    unsigned int mineCounter = 0;
    unsigned int safelyTouched = 0;
    // Check if all tiles are hit or if there is a mine that is hit
    for (unsigned int row = 0; row < m; ++row) {
        for (unsigned int col = 0; col < n; ++col) {
            if (field[row][col].mine) {
                ++mineCounter; // Count mines
                if (field[row][col].hit) {
                return true; // We hit a mine, game over
                }
            } else {
                if (field[row][col].hit) {
                    ++safelyTouched; // Count non-mines
                }
            }
        }

    }
    // If we made it to here we've not hit a mine
    if (safelyTouched + mineCounter == total_tiles) {
        return true; // All NON-MINE tiles are hit, game over
    } else {
        return false; // Game is still on
    }
}

// Do not modify the following function.
void deleteMinefield(Tile **field, unsigned int m) {
    for (unsigned int i = 0; i < m; i++) {
        delete[] field[i];
    }
    delete[] field;
}

// Do not modify the following function.
void revealMinefield(Tile **field, unsigned int m, unsigned int n) {
    for (unsigned int row = 0; row < m; row++) {
        for (unsigned int col = 0; col < n; col++) {
            if(field[row][col].mine){
                if(field[row][col].hit){
                    cout << "X";
                } else {
                    cout << "M";
                }
            } else {
                if(field[row][col].hit){
                    cout << "E";
                } else {
                    cout << " ";
                }
            }
        }
        cout << endl;
    }
}