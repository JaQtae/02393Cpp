struct Tile {
    int ship;      // or bool mine
    bool hit;
};

// Loop over every tile
for (unsigned r = 0; r < m; ++r) {
    for (unsigned c = 0; c < n; ++c) {
        Tile &t = sea[r][c];
        // → inspect t.ship, t.hit, etc.
    }
}

// Check bounds before access ( !!given m x n tileset!! ) 
bool inBounds(int r, int c, int m, int n) {
    return (r >= 0 && r < m && c >= 0 && c < n);
}

// Loop over the 8 neighbours of a mine (center tile)
static const int DR[8] = {-1,-1,-1, 0, 0, 1, 1, 1}; // row
static const int DC[8] = {-1, 0, 1,-1, 1,-1, 0, 1}; // column

for (unsigned r = 0; r < m; ++r) {
    for (unsigned c = 0; c < n; ++c) {
        int countMines = 0;
        for (int d = 0; d < 8; ++d) {
            int rr = (int)r + DR[d];
            int cc = (int)c + DC[d];
            if (inBounds(rr,cc,m,n) && sea[rr][cc].ship != 0) {
                ++countMines;
            }
        }
        // → countMines is number of adjacent ships/mines
    }
}

// Loop over orthogonal (4-way) neighbours
static const int ORTHO_DR[4] = {-1, 0, 0, 1};
static const int ORTHO_DC[4] = { 0,-1, 1, 0};

for (int d = 0; d < 4; ++d) {
    int rr = row + ORTHO_DR[d];
    int cc = col + ORTHO_DC[d];
    if (inBounds(rr,cc,m,n)) {
        // → sea[rr][cc]
    }
}


