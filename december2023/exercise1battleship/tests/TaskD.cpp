#include <iostream>
#include <string>
#include "ex01-library.h"

using namespace std;

// %%%CJ_HIDE_START%%%
Tile** __02393_createSea(unsigned int m, unsigned int n) {
    Tile **c = new Tile*[m];
    for (unsigned int row = 0; row < m; row++) {
        c[row] = new Tile[n];
        for (unsigned int col = 0; col < n; col++) {
            c[row][col] = {0, false};
        }
    }
    return c;
}

void __02393_revealSea(Tile **sea, unsigned int m, unsigned int n, bool reveal) {
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

bool __02393_placeShip(Tile **sea, unsigned int m, unsigned int n, unsigned int r, unsigned int c, unsigned int number, unsigned int size, bool vertical) {
    for (unsigned int row = 0; row < m; row++) {
        for (unsigned int col = 0; col < n; col++) {
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
        for (unsigned int i = 0; i < size; i++){
            if(sea[r+i][c].ship > 0) {
                return false;
            }
        }
        for (unsigned int i = 0; i < size; i++){
            sea[r+i][c].ship = number;
        }
    } else {
        if(c+size > n) {
            return false;
        }
        for (unsigned int i = 0; i < size; i++){
            if(sea[r][c+i].ship > 0) {
                return false;
            }
        }
        for (unsigned int i = 0; i < size; i++){
            sea[r][c+i].ship = number;
        }
    }

    return false; 
}

// %%%CJ_HIDE_END%%%
int main() {
    unsigned int rows = 8, cols = 20;
    Tile **sea = nullptr;

    // Here there is some HIDDEN CODE that allocates the cavern 'cav'.
    // If you have completed task (a), you can run this code on your computer
    // by uncommenting the following line:
    // c = createCavern(rows, cols);
    // %%%CJ_HIDE_START%%%
    cout << endl << "Creating sea and placing ships" << endl;
    sea = __02393_createSea(rows, cols);
    // %%%CJ_HIDE_END%%%

    __02393_placeShip(sea, rows, cols, 0, 10, 1,1,false);
    __02393_placeShip(sea, rows, cols, 1, 8, 2,2,false);
    __02393_placeShip(sea, rows, cols, 2, 5, 3,3,true);
    __02393_placeShip(sea, rows, cols, 3, 7, 4,4,true);
    __02393_placeShip(sea, rows, cols, 7, 2, 8,2,false);

    // Here there is some HIDDEN CODE that reveals the cavern 'cav'.
    // If you have completed task (b), you can run this code on your computer
    // by uncommenting the following line:
    // revealCavern(cav, rows, cols);
    // %%%CJ_HIDE_START%%%
    cout << "What the opponent sees of the sea is now:" << endl;
    __02393_revealSea(sea, rows, cols, false);
    cout << "The position of the ships in the sea is now:" << endl;
    __02393_revealSea(sea, rows, cols, true);
    // %%%CJ_HIDE_END%%%
    
    cout << endl << "Launching a missile to row 0, column 8..." << endl;
    launchMissile(sea, rows, cols, 0, 8);
    cout << endl << "Launching a missile to row 0, column 9..." << endl;
    launchMissile(sea, rows, cols, 0, 9);
    
    cout << endl << "Launching a missile to row 1, column 8..." << endl;
    launchMissile(sea, rows, cols, 1, 8);
    cout << endl << "Launching a missile to row 2, column 8..." << endl;
    launchMissile(sea, rows, cols, 2, 8);
    
    cout << endl << "Launching a missile to row 2, column 7..." << endl;
    launchMissile(sea, rows, cols, 2, 7);
    cout << endl << "Launching a missile to row 2, column 6..." << endl;
    launchMissile(sea, rows, cols, 2, 6);
    cout << endl << "Launching a missile to row 3, column 6..." << endl;
    launchMissile(sea, rows, cols, 3, 6);
    
    cout << endl << "Launching a missile to row 4, column 2..." << endl;
    launchMissile(sea, rows, cols, 4, 2);
    cout << endl << "Launching a missile to row 4, column 3..." << endl;
    launchMissile(sea, rows, cols, 4, 3);
    cout << endl << "Launching a missile to row 4, column 4..." << endl;
    launchMissile(sea, rows, cols, 4, 4);
    cout << endl << "Launching a missile to row 5, column 2..." << endl;
    launchMissile(sea, rows, cols, 5, 2);
    cout << endl << "Launching a missile to row 5, column 3..." << endl;
    launchMissile(sea, rows, cols, 5, 3);
    cout << endl << "Launching a missile to row 5, column 4..." << endl;
    launchMissile(sea, rows, cols, 5, 4);
    
    cout << endl << "Launching a missile to row 5, column 12..." << endl;
    launchMissile(sea, rows, cols, 5, 12);
    cout << endl << "Launching a missile to row 5, column 11..." << endl;
    launchMissile(sea, rows, cols, 5, 11);
    cout << endl << "Launching a missile to row 5, column 10..." << endl;
    launchMissile(sea, rows, cols, 5, 10);
    
    // Here there is some HIDDEN CODE that reveals the cavern 'cav'.
    // If you have completed task (b), you can run this code on your computer
    // by uncommenting the following line:
    // revealCavern(cav, rows, cols);
    // %%%CJ_HIDE_START%%%
    cout << "What the opponent sees of the sea is now:" << endl;
    __02393_revealSea(sea, rows, cols, false);
    cout << "The position of the ships in the sea is now:" << endl;
    __02393_revealSea(sea, rows, cols, true);
    // %%%CJ_HIDE_END%%%


    deleteSea(sea, rows);

    return 0;
}
