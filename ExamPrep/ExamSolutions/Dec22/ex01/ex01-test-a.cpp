#include <iostream>
#include "ex01-library.h"
using namespace std;

string describeContent(Content c) {
    switch (c) {
    case nothing:
        return "nothing";
    case player:
        return "the player";
    case rock:
        return "a rock";
    case wumpus:
        return "the Wumpus";
    default:
        return "WAT";
    }
}

int main() {
    unsigned int rows = 8, cols = 6;
    Tile **cav = createCavern(rows, cols);
    cav[1][2].content = player;
    cav[7][5].content = wumpus;
    cav[6][0].content = rock;
    cav[0][4].content = rock;
    cout << "The cavern at position (7,5) contains: ";
    cout << describeContent(cav[7][5].content) << endl;
    cout << "The cavern at position (1,2) contains: ";
    cout << describeContent(cav[1][2].content) << endl;
    cout << "The cavern at position (0,4) contains: ";
    cout << describeContent(cav[0][4].content) << endl;
    cout << endl;

    deleteCavern(cav, rows);

    rows = 15;
    cols = 16;
    cav = createCavern(rows, cols);
    cav[1][2].content = wumpus;
    cav[14][14].content = player;
    cav[13][1].content = rock;
    cav[1][15].content = rock;
    cout << "The new cavern at position (7,5) contains: ";
    cout << describeContent(cav[7][5].content) << endl;
    cout << "The new cavern at position (1,2) contains: ";
    cout << describeContent(cav[1][2].content) << endl;
    cout << "The new cavern at position (1,15) contains: ";
    cout << describeContent(cav[1][15].content) << endl;

    deleteCavern(cav, rows);

    return 0;
}
