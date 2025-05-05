#include <iostream>
#include "ex01-library.h"
using namespace std;

int main() {
    unsigned int rows = 6, cols = 16;
    cout << "Creating a field of " << rows << "x" << cols << " tiles" << endl << endl;
    Tile **field = createMinefield(rows, cols);

    cout << "What the opponent sees of the field is:" << endl;
    displayMinefield(field, rows, cols);

    cout << "The position of the mines in the field is:" << endl;
    revealMinefield(field, rows, cols);

    cout << endl << "Placing mines" << endl;
    placeMine(field, rows, cols, 0, 0);
    placeMine(field, rows, cols, 0, 3);
    placeMine(field, rows, cols, 0, 4);
    placeMine(field, rows, cols, 1, 7);
    placeMine(field, rows, cols, 1, 10);
    placeMine(field, rows, cols, 1, 11);
    placeMine(field, rows, cols, 1, 12);
    placeMine(field, rows, cols, 1, 13);
    placeMine(field, rows, cols, 2, 0);
    placeMine(field, rows, cols, 2, 7);
    placeMine(field, rows, cols, 3, 3);
    placeMine(field, rows, cols, 3, 7);
    placeMine(field, rows, cols, 4, 3);
    placeMine(field, rows, cols, 4, 13);
    placeMine(field, rows, cols, 4, 14);
    placeMine(field, rows, cols, 5, 10);

    cout << "What the opponent sees of the field is now:" << endl;
    displayMinefield(field, rows, cols);

    cout << "The position of the mines in the field is now:" << endl;
    revealMinefield(field, rows, cols);

    cout << "The game is" << (isGameOver(field, rows, cols) ? "" : " NOT") << " over" << endl;
    
    cout << endl << "Walking on the field" << endl << endl;
    
    field[0][1].hit = true;
    field[1][0].hit = true;
    field[1][1].hit = true;
    
    cout << "What the opponent sees of the field is now:" << endl;
    displayMinefield(field, rows, cols);

    cout << "The position of the mines in the field is now:" << endl;
    revealMinefield(field, rows, cols);

    cout << "The game is" << (isGameOver(field, rows, cols) ? "" : " NOT") << " over" << endl;
    
    cout << endl << "Walking on the field" << endl << endl;
    
    field[3][0].hit = true;
    field[4][0].hit = true;
    field[4][1].hit = true;
    field[5][0].hit = true;
    field[5][1].hit = true;
    field[5][2].hit = true;
    
    cout << "What the opponent sees of the field is now:" << endl;
    displayMinefield(field, rows, cols);

    cout << "The position of the mines in the field is now:" << endl;
    revealMinefield(field, rows, cols);

    cout << "The game is" << (isGameOver(field, rows, cols) ? "" : " NOT") << " over" << endl;
    
    cout << endl << "Walking on the field" << endl << endl;
    
    field[0][7].hit = true;
    field[1][6].hit = true;
    field[1][8].hit = true;
    field[2][8].hit = true;
    field[3][8].hit = true;

    cout << "What the opponent sees of the field is now:" << endl;
    displayMinefield(field, rows, cols);

    cout << "The position of the mines in the field is now:" << endl;
    revealMinefield(field, rows, cols);

    cout << "The game is" << (isGameOver(field, rows, cols) ? "" : " NOT") << " over" << endl;
    
    cout << endl << "Walking on the field" << endl << endl;
    
    field[1][11].hit = true;
    
    cout << "What the opponent sees of the field is now:" << endl;
    displayMinefield(field, rows, cols);

    cout << "The position of the mines in the field is now:" << endl;
    revealMinefield(field, rows, cols);

    cout << "The game is" << (isGameOver(field, rows, cols) ? "" : " NOT") << " over" << endl;
    
    deleteMinefield(field, rows);
    return 0;
}
