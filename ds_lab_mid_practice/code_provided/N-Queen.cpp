bool isSafe(int board[], int row, int col) {
    for (int i = 0; i < row; i++) {
        // Check if there's a queen in the same column or diagonals
        if (board[i] == col || abs(board[i] - col) == abs(i - row)) {
            return false;
        }
    }
    return true;
}
bool solveNQueens(int board[], int n, int row = 0) {
    if (row == n) {
        // All queens are placed successfully
        return true;
    }

    for (int col = 0; col < n; col++) {
        if (isSafe(board, row, col)) {
            board[row] = col; // Place the queen in this column

            // Recursively place queens in the next row
            if (solveNQueens(board, n, row + 1)) {
                return true; // If a solution is found, return true
            }

            // If placing the queen in this column doesn't lead to a solution, backtrack
            board[row] = -1;
        }
    }

    // If no safe position is found, return false (backtrack)
    return false;
}
