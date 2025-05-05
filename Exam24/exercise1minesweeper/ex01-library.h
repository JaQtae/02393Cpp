#ifndef EX01_LIBRARY_H_
#define EX01_LIBRARY_H_


struct Tile {
    bool mine;
    bool hit;
};

Tile **createMinefield(unsigned int m, unsigned int n);
bool placeMine(Tile **field, unsigned int m, unsigned int n, unsigned int r, unsigned int c);
void displayMinefield(Tile **field, unsigned int m, unsigned int n);
bool isGameOver(Tile **field, unsigned int m, unsigned int n);

//Existing
void deleteMinefield(Tile **field, unsigned int m);
void revealMinefield(Tile **field, unsigned int m, unsigned int n);

#endif /* EX01_LIBRARY_H_ */
