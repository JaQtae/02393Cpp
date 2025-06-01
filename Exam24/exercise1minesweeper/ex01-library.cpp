#include <iostream>
#include <random>
#include "ex01-library.h"

using namespace std;

// --------------- Helper functions ---------------- // 
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
static unsigned int countAllMines(Tile **field, unsigned int m, unsigned int n) {
    unsigned int total = 0;
    for (unsigned i = 0; i < m; ++i) {
        for (unsigned j = 0; j < n; ++j) {
            if (field[i][j].mine) {
                ++total;
            }
        }
    }
    return total;
}

static unsigned int countHitMines(Tile **field, unsigned int m, unsigned int n) {
    unsigned int cnt = 0;
    for (unsigned i = 0; i < m; ++i) {
        for (unsigned j = 0; j < n; ++j) {
            if (field[i][j].mine && field[i][j].hit) {
                ++cnt;
            }
        }
    }
    return cnt;
}

static unsigned int countHitSafe(Tile **field, unsigned int m, unsigned int n) {
    unsigned int cnt = 0;
    for (unsigned i = 0; i < m; ++i) {
        for (unsigned j = 0; j < n; ++j) {
            if (!field[i][j].mine && field[i][j].hit) {
                ++cnt;
            }
        }
    }
    return cnt;
}

static char displayTile(Tile &t, unsigned int adjMines, bool revealMode) {
    // If revealMode == true, show everything: mines as 'M' or 'X', safe as digit
    if (revealMode) {
        if (t.mine) {
            return t.hit ? 'X' : 'M';
        } else {
            return char('0' + adjMines);
        }
    }
    // If revealMode == false, hide:
    if (!t.hit) {
        return '?';
    }
    // Touched tile that’s not a mine → show adjacent count 0–8:
    if (t.mine) {
        return 'X';
    }
    return char('0' + adjMines);
}



// Task 1(a).  Implement this function
Tile **createMinefield(unsigned int m, unsigned int n) {

    Tile** minefield = new Tile*[m];
    for (unsigned int i = 0; i < m; i++) {
        minefield[i] = new Tile[n];
        for (unsigned int j = 0; j < n; j++) {
            minefield[i][j] = {0, false};
        }
    }
    return minefield;
}

// Task 1(b).  Implement this function
bool placeMine(Tile **field, unsigned int m, unsigned int n, unsigned int r, unsigned int c) {
    unsigned int total_tiles = m * n;
    unsigned int max_allowed_mines = total_tiles / 4; // Truncates by itself
    unsigned int mine_count = countAllMines(field, m, n);

    if (mine_count >= max_allowed_mines){
        return false; // We've exceeded pre-calculated integer cutoff for mines
    }
    if ((r < 0) || (r >= m) || (c < 0) || (c >= n)) {
        return false; // Just one has to be false for it to fail
    }
    if (field[r][c].mine) { // Text basically says NOT NOT occupied (false that it is not occupied)
        return false; // meaning we're checking if it IS occupied...
    }
    // Update
    field[r][c].mine = true;
    
    return true; //
}


// Task 1(c).  Implement this function
void displayMinefield(Tile **field, unsigned int m, unsigned int n) {
    // unsigned int count = 0;
    // for (unsigned int row = 0; row < m; row++) {
    //     for (unsigned int col = 0; col < n; col++) {
    //         if (!field[row][col].hit) {
    //             cout << "?"; // Untouched tiles
    //         } else if (field[row][col].mine){
    //                 cout << "X"; // Touched mines
    //         } else {
    //             unsigned int adj_mines = countAdjacentMines(field, m, n, row, col);
    //             cout << adj_mines;
    //         }
    //     }
    // cout << endl;
    // }
    bool revealMode = false;
    for (unsigned i = 0; i < m; ++i) {
        for (unsigned j = 0; j < n; ++j) {
            unsigned adj = countAdjacentMines(field, m, n, i, j);
            cout << displayTile(field[i][j], adj, revealMode);
        }
    cout << endl;
    }

}

// Task 1(d).  Implement this function
bool isGameOver(Tile **field, unsigned int m, unsigned int n){
    bool cleared_all_tiles_with_no_mine = true; // assume they're cleared
    for (unsigned int row = 0; row < m; row++) {
        for (unsigned int col = 0; col < n; col++) {
            if (field[row][col].mine && field[row][col].hit){
                return true; // hit a mine
            } else if (!field[row][col].mine && !field[row][col].hit) {
                cleared_all_tiles_with_no_mine = false; // untouched tile with no mine
            }
        }
    }
    if (cleared_all_tiles_with_no_mine) {
        return true; // If we made it through the for-loop, then we're clear
    }
    // Otherwise, we're not clear.
    return false;
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

