#include <iostream>
#include "ex01-library.h"

using namespace std;

// Task 1(a).  Implement this function
Complex **createMatrix(unsigned int m, unsigned int n, Complex c) {
    // Write your code here
    Complex **A = new Complex*[m];
    for (unsigned int i = 0; i < m; i++) {
        A[i] = new Complex[n];
        for (unsigned int j = 0; j < n; j++) {
            A[i][j] = c;
        }
    }
    return A;
}

// Task 1(b).  Implement this function
void displayMatrix(Complex **A, unsigned int m, unsigned int n) {
    // Write your code here
    for (unsigned int i = 0; i < m; i++) {
        for (unsigned int j = 0; j < n; j++) {
            cout << A[i][j].re;
            if (A[i][j].im < 0) {
                cout << A[i][j].im;
            } else {
                cout << "+" << A[i][j].im;
            }
            cout << "i";
            if (j != n-1) {
                cout << " ";
            }
        }
        cout << endl;
    }
}

// Task 1(c).  Implement this function
Complex **createIdentityMatrix(unsigned int n) {
    // Write your code here
    Complex zero = {0, 0};
    Complex one = {1, 0};
    Complex **A = createMatrix(n, n, zero);

    for (unsigned int i = 0; i < n; i++) {
        A[i][i] = one;
    }

    return A;
}

// Task 1(d).  Implement this function
void multMatrix(Complex **A, Complex **B, Complex **C,
                unsigned int m, unsigned int n, unsigned int p) {
    // Write your code here
    for (unsigned int i = 0; i < m; i++) {
        for (unsigned int j = 0; j < p; j++) {
            C[i][j] = {0, 0};
            for (unsigned int k = 0; k < n; k++) {
                Complex mlt = mult(A[i][k], B[k][j]);
                C[i][j] = add(C[i][j], mlt);
            }
        }
    }
}

// Do not modify
Complex add(Complex c, Complex d) {
    Complex result;
    result.re = c.re + d.re;
    result.im = c.im + d.im;
    return result;
}

// Do not modify
Complex mult(Complex c, Complex d) {
    Complex result;
    result.re = (c.re * d.re) - (c.im * d.im);
    result.im = (c.re * d.im) + (c.im * d.re);
    return result;
}

// Do not modify
void deleteMatrix(Complex **A, unsigned int nRows) {
    for (unsigned int i = 0; i < nRows; ++i) {
        delete[] A[i];
    }
    delete[] A;
}
