// Exercise 1: Minesweeper predicted re-exam tasks
#include <iostream>
using namespace std;

struct Tile {
    bool mine;
    bool hit;
};

unsigned int countMines(Tile **field, unsigned int m, unsigned int n) {
    unsigned int count = 0;
    for (unsigned int i = 0; i < m; ++i)
        for (unsigned int j = 0; j < n; ++j)
            if (field[i][j].mine) ++count;
    return count;
}

int countAdjacentMines(Tile **field, int m, int n, int r, int c) {
    int count = 0;
    for (int dr = -1; dr <= 1; ++dr)
        for (int dc = -1; dc <= 1; ++dc) {
            int nr = r + dr, nc = c + dc;
            if ((dr != 0 || dc != 0) && nr >= 0 && nr < m && nc >= 0 && nc < n && field[nr][nc].mine)
                ++count;
        }
    return count;
}

void revealSurroundings(Tile **field, int m, int n, int r, int c) {
    if (r < 0 || r >= m || c < 0 || c >= n || field[r][c].hit) return;
    field[r][c].hit = true;
    if (countAdjacentMines(field, m, n, r, c) == 0) {
        for (int dr = -1; dr <= 1; ++dr)
            for (int dc = -1; dc <= 1; ++dc)
                if (dr != 0 || dc != 0)
                    revealSurroundings(field, m, n, r + dr, c + dc);
    }
}

void displayRevealedField(Tile **field, unsigned int m, unsigned int n) {
    for (unsigned int i = 0; i < m; ++i) {
        for (unsigned int j = 0; j < n; ++j) {
            if (!field[i][j].hit) cout << '?';
            else if (field[i][j].mine) cout << 'X';
            else {
                int adj = countAdjacentMines(field, m, n, i, j);
                cout << (adj ? char('0' + adj) : ' ');
            }
        }
        cout << endl;
    }
}

bool safeMovesLeft(Tile **field, int m, int n) {
    for (int i = 0; i < m; ++i)
        for (int j = 0; j < n; ++j)
            if (!field[i][j].hit && !field[i][j].mine)
                return true;
    return false;
}