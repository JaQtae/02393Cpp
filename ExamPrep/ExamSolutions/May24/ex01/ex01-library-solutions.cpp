#include <iostream>
#include <random>
#include "ex01-library.h"

using namespace std;

// Task 1(a).  Implement this function
Tile **createSea(unsigned int m) {
    unsigned int n = m * 2;
    Tile **sea = new Tile*[m];
    for (unsigned int row = 0; row < m; row++) {
        sea[row] = new Tile[n];
        for (unsigned int col = 0; col < n; col++) {
            sea[row][col] = {0, false};
        }
    }
    return sea;
}


// Task 1(b).  Implement this function
void displaySea(Tile **sea, unsigned int m, bool reveal) {
    unsigned int n=m*2;
    for (unsigned int row = 0; row < m; row++) {
        for (unsigned int col = 0; col < n; col++) {
            if(sea[row][col].ship>0){
                if(sea[row][col].hit){
                    cout << "X";
                } else {
                    if(reveal) {
                        cout << sea[row][col].ship;
                    } else {
                        cout << "?";
                    }
                }
            } else {
                if(reveal){
                    cout << " ";
                } else {
                    if(sea[row][col].hit){
                        cout << " ";
                    } else {
                        cout << "?";
                    }
                }
            }
        }
        cout << endl;
    }
}

// Task 1(c).  Implement this function
bool launchBigMissile(Tile **sea, unsigned int m, unsigned int r, unsigned int c)
{
    unsigned int n = m*2;
    if ((r < 0) || (r >= m) || (c < 0) || (c >= n)) {
        return false; // The destination is outside the sea boundaries
    } else if(sea[r][c].hit == true) {
        return false;
    } else {
        sea[r][c].hit = true;
        if(r>0){
            sea[r-1][c].hit = true;
        }
        if(c>0){
            sea[r][c-1].hit = true;
        }
        if(r+1<m){
            sea[r+1][c].hit = true;
        }
        if(c+1<n){
            sea[r][c+1].hit = true;
        }
        return true;
    }
}

// Task 1(d).  Implement this function
bool isGameOver(Tile **sea, unsigned int m){
    unsigned int n=m*2;
    for (unsigned int row = 0; row < m; row++) {
        for (unsigned int col = 0; col < n; col++) {
            if (sea[row][col].ship>0 && sea[row][col].hit == false){
                return false;
            }
        }
    }
    return true;
}

// Do not modify the following function.
void deleteSea(Tile **sea, unsigned int m) {
    for (unsigned int i = 0; i < m; i++) {
        delete[] sea[i];
    }
    delete[] sea;
}
