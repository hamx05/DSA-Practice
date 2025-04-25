#include <iostream>
using namespace std;

#define N 4

bool isSafe(int row, int col, char board[N][N]) {
    for (int i=0; i<N; i++) {
        if (board[row][i] == 'Q') return false; // check row
        if (board[i][col] == 'Q') return false; // check cols
    }

    int r = row;
    int c = col;
    // upper left diagonal    
    while (r >= 0 && c >= 0) {
        if (board[r][c] == 'Q') return false;
        r--;
        c--;
    }

    r = row;
    c = col;
    // upper right diagonal    
    while (r >= 0 && c < N) {
        if (board[r][c] == 'Q') return false;
        r--;
        c++;
    }

    r = row;
    c = col;
    // lower left diagonal    
    while (r < N && c >= 0) {
        if (board[r][c] == 'Q') return false;
        r++;
        c--;
    }

    r = row;
    c = col;
    // upper right diagonal    
    while (r < N && c < N) {
        if (board[r][c] == 'Q') return false;
        r++;
        c++;
    }

    return true;
}

// One solution
bool findPath (int row, int col, char board[N][N]) {
    if (col >= N) return true;

    for (int row=0; row<N; row++) {
        if (isSafe(row, col, board)) {
            board[row][col] = 'Q';
            if (findPath(row, col + 1, board)) {
                return true;
            }
            board[row][col] = '.';
        }
        
    }
    return false;
}

void solveNQueens() {
    char board[N][N] = {{'.', '.', '.', '.'},
                        {'.', '.', '.', '.'},
                        {'.', '.', '.', '.'},
                        {'.', '.', '.', '.'}};

    findPath(0, 0, board);

    cout<<"Board: \n";
    for (int i=0; i<N; i++) {
        for (int j=0; j<N; j++) {
            cout<< board[i][j] << " ";
        }
        cout<<endl;
    } 

}


int main () {

    // char board[N][N] = {{'.', '.', '.', '.'},
    //                     {'.', '.', '.', '.'},
    //                     {'.', '.', '.', '.'},
    //                     {'.', '.', '.', '.'}};

    // findPath(0, 0, board);   
    
    solveNQueens();

    

    return 0;
}