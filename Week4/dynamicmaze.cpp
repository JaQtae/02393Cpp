#include <iostream>

typedef enum { wood, stone } material;

struct tile {
    int x, y;
    bool isWall;
    material type;
};

void displayMaze(tile** playground, int n, int m, int playerX, int playerY) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
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
    int n, m;
    // Get maze size from the user
    std::cin >> n;
    std::cin >> m;
    
    // Dynamically allocate the maze
    // playground -> array of pointers to tiles
    tile** playground = new tile*[n];  // new operator returns a pointer to the allocated memory at --runtime-- not compile time!
    for (int i = 0; i < n; i++) {
        playground[i] = new tile[m];
    }
    
    // Initialize
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            playground[i][j].x = j;
            playground[i][j].y = i;
            playground[i][j].isWall = (j == 0 || i == (n - 1) || (i == 0 && j != 3) || j == (m - 1));
            playground[i][j].type = playground[i][j].isWall ? stone : wood;
        }
    }
    
    // Initial player position
    int playerX = m / 2, playerY = n / 2;
    
    char command;
    do {
        displayMaze(playground, n, m, playerX, playerY);
        std::cin >> command;

        if (command == 'l' && playerX > 0 && !playground[playerY][playerX - 1].isWall) {
            playerX--;
        } else if (command == 'r' && playerX < m - 1 && !playground[playerY][playerX + 1].isWall) {
            playerX++;
        } else if (command == 'u' && playerY > 0 && !playground[playerY - 1][playerX].isWall) {
            playerY--;
        } else if (command == 'd' && playerY < n - 1 && !playground[playerY + 1][playerX].isWall) {
            playerY++;
        }
        
    } while (command != 'q');
    
    
    // Free up the dynamically allocated memory, no leakage.
    for (int i = 0; i < n; i++) {
        delete[] playground[i];
    }
    delete[] playground;
    
    return 0;
}
