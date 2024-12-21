#include <iostream>
#include <vector>
#include <iomanip>
#include "ex01-library.h"

using namespace std;

//Exercise 1 (a) Check ancorrect if necessary
int ** createMatrix(unsigned int n, unsigned int m){
	int ** A = new int *[n];
	for(unsigned int i = 0; i<n; i++){
		A[i] = new int[m];
	}
	return A;
}

/*
int ** createMatrixWrong(unsigned int n, unsigned int m){
	int ** A = new int *[n];
  //for(unsigned int i = 0; i< n; i++){
	for(unsigned int i = 0; i<=n; i++){
	  //A[i] = new int[m];
		A[i] = new int[n];
	}
	//return A;
}
*/

//Exercise 1 (b) Implement this function
int ** duplicateMatrix(int ** A, unsigned int n, unsigned int m){
	int ** B = new int *[n];
	for(unsigned int i = 0; i<n; i++){
		B[i] = new int[m];
		for(unsigned int j = 0; j<m; j++){
			B[i][j] = A[i][j];
		}
	}
	return B;
}

//Exercise 1 (c) Implement this function
void initMatrix(int ** A, unsigned int n, unsigned int m){
	for(unsigned int i = 0; i < n; i++){
		for(unsigned int j = 0; j < m; j++){
			A[i][j] = 0.0;
		}
	}
}

//Exercise 1 (d) Implement this function
void deallocateMatrix(int ** A, unsigned int n){
	for(unsigned int i = 0; i<n; i++){
		delete [] A[i];
	}
	delete [] A;
}

//Exercise 1 (e) Implement this function
int ** makeBitonal(int ** A, unsigned int n, unsigned int m, int threshold){
	int ** B = duplicateMatrix(A,n,m);
	for(int i=0; i < n; i++){
		for(int j=0; j < m; j++){
			if(B[i][j] < threshold){
				B[i][j]=0;
			}
			else{
				B[i][j]=255;
			}
		}
	}
	return B;
}

//Do not modify
void printMatrix(int ** A, unsigned int n, unsigned int m, string description){
	cout<< "Printing: " << description << endl;
	for(unsigned int i = 0; i < n; i++){
		for(unsigned int j = 0; j < m; j++){
			//We improve the readibility of the printed matrix by spacing the columns
			cout << setw(5) << A[i][j] << " ";
		}
		cout << endl;
	}
}
