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
// %%%CJ_HIDE_END%%%
int main() {
    unsigned int rows = 7, cols = 5;
    Tile **cav = nullptr;

    // Here there is some HIDDEN CODE that allocates the cavern 'cav'.
    // If you have completed task (a), you can run this code on your computer
    // by uncommenting the following line:
    // c = createCavern(rows, cols);
    // %%%CJ_HIDE_START%%%
    cav = __02393_createCavern(rows, cols);
    // %%%CJ_HIDE_END%%%

    setupCavern(cav, rows, cols, 42);

    cout << "Cavern:" << endl;
    revealCavern(cav, rows, cols);

    deleteCavern(cav, rows);

    rows = 16;
    cols = 20;
    // Here there is some HIDDEN CODE that re-allocates the cavern 'cav'.
    // If you have completed task (a), you can run this code on your computer
    // by uncommenting the following line:
    // d = createCavern(rows, cols);
    // %%%CJ_HIDE_START%%%
    cav = __02393_createCavern(rows, cols);
    // %%%CJ_HIDE_END%%%

    setupCavern(cav, rows, cols, 33);
    cout << endl << "New cavern:" << endl;
    revealCavern(cav, rows, cols);

    deleteCavern(cav, rows);

    return 0;
}
