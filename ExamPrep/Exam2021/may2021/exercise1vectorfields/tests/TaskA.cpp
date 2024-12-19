#include <iostream>
#include <string>
#include "ex01-library.h"

using namespace std;

int main() {
    Vector v = {1, 2};
    Vector **A = createField(4, 4, v);
    cout << "A[0][0] = (" << A[0][0].x << "," << A[0][0].y << ")" << endl;
    cout << "A[3][0] = (" << A[3][0].x << "," << A[3][0].y << ")" << endl;
    cout << "A[0][3] = (" << A[0][3].x << "," << A[0][3].y << ")" << endl;
    cout << "A[3][3] = (" << A[3][3].x << "," << A[3][3].y << ")" << endl;

    cout << endl;
    
    Vector v2 = {3, 9};
    Vector **B = createField(8, 8, v2);
    cout << "B[1][2] = (" << B[1][2].x << "," << B[1][2].y << ")" << endl;
    cout << "B[2][5] = (" << B[2][5].x << "," << B[2][5].y << ")" << endl;
    cout << "B[4][6] = (" << B[4][6].x << "," << B[4][6].y << ")" << endl;
    cout << "B[7][7] = (" << B[7][7].x << "," << B[7][7].y << ")" << endl;

    deleteField(A, 4); deleteField(B, 3);
    return 0;
}
