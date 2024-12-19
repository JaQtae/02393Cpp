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
// %%%CJ_HIDE_END%%%

int main() {
    unsigned int rows = 7, cols = 5;
    Tile **cav = nullptr;

    // Here there is some HIDDEN CODE that allocates the cavern 'cav'.
    // If you have completed task (a), you can run this code on your computer
    // by uncommenting the following line:
    // c = createCavern(rows, cols);
    // %%%CJ_HIDE_START%%%
    cav = __02393_createSea(rows, cols);
    // %%%CJ_HIDE_END%%%

    cout << "What the opponent sees of the sea is:" << endl;
    displaySea(cav, rows, cols, false);

    cout << "The position of the ships in the sea is:" << endl;
    displaySea(cav, rows, cols, true);

    cout << endl << "Manipulating the sea" << endl << endl;

    cav[0][0].ship = 0; cav[0][0].hit = true;
    cav[0][1].ship = 0; cav[0][1].hit = true;
    cav[0][2].ship = 1; cav[0][2].hit = true;
    cav[6][3].ship = 2; cav[6][3].hit = false;
    cav[6][4].ship = 2; cav[6][4].hit = true;
    cav[6][0].ship = 3; cav[6][0].hit = false;

    cout << "What the opponent sees of the sea is now:" << endl;
    displaySea(cav, rows, cols, false);

    cout << "The position of the ships in the sea is now:" << endl;
    displaySea(cav, rows, cols, true);


    deleteSea(cav, rows);

    cout << endl << "Creating a new sea" << endl << endl;

    rows = 16;
    cols = 20;
    // Here there is some HIDDEN CODE that re-allocates the cavern 'cav'.
    // If you have completed task (a), you can run this code on your computer
    // by uncommenting the following line:
    // d = createCavern(rows, cols);
    // %%%CJ_HIDE_START%%%
    cav = __02393_createSea(rows, cols);
    // %%%CJ_HIDE_END%%%

    cout << "What the opponent sees of the new sea is:" << endl;
    displaySea(cav, rows, cols, false);

    cout << "The position of the ships in the new sea is:" << endl;
    displaySea(cav, rows, cols, true);

    cout << endl << "Manipulating the new sea" << endl << endl;

    cav[4][0].ship = 0; cav[4][0].hit = true;
    cav[4][1].ship = 1; cav[4][1].hit = true;
    cav[4][2].ship = 0; cav[4][2].hit = true;
    cav[14][3].ship = 2; cav[14][3].hit = true;
    cav[15][3].ship = 2; cav[15][3].hit = false;
    cav[14][4].ship = 0; cav[14][4].hit = true;
    cav[15][4].ship = 0; cav[15][4].hit = false;
    cav[15][19].ship = 3; cav[15][19].hit = false;

    cout << "What the opponent sees of the new sea is now:" << endl;
    displaySea(cav, rows, cols, false);

    cout << "The position of the ships in the new sea is now:" << endl;
    displaySea(cav, rows, cols, true);

    deleteSea(cav, rows);

    return 0;
}
