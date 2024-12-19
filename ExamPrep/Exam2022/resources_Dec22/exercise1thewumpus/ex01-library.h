#ifndef EX01_LIBRARY_H_
#define EX01_LIBRARY_H_

enum Content { nothing, player, rock, wumpus };

struct Tile {
    Content content;
    bool explored;
};

Tile **createCavern(unsigned int m, unsigned int n);
void revealCavern(Tile **cav, unsigned int m, unsigned int n);
bool movePlayer(Tile **cav, int m, int n, int r, int c);
void drawCavern(Tile **cav, unsigned int m, unsigned int n);

void setupCavern(Tile **cav, unsigned int m, unsigned int n,
                 unsigned int seed);
void deleteCavern(Tile **cav, unsigned int m);

#endif /* EX01_LIBRARY_H_ */
