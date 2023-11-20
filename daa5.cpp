//N-Queen
#include <iostream>
#include <vector>
using namespace std;
void printBoard(const vector<vector<int>>& board) {
    for (const auto& row : board) {
        for (int col : row) {
            if (col == 1) {
                cout << "Q ";
            } else {
                cout << ". ";
            }
        }
        cout << endl;
    }
    cout << endl;
}
bool isSafe(const vector<vector<int>>& board, int row, int col, int n) {
    for (int i = 0; i < col; ++i) {
        if (board[row][i] == 1) {
            return false;
        }
    }
    for (int i = row, j = col; i >= 0 && j >= 0; --i, --j) {
        if (board[i][j] == 1) {
            return false;
        }
    }
    for (int i = row, j = col; i < n && j >= 0; ++i, --j) {
        if (board[i][j] == 1) {
            return false;
        }
    }
    return true;
}
bool solveNQueens(vector<vector<int>>& board, int col, int n) {
    if (col == n) {
        printBoard(board);
        return true; 
    }
    bool res = false;
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
    cout << "Enter the size of the chessboard (N x N): ";
    cin >> n;
    vector<vector<int>> board(n, vector<int>(n, 0));
    int firstQueenRow;
    cout << "Enter the row where the first queen is placed (0-indexed): ";
    cin >> firstQueenRow;
    board[firstQueenRow][0] = 1;
    if (!solveNQueens(board, 1, n)) {
        cout << "Solution does not exist." << endl;
    }
    return 0;
}