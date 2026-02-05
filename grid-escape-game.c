#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    FILE *file = fopen("game_state.txt", "r");
    int width, height, playerX, playerY, doorX, doorY;
    
    if (file == NULL) {
        printf("Generating a new board...\n");
        printf("Enter the width and height of board: ");
        scanf("%d %d", &width, &height);
        
        srand(time(NULL));
        playerX = rand() % width;
        playerY = rand() % height;

        doorX = rand() % width;
        doorY = rand() % height;

        if (doorX == playerX && doorY == playerY) {
            doorX = (doorX + 1) % width;
        }

        file = fopen("game_state.txt", "w");
        fprintf(file, "%d %d %d %d %d %d", width, height, playerX, playerY, doorX, doorY);
        fclose(file);
    }
		 else {
        fscanf(file, "%d %d %d %d %d %d", &width, &height, &playerX, &playerY, &doorX, &doorY);
        fclose(file);
    }
    
    printf("Width: %d, Height: %d Player: (%d,%d), Door: (%d,%d)\n", width, height, playerX, playerY, doorX, doorY);
    
    printf("Enter move (WASD or R to reset): ");
    char move;
    scanf(" %c", &move);
    
    if (move == 'R') {
        remove("game_state.txt");
        printf("Game reset! Restart the program to play again.\n");
        return 0;
    }

    if (move == 'W' && playerY > 0) playerY--;
    else if (move == 'A' && playerX > 0) playerX--;
    else if (move == 'S' && playerY < height - 1) playerY++;
    else if (move == 'D' && playerX < width - 1) playerX++;
    else {
        printf("Invalid move.\n");
        return 0;
    }

    if (playerX == doorX && playerY == doorY) {
        printf("Congratulations! You escaped!\n");
        remove("game_state.txt");
    } else {
        file = fopen("game_state.txt", "w");
        fprintf(file, "%d %d %d %d %d %d", width, height, playerX, playerY, doorX, doorY);
        fclose(file);
        printf("Player moves to (%d,%d)\nGame continues...\n", playerX, playerY);
    }

    return 0;
}

