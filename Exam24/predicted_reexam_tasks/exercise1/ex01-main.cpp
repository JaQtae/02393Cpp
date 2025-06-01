#include <iostream>
#include "ex01-library.h" // Make sure this header declares the predicted functions
using namespace std;

// Utility to allocate and initialize field (basic placeholder for createMinefield)
Tile** createDummyField(unsigned int m, unsigned int n) {
    Tile** field = new Tile*[m];
    for (unsigned int i = 0; i < m; ++i) {
        field[i] = new Tile[n];
        for (unsigned int j = 0; j < n; ++j) {
            field[i][j].mine = false;
            field[i][j].hit = false;
        }
    }
    return field;
}

void deleteDummyField(Tile** field, unsigned int m) {
    for (unsigned int i = 0; i < m; ++i) {
        delete[] field[i];
    }
    delete[] field;
}

int main() {
    unsigned int rows = 6, cols = 16;
    Tile** field = createDummyField(rows, cols);

    // Place some mines manually
    field[0][0].mine = true;
    field[0][3].mine = true;
    field[1][7].mine = true;
    field[4][13].mine = true;
    field[5][10].mine = true;

    cout << "Number of mines: " << countMines(field, rows, cols) << endl;

    cout << "\nInitial revealed field (nothing revealed yet):" << endl;
    displayRevealedField(field, rows, cols);

    // Manually hit a tile and reveal surroundings
    cout << "\nRevealing surroundings from (2,2):" << endl;
    revealSurroundings(field, rows, cols, 2, 2);
    displayRevealedField(field, rows, cols);

    // Check safe moves
    cout << "\nAre there safe moves left? " 
         << (safeMovesLeft(field, rows, cols) ? "Yes" : "No") << endl;

    deleteDummyField(field, rows);
    return 0;
}