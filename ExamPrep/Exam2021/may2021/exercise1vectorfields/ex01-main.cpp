#include <iostream>
#include "ex01-library.h"
using namespace std;

int main() {
    Vector c = {1, 2};
    Vector d = {2, -2};

    Vector **A = createField(3, 3, c);
    A[1][1] = {2, 2};
    cout << "Vector field A:" << endl;
    displayField(A, 3, 3);
    cout << endl;

    Vector **B = createField(3, 3, d);
    B[0][0] = B[2][2] = {9, 8};
    cout << "Vector field B:" << endl;
    displayField(B, 3, 3);
    cout << endl;

    Vector **R = createField(3, 3, {0,0});
    cout << "Result of A + B:" << endl;
    addFields(A, B, R, 3, 3);
    displayField(R, 3, 3);
    cout << endl;

    cout << "Result of scaling A by 2:" << endl;
    scaleField(A, 2, 3, 3);
    displayField(A, 3, 3);

    deleteField(A, 3); deleteField(B, 3);
    deleteField(R, 3);
    return 0;
}
