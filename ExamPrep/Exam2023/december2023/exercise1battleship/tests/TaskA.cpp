#include <iostream>
#include "ex01-library.h"
using namespace std;

string describeContent(Tile c) {
    if (c.ship == 0){
        return "water";
    } else {
        if (c.hit){
            return "a ship being hit on that location";
        } else {
            return "a ship not hit on that location";
        }
    }
}

int main() {
    unsigned int rows = 8, cols = 6;
    Tile **cav = createSea(rows, cols);
    cout << "The sea at position (1,2) contains: ";
    cout << describeContent(cav[1][2]) << endl;
    cout << "The sea at position (7,5) contains: ";
    cout << describeContent(cav[7][5]) << endl;
    cout << "The sea at position (6,0) contains: ";
    cout << describeContent(cav[6][0]) << endl;
    cout << "The sea at position (0,4) contains: ";
    cout << describeContent(cav[0][4]) << endl;

    cout << endl << "Manipulating the sea" << endl << endl;

    cav[1][2].ship = 1; cav[1][2].hit = false;
    cav[7][5].ship = 2; cav[7][5].hit = true;
    cav[6][0].ship = 3; cav[6][0].hit = false;

    
    cout << "The sea at position (1,2) now contains: ";
    cout << describeContent(cav[1][2]) << endl;
    cout << "The sea at position (7,5) now contains: ";
    cout << describeContent(cav[7][5]) << endl;
    cout << "The sea at position (6,0) now contains: ";
    cout << describeContent(cav[6][0]) << endl;
    cout << endl;

    deleteSea(cav, rows);

    cout << "Creating a new sea" << endl << endl;

    rows = 15;
    cols = 16;
    cav = createSea(rows, cols);

    cout << "The new sea at position (1,2) contains: ";
    cout << describeContent(cav[1][2]) << endl;
    cout << "The new sea at position (14,14) contains: ";
    cout << describeContent(cav[14][14]) << endl;
    cout << "The new sea at position (13,1) contains: ";
    cout << describeContent(cav[13][1]) << endl;
    cout << "The new sea at position (1,15) contains: ";
    cout << describeContent(cav[1][15]) << endl;

    cout << endl << "Manipulating the new sea" << endl << endl;
    
    cav[1][2].ship = 1; cav[1][2].hit = false;
    cav[14][14].ship = 2; cav[14][14].hit = true;
    cav[13][1].ship = 3; cav[13][1].hit = false;
    
    cout << "The new sea at position (1,2) now contains: ";
    cout << describeContent(cav[1][2]) << endl;
    cout << "The new sea at position (14,14) now contains: ";
    cout << describeContent(cav[14][14]) << endl;
    cout << "The new sea at position (13,1) now contains: ";
    cout << describeContent(cav[13][1]) << endl;
    cout << endl;
    
    deleteSea(cav, rows);

    return 0;
}
