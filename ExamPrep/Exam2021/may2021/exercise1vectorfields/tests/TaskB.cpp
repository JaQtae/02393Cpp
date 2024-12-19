#include <iostream>
#include <string>
#include "ex01-library.h"

using namespace std;

// %%%CJ_HIDE_START%%%
Vector **__02393_createField(unsigned int m, unsigned int n, Vector v) {
    // Write your code here
    Vector **A = new Vector*[m];
    for (unsigned int i = 0; i < m; i++) {
        A[i] = new Vector[n];
        for (unsigned int j = 0; j < n; j++) {
            A[i][j] = v;
        }
    }
    return A;
}
// %%%CJ_HIDE_END%%%
int main() {
    Vector v = {1, 2};
    Vector **A = nullptr;

    // HIDDEN CODE that allocates matrix A.  If you have completed task (a),
    // you can run this code on your computer by uncommenting the line:  
    // A = createMatrix(4, 3, v);
    // %%%CJ_HIDE_START%%%
    A = __02393_createField(4, 3, v);
    // %%%CJ_HIDE_END%%%

    A[0][0] = A[1][1] = A[2][2] = {0, 0};
    displayField(A, 4, 3);

    cout << endl;

    Vector d = {3, -9};
    Vector **B = nullptr;

    // HIDDEN CODE that allocates matrix B.  If you have completed task (a),
    // you can run this code on your computer by uncommenting the line:  
    // B = createMatrix(6, 8, d);
    // %%%CJ_HIDE_START%%%
    B = __02393_createField(6, 8, d);
    // %%%CJ_HIDE_END%%%

    B[0][1] = B[2][1] = B[3][2] = B[4][5] = B[5][6] = {0, 0};
    displayField(B, 6, 8);

    deleteField(A, 4); deleteField(B, 6);
    return 0;
}
