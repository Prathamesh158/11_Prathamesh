#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 10
void printBoard(int board[MAX_SIZE][MAX_SIZE], int n) {
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (board[i][j] == 1) {
                printf("Q ");
            } else {
                printf(". ");
            }
        }
        printf("\n");
    }
    printf("\n");
}
int isSafe(int board[MAX_SIZE][MAX_SIZE], int row, int col, int n) {
    for (int i = 0; i < col; ++i) {
        if (board[row][i] == 1) {
            return 0;
        }
    }
    for (int i = row, j = col; i >= 0 && j >= 0; --i, --j) {
        if (board[i][j] == 1) {
            return 0;
        }
    }
    for (int i = row, j = col; i < n && j >= 0; ++i, --j) {
        if (board[i][j] == 1) {
            return 0;
        }
    }
    return 1;
}
int solveNQueens(int board[MAX_SIZE][MAX_SIZE], int col, int n) {
    if (col == n) {
        printBoard(board, n);
        return 1;
    }
    int res = 0;
    for (int i = 0; i < n; ++i) {
        if (isSafe(board, i, col, n)) {
            board[i][col] = 1;
            res = solveNQueens(board, col + 1, n) || res;
            board[i][col] = 0;
        }
    }
    return res;
}
int main() {
    int n;
    printf("Enter the size of the chessboard (N x N): ");
    scanf("%d", &n);
    int board[MAX_SIZE][MAX_SIZE] = {0};
    int firstQueenRow;
    printf("Enter the row where the first queen is placed (0-indexed): ");
    scanf("%d", &firstQueenRow);
    board[firstQueenRow][0] = 1;
    if (!solveNQueens(board, 1, n)) {
        printf("Solution does not exist.\n");
    }
    return 0;
}
