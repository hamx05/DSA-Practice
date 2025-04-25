#include <iostream>
using namespace std;

#define N 4

bool isSafe(int row, int col, char board[N][N]) {
    // Check row and column
    for (int i = 0; i < N; i++) {
        if (board[row][i] == 'Q') return false; // check row
        if (board[i][col] == 'Q') return false; // check column
    }

    // Check the upper left diagonal
    int r = row, c = col;
    while (r >= 0 && c >= 0) {
        if (board[r][c] == 'Q') return false;
        r--;
        c--;
    }

    // Check the upper right diagonal
    r = row;
    c = col;
    while (r >= 0 && c < N) {
        if (board[r][c] == 'Q') return false;
        r--;
        c++;
    }

    // Check the lower left diagonal
    r = row;
    c = col;
    while (r < N && c >= 0) {
        if (board[r][c] == 'Q') return false;
        r++;
        c--;
    }

    // Check the lower right diagonal
    r = row;
    c = col;
    while (r < N && c < N) {
        if (board[r][c] == 'Q') return false;
        r++;
        c++;
    }

    return true;
}

bool findPath(int col, char board[N][N]) {
    if (col >= N) return true;  // All queens are placed successfully

    // Try placing a queen in each row of this column
    for (int row = 0; row < N; row++) {
        if (isSafe(row, col, board)) {
            board[row][col] = 'Q';  // Place the queen

            // Recur to place the rest of the queens
            if (findPath(col + 1, board)) {
                return true;
            }

            // Backtrack if placing the queen leads to no solution
            board[row][col] = '.';
        }
    }

    return false;  // If no safe position is found in this column
}

void solveNQueens() {
    char board[N][N] = {{'.', '.', '.', '.'},
                        {'.', '.', '.', '.'},
                        {'.', '.', '.', '.'},
                        {'.', '.', '.', '.'}};

    if (findPath(0, board)) {
        cout << "Solution found:\n";
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                cout << board[i][j] << " ";
            }
            cout << endl;
        }
    } else {
        cout << "No solution exists.\n";
    }
}

int main() {
    solveNQueens();
    return 0;
}
