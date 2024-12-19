#include <iostream>
#include <string>
#include "ex01-library.h"

using namespace std;

// %%%CJ_HIDE_START%%%
Square** __02393_createChessboard(unsigned int n) {
    Square **c = new Square*[n];
    for (unsigned int row = 0; row < n; row++) {
        c[row] = new Square[n];
        for (unsigned int col = 0; col < n; col++) {
            c[row][col] = {none, nobody};
        }
    }
    return c;
}
// %%%CJ_HIDE_END%%%
int main() {
    Square **c = nullptr;

    // Here there is some HIDDEN CODE that allocates the chessboard 'c'.
    // If you have completed task (a), you can run this code on your computer
    // by uncommenting the following line:
    // c = createChessboard(4);
    // %%%CJ_HIDE_START%%%
    c = __02393_createChessboard(4);
    // %%%CJ_HIDE_END%%%

    c[1][0] = {bishop, white};
    c[0][2] = {rook, white};
    c[3][0] = {rook, black};
    c[2][1] = {bishop, black};
    cout << "Chessboard 'c':" << endl;
    displayChessboard(c, 4);

    Square **d = nullptr;

    // Here there is some HIDDEN CODE that allocates the chessboard 'd'.
    // If you have completed task (a), you can run this code on your computer
    // by uncommenting the following line:
    // d = createChessboard(6);
    // %%%CJ_HIDE_START%%%
    d = __02393_createChessboard(6);
    // %%%CJ_HIDE_END%%%

    d[1][1] = {bishop, white};
    d[0][2] = {rook, white};
    d[3][3] = {rook, black};
    d[5][5] = {bishop, black};
    cout << endl << "Chessboard 'd':" << endl;
    displayChessboard(d, 6);

    deleteChessboard(c, 4);
    deleteChessboard(d, 6);
    return 0;
}
