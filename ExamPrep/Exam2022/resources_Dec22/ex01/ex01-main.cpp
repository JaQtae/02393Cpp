#include <iostream>
#include "ex01-library.h"
using namespace std;

int main() {
    unsigned int rows = 6, cols = 16;
    Tile **cav = createCavern(rows, cols);
    setupCavern(cav, rows, cols, 5);

    cout << "The cavern is:" << endl;
    drawCavern(cav, rows, cols);

    cout << endl << "Moving to row 3, column 0..." << endl;
    if (!movePlayer(cav, rows, cols, 3, 0)) {
        cout << "Cannot move to row 3, column 0!" << endl;
    }
    drawCavern(cav, rows, cols);

    cout << endl << "Moving to row 3, column 7..." << endl;
    if (!movePlayer(cav, rows, cols, 3, 7)) {
        cout << "Cannot move to row 3, column 7!" << endl;
    }
    drawCavern(cav, rows, cols);

    cout << endl << "Moving to row 2, column 4..." << endl;
    if (!movePlayer(cav, rows, cols, 2, 4)) {
        cout << "Cannot move to row 2, column 4!" << endl;
    }
    drawCavern(cav, rows, cols);

    cout << endl << "Moving to row 4, column 7..." << endl;
    if (!movePlayer(cav, rows, cols, 4, 7)) {
        cout << "Cannot move to row 4, column 7!" << endl;
    }
    drawCavern(cav, rows, cols);

    cout << endl << "Revealed cavern:" << endl;
    revealCavern(cav, rows, cols);

    deleteCavern(cav, rows);
    return 0;
}
