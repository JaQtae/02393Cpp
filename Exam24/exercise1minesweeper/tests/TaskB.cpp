#include <iostream>
#include <string>
#include "ex01-library.h"

using namespace std;

int main() {
    /* Manual creation of the minefield BEGIN*/
    unsigned int rows = 7, cols = 5;
    cout << "Manually creating a field of " << rows << "x" << cols << " tiles" << endl << endl;
    Tile *arrA[7];
    Tile row1A[5] = {{false, false}, {false, false}, {false, false}, {false, false}, {false, false}};
    Tile row2A[5] = {{false, false}, {false, false}, {false, false}, {false, false}, {false, false}};
    Tile row3A[5] = {{false, false}, {false, false}, {false, false}, {false, false}, {false, false}};
    Tile row4A[5] = {{false, false}, {false, false}, {false, false}, {false, false}, {false, false}};
    Tile row5A[5] = {{false, false}, {false, false}, {false, false}, {false, false}, {false, false}};
    Tile row6A[5] = {{false, false}, {false, false}, {false, false}, {false, false}, {false, false}};
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

    bool result = true;

    cout << endl << "Placing mines" << endl;
    result &= placeMine(field, rows, cols, 0, 0);
    result &= placeMine(field, rows, cols, 0, 4);
    result &= placeMine(field, rows, cols, 1, 4);
    result &= placeMine(field, rows, cols, 1, 1);
    result &= placeMine(field, rows, cols, 6, 0);
    result &= placeMine(field, rows, cols, 6, 2);
    result &= placeMine(field, rows, cols, 4, 1);
    result &= placeMine(field, rows, cols, 4, 2);




    if(!result) {
        cout << "wrong return value when invoking placeMine" << endl;
    }

    cout << "The position of the mines in the field is:" << endl;
    revealMinefield(field, rows, cols);

    cout << endl << "Attempting to place mines in the wrong position" << endl;
    result = false;
    // position out of bounds
    result |= placeMine(field, rows, cols, 7, 0);
    result |= placeMine(field, rows, cols, 0, 5);

    // tile already occupied by a mine
    result |= placeMine(field, rows, cols, 0, 4);
    result |= placeMine(field, rows, cols, 1, 1);

    if(result) {
        cout << "wrong return value when invoking placeMine" << endl;
    }

    cout << "The position of the mines in the field is:" << endl;
    revealMinefield(field, rows, cols);

    cout << endl << "Attempting to place too many mines" << endl;
    
    result = false;

    //too many mines
    result |= placeMine(field, rows, cols, 6, 1);
    
    if(result) {
        cout << "wrong return value when invoking placeMine" << endl;
    }

    cout << "The position of the mines in the field is:" << endl;
    revealMinefield(field, rows, cols);

    rows = 3; 
    cols = 2;
    cout << "Manually creating a new field of " << rows << "x" << cols << " tiles" << endl << endl;
    Tile *arrB[3];
    Tile row1B[2] = {{false, false}, {false, false}};
    Tile row2B[2] = {{false, false}, {false, false}};
    Tile row3B[2] = {{false, false}, {false, false}};
    arrB[0] = row1B;
    arrB[1] = row2B;
    arrB[2] = row3B;
    
    field = arrB;

    cout << endl << "Placing mines" << endl;

    result = true;

    result &= placeMine(field, rows, cols, 1, 1);

    if(!result) {
        cout << "wrong return value when invoking placeMine" << endl;
    }
    
    cout << "The position of the mines in the field is:" << endl;
    revealMinefield(field, rows, cols);

    cout << "Walking on the field" << endl;
    arrB[1][0].hit = true;

    cout << "The position of the mines in the field is:" << endl;
    revealMinefield(field, rows, cols);

    cout << endl << "Attempting to place mines after game started" << endl;
    
    result = false;

    //too many mines
    result |= placeMine(field, rows, cols, 0, 0);
    
    if(result) {
        cout << "wrong return value when invoking placeMine" << endl;
    }

    cout << "The position of the mines in the field is:" << endl;
    revealMinefield(field, rows, cols);

    return 0;
}
