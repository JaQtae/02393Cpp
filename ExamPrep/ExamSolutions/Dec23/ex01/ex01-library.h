#ifndef EX01_LIBRARY_H_
#define EX01_LIBRARY_H_


struct Tile {
    unsigned int ship;
    bool hit;
};

Tile **createSea(unsigned int m, unsigned int n);
void displaySea(Tile **sea, unsigned int m, unsigned int n, bool reveal);
bool placeShip(Tile **sea, unsigned int m, unsigned int n, unsigned int r, unsigned int c, unsigned int number, unsigned int size, bool vertical);
bool launchMissile(Tile **sea, unsigned int m, unsigned int n, unsigned int r, unsigned int c);

//Existing
void deleteSea(Tile **sea, unsigned int m);

#endif /* EX01_LIBRARY_H_ */
