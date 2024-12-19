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
// %%%CJ_HIDE_END%%%
int main() {
    unsigned int rows = 10, cols = 20;
    Tile **cav = nullptr;

    // Here there is some HIDDEN CODE that allocates the cavern 'cav'.
    // If you have completed task (a), you can run this code on your computer
    // by uncommenting the following line:
    // c = createCavern(rows, cols);
    // %%%CJ_HIDE_START%%%
    cav = __02393_createSea(rows, cols);
    // %%%CJ_HIDE_END%%%

    // Here there is some HIDDEN CODE that reveals the cavern 'cav'.
    // If you have completed task (b), you can run this code on your computer
    // by uncommenting the following line:
    // revealCavern(cav, rows, cols);
    // %%%CJ_HIDE_START%%%
    cout << "What the opponent sees of the sea is:" << endl;
    __02393_revealSea(cav, rows, cols, false);
    cout << "The position of the ships in the sea is:" << endl;
    __02393_revealSea(cav, rows, cols, true);
    // %%%CJ_HIDE_END%%%
    
    cout << endl << "Placing ships" << endl;
    placeShip(cav, rows, cols, 0, 0, 1,1,false);
    placeShip(cav, rows, cols, 0, 8, 2,2,false);
    placeShip(cav, rows, cols, 1, 4, 3,3,true);
    placeShip(cav, rows, cols, 1, 10, 4,4,true);
    placeShip(cav, rows, cols, 9, 0, 8,2,false);

    // Here there is some HIDDEN CODE that reveals the cavern 'cav'.
    // If you have completed task (b), you can run this code on your computer
    // by uncommenting the following line:
    // revealCavern(cav, rows, cols);
    // %%%CJ_HIDE_START%%%
    cout << "What the opponent sees of the sea is now:" << endl;
    __02393_revealSea(cav, rows, cols, false);
    cout << "The position of the ships in the sea is now:" << endl;
    __02393_revealSea(cav, rows, cols, true);
    // %%%CJ_HIDE_END%%%
   
    cout << endl << "Attempting to place ships in the wrong position" << endl;
    bool result = false;
    // existing ship number
    result |= placeShip(cav, rows, cols, 1, 1, 1,1,false);
    // wrong size
    result |= placeShip(cav, rows, cols, 2, 8, 5,5,false);
    // position out of bounds
    result |= placeShip(cav, rows, cols, 3, 20, 6,3,false);
    result |= placeShip(cav, rows, cols, 10, 2, 6,3,true);
    
    result |= placeShip(cav, rows, cols, 9, 18, 7,4,false);
    result |= placeShip(cav, rows, cols, 8, 19, 7,4,true);

    //overlapping ship
    result |= placeShip(cav, rows, cols, 2, 3, 9,3,false);
    result |= placeShip(cav, rows, cols, 8, 1, 9,2,true);

    if(result) {
        cout << "wrong return value when invoking placeShip" << endl;
    }

    // Here there is some HIDDEN CODE that reveals the cavern 'cav'.
    // If you have completed task (b), you can run this code on your computer
    // by uncommenting the following line:
    // revealCavern(cav, rows, cols);
    // %%%CJ_HIDE_START%%%
    cout << "What the opponent sees of the sea is now:" << endl;
    __02393_revealSea(cav, rows, cols, false);
    cout << "The position of the ships in the sea is now:" << endl;
    __02393_revealSea(cav, rows, cols, true);
    // %%%CJ_HIDE_END%%%

    deleteSea(cav, rows);

    return 0;
}
