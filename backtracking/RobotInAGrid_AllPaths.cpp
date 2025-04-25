#include <iostream>
using namespace std;

#define N 4

void printPath (char sol[N][N]) {
    for (int i=0; i<N; i++) {
        for (int j=0; j<N; j++) {
            cout << sol[i][j] << " ";
        }
        cout<<endl;
    }
    cout<<endl;
}

// All Possible Paths
void findAllPaths (int x, int y, char grid[N][N], char sol[N][N]) {
    if (x == N-1 && y == N-1 && grid[x][y] == '.') {
        sol[x][y] = '.';
        cout << "Solution: " << endl;
        printPath(sol);
        return;
    }

    // check current position
    if ((x >= 0 && x < N) && (y >= 0 && y < N) && grid[x][y] != 'X') {
        sol[x][y] = '.';

        if (x + 1 < N) {
            findAllPaths(x+1, y, grid, sol);
        }

        if (y + 1 < N) {
            findAllPaths(x, y+1, grid, sol);
        }

        sol[x][y] = 'X';
    }
}

void solveRobotInAGrid () {
    char grid[N][N] =  {{'.', '.', '.', 'X'}, 
                        {'X', '.', 'X', '.'}, 
                        {'.', '.', '.', '.'}, 
                        {'X', 'X', '.', '.'}};

    char sol[N][N] =   {{'X', 'X', 'X', 'X'}, 
                        {'X', 'X', 'X', 'X'}, 
                        {'X', 'X', 'X', 'X'}, 
                        {'X', 'X', 'X', 'X'}};


    cout<<"Grid: " << endl;
    printPath(grid);
    findAllPaths(0, 0, grid, sol);
}

int main () {

    solveRobotInAGrid();

    return 0;
}