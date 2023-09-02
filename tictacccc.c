#include <stdio.h>
#include <stdbool.h>

#define SIZE 4

char board[SIZE][SIZE];

// Initialize the board
void initializeBoard() {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            board[i][j] = ' ';
        }
    }
}

// Display the board
void displayBoard() {
    printf("\n");
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            printf("| %c ", board[i][j]);
        }
        printf("|\n");
        if (i < SIZE - 1) {
            printf("-------------\n");
        }
    }
    printf("\n");
}

// Check if the move is valid
bool isValidMove(int row, int col) {
    return (row >= 0 && row < SIZE && col >= 0 && col < SIZE && board[row][col] == ' ');
}

// Check if a player has won
bool checkWin(char player) {
    // Check rows, columns, and diagonals
    for (int i = 0; i < SIZE; i++) {
        bool rowWin = true;
        bool colWin = true;
        for (int j = 0; j < SIZE; j++) {
            if (board[i][j] != player) {
                rowWin = false;
            }
            if (board[j][i] != player) {
                colWin = false;
            }
        }
        if (rowWin || colWin) {
            return true;
        }
    }

    // Check diagonals
    bool diag1Win = true;
    bool diag2Win = true;
    for (int i = 0; i < SIZE; i++) {
        if (board[i][i] != player) {
            diag1Win = false;
        }
        if (board[i][SIZE - 1 - i] != player) {
            diag2Win = false;
        }
    }

    return diag1Win || diag2Win;
}

int main() {
    initializeBoard();
    char players[] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H'};
    int currentPlayer = 0;

    int moves = 0;
    while (moves < SIZE * SIZE) {
        displayBoard();
        int row, col;
        printf("Player %c's turn. Enter row and column (e.g., 1 2): ", players[currentPlayer]);
        scanf("%d %d", &row, &col);

        if (isValidMove(row - 1, col - 1)) {
            board[row - 1][col - 1] = players[currentPlayer];
            moves++;

            if (checkWin(players[currentPlayer])) {
                displayBoard();
                printf("Player %c wins!\n", players[currentPlayer]);
                break;
            }

            currentPlayer = (currentPlayer + 1) % 8;
        } else {
            printf("Invalid move. Try again.\n");
        }
    }

    if (moves == SIZE * SIZE) {
        displayBoard();
        printf("It's a draw!\n");
    }

    return 0;
}
