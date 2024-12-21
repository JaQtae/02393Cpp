#ifndef EX04_LIBRARY_H_
#define EX04_LIBRARY_H_

#include <string>
using namespace std;

//Do not modify
class Piece {
protected:
	int r;
	int c;
public:
	virtual ~Piece();
	void printPosition();	
	virtual string getColor()=0;
	virtual string printCode()=0;
	virtual void moveRight()=0;
	virtual void moveLeft()=0;
};

//Exercise 4 (a) declare WhitePiece
class WhitePiece : public Piece{
public:
	WhitePiece(int r, int c);
	string getColor();
	string printCode();
	void moveRight();
	void moveLeft();
};

//Exercise 4 (b) declare BalckPiece
class BlackPiece : public Piece{
public:
	BlackPiece(int r, int c);
	string getColor();
	string printCode();
	void moveRight();
	void moveLeft();
};

#endif
