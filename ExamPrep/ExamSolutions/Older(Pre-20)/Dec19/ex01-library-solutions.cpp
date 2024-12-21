#include <iostream>
#include "ex01-library.h"

using namespace std;

//Exercise 1 (a) Implement this function
cell ** createAndInitBoard(int n){
	cell ** board = new cell*[n];
	for(int r=0;r<n;r++){
		board[r]=new cell[n];
		for(int c=0;c<n;c++){
			board[r][c].color=computeColor(r,c);
			board[r][c].status=emptyC;
			if(r<3 && board[r][c].color==dark){
				board[r][c].status=blackPiece;
			}
			if(n-r<=3 && board[r][c].color==dark){
				board[r][c].status=whitePiece;
			}
		}
	}
	return board;
}

//Exercise 1 (b) Implement this function
cell ** duplicateBoard(cell ** A, int n){
	cell ** board = new cell*[n];
	for(int r=0;r<n;r++){
		board[r]=new cell[n];
		for(int c=0;c<n;c++){
			board[r][c]=A[r][c];
		}
	}
	return board;
}

//void deallocateBoard(cell ** A, int n){
//	for(int r=0; r<n;r++){
//		delete[] A[r];
//	}
//	delete[] A;
//}

//Exercise 1 (c) Implement this function
bool moveRight(cell ** A,int n,int r, int c){
	if(r<0||r>=n || c<0||c>=n){
		return false;
	}

	if(A[r][c].status==emptyC){
		return false;
	}
	int toc=-1;
	int tor=-1;
	if(A[r][c].status==blackPiece){
		tor=r+1;
		toc=c-1;
	}
	else{
		tor=r-1;
		toc=c+1;
	}
	if(tor<0||tor>=n || toc<0||toc>=n){
		return false;
	}
	if(A[tor][toc].status!=emptyC){
		return false;
	}
	cellStatus status = A[r][c].status;
	A[r][c].status=emptyC;
	A[tor][toc].status=status;
	return true;
}

//Exercise 1 (d) Implement this function
bool moveLeft(cell ** A,int n,int r, int c){
	if(r<0||r>=n || c<0||c>=n){
		return false;
	}
	if(A[r][c].status==emptyC){
		return false;
	}
	int toc=-1;
	int tor=-1;
	if(A[r][c].status==blackPiece){
		tor=r+1;
		toc=c+1;
	}
	else{
		tor=r-1;
		toc=c-1;
	}
	if(tor<0||tor>=n || toc<0||toc>=n){
		return false;
	}
	if(A[tor][toc].status!=emptyC){
		return false;
	}
	cellStatus status = A[r][c].status;
	A[r][c].status=emptyC;
	A[tor][toc].status=status;
	return true;
}

//Do not modify
cellColor computeColor(int r,int c){
	if((r%2 == 0 && c%2 == 0) || (r%2 != 0 && c%2 != 0)){
		return bright;
	}
	return dark;
}

//Do not modify
void printBoard(cell ** A, int n){
	cout << ' ';
	for(int c=0;c<n;c++){
		cout << c;
	}
	cout << endl;
	for(int r=0;r<n;r++){
		cout << r;
		for(int c=0;c<n;c++){
			//Print ' ' or '#' if emptyC, or the piece color (W or B)
			switch (A[r][c].status) {
			case emptyC:
				cout << ((A[r][c].color==bright)?' ':'#');
				break;
			case whitePiece:
				//cout << "\342\230\272";
				cout << "W";
				break;
			case blackPiece:
				//cout << "\342\230\273";
				cout << "B";
				break;
			}
		}
		cout << endl;
	}
	cout << endl;
}