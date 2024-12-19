#include <iostream>
#include <random>
#include "ex01-library.h"

using namespace std;

// Task 1(a).  Implement this function
Tile **createSea(unsigned int m, unsigned int n) {
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
void displaySea(Tile **sea, unsigned int m, unsigned int n, bool reveal) {
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
bool placeShip(Tile **sea, unsigned int m, unsigned int n, unsigned int r, unsigned int c, unsigned int number, unsigned int size, bool vertical) {
    for (int row = 0; row < m; row++) {
        for (int col = 0; col < n; col++) {
            if (sea[row][col].ship == number) {
                return false; // another ship has the same number
            }
        }
    }
    
    if(size < 1 || size > 4) {
        return false; // size is not between 1 and 4
    }
    
    if ((r < 0) || (r >= m) || (c < 0) || (c >= n)) {
        return false; // The destination is outside the sea boundaries
    }

    if(vertical){
        if(r+size > m) {
            return false;
        }
        for (int i = 0; i < size; i++){
            if(sea[r+i][c].ship > 0) {
                return false;
            }
        }
        for (int i = 0; i < size; i++){
            sea[r+i][c].ship = number;
        }
    } else {
        if(c+size > n) {
            return false;
        }
        for (int i = 0; i < size; i++){
            if(sea[r][c+i].ship > 0) {
                return false;
            }
        }
        for (int i = 0; i < size; i++){
            sea[r][c+i].ship = number;
        }
    }

    return true; 
}

// Task 1(d).  Implement this function
bool launchMissile(Tile **sea, unsigned int m, unsigned int n, unsigned int r, unsigned int c)
{
    if ((r < 0) || (r >= m) || (c < 0) || (c >= n)) {
        return false; // The destination is outside the sea boundaries
    } else if(sea[r][c].hit == true) {
        return false;
    } else {
        sea[r][c].hit = true;
        return true;
    }
}

// Do not modify the following function.
void deleteSea(Tile **sea, unsigned int m) {
    for (unsigned int i = 0; i < m; i++) {
        delete[] sea[i];
    }
    delete[] sea;
}
