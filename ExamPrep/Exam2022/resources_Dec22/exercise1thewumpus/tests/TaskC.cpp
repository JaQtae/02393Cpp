#include <iostream>
#include <string>
#include "ex01-library.h"

using namespace std;

// Internal function to check whether the player moved from (r1,c1) to (r2,c2)
void checkMoved(Tile **cav, int r1, int c1, int r2, int c2) {
    if (cav[r1][c1].content != nothing) {
        cout << "ERROR: the tile at (" << r1 << "," << c1 << ") is not empty!";
    }
    if (cav[r2][c2].content != player) {
        cout << "ERROR: the player is not at (" << r2 << "," << c2 << ")!";
    }
}

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
    unsigned int rows = 10, cols = 20;
    Tile **cav = nullptr;

    // Here there is some HIDDEN CODE that allocates the cavern 'cav'.
    // If you have completed task (a), you can run this code on your computer
    // by uncommenting the following line:
    // c = createCavern(rows, cols);
    // %%%CJ_HIDE_START%%%
    cav = __02393_createCavern(rows, cols);
    // %%%CJ_HIDE_END%%%

    setupCavern(cav, rows, cols, 42);

    cout << "Initial cavern:" << endl;
    // Here there is some HIDDEN CODE that reveals the cavern 'cav'.
    // If you have completed task (b), you can run this code on your computer
    // by uncommenting the following line:
    // revealCavern(cav, rows, cols);
    // %%%CJ_HIDE_START%%%
    __02393_revealCavern(cav, rows, cols);
    // %%%CJ_HIDE_END%%%

    cout << endl << "Moving to row 3, column 2..." << endl;
    if (!movePlayer(cav, rows, cols, 3, 2)) {
        cout << "Cannot move to row 3, column 2!" << endl;
    } else {
        checkMoved(cav, 0, 0, 3, 2);
    }

    cout << endl << "Moving to row 6, column 5..." << endl;
    if (!movePlayer(cav, rows, cols, 6, 5)) {
        cout << "Cannot move to row 6, column 5!" << endl;
    } else {
        checkMoved(cav, 3, 2, 6, 5);
    }

    cout << endl << "Moving to row 6, column 9..." << endl;
    if (!movePlayer(cav, rows, cols, 6, 9)) {
        cout << "Cannot move to row 6, column 9!" << endl;
    } else {
        checkMoved(cav, 6, 5, 6, 9);
    }

    cout << endl << "Moving to row 8, column 11..." << endl;
    if (!movePlayer(cav, rows, cols, 8, 11)) {
        cout << "Cannot move to row 8, column 11!" << endl;
    } else {
        checkMoved(cav, 6, 9, 8, 11);
    }

    cout << endl << "Moving to row 7, column 13..." << endl;
    if (!movePlayer(cav, rows, cols, 7, 13)) {
        cout << "Cannot move to row 7, column 13!" << endl;
    } else {
        checkMoved(cav, 6, 9, 7, 13);
    }

    cout << endl << "Moving to row 9, column 12..." << endl;
    if (!movePlayer(cav, rows, cols, 9, 12)) {
        cout << "Cannot move to row 9, column 12!" << endl;
    } else {
        checkMoved(cav, 7, 13, 9, 12);
    }

    cout << endl << "Revealed cavern after movements:" << endl;
    // Here there is some HIDDEN CODE that reveals the cavern 'cav'.
    // If you have completed task (b), you can run this code on your computer
    // by uncommenting the following line:
    // revealCavern(cav, rows, cols);
    // %%%CJ_HIDE_START%%%
    __02393_revealCavern(cav, rows, cols);
    // %%%CJ_HIDE_END%%%

    deleteCavern(cav, rows);

    return 0;
}
