#ifndef EX01_LIBRARY_H_
#define EX01_LIBRARY_H_

enum Piece { king, queen, none };
enum Team { black, white, nobody };

struct Square {
    Piece piece;
    Team team;
};

Square **createChessboard(unsigned int m, unsigned int n);
void displayChessboard(Square **c, unsigned int m, unsigned int n);
bool move(Square **c, unsigned int m, unsigned int n,
          int r1, int c1, int r2, int c2);
bool threatened(Square **c, unsigned int m, unsigned int n, int row, int col);
void deleteChessboard(Square **c, unsigned int m);

#endif /* EX01_LIBRARY_H_ */
