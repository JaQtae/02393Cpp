#include <iostream>
#include <string>
#include "ex01-library.h"

using namespace std;

// %%%CJ_HIDE_END%%%
int main() {

    /* Manual creation of the minefield BEGIN*/
    unsigned int rows = 7, cols = 5;
    cout << "Manually creating a field of " << rows << "x" << cols << " tiles" << endl << endl;
    Tile *arrA[7];
    Tile row1A[5] = {{false, false}, {false, false}, {true, false}, {false, false}, {false, false}};
    Tile row2A[5] = {{true, false}, {false, false}, {false, false}, {false, false}, {false, false}};
    Tile row3A[5] = {{false, false}, {true, false}, {false, false}, {false, false}, {false, false}};
    Tile row4A[5] = {{false, false}, {false, false}, {true, false}, {false, false}, {false, false}};
    Tile row5A[5] = {{false, false}, {false, false}, {false, false}, {false, false}, {false, false}};
    Tile row6A[5] = {{false, false}, {false, false}, {true, false}, {false, false}, {false, false}};
    Tile row7A[5] = {{false, false}, {false, false}, {false, false}, {false, false}, {false, false}};
    
    arrA[0] = row1A;
    arrA[1] = row2A;
    arrA[2] = row3A;
    arrA[3] = row4A;
    arrA[4] = row5A;
    arrA[5] = row6A;
    arrA[6] = row7A;

    Tile **field = arrA;
    /* Manual creation of the minefield END*/
    
    cout << "The position of the mines in the field is:" << endl;
    revealMinefield(field, rows, cols);

    cout << endl << "Walking on the field" << endl << endl;
    
    field[0][0].hit = true;
    field[0][1].hit = true;
    
    cout << "The field is now:" << endl;
    revealMinefield(field, rows, cols);
    cout << "The game is" << (isGameOver(field, rows, cols) ? "" : " NOT") << " over" << endl;
    cout << endl << "Walking on the field" << endl << endl;
    
    field[0][3].hit = true;
    field[6][3].hit = false;

    cout << "The field is now:" << endl;
    revealMinefield(field, rows, cols);
    cout << "The game is" << (isGameOver(field, rows, cols) ? "" : " NOT") << " over" << endl;
    cout << endl << "Walking on the field" << endl << endl;
    
    field[6][4].hit = true;
    field[6][0].hit = false;

    cout << "The field is now:" << endl;
    revealMinefield(field, rows, cols);
    cout << "The game is" << (isGameOver(field, rows, cols) ? "" : " NOT") << " over" << endl;
    
    cout << endl << "Creating a new field" << endl << endl;

    /* Manual creation of the minefield BEGIN*/
    rows = 4; 
    cols = 8;
    
    cout << "Manually creating a field of " << rows << "x" << cols << " tiles" << endl << endl;
    Tile *arrB[4];
    Tile row1B[8] = {{true, false}, {true, false}, {false, false}, {false, false}, {false, false}, {false, false}, {false, false}, {false, false}};
    Tile row2B[8] = {{false, false}, {false, false}, {false, false}, {false, false}, {false, false}, {false, false}, {false, false}, {false, false}};
    Tile row3B[8] = {{false, false}, {false, false}, {true, false}, {false, false}, {false, false}, {false, false}, {false, false}, {false, false}};
    Tile row4B[8] = {{true, false}, {false, false}, {false, false}, {false, false}, {false, false}, {false, false}, {false, false}, {false, false}};
    
    arrB[0] = row1B;
    arrB[1] = row2B;
    arrB[2] = row3B;
    arrB[3] = row4B;
    
    field = arrB;
    /* Manual creation of the minefield END*/
    
    cout << "The position of the mines in the new field is:" << endl;
    revealMinefield(field, rows, cols);

    cout << endl << "Walking on the new field" << endl << endl;

    field[3][1].hit = true;

    cout << "The field is now:" << endl;
    revealMinefield(field, rows, cols);
    cout << "The game is" << (isGameOver(field, rows, cols) ? "" : " NOT") << " over" << endl;
    cout << endl << "Walking on the field" << endl << endl;
    
    field[3][2].hit = true;
    field[1][3].hit = true;
    
    cout << "The field is now:" << endl;
    revealMinefield(field, rows, cols);
    cout << "The game is" << (isGameOver(field, rows, cols) ? "" : " NOT") << " over" << endl;
    cout << endl << "Walking on the field" << endl << endl;
    
    field[2][3].hit = false;
    field[1][4].hit = true;
    
    cout << "The field is now:" << endl;
    revealMinefield(field, rows, cols);
    cout << "The game is" << (isGameOver(field, rows, cols) ? "" : " NOT") << " over" << endl;
    cout << endl << "Walking on the field" << endl << endl;
    
    field[2][4].hit = false;
    field[1][6].hit = false;
    field[3][0].hit = true;
    
    cout << "The field is now:" << endl;
    revealMinefield(field, rows, cols);
    cout << "The game is" << (isGameOver(field, rows, cols) ? "" : " NOT") << " over" << endl;
    
    return 0;
}
