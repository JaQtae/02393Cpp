#include <iostream>

using namespace std;


#define NROWS 12 // Maze size
#define NCOLS 16

typedef enum { wood, stone } material; // material: wood or stone
struct tile {
    int x, y; // coordinates
    bool isWall; // is it a wall?
    material type; // what material type is it
};



void displayCurrentSituation(tile playground[NROWS][NCOLS], int playerX, int playerY) {
    // Output current situation of the maze
    // Depending on player position (playerX, playerY)
    for (int i = 0; i < NROWS; i++) {
        for (int j = 0; j < NCOLS; j++) {
            if (i == playerY && j == playerX) {
                cout << "O"; // Player's position
            } else if (playground[i][j].isWall) {
                cout << "*"; // Wall
            } else {
                cout << " "; // Empty space
            }
        }
        cout << endl;
    }
}

int main() {
    // Initialize playground
    tile playground[NROWS][NCOLS];

    for (int i = 0; i < NROWS; i++) {
        for (int j = 0; j < NCOLS; j++) {
            playground[i][j].x = j;
            playground[i][j].y = i;
            playground[i][j].isWall = (j==0 || i==(NROWS-1) || (i==0 && j!=3) || j==(NCOLS-1));
            // Below equivalent to:
            // playground[i][j].type = playground[i][j].isWall ? stone : wood; // (if wall, then stone. else wood.)
            if (playground[i][j].isWall) {
                playground[i][j].type = stone;
            } else {
                playground[i][j].type = wood;
            }   
        }       
    }

    // Initialize player position
    int playerX = 5, playerY = 5;

    char command;

    do {
        // Display the current situation
        displayCurrentSituation(playground, playerX, playerY);

        // Read user command
        cin >> command;

        // Move the player based on command
        // if "l" -> left, if "r" -> right, if "u" -> up, if "d" -> down
        // if player is NOT at the edge of the maze and the next tile is NOT a wall:
        // move the player to the next tile (decrement/increment playerX/playerY position)
        // e.g. (5,5) -> "l" -> playerX-- -> (4,5)
        if (command == 'l' && playerX > 0 && !playground[playerY][playerX - 1].isWall) {
            playerX--;
        } else if (command == 'r' && playerX < NCOLS - 1 && !playground[playerY][playerX + 1].isWall) {
            playerX++;
        } else if (command == 'u' && playerY > 0 && !playground[playerY - 1][playerX].isWall) {
            playerY--;
        } else if (command == 'd' && playerY < NROWS - 1 && !playground[playerY + 1][playerX].isWall) {
            playerY++;
        }
    } while (command != 'q'); // "q" -> quit

    return 0;
}