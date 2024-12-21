#include <iostream>
#include <vector>
#include <iomanip>
#include "ex01-library.h"

using namespace std;

//Exercise 1 (a) Check and correct if necessary
unsigned int ** createMatrix(int n, int m){
	unsigned int ** A = new unsigned int *[n];
	for(int j = 0; j<n; j++){
		A[j] = new unsigned int[m];
	}
	return A;
}

/*
unsigned int ** createMatrix(int n, int m){
	unsigned int ** A = new unsigned int *[n];
  //for(int j = 0; j<n; j++){
	for(int j = 1; j<n-1; j++){
		A[j] = new unsigned int[m];
	}
	return A;
}
*/


//Exercise 1 (b) Check and correct if necessary
void deallocateMatrix(unsigned int ** A, int n){
	for(int i = 0; i<n; i++){
		delete [] A[i];
	}
	delete [] A;
}


/*
void deallocateMatrix(unsigned int ** A, int n){
  delete [] A;
}
*/

//Exercise 1 (c) Implement this function
void fillWhite(unsigned int ** A, int n, int m){
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			A[i][j] = 255;
		}
	}
}

//Exercise 1 (d) Implement this function
void lighten(unsigned int ** A, int n, int m){
	for(int i=0; i < n; i++){
		for(int j=0; j < m; j++){
			if(A[i][j] < 255){
				A[i][j]+=1;
			}
		}
	}
}

//Exercise 1 (e) Implement this function
void darken(unsigned int ** A, int n, int m){
	for(int i=0; i < n; i++){
		for(int j=0; j < m; j++){
			if(A[i][j] > 0){
				A[i][j]-=1;
			}
		}
	}
}

//Do not modify
void printMatrix(unsigned int ** A, int n, int m, string description){
	cout<< "Printing: " << description << endl;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			//We improve the readibility of the printed matrix by spacing the columns
			cout << setw(5) << A[i][j] << " ";
		}
		cout << endl;
	}
}
