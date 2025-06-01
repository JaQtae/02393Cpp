#include <iostream>
#include "ex01-library.h"
using namespace std;

string toString(bool result){
    if(result)
        return "success!";
    return "failed!";
}

int main() {
    unsigned int rows = 8;
    Tile **sea = createSea(rows);

    cout << "What the opponent sees of the sea is:" << endl;
    displaySea(sea, rows, false);
    
    cout << "The position of the ships in the sea is:" << endl;
    displaySea(sea, rows, true);
    
    cout << endl << "Placing ships" << endl;
    sea[0][0].ship = 1;
    sea[0][3].ship = 2; 
    sea[0][4].ship = 2;
    sea[1][7].ship = 3;
    sea[2][7].ship = 3;
    sea[3][7].ship = 3;
    sea[1][10].ship = 4;
    sea[1][11].ship = 4;
    sea[1][12].ship = 4;
    sea[1][13].ship = 4;
    sea[2][0].ship = 5;
    sea[3][3].ship = 6; 
    sea[4][3].ship = 6; 
    sea[4][13].ship = 7; 
    sea[4][14].ship = 7; 
    sea[5][10].ship = 8; 

    cout << endl << "What the opponent sees of the sea is now:" << endl;
    displaySea(sea, rows, false);
    
    cout << "The position of the ships in the sea is now:" << endl;
    displaySea(sea, rows, true);
    
    cout << endl << "Launching a missile to row 0, column 15..." <<
        toString(launchBigMissile(sea, rows, 0, 15)) << endl;
    cout << endl << "Launching a missile to row 0, column 14..." << 
        toString(launchBigMissile(sea, rows, 0, 14)) << endl;
    
    cout << endl << "Launching a missile to row 0, column 11..." <<
        toString(launchBigMissile(sea, rows, 0, 11)) << endl;
    cout << endl << "Launching a missile to row 1, column 11..." <<
        toString(launchBigMissile(sea, rows, 1, 11)) << endl;
    
    cout << endl << "Launching a missile to row 2, column 7..." <<
        toString(launchBigMissile(sea, rows, 2, 7)) << endl;
    cout << endl << "Launching a missile to row 2, column 6..." <<
        toString(launchBigMissile(sea, rows, 2, 6)) << endl;
    cout << endl << "Launching a missile to row 3, column 6..." <<
        toString(launchBigMissile(sea, rows, 3, 6)) << endl;
    
    cout << endl << "Launching a missile to row 4, column 2..." <<
        toString(launchBigMissile(sea, rows, 4, 2)) << endl;
    cout << endl << "Launching a missile to row 4, column 3..." <<
        toString(launchBigMissile(sea, rows, 4, 3)) << endl;
    cout << endl << "Launching a missile to row 4, column 4..." <<
        toString(launchBigMissile(sea, rows, 4, 4)) << endl;
    cout << endl << "Launching a missile to row 5, column 2..." <<
        toString(launchBigMissile(sea, rows, 5, 2)) << endl;
    cout << endl << "Launching a missile to row 5, column 3..." <<
        toString(launchBigMissile(sea, rows, 5, 3)) << endl;
    cout << endl << "Launching a missile to row 5, column 4..." <<
        toString(launchBigMissile(sea, rows, 5, 4)) << endl;
    
    cout << endl << "Launching a missile to row 5, column 12..." <<
        toString(launchBigMissile(sea, rows, 5, 12)) << endl;
    cout << endl << "Launching a missile to row 5, column 11..." <<
        toString(launchBigMissile(sea, rows, 5, 11)) << endl;
    cout << endl << "Launching a missile to row 5, column 10..." <<
        toString(launchBigMissile(sea, rows, 5, 10)) << endl;
    
    cout << endl << "What the opponent sees of the sea is now:" << endl;
    displaySea(sea, rows, false);
    
    cout << "The position of the ships in the sea is now:" << endl;
    displaySea(sea, rows, true);

    deleteSea(sea, rows);
    return 0;
}
