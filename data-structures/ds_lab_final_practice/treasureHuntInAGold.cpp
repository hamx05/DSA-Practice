#include <iostream>
using namespace std;

#define N 5

void printBoard(char sol[N][N]) {
    for (int i=0; i<N; i++) {
        for (int j=0; j<N; j++) {
            cout << sol[i][j] << " ";
        }
        cout << endl;
    }
}

bool noSolution = false;
void findAllPaths(int x, int y, char map[N][N], char sol[N][N], string move) {
    // cout << "test" << endl;
    if ((x>=0 && y>=0) && (x < N && y < N) && map[x][y] == 'E') {
        cout << "Solution: " << endl;
        sol[x][y] = '.';
        noSolution = true;
        printBoard(sol);
        cout << "Moves: " << move << endl << endl;
        return;
    }

    // check current position
    if ((x>=0 && y>=0) && (x < N && y < N) && map[x][y] != 'X' && sol[x][y] == '0') {
        sol[x][y] = '.';

        if (x+1 < N) {
            findAllPaths(x+1, y, map, sol, move + 'D');
        }

        if (y+1 < N) {
            findAllPaths(x, y+1, map, sol, move + 'R');
        }

        if (x-1 >= 0) {
            findAllPaths(x-1, y, map, sol, move + 'U');
        }

        if (y-1 >= 0) {
            findAllPaths(x, y-1, map, sol, move + 'L');
        }

        sol[x][y] = '0';
    }
}

void solveTreasureHunt () {
    char map[N][N]={{'S', '0', '0', 'X', 'E'},
                    {'X', 'X', '0', 'X', '0'},
                    {'0', '0', '0', '0', '0'},
                    {'0', 'X', 'X', '0', 'X'},
                    {'0', '0', '0', '0', '0'}};

    char sol[N][N]={{'0', '0', '0', '0', '0'},
                    {'0', '0', '0', '0', '0'},
                    {'0', '0', '0', '0', '0'},
                    {'0', '0', '0', '0', '0'},
                    {'0', '0', '0', '0', '0'}};
    
    findAllPaths(0, 0, map, sol, "");

    if (noSolution) {
        cout << "No safe route possible." << endl;
    }
}

int main () {

    solveTreasureHunt();
    

    return 0;
}