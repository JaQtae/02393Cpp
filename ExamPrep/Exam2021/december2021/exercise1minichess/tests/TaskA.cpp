#include <iostream>
#include "ex01-library.h"
using namespace std;

int main() {
    Square **c = createChessboard(3);
    c[0][0] = {bishop, white};
    c[0][2] = {rook, white};
    c[2][0] = {rook, black};
    c[2][1] = {bishop, black};
    cout << "Chessboard c at position (1,2) contains: ";
    switch (c[1][2].piece) {
    case rook:
        cout << "a rook"; break;
    case bishop:
        cout << "a bishop"; break;
    case none:
        cout << "nothing"; break;
    default:
        cout << "WAT";
    }
    cout << endl;

    Square **d = createChessboard(5);
    d[0][1] = {bishop, white};
    d[0][4] = {rook, white};
    d[3][3] = {rook, black};
    d[4][4] = {bishop, black};
    cout << "Chessboard d at position (2,4) contains: ";
    switch (d[2][3].piece) {
    case rook:
        cout << "a rook"; break;
    case bishop:
        cout << "a bishop"; break;
    case none:
        cout << "nothing"; break;
    default:
        cout << "WAT";
    }
    cout << endl;

    deleteChessboard(c, 3);
    deleteChessboard(d, 5);
    return 0;
}
