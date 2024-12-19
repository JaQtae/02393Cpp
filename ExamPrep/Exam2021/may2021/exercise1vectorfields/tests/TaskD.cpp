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
    Vector v = {3, 1};
    Vector **A = nullptr, **B = nullptr;

    // HIDDEN CODE that allocates matrices A, B, and N.
    // If you have completed task (a), you can run this code on your computer
    // by uncommenting the lines:
    // A = createField(2, 3, u);
    // B = createField(6, 6, v);
    // %%%CJ_HIDE_START%%%
    A = __02393_createField(2, 3, u);
    B = __02393_createField(6, 6, v);
    // %%%CJ_HIDE_END%%%

    scaleField(A, 2, 2, 3);

    cout << "A[0][0] = (" << A[0][0].x << "," << A[0][0].y << ")" << endl;
    cout << "A[0][1] = (" << A[0][1].x << "," << A[0][1].y << ")" << endl;
    cout << "A[1][0] = (" << A[1][0].x << "," << A[1][0].y << ")" << endl;
    cout << "A[1][2] = (" << A[1][2].x << "," << A[1][2].y << ")" << endl;

    cout << endl;
    
    scaleField(B, 3, 6, 6);

    cout << "B[0][0] = (" << B[0][0].x << "," << B[0][0].y << ")" << endl;
    cout << "B[0][1] = (" << B[0][1].x << "," << B[0][1].y << ")" << endl;
    cout << "B[1][3] = (" << B[1][3].x << "," << B[1][3].y << ")" << endl;
    cout << "B[5][5] = (" << B[5][5].x << "," << B[5][5].y << ")" << endl;

    deleteField(A, 3); deleteField(B, 6);
    return 0;
}
