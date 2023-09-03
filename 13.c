#include <stdio.h>

#define MAX_N 10

int n;

void display(int board[MAX_N][MAX_N]) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (board[i][j]) {
                printf("Q "); 
            } else {
                printf("X ");
            }
        }
        printf("\n");
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (board[i][j]) {
                printf("%d ", j+1); 
            }
        }
    }

    printf("\n-----------------------");
}

int min(int a, int b) {
    return a < b ? a : b;
}

int isSafe(int board[MAX_N][MAX_N], int row, int col) {
    for (int i = 0; i < row; i++) {
        if (board[i][col]) {
            return 0;
        }
    }

    int maxLeft = min(row, col);
    for (int i = 1; i <= maxLeft; i++) {
        if (board[row - i][col - i]) {
            return 0;
        }
    }

    int maxRight = min(row, n - col - 1);
    for (int i = 1; i <= maxRight; i++) {
        if (board[row - i][col + i]) {
            return 0;
        }
    }
    return 1;
}

void queens(int board[MAX_N][MAX_N], int row) {
    if (row == n) {
        display(board);
        printf("\n");
    }
    for (int col = 0; col < n; col++) {
        if (isSafe(board, row, col)) {
            board[row][col] = 1;
            queens(board, row + 1);
            board[row][col] = 0;
        }
    }
}

int main() {
    n = 5;
    int board[MAX_N][MAX_N] = {0};

    queens(board, 0);

    return 0;
}
