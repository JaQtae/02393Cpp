#include <iostream>
#include "ex01-library.h"
using namespace std;

int main() {
    Square **c = createChessboard(3, 4);
    c[0][0] = {queen, black};
    c[0][3] = {king, black};
    c[2][0] = {king, white};
    c[1][2] = {queen, white};
    cout << "Chessboard:" << endl;
    displayChessboard(c, 3, 4);

    cout << "Is the piece in (0,0) threatened? ";
    if (threatened(c, 3, 4, 0, 0)) { cout << "Yes!" << endl; }
    else { cout << "No!" << endl; }

    cout << "Can we move from (0,0) to (0,3)? ";
    if (move(c, 3, 4, 0, 0, 0, 3)) { cout << "Yes!" << endl; }
    else { cout << "No!" << endl; }

    cout << "Can we move from (0,0) to (0,2)? ";
    if (move(c, 3, 4, 0, 0, 0, 2)) { cout << "Yes!" << endl; }
    else { cout << "No!" << endl; }

    cout << "Can we move from (2,0) to (2,2)? ";
    if (move(c, 3, 4, 2, 0, 2, 2)) { cout << "Yes!" << endl; }
    else { cout << "No!" << endl; }

    cout << "Can we move from (1,2) to (0,3)? ";
    if (move(c, 3, 4, 1, 2, 0, 3)) { cout << "Yes!" << endl; }
    else { cout << "No!" << endl; }

    cout << endl << "The chessboard is now:" << endl;
    displayChessboard(c, 3, 4);

    cout << "Is the piece in (2,0) threatened? ";
    if (threatened(c, 3, 4, 2, 0)) { cout << "Yes!" << endl; }
    else { cout << "No!" << endl; }

    deleteChessboard(c, 3);
    return 0;
}
