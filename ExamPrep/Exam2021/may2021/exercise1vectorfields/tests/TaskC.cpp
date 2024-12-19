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
    Vector u = {1, 2};
    Vector v = {3, 4};
    Vector **A = nullptr, **B = nullptr, **M = nullptr;

	// HIDDEN CODE that allocates matrices A, B, and N.
    // If you have completed task (a), you can run this code on your computer
    // by uncommenting the lines:
    // A = createMatrix(2, 3, u);
    // B = createMatrix(2, 3, v);
    // M = createMatrix(2, 3, {0,0});
    // %%%CJ_HIDE_START%%%
    A = __02393_createField(2, 3, u);
    B = __02393_createField(2, 3, v);
    M = __02393_createField(2, 3, {0,0});
    // %%%CJ_HIDE_END%%%

    addFields(A, B, M, 2, 3);

    cout << "M[0][0] = (" << M[0][0].x << "," << M[0][0].y << ")" << endl;
    cout << "M[0][1] = (" << M[0][1].x << "," << M[0][1].y << ")" << endl;
    cout << "M[1][0] = (" << M[1][0].x << "," << M[1][0].y << ")" << endl;
    cout << "M[1][2] = (" << M[1][2].x << "," << M[1][2].y << ")" << endl;

    deleteField(A, 3); deleteField(B, 3); deleteField(M, 3);
    return 0;
}
