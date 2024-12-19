#include <iostream>
#include "ex01-library.h"
#include <cmath> // For abs() below

using namespace std;

// Task 1(a).  Implement this function
Square **createChessboard(unsigned int n) {
    Square **c = new Square*[n];
    for (unsigned int row = 0; row < n; row++) {
        c[row] = new Square[n];
        for (unsigned int col = 0; col < n; col++) {
            c[row][col] = {none, nobody};
        }
    }
    return c;
}

// Task 1(b).  Implement this function
void displayChessboard(Square **c, unsigned int n) {
    for (unsigned int row = 0; row < n; row++) {
        for (unsigned int col = 0; col < n; col++) {
            switch (c[row][col].team) {
            case black:
                switch (c[row][col].piece) {
                case bishop:
                    cout << "B"; break;
                case rook:
                    cout << "R"; break;
                default:
                    cout << "X"; // This should not happen!
                }
                break;
            case white:
                switch (c[row][col].piece) {
                case bishop:
                    cout << "b"; break;
                case rook:
                    cout << "r"; break;
                default:
                    cout << "x"; // This should not happen!
                }
                break;
            case nobody:
                cout << "_";
            }
            cout << " ";
        }
        cout << endl;
    }
}

// Axiliary function used in move() and threatened() below.
// Returns true if a move is valid, and false otherwise
bool checkMove(Square **c, int r1, int c1, int r2, int c2) {
    if ((r1 == r2) && (c1 == c2)) {
        return false;
    }
    if ((c[r1][c1].team == nobody) || (c[r1][c1].team == c[r2][c2].team)) {
        return false;
    }
    if ((c[r1][c1].piece == rook) && (r1 != r2) && (c1 != c2)) {
        return false;
    }
    if ((c[r1][c1].piece == bishop) && (abs(r1 - r2) != abs(c1 - c2))) {
        return false;
    }

    return true;
}

// Task 1(c).  Implement this function
bool move(Square **c, unsigned int n, int r1, int c1, int r2, int c2) {
    if (checkMove(c, r1, c1, r2, c2)) {
        c[r2][c2] = c[r1][c1];
        c[r1][c1] = {none, nobody};
        return true;
    }
    return false;
}

// Task 1(d).  Implement this function
bool threatened(Square **c, unsigned int n, int row, int col) {
    if (c[row][col].piece == none) {
        return false;
    }

    // Check all squares, see if any can capture at position (row, col)
    for (unsigned int i = 0; i < n; i++) {
        for (unsigned int j = 0; j < n; j++) {
            if (checkMove(c, i, j, row, col)) {
                return true;
            }
        }
    }

    // No piece on the chessboard can capture the piece at position (row, col)
    return false;
}

// Do not modify
void deleteChessboard(Square **c, unsigned int n) {
    for (unsigned int i = 0; i < n; i++) {
        delete[] c[i];
    }
    delete[] c;
}
