#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define BOARD_SIZE 10
#define BOMB_COUNT 10

int board[BOARD_SIZE][BOARD_SIZE];
int revealed[BOARD_SIZE][BOARD_SIZE];

void print_board() {
    printf("\n  ");
    for (int i = 0; i < BOARD_SIZE; i++) {
        printf("%d ", i);
    }
    printf("\n");

    for (int i = 0; i < BOARD_SIZE; i++) {
        printf("%d ", i);
        for (int j = 0; j < BOARD_SIZE; j++) {
            if (revealed[i][j]) {
                if (board[i][j] == -1) {
                    printf("* ");
                } else {
                    printf("%d ", board[i][j]);
                }
            } else {
                printf(". ");
            }
        }
        printf("\n");
    }
}

void reveal_cell(int x, int y) {
    if (revealed[x][y]) {
        return;
    }

    revealed[x][y] = 1;

    if (board[x][y] == -1) {
        printf("\nYou hit a bomb! Game over.\n");
        exit(0);
    }

    if (board[x][y] == 0) {
        if (x > 0) {
            reveal_cell(x - 1, y);
        }
        if (x < BOARD_SIZE - 1) {
            reveal_cell(x + 1, y);
        }
        if (y > 0) {
            reveal_cell(x, y - 1);
        }
        if (y < BOARD_SIZE - 1) {
            reveal_cell(x, y + 1);
        }
    }
}

int main() {
    // Initialize board with zeros
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            board[i][j] = 0;
        }
    }

    // Place bombs randomly
    srand(time(NULL));
    int bombs_placed = 0;
    while (bombs_placed < BOMB_COUNT) {
        int x = rand() % BOARD_SIZE;
        int y = rand() % BOARD_SIZE;
        if (board[x][y] != -1) {
            board[x][y] = -1;
            bombs_placed++;
        }
    }

    // Calculate numbers for each cell
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            if (board[i][j] != -1) {
                int count = 0;
                if (i > 0 && board[i-1][j] == -1) {
                    count++;
                }
                if (i < BOARD_SIZE - 1 && board[i+1][j] == -1) {
                    count++;
                }
                if (j > 0 && board[i][j-1] == -1) {
                    count++;
                }
                if (j < BOARD_SIZE - 1 && board[i][j+1] == -1) {
                    count++;
                }
                board[i][j] = count;
            }
        }
    }

    // Main game loop
    while (1) {
        print_board();

        int x, y;
        printf("\nEnter row and column to reveal (e.g. 2 4): ");
        scanf("%d %d", &x, &y);
            if (x < 0 || x >= BOARD_SIZE || y < 0 || y >= BOARD_SIZE) {
        printf("Invalid input. Please try again.\n");
    } else {
        reveal_cell(x, y);
    }

    // Check for win condition
    int unrevealed_count = 0;
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            if (!revealed[i][j]) {
                unrevealed_count++;
            }
        }
    }
    if (unrevealed_count == BOMB_COUNT) {
        printf("\nYou win!\n");
        exit(0);
    }
}

return 0;
}

