#include <iostream>
#include "ex01-library.h"
using namespace std;

void describeContent(Tile c) {

    cout << "has ";
    if (!c.hit) {
        cout << "NOT ";
    }
    cout << "been touched and ";
    if (c.mine){
        cout << "contains ";
    } else {
        cout << "does not contain ";
    }
    cout << "a mine" << endl;
}

int main() {
    
    unsigned int rows = 8, cols = 6;
    cout << "Creating a field of " << rows << "x" << cols << " tiles" << endl << endl;
    Tile **field = createMinefield(rows, cols);
    cout << "The field at position (1,2) ";
    describeContent(field[1][2]);
    cout << "The field at position (7,5) ";
    describeContent(field[7][5]);
    cout << "The field at position (6,0) ";
    describeContent(field[6][0]);
    cout << "The field at position (0,4) ";
    describeContent(field[0][4]);

    cout << endl << "Manipulating the field" << endl << endl;

    field[1][2].mine = true; field[1][2].hit = false;
    field[7][5].mine = false; field[7][5].hit = true;
    field[6][0].mine = true; field[6][0].hit = true;

    
    cout << "The field at position (1,2) ";
    describeContent(field[1][2]);
    cout << "The field at position (7,5) ";
    describeContent(field[7][5]);
    cout << "The field at position (6,0) ";
    describeContent(field[6][0]);
    cout << "The field at position (0,4) ";
    describeContent(field[0][4]);

    deleteMinefield(field, rows);

    rows = 15;
    cols = 16;
    cout << "Creating a new field of " << rows << "x" << cols << " tiles" << endl << endl;
    
    field = createMinefield(rows, cols);

    cout << "The new field at position (1,2) ";
    describeContent(field[1][2]);
    cout << "The new field at position (14,14) ";
    describeContent(field[14][14]);
    cout << "The new field at position (13,1) ";
    describeContent(field[13][1]);
    cout << "The new field at position (1,15) ";
    describeContent(field[1][15]);

    cout << endl << "Manipulating the new field" << endl << endl;
    
    field[1][2].mine = true; field[1][2].hit = false;
    field[14][14].mine = true; field[14][14].hit = true;
    field[13][1].mine = false; field[13][1].hit = true;
    
    cout << "The new field at position (1,2) ";
    describeContent(field[1][2]);
    cout << "The new field at position (14,14) ";
    describeContent(field[14][14]);
    cout << "The new field at position (13,1) ";
    describeContent(field[13][1]);
    cout << "The new field at position (1,15) ";
    describeContent(field[1][15]);

    deleteMinefield(field, rows);

    return 0;
}
