#include <iostream>
#include "ex01-library.h"

using namespace std;

// Task 1(a).  Implement this function
Vector **createField(unsigned int m, unsigned int n, Vector v) {
    // Write your code here
    Vector** A = new Vector*[m]; // Allocate memory
    // init each array element as arg v
    for (unsigned int i=0; i<m; i++) {
        A[i] = new Vector[n]; // Initialize each row
        for (unsigned int j=0; j<n; j++) {
            A[i][j] = v; // Set each one to v
        }
    }
	return A; // return vectorfield.
}

// Task 1(b).  Implement this function
void displayField(Vector **A, unsigned int m, unsigned int n) {
    // Write your code here
    for (unsigned int i=0; i<m; i++) {
        for (unsigned int j=0; j<n; j++) {
            if (j==n-1) { // we're in the last column, so no space.
                cout << "(" << A[i][j].x <<"," << A[i][j].y << ")";
            } else {
                cout << "(" << A[i][j].x <<"," << A[i][j].y << ")" << " ";
            }

        }
    cout << endl; // New line per row
    }
}

// Task 1(c).  Implement this function
void addFields(Vector **A, Vector **B, Vector **C,
               unsigned int m, unsigned int n) {
    // Write your code here
    for (unsigned int i=0; i<m; i++) {
        for (unsigned int j=0; j<n; j++) {
            C[i][j].x = A[i][j].x + B[i][j].x; // Addition
            C[i][j].y = A[i][j].y + B[i][j].y;
        }
    } 
}

// Task 1(d).  Implement this function
void scaleField(Vector **A, double c,
                unsigned int m, unsigned int n) {
    // Write your code here
        for (unsigned int i=0; i<m; i++) {
        for (unsigned int j=0; j<n; j++) {
            A[i][j].x = A[i][j].x * c; // Scale by multiplying
            A[i][j].y = A[i][j].y * c;
        }
    } 
}

// Do not modify
void deleteField(Vector **A, unsigned int nRows) {
    for (unsigned int i = 0; i < nRows; ++i) {
        delete[] A[i];
    }
    delete[] A;
}
