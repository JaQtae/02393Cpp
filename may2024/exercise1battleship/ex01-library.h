#ifndef EX01_LIBRARY_H_
#define EX01_LIBRARY_H_


struct Tile {
    unsigned int ship;
    bool hit;
};

Tile **createSea(unsigned int m);
void displaySea(Tile **sea, unsigned int m, bool reveal);
bool launchBigMissile(Tile **sea, unsigned int m, unsigned int r, unsigned int c);
bool isGameOver(Tile **sea, unsigned int m);

//Existing
void deleteSea(Tile **sea, unsigned int m);

#endif /* EX01_LIBRARY_H_ */
