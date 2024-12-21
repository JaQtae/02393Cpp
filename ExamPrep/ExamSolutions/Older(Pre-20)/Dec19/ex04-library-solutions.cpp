#include "ex04-library.h"
#include <iostream>

//Do not modify
Piece::~Piece(){}

//Do not modify
void Piece::printPosition(){
	cout << "(" << r << "," << c << ")" << endl;
}

//Exercise 4 (a) implement the methods of WhitePiece
WhitePiece::WhitePiece(int r, int c){
	this->r=r;
	this->c=c;
}
string WhitePiece::getColor(){
	return "white";
}
string WhitePiece::printCode(){
	return "W";
//	return "\342\230\272";
}
void WhitePiece::moveRight(){
	r=r-1;
	c=c+1;
}
void WhitePiece::moveLeft(){
	r=r-1;
	c=c-1;
}

//Exercise 4 (b) implement the methods of BlackPiece
BlackPiece::BlackPiece(int r, int c){
	this->r=r;
	this->c=c;
}
string BlackPiece::getColor(){
	return "black";
}
string BlackPiece::printCode(){
	return "B";
//	return "\342\230\273";
}
void BlackPiece::moveRight(){
	r=r+1;
	c=c-1;
}
void BlackPiece::moveLeft(){
	r=r+1;
	c=c+1;
}