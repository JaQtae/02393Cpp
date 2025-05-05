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



    if ((r < 0) || (r >= m) || (c < 0) || (c >= n)) {
        // cout << "Out of bounds" << endl;
        return false; // (r,c) is outside the boundaries of map
    }
    // Contains mine already?
    if (field[r][c].mine) {
        return false;
    }
    
    // Calculate the number of mines already present
    int num_mines = 0;
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            if (field[i][j].mine) {
                ++num_mines;
            }
        }
    }
    // cout << "found " << num_mines << " mines" << endl;
    cout << "fraction: " << endl;
    // Check if less than one fourth of total tiles have a mine
    if (static_cast<double>(num_mines) / (m * n) >= 1.0 / 4.0) {
        // cout << "fraction if" << endl;
        return false;
    }

    bool game_started = false;
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            if (field[i][j].hit) {
                game_started = true;
            }
        }
    }
    if (game_started){
        return false; // Can't place mine if game has started
    }

    
    // Place mine
    field[r][c].mine = true;
    return true;

}

// int numberOfMinesAround(Tile **field, unsigned int m, unsigned int n){
//     // Check if up, down, left, right has a 
    
// }

// Task 1(c).  Implement this function
void displayMinefield(Tile **field, unsigned int m, unsigned int n) {
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
                    cout << "?";
                }
            }
        }
        cout << endl;
    }
}

// Task 1(d).  Implement this function
bool isGameOver(Tile **field, unsigned int m, unsigned int n)
{

    return true; 
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