#include <iostream>
using namespace std;

#define N 4


bool isSafe(int row, int col, char board[N][N]) {
    for (int i=0; i<N; i++) {
        if (board[row][i] == 'Q') return false;
        if (board[i][col] == 'Q') return false;
    }

    int r = row;
    int c = col;

    // check upper left
    while (r>=0 && c>=0) {
        if (board[r][c] == 'Q') return false;
        r--;
        c--;
    }

    r = row;
    c = col;
    // check upper right
    while (r>=0 && c < N) {
        if (board[r][c] == 'Q') return false;
        r--;
        c++;
    }

    r = row;
    c = col;
    // check lower left
    while (r < N && c >= 0) {
        if (board[r][c] == 'Q') return false;
        r++;
        c--;
    }

    r = row;
    c = col;
    // check upper right
    while (r < N && c < N) {
        if (board[r][c] == 'Q') return false;
        r++;
        c++;
    }

    return true;
}

void printBoard (char board[N][N]) {
    cout<<"Board: \n";
    for (int i=0; i<N; i++) {
        for (int j=0; j<N; j++) {
            cout << board[i][j] << " ";
        }
        cout<<endl;
    }
}

// All possible solutions
void findAllPaths(int row, int col, char board[N][N]) {
    if (col >= N) {
        printBoard(board);
        return;
    }

    for (int row=0; row<N; row++) {
        if (isSafe(row, col, board)) {
            board[row][col] = 'Q';
            findAllPaths(row, col+1, board);
            board[row][col] = '.';
        }
    }
    return;
}



void solveNQueens () {
    char board[N][N] = {{'.', '.', '.', '.'},
                        {'.', '.', '.', '.'},
                        {'.', '.', '.', '.'},
                        {'.', '.', '.', '.'}};

    findAllPaths(0, 0, board); 
}

int main () {
    
    solveNQueens();

    return 0;

}
    
