#include <iostream>
#include <string>
#include "ex01-library.h"

using namespace std;

string toString(bool result){
    if(result)
        return "yes!";
    return "no!";
}

// %%%CJ_HIDE_START%%%
Tile** __02393_createSea(unsigned int m) {
    unsigned int n = m*2;
    Tile **c = new Tile*[m];
    for (unsigned int row = 0; row < m; row++) {
        c[row] = new Tile[n];
        for (unsigned int col = 0; col < n; col++) {
            c[row][col] = {0, false};
        }
    }
    return c;
}

void __02393_revealSea(Tile **sea, unsigned int m, bool reveal) {
    unsigned int n = m*2;
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

bool __02393_placeShip(Tile **sea, unsigned int m, unsigned int r, unsigned int c, unsigned int number, unsigned int size, bool vertical) {
    unsigned int n = m*2;
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
    unsigned int rows = 8;
    Tile **sea = nullptr;

    // Here there is some HIDDEN CODE that allocates the cavern 'cav'.
    // If you have completed task (a), you can run this code on your computer
    // by uncommenting the following line:
    // c = createCavern(rows, cols);
    // %%%CJ_HIDE_START%%%
    cout << endl << "Creating sea and placing ships" << endl;
    sea = __02393_createSea(rows);
    // %%%CJ_HIDE_END%%%

    __02393_placeShip(sea, rows, 0, 10, 1,1,false);
    __02393_placeShip(sea, rows, 2, 5, 3,3,true);
    __02393_placeShip(sea, rows, 7, 2, 8,2,false);

    // Here there is some HIDDEN CODE that reveals the cavern 'cav'.
    // If you have completed task (b), you can run this code on your computer
    // by uncommenting the following line:
    // revealCavern(cav, rows, cols);
    // %%%CJ_HIDE_START%%%
    cout << "What the opponent sees of the sea is now:" << endl;
    __02393_revealSea(sea, rows, false);
    cout << "The position of the ships in the sea is now:" << endl;
    __02393_revealSea(sea, rows, true);
    // %%%CJ_HIDE_END%%%
    
    cout << "Is the game over? " << toString(isGameOver(sea,rows)) << endl;

    cout << endl << "Manipulating the new sea" << endl << endl;

    sea[2][5].hit = true;
    sea[3][5].hit = true;
    sea[4][5].hit = true;
    
    sea[7][2].hit = true;
    
    cout << "What the opponent sees of the sea is now:" << endl;
    __02393_revealSea(sea, rows, false);
    cout << "The position of the ships in the sea is now:" << endl;
    __02393_revealSea(sea, rows, true);
    // %%%CJ_HIDE_END%%%
    
    cout << "Is the game over? " << toString(isGameOver(sea,rows)) << endl;

    cout << endl << "Manipulating the new sea" << endl << endl;

    sea[7][3].hit = true;

    sea[0][10].hit = true;

    // Here there is some HIDDEN CODE that reveals the cavern 'cav'.
    // If you have completed task (b), you can run this code on your computer
    // by uncommenting the following line:
    // revealCavern(cav, rows, cols);
    // %%%CJ_HIDE_START%%%
    cout << "What the opponent sees of the sea is now:" << endl;
    __02393_revealSea(sea, rows, false);
    cout << "The position of the ships in the sea is now:" << endl;
    __02393_revealSea(sea, rows, true);
    // %%%CJ_HIDE_END%%%

    cout << "Is the game over? " << toString(isGameOver(sea,rows)) << endl;

    deleteSea(sea, rows);

    rows = 5;

    cout << endl << "Creating a new sea" << endl << endl;

    sea = __02393_createSea(rows);
    // %%%CJ_HIDE_END%%%

    __02393_placeShip(sea, rows, 0, 5, 1,1,false);
    __02393_placeShip(sea, rows, 2, 6, 8,2,false);
    __02393_placeShip(sea, rows, 2, 9, 3,3,true);
    
    // Here there is some HIDDEN CODE that reveals the cavern 'cav'.
    // If you have completed task (b), you can run this code on your computer
    // by uncommenting the following line:
    // revealCavern(cav, rows, cols);
    // %%%CJ_HIDE_START%%%
    cout << "What the opponent sees of the sea is now:" << endl;
    __02393_revealSea(sea, rows, false);
    cout << "The position of the ships in the sea is now:" << endl;
    __02393_revealSea(sea, rows, true);
    // %%%CJ_HIDE_END%%%
    
    cout << "Is the game over? " << toString(isGameOver(sea,rows)) << endl;

    cout << endl << "Manipulating the new sea" << endl << endl;

    sea[0][0].hit = true;
    sea[0][1].hit = true;
    sea[1][0].hit = true;
    
    cout << "What the opponent sees of the sea is now:" << endl;
    __02393_revealSea(sea, rows, false);
    cout << "The position of the ships in the sea is now:" << endl;
    __02393_revealSea(sea, rows, true);
    // %%%CJ_HIDE_END%%%
    
    cout << "Is the game over? " << toString(isGameOver(sea,rows)) << endl;

    cout << endl << "Manipulating the new sea" << endl << endl;

    sea[0][5].hit = true;

    sea[2][5].hit = true;
    sea[2][6].hit = true;
    sea[2][7].hit = true;
    
    cout << "What the opponent sees of the sea is now:" << endl;
    __02393_revealSea(sea, rows, false);
    cout << "The position of the ships in the sea is now:" << endl;
    __02393_revealSea(sea, rows, true);
    // %%%CJ_HIDE_END%%%
    
    cout << "Is the game over? " << toString(isGameOver(sea,rows)) << endl;

    cout << endl << "Manipulating the new sea" << endl << endl;

    sea[2][8].hit = true;
    sea[2][9].hit = true;
    sea[3][9].hit = true;
    sea[4][9].hit = true;
    sea[4][8].hit = true;

    // Here there is some HIDDEN CODE that reveals the cavern 'cav'.
    // If you have completed task (b), you can run this code on your computer
    // by uncommenting the following line:
    // revealCavern(cav, rows, cols);
    // %%%CJ_HIDE_START%%%
    cout << "What the opponent sees of the sea is now:" << endl;
    __02393_revealSea(sea, rows, false);
    cout << "The position of the ships in the sea is now:" << endl;
    __02393_revealSea(sea, rows, true);
    // %%%CJ_HIDE_END%%%

    cout << "Is the game over? " << toString(isGameOver(sea,rows)) << endl;

    return 0;
}
