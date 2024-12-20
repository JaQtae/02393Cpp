#include <iostream>
#include "ex01-library.h"

using namespace std;

// Task 1(a).  Implement this function
Square **createChessboard(unsigned int n) {
    // Replace the following with your code
    if (n < 2) {
        return nullptr;
    }
    Square **chessboard = new Square*[n]; // n
    // 
    for (unsigned int i = 0; i < n; i++) {
        chessboard[i] = new Square[n]; // times n
        for (unsigned int j=0; j < n; j++) {
            // Information of board:
            chessboard[i][j].piece = none;
            chessboard[i][j].team = nobody;
        }
    }
    return chessboard; // Return chess object.
}

// Task 1(b).  Implement this function
void displayChessboard(Square **c, unsigned int n) {
    for (unsigned int i = 0; i < n; i++) { // For each row
     // Adjacent squares on same ROW must be seperated by one space
     // Could do column values first, e.g. [j][i] -> all " " -> but cba...
        for (unsigned int j = 0; j < n; j++) { // For each column
        // I am super explicit. You can do else statement by inferring...
            if ((c[i][j].piece == none) || (c[i][j].team == nobody)) {
                cout << "_" << " ";
            }
            if ((c[i][j].team == white) && (c[i][j].piece == rook)) {
                    cout << "r" << " ";
                } else if ((c[i][j].team == white) && (c[i][j].piece == bishop)){
                    cout << "b" << " ";
                }
            if ((c[i][j].team == black) && (c[i][j].piece == rook)) {
                    cout << "R" << " ";
                } else if ((c[i][j].team == black) && (c[i][j].piece == bishop)){
                    cout << "B" << " ";
                }
        }
    cout << endl;        // New line for next row...
    }
}

bool validMove(Square **c, int r1, int c1, int r2, int c2){
    // Not valid if: 
    // Same start and end capture (self-capture)
    if ((r1 == r2) && (c1 == c2)) {
        return false;
    }
    // Capturing piece position isn't valid OR belongs to same team on both squares.
    if ((c[r1][c1].team == nobody) || (c[r1][c1].team == c[r2][c2].team) ) {
        return false;
    }
    // A rook CANNOT capture if target isn't on same row and column
    if ((c[r1][c1].piece == rook) && (r1 != r2) && (c1 != c2)) {
        return false;
    }
    // Bishop can only move diagonally. func returns true if they on same diagonal.
    if ( (c[r1][c1].piece == bishop) && (abs(r1 - r2) != abs(c1 - c2)) ){
        return false;
    }
    // Valid otherwise
    return true;
}


// Task 1(c).  Implement this function
bool move(Square **c, unsigned int n,
int r1, int c1, int r2, int c2) {
    // Replace the following with your code
    // WE GET COLUMN AND ROW NUMBERS. SO NOT COORDINATES!!!!
    if (validMove(c, r1, c1, r2, c2)){
        c[r2][c2] = c[r1][c1]; // Move to square (r1,c1) -> (r2,c2)
        c[r1][c1] = {none, nobody}; // Empty old square
        return true;
    }
    return false;
}

// Task 1(d).  Implement this function
bool threatened(Square **c, unsigned int n,
                int row, int col) {
    // Replace the following with your code
    if (c[row][col].piece == none){
        return false; // target contains nothing (no threats)
    }

    for (unsigned int i = 0; i < n; i++) {
        for (unsigned int j=0; j<n; j++) { // For every i,j
        // Check if (row,col) can be accessed by enemy teams
        // bishop/rook that can move from (i,j) onto (row,col)
            if (validMove(c, i, j, row, col)) {
                return true;
            }
        }
    }

    return false;
}

// Do not modify
void deleteChessboard(Square **c, unsigned int n) {
    for (unsigned int i = 0; i < n; i++) {
        delete[] c[i];
    }
    delete[] c;
}
