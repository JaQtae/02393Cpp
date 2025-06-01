#ifndef EX01_LIBRARY_H_
#define EX01_LIBRARY_H_

struct Tile {
    bool mine;
    bool hit;
};

// Re-exam predicted functions
unsigned int countMines(Tile **field, unsigned int m, unsigned int n);
void revealSurroundings(Tile **field, int m, int n, int r, int c);
void displayRevealedField(Tile **field, unsigned int m, unsigned int n);
bool safeMovesLeft(Tile **field, int m, int n);

#endif /* EX01_LIBRARY_H_ */