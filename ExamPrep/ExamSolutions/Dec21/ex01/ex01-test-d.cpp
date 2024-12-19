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

void __02393_displayChessboard(Square **c, unsigned int n) {
    for (unsigned int row = 0; row < n; row++) {
        for (unsigned int col = 0; col < n; col++) {
            switch (c[row][col].team) {
            case black:
                switch (c[row][col].piece) {
                case bishop:
                    cout << "B"; break;
                case rook:
                    cout << "R"; break;
                default:
                    cout << "X"; // This should not happen!
                }
                break;
            case white:
                switch (c[row][col].piece) {
                case bishop:
                    cout << "b"; break;
                case rook:
                    cout << "r"; break;
                default:
                    cout << "x"; // This should not happen!
                }
                break;
            case nobody:
                cout << "_";
            }
            cout << " ";
        }
        cout << endl;
    }
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
    
    // Here there is some HIDDEN CODE that displays the chessboard 'c'.
    // If you have completed task (b), you can run this code on your computer
    // by uncommenting the following line:
    // displayChessboard(c, 4);
    // %%%CJ_HIDE_START%%%
    __02393_displayChessboard(c, 4);
    // %%%CJ_HIDE_END%%%

    cout << "Is the piece in (2,1) threatened? ";
    if (threatened(c, 4, 2, 1)) {
        cout << "Yes!" << endl;
    } else {
        cout << "No!" << endl;
    }
    cout << "Is the piece in (1,0) threatened? ";
    if (threatened(c, 4, 1, 0)) {
        cout << "Yes!" << endl;
    } else {
        cout << "No!" << endl;
    }

    Square **d = nullptr;

    // Here there is some HIDDEN CODE that allocates the chessboard 'd'.
    // If you have completed task (a), you can run this code on your computer
    // by uncommenting the following line:
    // d = createChessboard(6);
    // %%%CJ_HIDE_START%%%
    d = __02393_createChessboard(6);
    // %%%CJ_HIDE_END%%%

    d[1][0] = {bishop, white};
    d[0][2] = {rook, white};
    d[3][2] = {rook, black};
    d[5][5] = {bishop, black};
    cout << endl << "Chessboard 'd':" << endl;

    // Here there is some HIDDEN CODE that displays the chessboard 'd'.
    // If you have completed task (b), you can run this code on your computer
    // by uncommenting the following line:
    // displayChessboard(d, 6);
    // %%%CJ_HIDE_START%%%
    __02393_displayChessboard(d, 6);
    // %%%CJ_HIDE_END%%%

    cout << "Is the piece in (1,0) threatened? ";
    if (threatened(d, 6, 1, 0)) {
        cout << "Yes!" << endl;
    } else {
        cout << "No!" << endl;
    }
    cout << "Is the piece in (3,2) threatened? ";
    if (threatened(d, 6, 3, 2)) {
        cout << "Yes!" << endl;
    } else {
        cout << "No!" << endl;
    }

    deleteChessboard(c, 4);
    deleteChessboard(d, 6);
    return 0;
}
