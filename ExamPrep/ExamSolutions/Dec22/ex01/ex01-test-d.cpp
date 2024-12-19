#include <iostream>
#include <string>
#include "ex01-library.h"

using namespace std;

// %%%CJ_HIDE_START%%%
Tile** __02393_createCavern(unsigned int m, unsigned int n) {
    Tile **c = new Tile*[m];
    for (unsigned int row = 0; row < m; row++) {
        c[row] = new Tile[n];
        for (unsigned int col = 0; col < n; col++) {
            c[row][col] = {nothing, false};
        }
    }
    return c;
}

void __02393_revealCavern(Tile **cav, unsigned int m, unsigned int n) {
    for (unsigned int row = 0; row < m; row++) {
        for (unsigned int col = 0; col < n; col++) {
            switch (cav[row][col].content) {
            case nothing:
                cout << " "; break;
            case player:
                cout << "X"; break;
            case rock:
                cout << "#"; break;
            case wumpus:
                cout << "W"; break;
            default:
                cout << "?"; // This case should never occur
            }
        }
        cout << endl;
    }
}
// %%%CJ_HIDE_END%%%
int main() {
    unsigned int rows = 8, cols = 20;
    Tile **cav = nullptr;

    // Here there is some HIDDEN CODE that allocates the cavern 'cav'.
    // If you have completed task (a), you can run this code on your computer
    // by uncommenting the following line:
    // c = createCavern(rows, cols);
    // %%%CJ_HIDE_START%%%
    cav = __02393_createCavern(rows, cols);
    // %%%CJ_HIDE_END%%%

    setupCavern(cav, rows, cols, 9);

    cout << "Revealed cavern:" << endl;    
    // Here there is some HIDDEN CODE that reveals the cavern 'cav'.
    // If you have completed task (b), you can run this code on your computer
    // by uncommenting the following line:
    // revealCavern(cav, rows, cols);
    // %%%CJ_HIDE_START%%%
    __02393_revealCavern(cav, rows, cols);
    // %%%CJ_HIDE_END%%%

    cout << endl << "Cavern with player at row 0, column 0:" << endl;
    drawCavern(cav, rows, cols);

    cav[0][0].content = nothing; cav[3][3].content = player; // Move player

    cout << endl << "Cavern with player at row 3, column 3:" << endl;
    drawCavern(cav, rows, cols);

    cav[3][3].content = nothing; cav[4][16].content = player; // Move player

    cout << endl << "Cavern with player at row 4, column 16:" << endl;
    drawCavern(cav, rows, cols);

    cav[4][16].content = nothing; cav[6][15].content = player; // Move player

    cout << endl << "Cavern with player at row 6, column 15:" << endl;
    drawCavern(cav, rows, cols);

    deleteCavern(cav, rows);

    return 0;
}
