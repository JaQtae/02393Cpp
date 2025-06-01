#include <iostream>
#include "ex01-library.h"
using namespace std;

int main() {
    unsigned int rows = 6, cols = 16;
    Tile **sea = createSea(rows, cols);

    cout << "What the opponent sees of the sea is:" << endl;
    displaySea(sea, rows, cols, false);
    
    cout << "The position of the ships in the sea is:" << endl;
    displaySea(sea, rows, cols, true);
    
    cout << endl << "Placing ships" << endl;
    placeShip(sea, rows, cols, 0, 0, 1,1,false);
    placeShip(sea, rows, cols, 0, 3, 2,2,false);
    placeShip(sea, rows, cols, 1, 7, 3,3,true);
    placeShip(sea, rows, cols, 1, 10, 4,4,false);
    placeShip(sea, rows, cols, 2, 0, 5,1,false);
    placeShip(sea, rows, cols, 3, 3, 6,2,true);
    placeShip(sea, rows, cols, 4, 13, 7,2,false);
    placeShip(sea, rows, cols, 5, 10, 8,1,false);

    cout << endl << "What the opponent sees of the sea is now:" << endl;
    displaySea(sea, rows, cols, false);
    
    cout << "The position of the ships in the sea is now:" << endl;
    displaySea(sea, rows, cols, true);
    
    cout << endl << "Launching a missile to row 0, column 15..." << endl;
    launchMissile(sea, rows, cols, 0, 15);
    cout << endl << "Launching a missile to row 0, column 14..." << endl;
    launchMissile(sea, rows, cols, 0, 14);
    
    cout << endl << "Launching a missile to row 0, column 11..." << endl;
    launchMissile(sea, rows, cols, 0, 11);
    cout << endl << "Launching a missile to row 1, column 11..." << endl;
    launchMissile(sea, rows, cols, 1, 11);
    
    cout << endl << "Launching a missile to row 2, column 7..." << endl;
    launchMissile(sea, rows, cols, 2, 7);
    cout << endl << "Launching a missile to row 2, column 6..." << endl;
    launchMissile(sea, rows, cols, 2, 6);
    cout << endl << "Launching a missile to row 3, column 6..." << endl;
    launchMissile(sea, rows, cols, 3, 6);
    
    cout << endl << "Launching a missile to row 4, column 2..." << endl;
    launchMissile(sea, rows, cols, 4, 2);
    cout << endl << "Launching a missile to row 4, column 3..." << endl;
    launchMissile(sea, rows, cols, 4, 3);
    cout << endl << "Launching a missile to row 4, column 4..." << endl;
    launchMissile(sea, rows, cols, 4, 4);
    cout << endl << "Launching a missile to row 5, column 2..." << endl;
    launchMissile(sea, rows, cols, 5, 2);
    cout << endl << "Launching a missile to row 5, column 3..." << endl;
    launchMissile(sea, rows, cols, 5, 3);
    cout << endl << "Launching a missile to row 5, column 4..." << endl;
    launchMissile(sea, rows, cols, 5, 4);
    
    cout << endl << "Launching a missile to row 5, column 12..." << endl;
    launchMissile(sea, rows, cols, 5, 12);
    cout << endl << "Launching a missile to row 5, column 11..." << endl;
    launchMissile(sea, rows, cols, 5, 11);
    cout << endl << "Launching a missile to row 5, column 10..." << endl;
    launchMissile(sea, rows, cols, 5, 10);
    
    cout << endl << "What the opponent sees of the sea is now:" << endl;
    displaySea(sea, rows, cols, false);
    
    cout << "The position of the ships in the sea is now:" << endl;
    displaySea(sea, rows, cols, true);

    deleteSea(sea, rows);
    return 0;
}
