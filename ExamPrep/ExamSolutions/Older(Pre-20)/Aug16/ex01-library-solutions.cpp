#include <iostream>
#include <vector>
#include "ex01-library.h"

using namespace std;

void reset(double * * A, unsigned int n, double x){
    for(unsigned int i = 0; i < n; i++){
        for(unsigned int j = 0; j < n; j++){
            A[i][j] = x;
        }
    }
}

void display(double * * A, unsigned int n){
    for(unsigned int i = 0; i < n; i++){
        for(unsigned int j = 0; j < n; j++){
            cout << A[i][j] << " ";
        }
        cout << endl;
    }
}

void reduce(double * * A, unsigned int n){
    
    double * * B = new double *[n];
    for(unsigned int i = 0; i<n; i++){
        B[i] = new double[n];
    }
    
    for(unsigned int i = 0; i < n; i++){
        for(unsigned int j = 0; j < n; j++){
            B[i][j] =
              (i>0      ? A[i-1][j] : 0)
            + (j<(n-1)  ? A[i][j+1] : 0)
            + (i<(n-1)  ? A[i+1][j] : 0)
            + (j>0      ? A[i][j-1] : 0) ;
        }
    }
    
    for(unsigned int i = 0; i < n; i++){
        for(unsigned int j = 0; j < n; j++){
            A[i][j] = B[i][j];
        }
    }
    
    for(unsigned int i = 0; i<n; i++){
        delete [] B[i];
    }
    delete [] B;
    
}

vector<double> sumRows(double * * A, unsigned int n){
    
    vector<double> v(n,0);
    
    for(unsigned int i = 0; i < n; i++){
        for(unsigned int j = 0; j < n; j++){
            v[i] += A[i][j];
        }
    }
    
    return v;
}

vector<double> sumCols(double * * A, unsigned int n){
    
    vector<double> v(n,0);
    
    for(unsigned int i = 0; i < n; i++){
        for(unsigned int j = 0; j < n; j++){
            v[j] += A[i][j];
        }
    }
    
    return v;
}

void print(vector<double> & v){
    for(auto e : v){
        cout << e << " ";
    }
    cout << endl;
}
