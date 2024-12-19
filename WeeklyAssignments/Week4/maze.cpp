#include <iostream>

typedef enum { wood, stone } material;

struct tile {
    int x, y;
    bool isWall;
    material type;
};

#define NROWS 12
#define NCOLS 16

void displayMaze(tile playground[NROWS][NCOLS], int playerX, int playerY) {
    for (int i = 0; i < NROWS; i++) {
        for (int j = 0; j < NCOLS; j++) {
            if (i == playerY && j == playerX) {
                std::cout << "O"; // Player's position
            } else if (playground[i][j].isWall) {
                std::cout << "*"; // Wall
            } else {
                std::cout << " "; // Empty space
            }
        }
        std::cout << std::endl;
    }
}

int main() {
    tile playground[NROWS][NCOLS];
    
    // Initialize the playground
    for (int i = 0; i < NROWS; i++) {
        for (int j = 0; j < NCOLS; j++) {
            playground[i][j].x = j;
            playground[i][j].y = i;
            playground[i][j].isWall = (j == 0 || i == (NROWS - 1) || (i == 0 && j != 3) || j == (NCOLS - 1));
            playground[i][j].type = playground[i][j].isWall ? stone : wood;
        }
    }
    
    // Initial player position
    int playerX = 5, playerY = 5;
    
    char command;
    do {
        // Display the current state
        displayMaze(playground, playerX, playerY);
        
        // Read user command
        std::cin >> command;
        
        // Move the player based on command
        if (command == 'l' && playerX > 0 && !playground[playerY][playerX - 1].isWall) {
            playerX--;
        } else if (command == 'r' && playerX < NCOLS - 1 && !playground[playerY][playerX + 1].isWall) {
            playerX++;
        } else if (command == 'u' && playerY > 0 && !playground[playerY - 1][playerX].isWall) {
            playerY--;
        } else if (command == 'd' && playerY < NROWS - 1 && !playground[playerY + 1][playerX].isWall) {
            playerY++;
        }
        
    } while (command != 'q');

    
    return 0;
}
